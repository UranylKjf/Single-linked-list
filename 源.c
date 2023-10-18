#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode;
//ͷ�巨 ��Ҫ�޸�ָ����ö���ָ��ָ������������head=�������ݵ�ֵ���Ǻ����͵�д��ָ���Ͷ�����void
void headInsert(Lnode** head, int k) {
	Lnode *temp = (Lnode*)malloc(sizeof(struct Lnode));
	temp->data = k;
	temp->next = NULL;
	temp->next = *head;
	*head = temp;
}

//����λ�ò���һ����� k������n��λ�� ѭ��n-2������Ϊ��n-2��temp2�Ѿ��ǵ�n-1��λ���ˣ���һ��temp2�ǵڶ���λ�ã�����n-1->=��n��λ�ø�temp1
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

//β�巨 head��ʼֵ����NULL�����жϵ�һ��λ���Ƿ�������
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

//����λ��ɾ��һ����� ˼��ͬ����λ�ò���
void Delete(Lnode**head,int n){
	Lnode* temp1 = *head;
	if (*head == NULL) {
		printf("����Ϊ�գ�����ɾ��");
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

//��תһ������������ʽʵ�֣�
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

//��תһ�������ݹ鷽ʽʵ�֣�
Lnode* Reverse2(Lnode *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Lnode* newhead = Reverse2(head->next);
	(head->next)->next = head;
	head->next = NULL;
	return newhead;
}

//��ӡ���� Ϊ�˲��޸�head����һ��ָ�봫ֵ
void Print1(Lnode *head) {
	printf("The list is:\n");
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("\n");
}

//��ӡ���� �ݹ鷽ʽʵ��
void Print2(Lnode *head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	printf("%d", head->data);
	Print2(head->next);
}

int main() {
	Lnode* head = NULL;//����Ŀʹ�þֲ���������ͷ��㣬�����ȫ�ֱ����Ϳ��Բ��ö���ָ���˴�ָ�뱾��ĵ�ַ��;
	int x, k;
	printf("������Ҫ����ĸ���\n");
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		printf("������Ҫ�����ֵ\n");
		scanf("%d", &k);
		//ʹ�ú����������� ����Insert(&head,k,i+1) i+1�൱��λ���ˣ�Ҳ���Բ���scanfֱ���ú���
		Insert(&head, k, i + 1);
		Print2(head);
	}
	head=Reverse2(head);
	Print2(head);
	return 0;
}