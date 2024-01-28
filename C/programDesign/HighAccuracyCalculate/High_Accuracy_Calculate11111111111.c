//������ƻ���_1 �߾��ȼ���
//22009201256 ͯ����

#include <stdio.h>
#include <string.h>

char num_1[101], num_2[101], op;
int first[101] = {0}, second[101] = {0}, result[101] = {0};
int sym[2] = {0}, len[2] = {0}, lenMax = 0;

//���ַ�����ת������������ 
void translate(char input[], int result[]) {	
	for (int i = 0; i < strlen(input); i++) {
		result[i] = input[i] - '0';
	}
}

// �ж�����������Դ�С 
int isBigger(int first[], int second[]) {
	if(len[0] > len[1]) {
		return 1;
	} else if ( len[0] < len[1]) {
		return 0;
	}
	for (int i = lenMax - 1; i >= 0; i--) {
		if (first[i] < second[i]) {
			return 0;
		} else if (first[i] > second[i]) {
			return 1;
		}
	}
	return 1;
}

// ����ֵ���������ڼ�����������ֵ�Ĳ�
void absoluteMinus(int first[], int second[]) {
	int i, res;
	for( i = 0; i < lenMax; i++) {
		if(first[i] < second[i]) {
			first[i + 1] -= 1;
			res = first[i] - second[i] + 10;
		} else {
			res = first[i] - second[i];
		}	
		result[i] = res;
	}
} 

// �����ļ��������������з���
void minus(int first[], int second[]) {
	if(isBigger(first,second)) {
		absoluteMinus(first, second);
	} else {
		absoluteMinus(second, first);
		printf("-");
	}
}

// ��ͨ�ļӷ� 
void add(int first[], int second[]) {
	int i, res, step;
	for( i = 0; i <= lenMax; i++) {
		res = first[i] + second[i] + step;
		if(res > 9) {
			res %= 10;
			step = 1;
		} 
		result[i] += res;
	}
}

// ��ʼ������ ��������ţ����ַ���ת�����������飬�������ִ������Ը�ʮ��ǧ���˳���ŷ�
void initNum(char num[], int order) {
	if(num[0] == '-') {
			sym[order] = -1;
			len[order] = strlen(num);
			num = strrev(num);
			len[order] -=1;
			num[len[order]] = '\0';
			translate(num, first);
	} else {
			sym[order] = 1;
			num = strrev(num);
			len[order] = strlen(num);
			translate(num, second);
	}
}

// �жϼ������� 
void judge() {
	int type = 0;
	if (op == '+' && sym[0] == 1 && sym[1] == 1) 		type = 1;
	if (op == '-' && sym[0] == 1 && sym[1] == -1)		type = 1;

	if (op == '-' && sym[0] == -1 && sym[1] == 1)		type = 2;
	if (op == '+' && sym[0] == -1 && sym[1] == -1)	type = 2;

	if (op == '-' && sym[0] == 1 && sym[1] == 1)		type = 3;
	if (op == '+' && sym[0] == 1 && sym[1] == -1)		type = 3;

	if (op == '+' && sym[0] == -1 && sym[1] == +1)	type = 4;
	if (op == '-' && sym[0] == -1 && sym[1] == -1)	type = 4;

	switch (type) {
	case 1:	add(first, second);
		break;
	case 2:	printf("-");
			add(first, second);
		break;
	case 3:	minus(first, second);
		break;
	case 4:	minus(second, first);
		break;
	}
}

// ���������ʾ 
void start() {
	printf("����������������\n");
	gets(num_1);
	gets(num_2);
	printf("��ѡ���������+/-����\n");
	scanf("%c",&op);
}

// ����������ŵ������� 
void output() {
	int i = 0;
	int isZero = 1;
	for (i = lenMax; i >= 0; i--) {
		if (result[i] != 0) {
			isZero = 0;
			for( ; i >= 0; i--) {
				printf("%d",result[i]);
			}
			break;
		}	
	}
	if(isZero) {
		printf("0");
	}
}

int main() {
	start();
	initNum(num_1, 0);
	initNum(num_2, 1);
	lenMax = len[0] > len[1] ? len[0]:len[1];
	judge();
	output();

	printf("\n");
	for (int i = 0; i < 101; i++) {
		printf("%d",first[i]);
	}
	printf("\n");
	for (int i = 0; i < 101; i++) {
		printf("%d",second[i]);
	}
	printf("\n");
	for (int i = 0; i < 101; i++) {
		printf("%d",result[i]);
	}	
	
	return 0;
}
