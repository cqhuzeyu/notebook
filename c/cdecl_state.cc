#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXCDECLLEN 4096
#define MAXTOKENS 100
#define MAXTOKENLEN 64

typedef void (*state_func)(void);


enum type_tag { IDENTIFIER, QUALIFIER, TYPE };
typedef struct token {
    char type;
    char string[MAXTOKENLEN];
} token;
class CdeclParser {
    char result[MAXCDECLLEN];
    state_func* nextstate;
    FILE* stream;
    int top;  /* holds all the tokens before first identifier */
    token stack[MAXTOKENS];  /* holds the token just read */
    token this_token;

    void init(void) {
        top = -1;
        result[0] = '\0';
        nextstate = NULL;
        stream = NULL;
    }
    token& pop() {
        return stack[top--];
    }
    void push(const struct token& this_token) {
        stack[++top]=this_token;
    }
    void parse() {
        stream = stdin;
        process_decl();
    }
    void parse(const char* input) {
        stream = fopen("tmp", "w");
        fputs(input, stream);
        parse();
        fclose(stream);
    }
private:
    enum type_tag  classify_string()
    /* figure out the identifier type */
    /*look at the current token and
            return a value of "type" "qualifier" or "identifier" in this_token.type*/
    {
        char *s = this_token.string;
        if (!strcmp(s, "const"))
        {
            strcpy(s, "read-only");
            return QUALIFIER;
        }
        if (!strcmp(s, "volatile")) return QUALIFIER;
        if (!strcmp(s, "void")) return TYPE;
        if (!strcmp(s, "char")) return TYPE;
        if (!strcmp(s, "signed")) return TYPE;
        if (!strcmp(s, "unsigned")) return TYPE;
        if (!strcmp(s, "short")) return TYPE;
        if (!strcmp(s, "int")) return TYPE;
        if (!strcmp(s, "long")) return TYPE;
        if (!strcmp(s, "float")) return TYPE;
        if (!strcmp(s, "double")) return TYPE;
        if (!strcmp(s, "struct")) return TYPE;
        if (!strcmp(s, "union")) return TYPE;
        if (!strcmp(s, "enum")) return TYPE;
        return IDENTIFIER;
    }

    void gettoken(void)
    /*read the next token into this_token.string
    if it is alphanumeric, classify_string
    else it must be a single character token
    this_token.type = the token itself; terminate this_token.string with a nul.*/
    {
        /* read next token into "this_token" */
        char *p = this_token.string;
        /* read past any spaces */
        while ((*p = getc(stream)) == ' ');
        if (isalnum(*p)) {         /* it starts with A-Z,1-9 read in identifier */
            while (isalnum(*++p = getc(stream)));
            ungetc(*p, stream); // restore last char that's not alnum to stream
            *p = '\0';
            this_token.type = classify_string();
            return;
        }
        this_token.string[1] = '\0';
        this_token.type = *p;
        return;
    }


    void process_decl() {
        nextstate = std::bind(initialize, this);
        /* transition through the states, until the pointer is null */
        while (nextstate != NULL)
            (*nextstate)();
    }

    void record_result(const char* ss) {
        strcat(result, ss);
        printf("%s", ss);
    }

    void initialize()
    {
        gettoken();
        while (this_token.type != IDENTIFIER)
        {
            push(this_token);
            gettoken();
        }
        record_result(this_token.string);
        record_result(" is ");
        gettoken();
        nextstate = get_array;
    }
    void get_array()  {
        nextstate = get_params;
        while (this_token.type == '[') {
            record_result("array ");
            gettoken();/* a number or ']' */
            if (isdigit(this_token.string[0])) {
                int max_idx = atoi(this_token.string) - 1;
                record_result("0..");
                record_result(itoa(max_idx));
                gettoken();/* read the ']' */
            }
            gettoken();/* read next past the ']' */
            record_result("of ");
            nextstate = get_lparen;
        }
    }


    void get_params()  {
        nextstate = get_lparen;
        if (this_token.type == '(') {
            record_result("function(");
            char argument[MAXTOKENLEN] = {'\0'};
            int arg_idx = 1;
            while (this_token.type != ')') {
                gettoken();
                if (this_token.type == ',') {
                    record_result("argument");
                    record_result(itoa(arg_idx));
                    struct CdeclParser aparser;
                    aparser.init();
                    aparser.parse(argument);
                    record_result(aparser.result);
                    record_result(", ");
                    argument[0] = '\0';
                }
                strcat(argument, this_token.type);
            }
            gettoken();
            record_result(") returning ");
        }
    }

    void get_lparen()  {
        nextstate = get_ptr_part;
        if (top >= 0) {
            if (stack[top].type == '(') {
                (void)pop();
                gettoken(); /* read past ')' */
                nextstate = get_array;
            }
        }
    }

    void get_ptr_part()  {
        nextstate = get_type;
        if (stack[top].type == '*') {
            record_result("pointer to ");
            (void)pop();
            nextstate = get_lparen;
        } else if (stack[top].type == QUALIFIER) {
            record_result(pop().string);
            record_result(" ");
            nextstate = get_lparen;
        }
    }

    void get_type()  {
        nextstate = NULL;
        /* process tokens that we
        stacked while reading to identifier */
        while (top >= 0) {
            record_result(pop().string);
            record_result(" ");
        }
        record_result("\n");
    }
};

int main()  /* Cdecl written as a finite state machine */
{
    CdeclParser parser;
    parser.init();
    parser.parse();
    return 0;
}
