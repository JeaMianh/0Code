#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book {
    char name[20];
    int number;
    int amount;
} Book;
typedef struct Reader {
    char name[20];
    int number;
} Reader;
typedef struct Administrator {
    char name[20];
    int number;
} Admin;

Book books[100];
Reader readers[50];
Admin admins[10];
char borrowerList[110][100];      //�ڽ����
char borrowedBookList[110][100];  //�ڽ�ͼ��

void ShowBook(char* bookName);
void ShowReader(char* readerName);
void BookLend(char *readerName, char *bookName);
void BookReturn(char *readerName, char* bookName);
void ReadBooksInfo();
void ReadReadersInfo();
void ReadAdministratorsInfo();
void UpdateBorrowerList();
void UpdateBorrowedBookList();
void UpdateBookleft();
void UpdateBooks();
void UpdateReaders();
void UpdateAdministrators();
void AddBook(char* bookName);
void DelBook(char* bookName);
void AddReader(char* readerName);							
void DelReader(char* readerName);

int main(int argc, char *argv[3]) {
	ReadBooksInfo();
	ReadReadersInfo();
	ReadAdministratorsInfo();
    int choose;
    printf("��½�ɹ�\n");
    if (!strcmp(argv[1],"-a")){
		while(1) {
			printf("1.�鿴ͼ����Ϣ \n2.ɾ��ͼ����Ϣ \n3.���ͼ����Ϣ\n");
        	printf("4.�鿴������Ϣ \n5.ɾ��������Ϣ \n6.��Ӷ�����Ϣ\n");
        	printf("0.�˳�����\n");
        	printf("������Ž���ѡ��");
        	scanf("%d", &choose);
        	if (choose == 0){
				printf("�˳��ɹ�");
				return 0;
			}
        	switch(choose){
				case 1:{ // �鿴ͼ����Ϣ
					char bookName[20];
					printf("����������\n");
					scanf("%s", bookName);
					ShowBook(bookName);
					break;
				}
				case 2:{ // ɾ��ͼ����Ϣ
					char bookName[20];
					printf("������������\n");
					scanf("%s", bookName);
					DelBook(bookName);
					break;
				}
				case 3:{ // ���ͼ����Ϣ
                    char bookName[20];
					printf("������������\n");
					scanf("%s", bookName);
					AddBook(bookName);
					break;
				}
				case 4:{ // �鿴������Ϣ
					char readerName[20];
					printf("���������������\n");
					scanf("%s", readerName);																	
					ShowReader(readerName);			
					break;
				}
				case 5:{ // ɾ��������Ϣ
					char readerName[20];
					printf("���������������\n");
					scanf("%s", readerName);																	
					DelReader(readerName);			
					break;
				}
				case 6:{ // ��Ӷ�����Ϣ
					char readerName[20];
					printf("���������������\n");
					scanf("%s", readerName);																	
					AddReader(readerName);			
					break;
				}
				default:{
					printf("�������");
					break;
				}
			}
		}
    } else if (!strcmp(argv[1],"-u")) {
		while(1) {
			printf("1.��ѯͼ�� \n2.����ͼ�� \n3.�黹ͼ�� \n0.�˳�����");
       		printf("�������ѡ��");
        	scanf("%d",&choose);
        	if (choose == 0){
				printf("�˳��ɹ�");
				return 0;
			}
			switch(choose){
				case 1:{
					char bookName[20];
					printf("������������\n");
					scanf("%s", bookName);
					ShowBook(bookName);
					break;
				}
				case 2:{
					char bookName[20];
					printf("������������\n");
					scanf("%s", bookName);
					BookLend(argv[2], bookName);
					break;
				}
				case 3:{
					char bookName[20];
					printf("������������\n");
					scanf("%s", bookName);
					BookLend(argv[2], bookName);
					break;
				}
				default:{
					printf("�������");
					break;
				}
			}
		}
    } else {
		printf("��֪��������ʲô");
	}
    
    return 0;
}

