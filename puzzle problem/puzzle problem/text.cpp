#define _CRT_SECURE_NO_WARNINGS 1
////头文件
////#include<stdio.h>
////#include<windows.h>//Sleep(500)函数调用此头文件
////#include<conio.h>//getch()函数调用此头文件
////#include<stdlib.h>//system("cls")函数调用此头文件
////
////函数状态码定义
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
////#define Pass 0 //可通过
////#define Wall 1 //墙
////#define Start 6 //起点
////#define End 7   //终点
////#define Back 8 //返回
////#define Exit 9 //出口：找到终点后标志出来
////自定义数据类型
////
////自定义枚举类型
////enum direction { East = 2, South, West, North };//2,3,4,5分别代表东、南、西、北
////												/*+------------------------
////												使用枚举类型来表示方向
////												该枚举类型定义的变量只能取值 East,West,South,North
////												且East=2,South=3,West=4,North=5
////												本源码上面使用枚举类型,基本等效于下面
////												#define East 2
////												#define South 3
////												#define West 4
////												#define North 5
////												+------------------------*/
////
////												自定义坐标结构体
////typedef struct //迷宫x行，y列
////{
////	int x;
////	int y;
////}Position;//坐标结构体
////
////		  二维数组构造迷宫,1代表墙,0代表可通过。
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
////自定义结构体作为中间变量保存当前临时坐标信息
////typedef struct {
////	int number;//记录是第几步
////	Position seat;//通道块在迷宫中的"位置坐标"
////	enum direction direc;//direction为枚举类型，用来表示从此通道走向下一通道的方向
////						 direc只能取值 East,West,South,North
////						 且East=2,South=3,West=4,North=5
////}SElemType;
////
////自定义栈结构便于将上面结构体的临时坐标信息放到栈内存储
////typedef struct {
////	SElemType * base;
////	SElemType * top;
////	int stacksize;
////}SqStack;//栈
////
////		 函数声明
////void Welcome();//欢迎界面函数
////void printfMap();//打印迷宫函数
////Status findPath(SqStack & S, Position start, Position end);//迷宫寻路径函数
////Status InitStack(SqStack & S);//初始化栈
////Status StackEmpty(SqStack S);//判断栈是否为空
////Status Push(SqStack & S, SElemType e);//入栈
////Status Pop(SqStack & S, SElemType & e);//出栈
////enum direction Judge_direc(Position pos);//根据一个坐标探索周围坐标返回可通行的坐标
////Position change_seat(Position & pos, enum direction direc);//根据方向移动到下一个可通行的坐标处
////Status change_Map(int mapid);
////
/////****************主函数开始***********************/
////主函数
////int main() {
////	Position start, end;
////	int n;
////	SqStack S;
////	InitStack(S);//初始化栈
////	Welcome();//调用欢迎界面函数
////	start.x = 0;//0
////	start.y = 1;//1
////	printf("请选择地图:\n\n");
////	change_Map(0);
////	printf("\t\t默认地图0\n\n");
////	printfMap();
////	printf("选择默认地图0请输入0:\n");
////	printf("您的选择：");
////	scanf_s("%d", &n);
////	system("cls");
////	switch (n) {
////	case 0:
////	{
////		change_Map(0);
////		printf("初始迷宫如下所示:\n\n");
////		end.x = 8; end.y = 9;
////		printfMap();
////		printf("按任意键继续!");
////		_getch();
////		system("cls");
////		break;
////	}
////	}
////	findPath(S, start, end);
////	printf("\n\n按下任意键退出系统！\n");
////	_getch();
////	return 0;
////}
/////***************主函数结束***********************/
////打印迷宫
////void printfMap()
////{
////	int i, j;
////	for (i = 0; i < 10; i++) {
////		printf("\t");
////		for (j = 0; j < 10; j++)
////			switch (Map[i][j]) {
////			case Pass:printf("□"); break;//可通过0
////			case Wall:printf("■"); break;//墙1
////			case East:printf("→"); break;//东2
////			case South:printf("↓"); break;//南3
////			case West:printf("←"); break;//西4
////			case North:printf("↑"); break;//北5
////			case Start:printf("⊙"); break;//起点6
////			case End:printf("◎"); break;//终点7
////			case Back:printf("Θ"); break;//返回8
////			case Exit:printf("To"); break;//出口9
////			}
////		printf("\n");
////	}
////	printf("\n");
////}
////
////走迷宫
////Status findPath(SqStack & S, Position start, Position end) {
////	Position curpos;//当前坐标
////	SElemType elem;//路径相关信息结构体
////	int step = 1;//记录步骤数
////	curpos = start;//开始坐标    
////	while (1) {
////		if (curpos.x == start.x && curpos.y == start.y)//此段代码只执行一次
////		{
////			elem.number = 1;
////			elem.direc = Judge_direc(curpos);//判断下一个位置是什么方向
////			elem.seat = curpos;
////			step++;
////			Push(S, elem);//第一个起点无条件入栈 
////		}
////		Map[curpos.x][curpos.y] = (int)elem.direc;//锁定当前位置
////		curpos = change_seat(curpos, elem.direc);//移动到下一个位置，根据方向改变坐标位置
////		if (Map[curpos.x][curpos.y] == End)//找到终点，退出循环
////		{
////			elem.seat = curpos;
////			elem.number = step;
////			Push(S, elem);
////			Map[curpos.x][curpos.y] = Exit;
////			system("cls");
////			printf("\n");
////			printfMap();
////			printf("\n\t恭喜您，迷宫路径已经找到！\n\n");
////			printf("路径坐标为：\n\n");
////			while (!StackEmpty(S))
////			{
////				Pop(S, elem);//出栈
////				curpos = elem.seat;
////				printf("(%d,%d)\t", curpos.x, curpos.y);
////			}
////			break;
////		}
////		if (Map[curpos.x][curpos.y] == Pass)//如果当前路可通
////		{
////			elem.number = step;
////			elem.seat = curpos;
////			elem.direc = Judge_direc(curpos);
////			Push(S, elem);//将当前坐标入栈
////			step++;
////		}
////		else//如果当前位置不通
////		{
////			Pop(S, elem);
////			curpos = elem.seat;
////			step = elem.number - 1;
////			Map[curpos.x][curpos.y] = Back;//表示四个都不通，标记走过了
////			do
////			{
////				Pop(S, elem);//出栈
////				curpos = elem.seat;
////				/************while循环开始*****************/
////				while (elem.direc <= 4)
////				{
////					elem.direc = (enum direction)(elem.direc + 1);
////					curpos = change_seat(curpos, elem.direc);//移动到下一个位置，根据方向改变坐标位置
////					if (Map[curpos.x][curpos.y] == Pass)
////					{
////						break;
////					}
////				};
////				/************while循环结束*****************/
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
////				printf("正在遍历查找...\n\n");
////				printfMap();
////				Sleep(1000);
////				system("cls");
////			} while (!StackEmpty(S));//直到栈为空跳出循环        
////		}
////		printf("正在遍历查找...\n\n");
////		printfMap();
////		Sleep(1000);
////		system("cls");
////	}
////	return OK;
////}
////
////改变坐标
////Position change_seat(Position & pos, enum direction direc) {
////	switch (direc) {
////	case East:  pos.y = pos.y + 1; break;//2
////	case South: pos.x = pos.x + 1; break;//3
////	case West:  pos.y = pos.y - 1; break;//4
////	case North: pos.x = pos.x - 1; break;//5
////	}
////	return pos;
////}
////判断下一个位置方向
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
////	if (mapid == 0)//默认地图
////	{
////		Map[0][8] = Wall;
////		Map[8][9] = End;
////	}
////	return OK;
////}
////初始化栈
////Status InitStack(SqStack & S) {
//// 	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
////	if (!S.base)exit(OVERFLOW);
////	S.top = S.base;
////	S.stacksize = STACK_INIT_SIZE;
////	return OK;
////
////}
////
////判断栈是否为空
////Status StackEmpty(SqStack S) {
////	if (S.top == S.base)
////		return TRUE;
////	else
////		return FALSE;
////}
////入栈
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
////出栈
////Status Pop(SqStack & S, SElemType & e) {
////	if (S.top == S.base)return ERROR;
////	e = *--S.top;
////	return OK;
////}
////去栈顶元素
////Status GetTop(SqStack S, SElemType & e) {
////	if (S.top == S.base)return ERROR;
////	e = *(S.top - 1);  //注意top指向待插入位置
////	return OK;
////}
////欢迎界面函数
////void Welcome() {
////	system("title 迷宫求解程序");//设置窗口标题
////	system("mode con cols=80 lines=30");  //窗口宽度高度
////	system("color f0");//设置文本颜色，所在头文件
////	printf("★**************************************************************★\n");
////	printf("★                                                              ★\n");
////	printf("★                     欢迎使用迷宫求解程序                     ★\n");
////	printf("★**************************************************************★\n");
////	printf("按任意键继续！\n");
////	_getch();//暂停函数，所在头文件<conio.h>
////	system("cls");//清屏函数
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
//struct pcb { /* 定义进程控制块PCB */
//	char name[10];
//	char state;//进程状态
//	int ntime;//需要时间
//	int rtime;//已经执行时间
//	int atime;//到达时间 
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
//	if (ready == NULL) /*,插入队首*/
//	{
//		p->link = ready;
//		ready = p;
//	}
//	else {//插入队尾 
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
//void sort() { /* 建立对进程进行短进程排列函数*/
//	PCB *first, *second;
//	if (ready == NULL || space() == 1) /*,插入队首*/
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
//void input() /* 建立进程控制块函数*/
//{
//	int i, num;
//	//clrscr(); /*清屏*/
//	system("cls");
//	printf("            ***************************短进程优先调度算法******************************");
//	printf("\n 请输入即将运行的进程总数目：");
//	scanf("%d", &num);
//	for (i = 0; i < num; i++)
//	{
//
//		p = getpch(PCB);//申请空间，指针 
//		printf("\n 请输入进程名称:");
//		scanf("%s", p->name);
//		printf("\n 请输入进程到达时间:");
//		scanf("%d", &p->atime);
//		printf("\n 请输入进程运行所需时间:");
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
//void disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/
//{
//	printf("\n 进程名称 \t 进程状态 \t 到达时间 \t 运行所需时间 \t 已经运行时间 \n");
//	printf("|%s\t", pr->name);
//	printf("|%c\t", pr->state);
//	printf("|%d\t", pr->atime);
//	printf("|%d\t", pr->ntime);
//	printf("|%d\t", pr->rtime);
//	printf("\n");
//}
//void check() /* 建立进程查看函数 */
//{
//	PCB* pr;
//	printf("\n **** 当前正在运行的进程是:%s", p->name); /*显示当前运行进程*/
//	disp(p);
//	pr = ready;
//	printf("\n ****当前就绪队列状态为:\n"); /*显示就绪队列状态*/
//	if (pr == NULL)printf("\n 就绪队列为空。\n ");
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
//void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/
//{
//	printf("\n 进程 [%s] 已完成.\n", p->name);
//	free(p);
//}
//void running() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/
//{
//	runningTime += p->ntime;
//	p->rtime = p->ntime;
//	if (ready != NULL && runningTime < ready->atime) {
//		runningTime = ready->atime;
//	}
//	destroy(); /* 调用destroy函数*/
//	sort(); /*调用sort函数*/
//}
//int main() /*主函数*/
//{
//	int len, h = 0;
//	char ch;
//	input();
//	len = space();
//
//	while ((len != 0) && (ready != NULL))
//	{
//		printf("********************************\n");
//		printf("当前时刻%d\n", h++);
//		p = ready;
//		ready = p->link;
//		p->link = NULL;
//		p->state = 'R';
//		check();
//		running();
//
//	}
//	printf("\n\n 进程已经完成.\n");
//	ch = getchar();
//	system("Pause");
//	return 0;
//}
#include "stdafx.h"
#include <iostream>
using namespace std;

int n = 0;
int arr[100];
bool place(int i)		//判断能不能放置第N个皇后
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
		while (!place(k) && k<n)			//放置第N个皇后
			arr[k] = arr[k] + 1;
		if (arr[k]<n&&k == n - 1)				//排列完成一次
		{
			solution++;
			arr[k] = arr[k] + 1;
		}
		else if (arr[k]<n&&k<n - 1)			//排列完一个皇后
		{
			k = k + 1;
			arr[k] = -1;
		}
		else								//当前皇后没有合适的位置
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