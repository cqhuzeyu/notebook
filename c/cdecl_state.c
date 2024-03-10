#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64
enum type_tag { IDENTIFIER, QUALIFIER, TYPE };
struct token {
    char type;
    char string[MAXTOKENLEN];
};

typedef struct token_stack {
    int top;
/* holds all the tokens before first identifier */
    struct token stack[MAXTOKENS];
    /* holds the token just read */
    struct token this;
    char result[4096];
    FILE* stream;

} token_stack;

#define init(stack) {stack.top=-1; strcpy(stack.result, ""); stack.stream=stdin;}
#define init_with_string(stack, ss) {init(stack) stack.stream = fopen("tmp", "w"); fputs(ss, stack.stream); fclose(stack.stream); stack.stream = fopen("tmp", "r");}
#define close(stack) {if (stack.stream != stdin) fclose(stack.stream);}
#define pop(stack) stack->stack[stack->top--]
#define push(stack, s) stack->stack[++(stack->top)]=s
#define record(stack, s) {if (stack->stream == stdin) printf("%s", s); strcat(stack->result, s); if (0) printf("record %s--%s\n", stack->result, s);}

enum type_tag
classify_string(token_stack* stack)
/* figure out the identifier type */
{
    char *s = stack->this.string;
    if (!strcmp(s, "const")) {
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
void gettoken(token_stack* stack)
{             /* read next token into "this" */
    char *p = stack->this.string;
    /* read past any spaces */
    while ((*p = fgetc(stack->stream)) == ' ');
    if (isalnum(*p)) {
        /* it starts with A-Z,1-9 read in identifier */
        while (isalnum(*++p = fgetc(stack->stream)));
        ungetc(*p, stdin);
        *p = '\0';
        stack->this.type = classify_string(stack);
        return;
    }
    stack->this.string[1] = '\0';
    stack->this.type = *p;
    return;
}
void initialize(token_stack*),
 get_array(token_stack*), get_params(token_stack*), get_lparen(token_stack*),
get_ptr_part(token_stack*), get_type(token_stack*);
void (*nextstate)(token_stack*) = initialize;
void (*prev_nextstate)(token_stack*) = initialize;
void process_cdecl(token_stack* stack) {
    while (nextstate != NULL)
        (*nextstate)(stack);
}
int main()
/* Cdecl written as a finite state machine */
{
    /* transition through the states, until the pointer
is null */
    token_stack stack;
    init(stack)
    process_cdecl(&stack);
    return 0;
}


void initialize(token_stack* stack)
{
    gettoken(stack);
    while (stack->this.type != IDENTIFIER) {
        push(stack, stack->this);
        gettoken(stack);
    }
    record(stack, stack->this.string)
    record(stack, " is ")
    gettoken(stack);
    nextstate = get_array;
}
void get_array(token_stack* stack)
{
    nextstate = get_params;
    while (stack->this.type == '[') {
        record(stack, "array ")
        gettoken(stack);/* a number or ']' */
        if (isdigit(stack->this.string[0])) {
            int max_index = atoi(stack->this.string) - 1;
            char mindex[32];
            sprintf(mindex, "%d", max_index);
            record(stack, "0..")
            record(stack, mindex)
            gettoken(stack);/* read the ']' */
        }
        gettoken(stack);/* read next past the ']' */
        record(stack, "of ")
        nextstate = get_lparen;
    }
}
void get_params(token_stack* stack)
{
    nextstate = get_lparen;
    prev_nextstate = nextstate;
    if (stack->this.type == '(') {
        record(stack, "function (")
        char argument[4096] = "";
        char c;
        int i = 0;
        int paren_count = 1;
        while (paren_count && !feof(stack->stream)) {
            c = fgetc(stack->stream);
            // printf("xxx %c\n", c);
            if (c != ',') {
                argument[i++] = c;
            }
            else {
                token_stack astack;
                argument[i] = '\0';
                // printf("xxx argument=%s\n", argument);
                i = 0;
                init_with_string(astack, argument);
                nextstate = initialize;
                process_cdecl(&astack);
                close(astack)
                record(stack, "arg <")
                record(stack, astack.result)
                record(stack, ">, ")
            }
            if (c == '(')
                paren_count += 1;
            else if (c == ')')
                paren_count -= 1;
            // printf("xxx c=%c, paren_count=%d\n", c, paren_count);
        }
        if (c == ')') {
            argument[i] = '\0';
            // printf("xxx argument=%s\n", argument);
            token_stack astack;
            init_with_string(astack, argument);
            nextstate = initialize;
            process_cdecl(&astack);
            close(astack)
            record(stack, "arg <")
            record(stack, astack.result)
            record(stack, ">, ")
        }
        nextstate = prev_nextstate;
        record(stack, ") returning ")
    }
}
void get_lparen(token_stack* stack)
{
    nextstate = get_ptr_part;
    if (stack->top >= 0) {
        if (stack->stack[stack->top].type == '(') {
            pop(stack);
            gettoken(stack);/* read past ')' */
            nextstate = get_array;
        }
    }
}
void get_ptr_part(token_stack* stack)
{
    nextstate = get_type;
    if (stack->stack[stack->top].type == '*') {
        record(stack, "pointer to ")
        pop(stack);
        nextstate = get_lparen;
    } else if (stack->stack[stack->top].type == QUALIFIER) {
        record(stack, pop(stack).string)
        record(stack, " ")
        nextstate = get_lparen;
    }
}
void get_type(token_stack* stack)
{
    nextstate = NULL;
    /* process tokens that we stacked while reading to
identifier */
    while (stack->top >= 0) {
        // const char* type = pop(stack).string;
        // printf("type: %s\n", type);
        // printf("type1: %s", )
        record(stack, pop(stack).string)
        record(stack, " ")
    }
    if (stack->stream == stdin)
        printf("\n");
}