void ReadBooksInfo(){
	FILE *fp1 = fopen("books.txt", "r");
	FILE *fp2 = fopen("booksleft.txt", "r");
	FILE *fp3 = fopen("borrowerList.txt", "r");
	if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
		printf("system error\n");
		return;
	}
	char t[100];
	int i = 0;
	while(fgets(t, 100, fp1) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		strcpy(books[i].name, t);
		books[i].number = i;
		i++;
		if(!strcmp(t, "end"))	break;
	}
	i = 0;
	while(fgets(t, 100, fp2) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		if(!strcmp(t, "end")){
			books[i].amount = -1;
			break;
		}
		int n = atoi(t);
		books[i].amount = n; 
		i++;
	}
	i = 0;		
	while(fgets(t, 100, fp3) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		strcpy(borrowerList[i], t);
		i++;
		if(!strcmp(t, "end"))	break;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void ReadReadersInfo(){
	FILE *fp1 = fopen("readers.txt", "r");
	FILE *fp2 = fopen("borrowedBookList.txt", "r");

	if(fp1 == NULL || fp2 == NULL){
		printf("system error\n");
		return;
	}
	char t[100];
	int i = 0;
	while(fgets(t, 100, fp1) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		strcpy(readers[i].name, t);
		readers[i].number = i;
		i++;
		if(!strcmp(t, "end"))	break;
	}
	i = 0;
	while(fgets(t, 100, fp2) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		strcpy(borrowedBookList[i], t);
		i++;
		if(!strcmp(t, "end"))	break;
	}
	i = 0;

	fclose(fp1);
	fclose(fp2);
}
void ReadAdministratorsInfo(){
	FILE *fp1 = fopen("administrators.txt", "r");

	if(fp1 == NULL){
		printf("system error\n");
		return;
	}
	char t[100];
	int i = 0;
	while(fgets(t, 100, fp1) != NULL){
		if(t[strlen(t)-1] == '\n')	t[strlen(t)-1] = '\0';
		strcpy(admins[i].name, t);
		admins[i].number = i;
		i++;
		if(!strcmp(t, "end"))	break;
	}
	i = 0;
	
	fclose(fp1);
}
void UpdateBorrowerList(){
	FILE *fw = fopen("borrowerList.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int k;
	for(k = 0; k < 100; k++){
		if(!strcmp(borrowerList[k], "no"))	fputc('\n', fw);
		else {
			fputs(borrowerList[k], fw);
			fputc('\n', fw);
		}
		if(!strcmp(borrowerList[k], "end"))	break;
	}
	fclose(fw);
}
void UpdateBorrowedBookList(){
	FILE *fw = fopen("borrowedBookList.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int k;
	for(k = 0; k < 100; k++){
		fputs(borrowedBookList[k], fw);
		fputc('\n', fw);
		if(!strcmp(borrowedBookList[k], "end"))	break;
	}
	fclose(fw);
}
void UpdateBookleft(){
	FILE *fw = fopen("booksleft.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int k;
	for(k = 0; k < 100; k++){
		char x[10];
		if(books[k].amount == -1){
			fputs("end", fw);
			break;
		}
		itoa(books[k].amount, x, 10);
		fputs(x, fw);
		fputc('\n', fw);
		
	}
	fclose(fw);
}
void UpdateBooks(){
	FILE *fw = fopen("books.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int i;
	for(i = 0; i < 100; i++){
		if(!strcmp(books[i].name, "end")){
			fputs("end", fw);
			fclose(fw);
			return;
		}
		fputs(books[i].name, fw);
		fputc('\n', fw);
	}
}
void UpdateReaders(){
	FILE *fw = fopen("readers.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int i;
	for(i = 0; i < 100; i++){
		if(!strcmp(readers[i].name, "end")){
			fputs("end", fw);
			fclose(fw);
			return;
		}
		fputs(readers[i].name, fw);
		fputc('\n', fw);
	}	
}
void UpdateAdministrators(){
	FILE *fw = fopen("administrators.txt", "w");
	if(fw == NULL){
		printf("system error\n");
		return;
	}
	int i;
	for(i = 0; i < 100; i++){
		if(!strcmp(admins[i].name, "end")){
			fputs("end", fw);
			fclose(fw);
			return;
		}
		fputs(admins[i].name, fw);
		fputc('\n', fw);
	}
}


void ShowBook(char* bookName){
	int i;
	for(i = 0; i < 100; i++){
		if(!strcmp(bookName, books[i].name)){
			printf("������ %s\n", books[i].name);
			printf("��ţ� %d\n", books[i].number);
			printf("������ %d\n", books[i].amount);
			printf("�ڽ���� %s\n", borrowerList[i]);
		}
		if(!strcmp(books[i].name, "end"))	break;
	}
}
void ShowReader(char* readerName){
	int i;
	for(i = 0; i < 100; i++){		
		if(!strcmp(readerName, readers[i].name)){
			printf("������%s\n", readers[i].name);
			printf("��ţ�%d\n", readers[i].number);
			printf("�ڽ�ͼ�飺 %s\n", borrowedBookList[i]);
		}
		if(!strcmp(books[i].name, "end"))	break;
	}
}
void BookLend(char *readerName, char *bookName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(books[i].name, bookName)){
			if(books[i].amount == 0){
				printf("��Ǹ���Ȿ���Ѿ����ȥ�ˡ�");
				return;
			}else{
				books[i].amount--;
				if(!strcmp(borrowerList[i], "end")){
					strcpy(borrowerList[i], readerName);
					strcpy(borrowerList[i+1], "end");
				}else{
					strcat(borrowerList[i], " ");
					strcat(borrowerList[i], readerName);
				}
				int j;
				for(j = 0; j < 100; j++){
					if(!strcmp(readers[j].name, readerName)){
						if(!strcmp(borrowedBookList[j], "end")){
							strcpy(borrowedBookList[j], bookName);
							strcpy(borrowedBookList[j+1], "end");
						}else{
							strcat(borrowedBookList[j], " ");
							strcat(borrowedBookList[j], bookName);
						}
					}
				}
				flag = 1;
				break;
			}
		}
	}
	UpdateBorrowerList();
	UpdateBorrowedBookList();
	UpdateBookleft();
	if(flag)	printf("success\n");
	else	printf("fail\n");
	ReadBooksInfo();
	ReadReadersInfo();
}
void BookReturn(char *readerName, char* bookName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(books[i].name, bookName)){
			books[i].amount++;
			char *des1 = strstr(borrowerList[i], readerName), *des2 = strstr(borrowerList[i], readerName);
			char p[100];
			des1 += strlen(readerName);
			if(des1 != NULL){
				strcpy(p, des1);
				strcpy(des2, p);
			}
			int j;
			for(j = 0; j < 100; j++){
				if(!strcmp(readers[j].name, readerName)){
					char *des3 = strstr(borrowedBookList[j], bookName), *des4 = strstr(borrowedBookList[j], bookName);
					char q[100];
					des3 += strlen(bookName);
					if(des3 != NULL){
						strcpy(q, des3);
						strcpy(des4, q);
					}
				}
			}
			flag = 1;
			break;
		}
	}
	UpdateBorrowerList();
	UpdateBorrowedBookList();
	UpdateBookleft();
	if(flag)	printf("success\n");
	else	printf("fail\n");
	ReadBooksInfo();
	ReadReadersInfo();
}
void AddBook(char* bookName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(books[i].name, "end")){
			strcpy(books[i].name, bookName);
			books[i].number = i;
			books[i].amount = 3;
			strcpy(books[i+1].name, "end");
			strcpy(borrowerList[i], "no");
			strcpy(borrowerList[i+1], "end");
			books[i+1].amount = -1;
			flag = 1;
			break;
		}
	}
	UpdateBookleft();
	UpdateBooks();
	UpdateBorrowerList();
	if(flag)	printf("success\n");
	else	printf("fail\n");
}
void DelBook(char* bookName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(books[i].name, bookName)){
			if(books[i].amount != 3){
				printf("fail\n");
				return;
			}
			strcpy(books[i].name, "null");
			books[i].amount = 0;
			flag = 1;
			break;
		}
	}
	UpdateBookleft();
	UpdateBooks();
	if(flag)	printf("success\n");
	else	printf("fail\n");
}
void AddReader(char* readerName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(readers[i].name, "end")){
			strcpy(readers[i].name, readerName);
			readers[i].number = i;
			strcpy(readers[i+1].name, "end");
			flag = 1;
			break;
		}
	}
	UpdateReaders();
	if(flag)	printf("success\n");
	else	printf("fail\n");
}													
void DelReader(char* readerName){
	int i, flag = 0;
	for(i = 0; i < 100; i++){
		if(!strcmp(readers[i].name, readerName)){
			if(!strcmp(borrowedBookList[i], "null")){
				printf("fail\n");
				return;
			}
			strcpy(readers[i].name, "null");
			flag = 1;
			break;
		}
	}
	UpdateReaders();
	if(flag)	printf("success\n");
	else	printf("fail\n");
}