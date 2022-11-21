#define _CRT_SECURE_NO_WARNINGS 1

//数组


//输入12个整数，以3行4列二维数组输出，并输出各行最大、最小值

//#include<stdio.h>
//int main()
//{
//	int a[3][4];
//	int i, j, max, min;
//	for (i = 0; i < 3; i++)
//	for (j = 0; j < 4; j++)
//		scanf("%d", &a[i][j]);
//	printf("The result is:\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%5d", a[i][j]);
//			max = min = a[i][0];
//			if (max < a[i][j])
//				max = a[i][j];
//			if (min>a[i][j])
//				min = a[i][j];
//		}
//		printf("	max=%d	min=%d", max, min);
//		printf("\n");
//	}
//	return 0;
//}


//#include<stdio.h>
//main()
//{
//	int i;
//	char a[7] = "Foxpro";
//	printf("%s\n", a);
//	for (i = 0; i < 7;i++)
//		printf("%c\n", a[i]);
//}

//上机作业
//#include<stdio.h>
//main()
//{
//	int i;
//	char a[][8] = { "SQL", "Foxpro", "Unix", "ASP" };
//	for (i = 0; i < 3; i++)
//		printf("%s\n", a[i]);
//}
//#include<string.h>
//#include<stdio.h>
//void strc(char a[], char b[])
//{
//	int i=0;
//	int j = strlen(a);
//	for (i = 0; b[i] != '\0'; i++, j++)
//		a[j] = b[i];
//	a[j] = '\0';
//}
//int main()
//{
//	char a[20]="very", b[20]=" good";
//	strc(a, b);
//	puts(a);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char ch[20] = { '0' };
//	gets(ch);
//	for (i = 0; ch[i] != '\0'; i++)
//	{
//		if (ch[i] >= 'a' && ch[i] <= 'z')
//			ch[i] -= 32;
//		else if (ch[i] >= 'A'&& ch[i] <= 'Z')
//			ch[i] += 32;
//	}
//	puts(ch);
//
//	return 0;
//}


//#include<stdio.h>
//#define N 100
//char main()
//{
//	char a[N], b[N] = { 0 };
//	int i = 0;
//	gets(a);
//	for (i = 0; i < N; i++)
//	{
//		if (a[i] >= 'a'&&a[i] <= 'z')
//			b[i] = a[i] - 32;
//		else if (a[i] >= 'A'&&a[i] <= 'Z')
//			b[i] = a[i] + 32;
//	}
//
//	puts(b);
//
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0,a=0,b=0,sum=0;
//	float ch[10] = { 0 };
//	for (i = 0; i < 10; i++)
//		scanf("%f", &ch[i]);
//	int max = ch[0];
//	int min = ch[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (ch[i]>max)
//		{
//			max = ch[i];
//			a = i;
//		}
//		if (ch[i] < min)
//		{
//			min = ch[i];
//			b = i;
//		}
//	}
//	ch[a] = 0;
//	ch[b] = 0;
//	for (i = 0; i < 10; i++)
//		sum += ch[i];
//	printf("%f", sum / 10);
//
//	return 0;
//}


//#include<stdio.h>
//int Fun(int ch[])
//{
//	int i = 0, count=0;
//
//	for (i = 0; ch[i] != '\0'; i++)
//	{
//		if (ch[i] >= 'a' && ch[i] <= 'z')
//			count++;
//	}
//
//	return count;
//}
//int main()
//{
//	char a[10] = { '0' };
//	gets(a);
//	int n = Fun(a[10]);
//	printf("%d\n", n);
//
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	char a[10] = { '0' };
//	int i = 0, count = 0;
//	gets(a);
//
//	for (i = 0; a[i] != '\0'; i++)
//	{
//		if (a[i] >= 'a' && a[i] <= 'z')
//			count++;
//	}
//	printf("%d\n", count);
//
//	return 0;
//}

