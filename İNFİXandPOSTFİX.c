#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Infix ifadeyi giriniz: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        ch = infix[i];

        /* Operand */
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        /* Sol parantez */
        else if (ch == '(') {
            push(ch);
        }
        /* Sag parantez */
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); /* '(' at */
        }
        /* Operator */
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }

    /* Stack'te kalanlari ekle */
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix ifade: %s\n", postfix);

    return 0;
}

