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
        exit(1); // �쳣�˳�����
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

// �ж��ַ��Ƿ�Ϊ���������Ӽ��˳���
int isOperator(char c) { 
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// ���ݲ�ͬ�Ĳ����������ز�ͬ�����ȼ�
int precedence(char c) { 
    switch (c) { 
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1; // �Ƿ�����������-1
    }
}

// ���ݲ���������������������ֵ
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
            printf("Invalid operator\n"); //�Ƿ������� 
            exit(1); 
    }
}

// ��׺���ʽ��ֵ����
double evaluate(char expression[]) { 
    Stack Data; 
    initStack(&Data);
    Stack Operator; 
    initStack(&Operator);
    
    int i = 0; 
    while (expression[i] != '\0') { // ����ַ���δ����
       if (isdigit(expression[i])) {// �����ǰ�ַ�������
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&Data, operand);
        } else if (isOperator(expression[i])) { // ����ǲ�����
        	// ֻҪ������ջ�ǿգ�����ջ�������������ȼ������ڵ�ǰ������
            while (!isEmpty(&Operator) && precedence(getTop(&Operator)) >= precedence(expression[i])) { 
                char op = pop(&Operator); 
                double operand_2 = pop(&Data); 
                double operand_1 = pop(&Data); 
                double result = calculate(operand_1, operand_2, op); 
                push(&Data, result); 
            }
            push(&Operator, expression[i]); 
            i++; 
        } else if (expression[i] == '(') { // �����������
            push(&Operator, expression[i]); 
            i++; 
        } else if (expression[i] == ')') { // �����������
            while (getTop(&Operator) != '(') { // ѭ����������ջ��Ϊ������
                char op = pop(&Operator); 
                double operand_2 = pop(&Data); 
                double operand_1 = pop(&Data); 
                double result = calculate(operand_1, operand_2, op);
                push(&Data, result); 
            }
            pop(&Operator); // �������ų�ջ
            i++; 
        } else {
            i++; 
        }
    }
    while (!isEmpty(&Operator)) { // ���������ջ�ǿ�
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
