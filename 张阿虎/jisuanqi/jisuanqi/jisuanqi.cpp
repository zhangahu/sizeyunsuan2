// jisuanqi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "time.h"
#include "conio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;
void srand(unsigned int seed);
void getNumber(int &a,int &b,int &c,int &d)
{
	
	a=rand()%100;//生成一个100以内的随机整数
	b=rand()%100;
	c=rand()%100;
	d=rand()%100;
}
void getmode(int &mode1,int &mode2,int &mode3)
{
	mode1=rand()%4;//生成一个0-4之间的随机整数
	mode2=rand()%5;
	mode3=rand()%5;
}
void mode(int b,int m,int &i)
{
	switch(m)
		{
		case 0:
			printf("+");
			break;
		case 1:
			printf("-");
			break;
		case 2:
			printf("*");
			break;
		case 3:
			if(b==0)
			{
				i--;
				break;
			}
			printf("/");
			break;
		}
}
void yunsuan(int &r,int mo, int n1, int n2)
{
	switch(mo)
	{
	case 0:r=n1+n2;break;
	case 1:r=n1-n2;break;
	case 2:r=n1*n2;break;
	case 3:
		/*if(n2==0 || n1%n2!=0)
		{
			i--;
			break;
		}
		else*/
			r=n1/n2;
		break;
	}
}
void printfsuanshi(int &a,int &b,int &c,int &d,int &r,int &mode1,int &mode2,int &mode3,int &i)
{
	printf("%d",a);
	mode(b,mode1,i);
	printf("%d",b);
	if(mode2!=4)
	{
		mode(c,mode2,i);
	}
	else
	{
		printf("=\n");
		printf("答案：%d\n",r);
		return;
	}
	printf("%d",c);
	if(mode3!=4)
	{
		mode(d,mode3,i);
	}
	else
	{
		printf("=\n");
		printf("答案：%d\n",r);
		return;
	}
	printf("%d=\n",d);
	printf("答案：%d\n",r);
}
int _tmain(int argc, _TCHAR* argv[])
{	
	int n=0;//生成题目的个数
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int r=0;//答案
	int m;
	int mode1=0;//0 加，1  减，2  乘，3  除
	int mode2=0;//0 加，1  减，2  乘，3  除,4 无
	int mode3=0;//0 加，1  减，2  乘，3  除,4 无
	scanf("%d",&n); //输入生成题目的个数
	srand((int)time(NULL));//初始化随机数发生器，使得每次运行生成的随机数不同
	for(int i=0;i<n;i++)
	{
		getNumber(a,b,c,d);
		getmode(mode1,mode2,mode3);
		r=a;
		if(!(mode1==0 || mode1==1 || mode2==0 || mode2==1 || mode2==4))//1 1 (1 0 4)
		{
			if(mode1==3 && (b==0 || a%b!=0))
				{
					i--;
					goto part2;
				}
			yunsuan(r,mode1, a, b);
			if(mode2==3 && (c==0 || r%c!=0))
				{
					i--;
					goto part2;
				}
			yunsuan(r,mode2, r, c);
			if(mode3!=4)
			{
				if(mode3==3 && (d==0 || r%d!=0))
					{
						i--;
						goto part2;
					}
				yunsuan(r,mode3, r, d);
			}
		}
		if(!(mode1==0 || mode1==1 || mode2==2 || mode2==3 || mode2==4))//1 0 (1 0 4)
		{
			int c1=0;
			if(mode1==3 && (b==0 || a%b!=0))
				{
					i--;
					goto part2;
				}
			yunsuan(r,mode1, a, b);
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				if(mode3==3 && (d==0 || c%d!=0))
					{
						i--;
						goto part2;
					}
				yunsuan(c1,mode3, c, d);
				yunsuan(r,mode2, r, c1);
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				yunsuan(r,mode2, r, c);
				yunsuan(r,mode3, r, d);
			}
			else
			{
				yunsuan(r,mode2, r, c);
			}
		}
		if(!(mode1==2 || mode1==3|| mode2==0 || mode2==1|| mode2==4))//0 1 (1 0 4)
		{
			int c2=0;
			if(mode2==3 && (c==0 || b%c!=0))
			{
				i--;
				goto part2;
			}
			yunsuan(r,mode2, b, c);
			c2=r;
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				if(mode3==3 && (d==0 || c2%d!=0))
					{
						i--;
						goto part2;
					}
				yunsuan(r,mode3, c2, d);
				yunsuan(r,mode1, a,r);
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				yunsuan(r,mode1, a, r);
				yunsuan(r,mode3, r, d);
			}
			else
			{
				yunsuan(r,mode1, a, r);
			}

		}
		if(!(mode1==2 || mode1==3|| mode2==2 || mode2==3 || mode2==4))//0 0 (1 0 4)
		{
			int c3=0;
			int b1=0;
			if(!(mode3==4 || mode3==0 || mode3==1))
			{
				if(mode3==3 && (d==0 || c%d!=0))
				{
					i--;
					goto part2;
				}
				yunsuan(r,mode3, c, d);
				c3=r;
				yunsuan(r,mode1, a, b);
				yunsuan(r,mode2, r, c3);
			}
			else if(!(mode3==4 || mode3==2 || mode3==3))
			{
				yunsuan(r,mode1, a, b);
				yunsuan(r,mode2, r, c);
				yunsuan(r,mode3, r, d);
			}
			else
			{
				yunsuan(r,mode1, a, b);
				yunsuan(r,mode2, r, c);
			}
		}
		if(mode2==4)
		{
			if(mode1==3 && (b==0 || a%b!=0))
			{
				i--;
				goto part2;
			}
			yunsuan(r,mode1, a, b);
		}
		if(r<0)
		{
			i--;
			goto part2;
		}
		m=i+1;
		printf("%d.\n",m);
		printfsuanshi(a,b,c,d,r,mode1,mode2,mode3,i);
part2 :
		printf("");
	}
	return 0;
}