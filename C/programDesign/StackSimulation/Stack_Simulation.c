#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    double elem[MAX_SIZE];
} Stack;

void push(Stack *s, double value) {
    if (s->top < MAX_SIZE - 1) {
        s->top++;
        s->elem[s->top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

double pop(Stack *s) {
    if (s->top > -1) {
        double value = s->elem[s->top];
        s->top--;
        return value;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

double getTop(Stack *s) {
    if (s->top > -1) {
        return s->elem[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

double calculate(char expression[]) {
    Stack Data;
    Data.top = -1;
    Stack Operator;
    Operator.top = -1;
    int i = 0;
    
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&Data, operand);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(&Operator) && precedence(getTop(&Operator)) >= precedence(expression[i])) {
                char op = pop(&Operator);
                double operand_2 = pop(&Data);
                double operand_1 = pop(&Data);
                switch (op) {
                    case '+':
                        push(&Data, operand_1 + operand_2);
                        break;
                    case '-':
                        push(&Data, operand_1 - operand_2);
                        break;
                    case '*':
                        push(&Data, operand_1 * operand_2);
                        break;
                    case '/':
                        push(&Data, operand_1 / operand_2);
                        break;
                    case '^': {
                        double result = 1;
                        for (int j = 0; j < operand_2; j++) {
                            result *= operand_1;
                        }
                        push(&Data, result);
                        break;
                    }
                    default:
                        printf("Invalid operator\n");
                        exit(1);
                }
            }
            push(&Operator, expression[i]);
            i++;
        } else {
            i++;
        }
    }
    while (!isEmpty(&Operator)) {
        char op = pop(&Operator);
        double operand_2 = pop(&Data);
        double operand_1 = pop(&Data);
        switch (op) {
            case '+':
                push(&Data, operand_1 + operand_2);
                break;
            case '-':
                push(&Data, operand_1 - operand_2);
                break;
            case '*':
                push(&Data, operand_1 * operand_2);
                break;
            case '/':
                push(&Data, operand_1 / operand_2);
                break;
            case '^': {
                double result = 1;
                for (int j = 0; j < operand_2; j++) {
                    result *= operand_1;
                }
                push(&Data, result);
                break;
            }
            default:
                printf("Invalid operator\n");
                exit(1);
        }
    }
    return pop(&Data);
}

int main() {
    char infix[MAX_SIZE];
    printf("Please input an infix expression:\n");
    gets(infix);
    double result = calculate(infix);
    printf("The result is: \n%.3lf", result);
    return 0;
}

