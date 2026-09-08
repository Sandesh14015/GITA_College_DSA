// write a function that converts a postfix expression to an infix expression
#include <stdio.h>
#include <stdlib.h>
#define max 20

int stack[max];
int top = -1;

// function to push an element onto the stack
void push(int item) {
    if (top == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

// function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// function to evaluate teh postfix expression
int post_eval(char *postfix) {
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            // push operand to stack
            stack[++top] = ch - '0';
        } else {
            // pop two operands from stack
            int op2 = stack[top--];
            int op1 = stack[top--];
            // perform operation and push result back to stack
            switch (ch) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    stack[++top] = op1 / op2;
                    break;
            }
        }
    }
    return stack[top];
}
int main() {
    char postfix[max];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = post_eval(postfix);
    printf("Result of postfix evaluation: %d\n", result);
    return 0;
}