#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 

typedef struct { 
    int top; 
    double elem[MAX_SIZE]; 
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, double value) { 
    if (s->top < MAX_SIZE - 1) { 
        s->top++; 
        s->elem[s->top] = value; 
    } else { 
        printf("Stack Overflow\n"); 
        exit(1); // 异常退出程序
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

// 判断字符是否为操作符（加减乘除）
int isOperator(char c) { 
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// 根据不同的操作符，返回不同的优先级
int precedence(char c) { 
    switch (c) { 
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1; // 非法操作符返回-1
    }
}

// 根据操作符计算两个操作数的值
double calculate(double operand_1, double operand_2, char op) { 
    switch (op) { 
        case '+':
            return operand_1 + operand_2;
        case '-':
            return operand_1 - operand_2;
        case '*':
            return operand_1 * operand_2;
        case '/':
            return operand_1 / operand_2;
        default:
            printf("Invalid operator\n"); //非法操作符 
            exit(1); 
    }
}

// 中缀表达式求值函数
double evaluate(char expression[]) { 
    Stack Data; 
    initStack(&Data);
    Stack Operator; 
    initStack(&Operator);
    
    int i = 0; 
    while (expression[i] != '\0') { // 如果字符串未结束
       if (isdigit(expression[i])) {// 如果当前字符是数字
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&Data, operand);
        } else if (isOperator(expression[i])) { // 如果是操作符
        	// 只要操作符栈非空，并且栈顶操作符的优先级不低于当前操作符
            while (!isEmpty(&Operator) && precedence(getTop(&Operator)) >= precedence(expression[i])) { 
                char op = pop(&Operator); 
                double operand_2 = pop(&Data); 
                double operand_1 = pop(&Data); 
                double result = calculate(operand_1, operand_2, op); 
                push(&Data, result); 
            }
            push(&Operator, expression[i]); 
            i++; 
        } else if (expression[i] == '(') { // 如果是左括号
            push(&Operator, expression[i]); 
            i++; 
        } else if (expression[i] == ')') { // 如果是右括号
            while (getTop(&Operator) != '(') { // 循环至操作符栈顶为左括号
                char op = pop(&Operator); 
                double operand_2 = pop(&Data); 
                double operand_1 = pop(&Data); 
                double result = calculate(operand_1, operand_2, op);
                push(&Data, result); 
            }
            pop(&Operator); // 将左括号出栈
            i++; 
        } else {
            i++; 
        }
    }
    while (!isEmpty(&Operator)) { // 如果操作符栈非空
        char op = pop(&Operator); 
        double operand_2 = pop(&Data); 
        double operand_1 = pop(&Data); 
        double result = calculate(operand_1, operand_2, op); 
        push(&Data, result); 
    }
    return pop(&Data); 
}

int main() { 
    char infix[MAX_SIZE]; 
    printf("Please input an infix expression:\n"); 
    gets(infix); 
    double result = evaluate(infix); 
    printf("The result is:\n %.2lf", result); 
    return 0; 
}