//判断输入的字符串是否是“回文”
//
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int right = 0,left = 0;
//	char a[20], *p = a;
//	gets(a);
//	right = strlen(a) - 1;
//	while (right>left)
//	if (*(p + left) == *(p + right))
//	{
//		left++; right--;
//	}
//	else
//	{
//		printf("no\n");
//		return 0;
//	}
//	printf("yes\n");
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//void main()
//{
//	int k = 0;
//	char a[80], b[80], c[80] = { '\0' }, *p, *q;
//	p = a; q = b;
//	gets(a);
//	gets(b);
//	while (a[k] != '\0' || b[k] != '\0')
//	{
//		if (a[k] > b[k])
//			c[k] = *p;
//		else
//			c[k] = *q;
//		p++; q++; k++;
//	}
//	if (*p != '\0')
//		strcat(c, p);
//	else
//		strcat(c, q);
//	puts(c);
//}


//指针实现冒泡排序 
//
//#include<stdio.h>
//int main()
//{
//	int a[10] = { 0 };
//	int i = 0,j = 0,tmp=0;
//	int *p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for(i = 10; i < 10; i--)
//	{
//		for (j = 0; j < i&&p<a+9; j++)
//		{
//			if (*p>*(p++))
//			{
//				tmp = *p;
//				*p = *(p++);
//				*(p++) = tmp;
//			}
//		}
//	}
//	puts(a);
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int x = strlen("12345");
//	int y = sizeof("12345");
//	printf("x=%d,y=%d\n", x, y);
//	return 0;
//}


//#include<stdio.h>
//struct data
//{
//	int num;
//	char name[20];
//	int score[6];
//	int ave;
//}*p;
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++,p++)
//	{
//		scanf("%d %s", p->num, p->name);
//		for (j = 0, sum = 0; j < 6; j++)
//		{	
//			scanf("%d", &p->score[j]);
//			sum += p->score[j];
//		}
//		p->ave = sum / 6;
//	}
//
//
//}

//#include <stdio.h>
//#define N 3
//#define M 3
//main()
//{
//	int a[N][M], sum[N] = ;
//	double avg[N];
//	int i, j;
//	for (i = 0; i<N; i++)
//	{
//		printf("Input the %dth student's scores:", i + 1);
//		for (j = 0; j<M; j++)
//		{
//			scanf("%d", &a[i][j]);
//			sum[i] += a[i][j];
//		}
//		avg[i] = (double)sum[i] / M;
//	}
//	printf("The sums are:");
//	for (i = 0; i<N; i++)
//		printf("%4d", sum[i]);
//	printf("\nThe averages are:");
//	for (i = 0; i<N; i++)
//		printf("%6.2lf", avg[i]);
//	printf("\n");
//}



//#include<stdio.h>
//struct Date
//{
//	int year;
//	int month;
//	int day;
//};
//
//int main()
//{
//	struct Date p;
//	scanf("%d,%d,%d", &p.year, &p.month, &p.day);
//	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int sum, i;
//	sum = p.day;
//	for (i = 0; i<p.month - 1; i++)
//		sum += a[i];
//	if (((p.year % 4 == 0 && p.year % 100 != 0) || p.year % 400 == 0) && p.month>2)
//		printf("该日是在%d年中的第%d天", p.year, sum + 1);
//	else
//		printf("该日是在%d年中的第%d天", p.year, sum);
//}



#include <stdio.h>
typedef struct Complex
{
	double real;
	double imag;
}Complex;
Complex mul(Complex c1, Complex c2)
{
	Complex c3;
	c3.real = c1.real * c2.real - c1.imag * c2.imag;
	c3.imag = c1.imag * c2.real + c1.real * c2.imag;
	return c3;
}
Complex div(Complex c1, Complex c2)
{
	Complex c3;
	double u = c2.real * c2.real + c2.imag * c2.imag;
	c3.real = (c1.real * c2.real + c1.imag * c2.imag) / u;
	c3.imag = (c1.imag * c2.real - c1.real * c2.imag) / u;
	return c3;
}
void print(Complex c)
{
	printf("%lf+%lfi", c.real, c.imag);
}
int main()
{
	Complex c1 = { 5, 6 };
	Complex c2 = { 3, 4 };
	print(mul(c1, c2));
	printf("\n");
	print(div(c1, c2));
	printf("\n");
	return 0;
}
