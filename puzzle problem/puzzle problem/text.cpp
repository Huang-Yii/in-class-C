#define _CRT_SECURE_NO_WARNINGS 1
////ͷ�ļ�
////#include<stdio.h>
////#include<windows.h>//Sleep(500)�������ô�ͷ�ļ�
////#include<conio.h>//getch()�������ô�ͷ�ļ�
////#include<stdlib.h>//system("cls")�������ô�ͷ�ļ�
////
////����״̬�붨��
/////******************************/
////#define TRUE 1
////#define FALSE 0
////#define OK 1
////#define ERROR 0
////#define INFEASIBLE - 1
////#define OVERFLOW - 2
////typedef int Status;
////#define STACK_INIT_SIZE 100
////#define STACKINCREMENT 10
////#define Pass 0 //��ͨ��
////#define Wall 1 //ǽ
////#define Start 6 //���
////#define End 7   //�յ�
////#define Back 8 //����
////#define Exit 9 //���ڣ��ҵ��յ���־����
////�Զ�����������
////
////�Զ���ö������
////enum direction { East = 2, South, West, North };//2,3,4,5�ֱ�������ϡ�������
////												/*+------------------------
////												ʹ��ö����������ʾ����
////												��ö�����Ͷ���ı���ֻ��ȡֵ East,West,South,North
////												��East=2,South=3,West=4,North=5
////												��Դ������ʹ��ö������,������Ч������
////												#define East 2
////												#define South 3
////												#define West 4
////												#define North 5
////												+------------------------*/
////
////												�Զ�������ṹ��
////typedef struct //�Թ�x�У�y��
////{
////	int x;
////	int y;
////}Position;//����ṹ��
////
////		  ��ά���鹹���Թ�,1����ǽ,0�����ͨ����
////int Map[10][10] = {
////	{ 1,6,1,1,1,1,1,1,1,1 },
////	{ 1,0,0,1,0,0,0,1,0,1 },
////	{ 1,0,0,1,0,0,0,1,0,1 },
////	{ 1,0,0,0,0,1,1,0,0,1 },
////	{ 1,0,1,1,1,0,0,0,0,1 },
////	{ 1,0,0,0,1,0,0,0,0,1 },
////	{ 1,0,1,0,0,0,1,0,0,1 },
////	{ 1,0,1,1,1,0,1,1,0,1 },
////	{ 1,1,0,0,0,0,0,0,0,7 },
////	{ 1,1,1,1,1,1,1,1,1,1 }
////};
////
////�Զ���ṹ����Ϊ�м�������浱ǰ��ʱ������Ϣ
////typedef struct {
////	int number;//��¼�ǵڼ���
////	Position seat;//ͨ�������Թ��е�"λ������"
////	enum direction direc;//directionΪö�����ͣ�������ʾ�Ӵ�ͨ��������һͨ���ķ���
////						 direcֻ��ȡֵ East,West,South,North
////						 ��East=2,South=3,West=4,North=5
////}SElemType;
////
////�Զ���ջ�ṹ���ڽ�����ṹ�����ʱ������Ϣ�ŵ�ջ�ڴ洢
////typedef struct {
////	SElemType * base;
////	SElemType * top;
////	int stacksize;
////}SqStack;//ջ
////
////		 ��������
////void Welcome();//��ӭ���溯��
////void printfMap();//��ӡ�Թ�����
////Status findPath(SqStack & S, Position start, Position end);//�Թ�Ѱ·������
////Status InitStack(SqStack & S);//��ʼ��ջ
////Status StackEmpty(SqStack S);//�ж�ջ�Ƿ�Ϊ��
////Status Push(SqStack & S, SElemType e);//��ջ
////Status Pop(SqStack & S, SElemType & e);//��ջ
////enum direction Judge_direc(Position pos);//����һ������̽����Χ���귵�ؿ�ͨ�е�����
////Position change_seat(Position & pos, enum direction direc);//���ݷ����ƶ�����һ����ͨ�е����괦
////Status change_Map(int mapid);
////
/////****************��������ʼ***********************/
////������
////int main() {
////	Position start, end;
////	int n;
////	SqStack S;
////	InitStack(S);//��ʼ��ջ
////	Welcome();//���û�ӭ���溯��
////	start.x = 0;//0
////	start.y = 1;//1
////	printf("��ѡ���ͼ:\n\n");
////	change_Map(0);
////	printf("\t\tĬ�ϵ�ͼ0\n\n");
////	printfMap();
////	printf("ѡ��Ĭ�ϵ�ͼ0������0:\n");
////	printf("����ѡ��");
////	scanf_s("%d", &n);
////	system("cls");
////	switch (n) {
////	case 0:
////	{
////		change_Map(0);
////		printf("��ʼ�Թ�������ʾ:\n\n");
////		end.x = 8; end.y = 9;
////		printfMap();
////		printf("�����������!");
////		_getch();
////		system("cls");
////		break;
////	}
////	}
////	findPath(S, start, end);
////	printf("\n\n����������˳�ϵͳ��\n");
////	_getch();
////	return 0;
////}
/////***************����������***********************/
////��ӡ�Թ�
////void printfMap()
////{
////	int i, j;
////	for (i = 0; i < 10; i++) {
////		printf("\t");
////		for (j = 0; j < 10; j++)
////			switch (Map[i][j]) {
////			case Pass:printf("��"); break;//��ͨ��0
////			case Wall:printf("��"); break;//ǽ1
////			case East:printf("��"); break;//��2
////			case South:printf("��"); break;//��3
////			case West:printf("��"); break;//��4
////			case North:printf("��"); break;//��5
////			case Start:printf("��"); break;//���6
////			case End:printf("��"); break;//�յ�7
////			case Back:printf("��"); break;//����8
////			case Exit:printf("To"); break;//����9
////			}
////		printf("\n");
////	}
////	printf("\n");
////}
////
////���Թ�
////Status findPath(SqStack & S, Position start, Position end) {
////	Position curpos;//��ǰ����
////	SElemType elem;//·�������Ϣ�ṹ��
////	int step = 1;//��¼������
////	curpos = start;//��ʼ����    
////	while (1) {
////		if (curpos.x == start.x && curpos.y == start.y)//�˶δ���ִֻ��һ��
////		{
////			elem.number = 1;
////			elem.direc = Judge_direc(curpos);//�ж���һ��λ����ʲô����
////			elem.seat = curpos;
////			step++;
////			Push(S, elem);//��һ�������������ջ 
////		}
////		Map[curpos.x][curpos.y] = (int)elem.direc;//������ǰλ��
////		curpos = change_seat(curpos, elem.direc);//�ƶ�����һ��λ�ã����ݷ���ı�����λ��
////		if (Map[curpos.x][curpos.y] == End)//�ҵ��յ㣬�˳�ѭ��
////		{
////			elem.seat = curpos;
////			elem.number = step;
////			Push(S, elem);
////			Map[curpos.x][curpos.y] = Exit;
////			system("cls");
////			printf("\n");
////			printfMap();
////			printf("\n\t��ϲ�����Թ�·���Ѿ��ҵ���\n\n");
////			printf("·������Ϊ��\n\n");
////			while (!StackEmpty(S))
////			{
////				Pop(S, elem);//��ջ
////				curpos = elem.seat;
////				printf("(%d,%d)\t", curpos.x, curpos.y);
////			}
////			break;
////		}
////		if (Map[curpos.x][curpos.y] == Pass)//�����ǰ·��ͨ
////		{
////			elem.number = step;
////			elem.seat = curpos;
////			elem.direc = Judge_direc(curpos);
////			Push(S, elem);//����ǰ������ջ
////			step++;
////		}
////		else//�����ǰλ�ò�ͨ
////		{
////			Pop(S, elem);
////			curpos = elem.seat;
////			step = elem.number - 1;
////			Map[curpos.x][curpos.y] = Back;//��ʾ�ĸ�����ͨ������߹���
////			do
////			{
////				Pop(S, elem);//��ջ
////				curpos = elem.seat;
////				/************whileѭ����ʼ*****************/
////				while (elem.direc <= 4)
////				{
////					elem.direc = (enum direction)(elem.direc + 1);
////					curpos = change_seat(curpos, elem.direc);//�ƶ�����һ��λ�ã����ݷ���ı�����λ��
////					if (Map[curpos.x][curpos.y] == Pass)
////					{
////						break;
////					}
////				};
////				/************whileѭ������*****************/
////				if (Map[curpos.x][curpos.y] == Pass)
////				{
////					curpos = elem.seat;
////					elem.number = step;
////					elem.seat = curpos;
////					Push(S, elem);
////					step++;
////					break;
////				}
////				else
////				{
////					curpos = elem.seat;
////					Map[curpos.x][curpos.y] = Back;
////				}
////				printf("���ڱ�������...\n\n");
////				printfMap();
////				Sleep(1000);
////				system("cls");
////			} while (!StackEmpty(S));//ֱ��ջΪ������ѭ��        
////		}
////		printf("���ڱ�������...\n\n");
////		printfMap();
////		Sleep(1000);
////		system("cls");
////	}
////	return OK;
////}
////
////�ı�����
////Position change_seat(Position & pos, enum direction direc) {
////	switch (direc) {
////	case East:  pos.y = pos.y + 1; break;//2
////	case South: pos.x = pos.x + 1; break;//3
////	case West:  pos.y = pos.y - 1; break;//4
////	case North: pos.x = pos.x - 1; break;//5
////	}
////	return pos;
////}
////�ж���һ��λ�÷���
////enum direction Judge_direc(Position pos) {
////	enum direction judge;
////	if (Map[pos.x][pos.y + 1] == Pass || Map[pos.x][pos.y + 1] == End) {
////		judge = East;
////	}
////	else {
////		if (Map[pos.x + 1][pos.y] == Pass || Map[pos.x + 1][pos.y] == End) {
////			judge = South;
////		}
////		else {
////			if (Map[pos.x][pos.y - 1] == Pass || Map[pos.x][pos.y - 1] == End) {
////				judge = West;
////			}
////			else {
////				if (Map[pos.x - 1][pos.y] == Pass || Map[pos.x - 1][pos.y] == End) {
////					judge = North;
////				}
////			}
////		}
////	}
////	return judge;
////}
////
////Status change_Map(int mapid)
////{
////	if (mapid == 0)//Ĭ�ϵ�ͼ
////	{
////		Map[0][8] = Wall;
////		Map[8][9] = End;
////	}
////	return OK;
////}
////��ʼ��ջ
////Status InitStack(SqStack & S) {
//// 	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
////	if (!S.base)exit(OVERFLOW);
////	S.top = S.base;
////	S.stacksize = STACK_INIT_SIZE;
////	return OK;
////
////}
////
////�ж�ջ�Ƿ�Ϊ��
////Status StackEmpty(SqStack S) {
////	if (S.top == S.base)
////		return TRUE;
////	else
////		return FALSE;
////}
////��ջ
////Status Push(SqStack & S, SElemType e) {
////	if (S.top - S.base >= S.stacksize) {
////		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
////		if (!S.base)exit(OVERFLOW);
////		S.top = S.base + S.stacksize;
////		S.base += STACKINCREMENT;
////	}
////	*S.top++ = e;
////	return OK;
////}
////
////��ջ
////Status Pop(SqStack & S, SElemType & e) {
////	if (S.top == S.base)return ERROR;
////	e = *--S.top;
////	return OK;
////}
////ȥջ��Ԫ��
////Status GetTop(SqStack S, SElemType & e) {
////	if (S.top == S.base)return ERROR;
////	e = *(S.top - 1);  //ע��topָ�������λ��
////	return OK;
////}
////��ӭ���溯��
////void Welcome() {
////	system("title �Թ�������");//���ô��ڱ���
////	system("mode con cols=80 lines=30");  //���ڿ�ȸ߶�
////	system("color f0");//�����ı���ɫ������ͷ�ļ�
////	printf("��**************************************************************��\n");
////	printf("��                                                              ��\n");
////	printf("��                     ��ӭʹ���Թ�������                     ��\n");
////	printf("��**************************************************************��\n");
////	printf("�������������\n");
////	_getch();//��ͣ����������ͷ�ļ�<conio.h>
////	system("cls");//��������
////
////}
////
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "stdio.h" 
//#include <stdlib.h> 
//#include <conio.h> 
//
//#define getpch(type) (type*)malloc(sizeof(type)) 
//#define NULL 0 
//struct pcb { /* ������̿��ƿ�PCB */
//	char name[10];
//	char state;//����״̬
//	int ntime;//��Ҫʱ��
//	int rtime;//�Ѿ�ִ��ʱ��
//	int atime;//����ʱ�� 
//	struct pcb* link;
//}*ready = NULL, *p;
//typedef struct pcb PCB;
//int runningTime = 0;
//int space()
//{
//	int l = 0; PCB* pr = ready;
//	while (pr != NULL)
//	{
//		l++;
//		pr = pr->link;
//	}
//	return(l);
//}
//void linkpcb() {
//	PCB *first, *second;
//	int insert = 0;
//	if (ready == NULL) /*,�������*/
//	{
//		p->link = ready;
//		ready = p;
//	}
//	else {//�����β 
//		first = ready;
//		second = first->link;
//		while (second != NULL)
//		{
//			first = first->link;
//			second = second->link;
//		}
//		first->link = p;
//	}
//}
//void sort() { /* �����Խ��̽��ж̽������к���*/
//	PCB *first, *second;
//	if (ready == NULL || space() == 1) /*,�������*/
//	{
//		return;
//	}
//	else
//	{
//		first = ready->link;
//		while (first != NULL && first->atime <= runningTime) {
//			second = first->link;
//			if (first->ntime < ready->ntime) {
//				PCB *temp = ready;
//				while (temp != NULL) {
//					if (temp->link == first)break;
//					temp = temp->link;
//				}
//				temp->link = second;
//				first->link = ready;
//				ready = first;
//			}
//			first = second;
//		}
//	}
//}
//void input() /* �������̿��ƿ麯��*/
//{
//	int i, num;
//	//clrscr(); /*����*/
//	system("cls");
//	printf("            ***************************�̽������ȵ����㷨******************************");
//	printf("\n �����뼴�����еĽ�������Ŀ��");
//	scanf("%d", &num);
//	for (i = 0; i < num; i++)
//	{
//
//		p = getpch(PCB);//����ռ䣬ָ�� 
//		printf("\n �������������:");
//		scanf("%s", p->name);
//		printf("\n ��������̵���ʱ��:");
//		scanf("%d", &p->atime);
//		printf("\n �����������������ʱ��:");
//		scanf("%d", &p->ntime);
//		printf("\n");
//		p->rtime = 0;
//		p->state = 'w';
//		p->link = NULL;
//		linkpcb();
//	}
//
//}
//
//void disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/
//{
//	printf("\n �������� \t ����״̬ \t ����ʱ�� \t ��������ʱ�� \t �Ѿ�����ʱ�� \n");
//	printf("|%s\t", pr->name);
//	printf("|%c\t", pr->state);
//	printf("|%d\t", pr->atime);
//	printf("|%d\t", pr->ntime);
//	printf("|%d\t", pr->rtime);
//	printf("\n");
//}
//void check() /* �������̲鿴���� */
//{
//	PCB* pr;
//	printf("\n **** ��ǰ�������еĽ�����:%s", p->name); /*��ʾ��ǰ���н���*/
//	disp(p);
//	pr = ready;
//	printf("\n ****��ǰ��������״̬Ϊ:\n"); /*��ʾ��������״̬*/
//	if (pr == NULL)printf("\n ��������Ϊ�ա�\n ");
//	while (pr != NULL)
//	{
//		if (pr->atime <= runningTime) {
//			disp(pr);
//			pr = pr->link;
//		}
//		else {
//			break;
//		}
//	}
//}
//void destroy() /*�������̳�������(�������н���,��������)*/
//{
//	printf("\n ���� [%s] �����.\n", p->name);
//	free(p);
//}
//void running() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/
//{
//	runningTime += p->ntime;
//	p->rtime = p->ntime;
//	if (ready != NULL && runningTime < ready->atime) {
//		runningTime = ready->atime;
//	}
//	destroy(); /* ����destroy����*/
//	sort(); /*����sort����*/
//}
//int main() /*������*/
//{
//	int len, h = 0;
//	char ch;
//	input();
//	len = space();
//
//	while ((len != 0) && (ready != NULL))
//	{
//		printf("********************************\n");
//		printf("��ǰʱ��%d\n", h++);
//		p = ready;
//		ready = p->link;
//		p->link = NULL;
//		p->state = 'R';
//		check();
//		running();
//
//	}
//	printf("\n\n �����Ѿ����.\n");
//	ch = getchar();
//	system("Pause");
//	return 0;
//}
#include "stdafx.h"
#include <iostream>
using namespace std;

