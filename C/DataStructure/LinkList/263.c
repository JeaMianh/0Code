#include <stdio.h>
#include <stdlib.h>

// 定义链表结点结构体
typedef struct node {
  int height; // 身高值
  struct node *next; // 指向下一个结点的指针
} node;

// 创建一个新的结点，返回指向它的指针
node *new_node(int height) {
  node *n = (node *)malloc(sizeof(node)); // 分配内存空间
  n->height = height; // 设置身高值
  n->next = NULL; // 初始化指针为空
  return n; // 返回指针
}

// 在链表的尾部插入一个新的结点
void insert_tail(node **head, node *n) {
  if (*head == NULL) { // 如果链表为空
    *head = n; // 新结点就是头结点
  } else { // 如果链表不为空
    node *p = *head; // 用一个临时指针遍历链表
    while (p->next != NULL) { // 找到链表的最后一个结点
      p = p->next;
    }
    p->next = n; // 在最后一个结点后面插入新结点
  }
}

// 在链表中按照身高递增的顺序插入一个新的结点
void insert_order(node **head, node *n) {
  if (*head == NULL || (*head)->height >= n->height) { // 如果链表为空或者新结点的身高小于等于头结点的身高
    n->next = *head; // 新结点的下一个结点指向原来的头结点
    *head = n; // 新结点成为新的头结点
  } else { // 如果链表不为空且新结点的身高大于头结点的身高
    node *p = *head; // 用一个临时指针遍历链表
    while (p->next != NULL && p->next->height < n->height) { // 找到第一个身高大于等于新结点的结点的前一个结点
      p = p->next;
    }
    n->next = p->next; // 新结点的下一个结点指向找到的结点
    p->next = n; // 前一个结点的下一个结点指向新结点
  }
}

// 打印链表中的所有结点的身高值
void print_list(node *head) {
  node *p = head; // 用一个临时指针遍历链表
  while (p != NULL) { // 当指针不为空时
    printf("%d", p->height); // 打印当前结点的身高值
    if (p->next != NULL) { // 如果不是最后一个结点
      printf(" "); // 打印一个空格
    }
    p = p->next; // 指针指向下一个结点
  }
  printf("\n"); // 打印一个换行符
}

// 释放链表占用的内存空间
void free_list(node *head) {
  node *p = head; // 用一个临时指针遍历链表
  while (p != NULL) { // 当指针不为空时
    node *q = p->next; // 用另一个临时指针保存下一个结点的地址
    free(p); // 释放当前结点的内存空间
    p = q; // 指针指向下一个结点
  }
}

int main() {
  int N, M; // 输入的原队列长度和待插入的身高值
  node *head = NULL; // 链表的头结点指针，初始化为空
  scanf("%d %d", &N, &M); // 读取输入的原队列长度和待插入的身高值
  for (int i = 0; i < N; i++) { // 读取输入的原队列中的身高值
    int h; // 临时变量，存储身高值
    scanf("%d", &h); // 读取身高值
    node *n = new_node(h); // 创建一个新的结点
    insert_tail(&head, n); // 在链表的尾部插入新的结点
  }
  node *n = new_node(M); // 创建一个新的结点，存储待插入的身高值
  insert_order(&head, n); // 在链表中按照身高递增的顺序插入新的结点
  print_list(head); // 打印链表中的所有结点的身高值
  free_list(head); // 释放链表占用的内存空间
  return 0; // 程序正常结束
}
