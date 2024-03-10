#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTORENLEN 64
enum type_tag {IDENTIFIER, QUALIFIER, TYPE};
struct token {
    char type;
    char string [MAXTOKENS];
};
int top = -1;
struct token stack[MAXTOKENS];
struct token this;
#define pop stack[top--]
#define push(s) stack[++top] = s
enum type_tag classily_string(void)
/* 推断标识符的类型 */
/*/*look at the current token and
        return a value of "type" "qualifier" or "identifier" in this.type*/
{
    char *s = this.string;
    if(!strcmp(s, "const")) {
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

void gettoken(void) /*读取下一个标记到"this"*/
/*read the next token into this.string
        if it is alphanumeric, classify_string
        else it must be a single character token
        this.type = the token itself; terminate this.string with a nul.*/
{
    char* p = this.string;
    while((*p = getchar()) == ' ');
    if (isalnum(*p)) {
        //alpha or number, identifier
        while(isalnum(*++p = getchar()));
        ungetc(*p, stdin);
        *p = '\0';
        this.type = classily_string();
        return;
    }
    if (*p == '*') {
        strcpy(this.string, "pointer to");
        this.type = '*';
        return;
    }
    this.string[1] = '\0';
    this.type = *p;
    return;
}

void read_to_first_identifier() {
    /*gettoken and push it onto the stack until the first identifier is read.
        Print "identifier is", this.string
        gettoken*/
    gettoken();
    while(this.type!=IDENTIFIER) {
        push(this);
        gettoken();
    }
    printf("%s is ", this.string);
    gettoken();
}

void deal_with_arrays() {
/*while you've got "[size]" print it out and read past it*/
    while(this.type == '[') {
        printf("array ");
        gettoken();
        if(isdigit(this.string[0])) {
            printf("0..%d ", atoi(this.string)-1);
            gettoken();
        }
        gettoken(); //读取']'之后的下一个标记
        printf("of ");
    }
}

void deal_with_function_args() {
/*read past closing ')' print out "function returning"*/
    while(this.type != ')') {
        gettoken();
    }
    gettoken();
    printf("function returning ");
}

void deal_with_pointers() {
/*while you've got "*" on the stack print "pointer to" and pop it*/
    while(stack[top].type == '*') {
        printf("%s ", pop.string);
    }
}

void deal_with_declarator() {
/*if this.type is '['
    deal_with_arrays
if this.type is '('
    deal_with_function_args
deal_with_any_pointers
while there's stuff on the stack
    if it's a '('      pop it and gettoken; it should be the closing ')'
deal_with_declarator
    else pop it and print it*/
    switch(this.type) {/*处理标识 之后可能存在的数组/函数 */
        case '[': deal_with_arrays(); break;
        case '(': deal_with_function_args();
    }

    deal_with_pointers();

    /* 处理在读入到标识符之前压入到堆栈中的符号 */
    while (top>=0) {
        if(stack[top].type == '(') {
            pop;
            gettoken();
            /* 读 取 ')' 之 后 的 符 号 */
            deal_with_declarator();
        } else {
            printf("%s ", pop.string);
        }
    }
}

int main(int argc, char** argv) {
    read_to_first_identifier();
    deal_with_declarator();
    printf("\n");
    return 0;
}