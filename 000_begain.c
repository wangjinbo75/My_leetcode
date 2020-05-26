/*
*作者：fish
*日期：2020年 05月 21日 星期四 20:53:42 CST
*功能：
*附加说明：
*记录  ：
2020年 05月 23日 星期六 10:51:22 CST
1.  letecode 88题 对于两个已经排好序的数组 倒车入库 太TM形象了
2.  对于 合并排序 感觉 并没有完全 理解
3.  对于指针传参的概念 有点模糊
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
int main (void)
{
		int NumsSize = get_int("NumsSize: ");
		int Nums[NumsSize];
		for(int i= 0;i<NumsSize;i++)
		{
				int a = get_int("Nums: ");
				Nums[i]=a;
		}
		for(int i= 0;i<NumsSize;i++)
		{
				printf(" %d ",Nums[i]); 
		} 
		printf("\n");

		return 0;
}
