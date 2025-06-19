#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack{
    int top;
    char items[MAX];
};

struct Stack * createStack(){
    struct Stack *s = (struct Stack *)(malloc(sizeof(struct Stack)));
    s -> top = -1;
    return s;
}

int isFull(struct Stack *s){
    return (s -> top == MAX - 1);
}

int isEmpty(struct Stack *s){
    return (s -> top == -1);
}

int isNotEmpty(struct Stack *s){
    return (s -> top != -1);
}

void Push(struct Stack *s, char items){
    if(isFull(s)){
        printf("Stack Overflow");
        return;
    }

    s -> items[++s -> top] = items;
}

char Pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow");
        return -1;
    }

    return (s -> items[s -> top--]);
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int Precedence(char op){
    switch(op){
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
        case '^' : return 3;
        default : return 0;
    }
}

void InfixToPostfix(char *infix, char *postfix) {
    struct Stack *s = createStack();    // Create a stack to store operators during conversion
    int i = 0, j = 0;                   // i -> infix index, j -> postfix index

    while (infix[i] != '\0') {
        char ch = infix[i];
        
        if (isalnum(ch)) {               // Check if ch is an operand; if true, it goes into postfix
            postfix[j++] = ch;           // Assign operand to postfix and increment postfix index
        }
        
        else if (ch == '(') {
            Push(s, ch);                  // Push '(' onto the stack
        }
        
        else if (ch == ')') {
            // While the stack is not empty and the top of the stack is not '('
            while (isNotEmpty(s) && s->items[s->top] != '(') {
                postfix[j++] = Pop(s);    // Pop operators from the stack until '(' is encountered
            }
            Pop(s);                         // Pop and discard '('
        } 
        
        else if (isOperator(ch)) {
            // While the stack is not empty and precedence of the top of the stack >= precedence of current operator
            while (isNotEmpty(s) && Precedence(s->items[s->top]) >= Precedence(ch)) {
                postfix[j++] = Pop(s);    // Pop higher or equal precedence operators from the stack
            }
            Push(s, ch);                    // Push the current operator onto the stack
        }

        i++;
    }

    // Pop any remaining operators from the stack
    while (s->top != -1) {
        postfix[j++] = Pop(s);
    }

    postfix[j++] = '\0';                // Convert the postfix array to a string

    free(s);                            // Free the memory allocated for the stack
}

int main(){
    char infix[MAX], postfix[MAX];

    printf("Enter an Infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    InfixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}