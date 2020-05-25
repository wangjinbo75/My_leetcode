/*
*作者：fish
*日期：2020年 05月 24日 星期日 08:04:46 CST
*功能：
*附加说明：
*记录  ：用法就是 一个数组里面的 肯定含有有一个 最大值 
        而这个最大值 是 其他值的二倍 关系
     第一种方法：朴实无华 
	   先找最大值和最大值索引值
	   再排除 最大值 和让 最大值与其他值进行比较
*/
#include<stdio.h>
#include<cs50.h>
int dominantIndex(int *nums,int numsSize)
{
		if(numsSize==1) 
				return 0; 
		int maxNum=0;
		int index=0;
		for(int i=0;i<numsSize;i++)
		{
				if(nums[i]>maxNum)
				{
						maxNum=nums[i];
						index=i;
				}
		}
		printf("maxNum =%d\n",maxNum);
		for(int i=0;i<numsSize;i++)
		{
			if(i != index && maxNum < nums[i]* 2)	
			{
						return -1;
			}
		}
		return index;
}
int main (void)
{
 int numsSize = get_int("numsSize ");
 int nums[numsSize];
 for(int i= 0;i<numsSize;i++)
 {
	int a = get_int("nums: ");
	nums[i]=a;
 }
 for(int i= 0;i<numsSize;i++)
 {
	printf(" %d ",nums[i]); 
 } 
 printf("\n");
 int index = dominantIndex(nums,numsSize);
 printf("index = %d\n",index);
 return 1;
}