int n = 0;
int arr[100];
bool place(int i)		//�ж��ܲ��ܷ��õ�N���ʺ�
{
	for (int j = 0; j<i; j++)
		if (arr[j] == arr[i] || abs(arr[j] - arr[i]) == abs(j - i))
			return false;
	return true;
}
int queue(int n)
{
	int solution = 0;
	for (int i = 0; i<n; i++)
		arr[i] = 0;
	int k = 1;
	while (k >= 0)
	{
		while (!place(k) && k<n)			//���õ�N���ʺ�
			arr[k] = arr[k] + 1;
		if (arr[k]<n&&k == n - 1)				//�������һ��
		{
			solution++;
			arr[k] = arr[k] + 1;
		}
		else if (arr[k]<n&&k<n - 1)			//������һ���ʺ�
		{
			k = k + 1;
			arr[k] = -1;
		}
		else								//��ǰ�ʺ�û�к��ʵ�λ��
		{
			arr[k] = 0;
			k = k - 1;
			arr[k] = arr[k] + 1;
		}
	}

	return solution;
}
void main()
{
	while (1)
	{
		cout << "Please input the queue number:" << endl;
		cin >> n;
		if (n == -1)
			break;
		int x = queue(n);
		cout << x << " solution(s)" << endl;
	}
	system("pause");
}