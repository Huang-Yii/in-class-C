#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 

#define getpch(type) (type*)malloc(sizeof(type)) 
#define NULL 0 
struct pcb { /* ������̿��ƿ�PCB */
	char name[10];
	char state;//����״̬
	int ntime;//��Ҫʱ��
	int rtime;//�Ѿ�ִ��ʱ��
	int atime;//����ʱ�� 
	struct pcb* link;
}*ready = NULL, *p;
typedef struct pcb PCB;
int runningTime = 0;
int space()
{
	int l = 0; PCB* pr = ready;
	while (pr != NULL)
	{
		l++;
		pr = pr->link;
	}
	return(l);
}
void linkpcb() {
	PCB *first, *second;
	int insert = 0;
	if (ready == NULL) /*,�������*/
	{
		p->link = ready;
		ready = p;
	}
	else {//�����β 
		first = ready;
		second = first->link;
		while (second != NULL)
		{
			first = first->link;
			second = second->link;
		}
		first->link = p;
	}
}
void sort() { /* �����Խ��̽��ж̽������к���*/
	PCB *first, *second;
	if (ready == NULL || space() == 1) /*,�������*/
	{
		return;
	}
	else
	{
		first = ready->link;
		while (first != NULL && first->atime <= runningTime) {
			second = first->link;
			if (first->ntime < ready->ntime) {
				PCB *temp = ready;
				while (temp != NULL) {
					if (temp->link == first)break;
					temp = temp->link;
				}
				temp->link = second;
				first->link = ready;
				ready = first;
			}
			first = second;
		}
	}
}
void input() /* �������̿��ƿ麯��*/
{
	int i, num;
	//clrscr(); /*����*/
	system("cls");
	printf("            ***************************�̽������ȵ����㷨******************************");
	printf("\n �����뼴�����еĽ�������Ŀ��");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{

		p = getpch(PCB);//����ռ䣬ָ�� 
		printf("\n �������������:");
		scanf("%s", p->name);
		printf("\n ��������̵���ʱ��:");
		scanf("%d", &p->atime);
		printf("\n �����������������ʱ��:");
		scanf("%d", &p->ntime);
		printf("\n");
		p->rtime = 0;
		p->state = 'w';
		p->link = NULL;
		linkpcb();
	}

}

void disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/
{
	printf("\n �������� \t ����״̬ \t ����ʱ�� \t ��������ʱ�� \t �Ѿ�����ʱ�� \n");
	printf("|%s\t", pr->name);
	printf("|%c\t", pr->state);
	printf("|%d\t", pr->atime);
	printf("|%d\t", pr->ntime);
	printf("|%d\t", pr->rtime);
	printf("\n");
}
void check() /* �������̲鿴���� */
{
	PCB* pr;
	printf("\n **** ��ǰ�������еĽ�����:%s", p->name); /*��ʾ��ǰ���н���*/
	disp(p);
	pr = ready;
	printf("\n ****��ǰ��������״̬Ϊ:\n"); /*��ʾ��������״̬*/
	if (pr == NULL)printf("\n ��������Ϊ�ա�\n ");
	while (pr != NULL)
	{
		if (pr->atime <= runningTime) {
			disp(pr);
			pr = pr->link;
		}
		else {
			break;
		}
	}
}
void destroy() /*�������̳�������(�������н���,��������)*/
{
	printf("\n ���� [%s] �����.\n", p->name);
	free(p);
}
void running() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/
{
	runningTime += p->ntime;
	p->rtime = p->ntime;
	if (ready != NULL && runningTime < ready->atime) {
		runningTime = ready->atime;
	}
	destroy(); /* ����destroy����*/
	sort(); /*����sort����*/
}
int main() /*������*/
{
	int len, h = 0;
	char ch;
	input();
	len = space();

	while ((len != 0) && (ready != NULL))
	{
		printf("********************************\n");
		printf("��ǰʱ��%d\n", h++);
		p = ready;
		ready = p->link;
		p->link = NULL;
		p->state = 'R';
		check();
		running();

	}
	printf("\n\n �����Ѿ����.\n");
	ch = getchar();
	system("Pause");
	return 0;
}
