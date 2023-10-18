#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode;
//头插法 想要修改指针得用二级指针指向它，或者用head=函数传递的值，那函数就得写成指针型而不是void
void headInsert(Lnode** head, int k) {
	Lnode *temp = (Lnode*)malloc(sizeof(struct Lnode));
	temp->data = k;
	temp->next = NULL;
	temp->next = *head;
	*head = temp;
}

//任意位置插入一个结点 k是数据n是位置 循环n-2次是因为第n-2次temp2已经是第n-1个位置了（第一次temp2是第二个位置），用n-1->=第n个位置给temp1
void Insert(Lnode **head,int k,int n){
	Lnode* temp1 = (Lnode*)malloc(sizeof(struct Lnode));
	temp1->data = k;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = *head;
		*head = temp1;
	}
	else if (n > 1) {
		Lnode* temp2 = *head;
		for (int i = 0; i < n - 2; i++) {
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}
}

//尾插法 head初始值就是NULL，来判断第一个位置是否有数据
void tailInsert(Lnode **head,int k){
	Lnode* temp1 = (Lnode*)malloc(sizeof(struct Lnode));
	temp1->data = k;
	temp1->next = NULL;
	Lnode* temp2 = *head;
	if (*head==NULL){
		temp1->next = *head;
		*head = temp1;
	}
	else {
		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp1;
	}
}

//任意位置删除一个结点 思想同任意位置插入
void Delete(Lnode**head,int n){
	Lnode* temp1 = *head;
	if (*head == NULL) {
		printf("链表为空，不可删除");
	}
	else if (n == 1){
		*head = temp1->next;
		free(temp1);
	}
	else if (n > 1) {
		for (int i = 0; i < n - 2; i++) {
			temp1 = temp1->next;
		}
		Lnode* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
}

//反转一个链表（迭代方式实现）
void Reverse1(Lnode**head) {
	Lnode* prev;
	Lnode* current;
	Lnode* next;
	prev = NULL;
	current=*head;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

//反转一个链表（递归方式实现）
Lnode* Reverse2(Lnode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Lnode* newhead = Reverse2(head->next);
	(head->next)->next = head;
	head->next = NULL;
	return newhead;
}

//打印链表 为了不修改head，用一级指针传值
void Print1(Lnode *head) {
	printf("The list is:\n");
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("\n");
}

//打印链表 递归方式实现
void Print2(Lnode *head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	printf("%d", head->data);
	Print2(head->next);
}

int main() {
	Lnode* head = NULL;//本项目使用局部变量创建头结点，如果是全局变量就可以不用二级指针了传指针本身的地址了;
	int x, k;
	printf("请输入要输出的个数\n");
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		printf("请输入要输出的值\n");
		scanf("%d", &k);
		//使用函数插入数据 例如Insert(&head,k,i+1) i+1相当于位置了，也可以不用scanf直接用函数
		Insert(&head, k, i + 1);
		Print2(head);
	}
	head=Reverse2(head);
	Print2(head);
	return 0;
}