#include <stdio.h>
#include <stdlib.h>

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

char isEmpty(struct Stack *s){
    return (s -> top == - 1);
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

char isBalanced(struct Stack *s, char *expr){
    for(int i = 0; expr[i] != '\0'; i++){
        
        char ch = expr[i];
        
        if(ch == '(' || ch == '{' || ch == '['){
            Push(s, ch);
        }

        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty(s)){
                return 0;   // unmatched closing bracket as the stack is empty
            }

            char top = Pop(s);

            if(ch == ')' && top != '(' || ch == '}' && top != '{' || ch == ']' && top != '['){
                return 0;   // mismatched opening and closing brackets
            }
        }
    }

    return isEmpty(s);  // if the stack is empty, expression is balanced
}

int main(){
    struct Stack *p = createStack();
    
    char *expr = "[][][](((({[]}))))";
    
    if(isBalanced(p, expr)){
        printf("Balanced %s", expr);
    }

    else{
        printf("Not Balanced %s", expr);
    }

    free(p);

    return 0;
}
