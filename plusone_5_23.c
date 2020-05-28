/*
*作者：fish
*日期：2020年 05月 25日 星期一 08:57:06 CST
*功能：
*附加说明：
*记录  ：由整数组成的非空数组 在该数的基础上加一
*		1.先把整数组成的非空数组 变成整数  （几种特殊 999 ）这
*		2.会不会移位的方法呢？ 会更方便呢？
*		3.先合 ，加一， 再分 把数字分开 动感觉
*		4.为啥合 可以把直接加一 ,其不是更爽
*		逢9进1
*		malloc 这个很函数很迷 
*		(digitsSize+1)*sizeof(int) 也很迷
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cs50.h>
int * plusone(int *digits,int digitsSize,int *returnSize)
{
		int * nums =malloc( (digitsSize+1)*sizeof(int) );
		for(int i=digitsSize-1;i>=0;i--)
		{   
				if(digits[i] == 9 )
				{
						digits[i]=0;
				}
				else
				{
						digits[i]++;
						*returnSize=digitsSize;
						return digits;
				}
		}
		memset(nums,0, (digitsSize+1)*sizeof(int));
		nums[0]=1;
		*returnSize=digitsSize+1;
		return nums;
}
int main (void)
{
		int NumsSize = get_int("numsSize: ");
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
		int *returnSize;
		int *reSize;
        reSize =  plusone(Nums,NumsSize,returnSize);
		printf("reSize sizeof is %d \n", returnSize[0] ); 
		for(int i = 0;i<returnSize[0] ;i++)
		{
				printf(" %d ",reSize[i]); 
		} 
		printf("\n");
		return 0;
}
