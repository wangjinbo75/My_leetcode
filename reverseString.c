/*
*作者：fish
*日期：2020年 05月 21日 星期四 20:53:42 CST
*功能：
*附加说明：
*记录  ：
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
// 应该更快的办法 如果真的需要排序 怎么办
// 这就很尴尬
//
// 首尾想加 向中间逼近
// 只需要遍历 size/2 ,存在奇，偶 数 情况 把奇偶 问题解决了
// 返回值 这可咋整？
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
		int *index =(int*)malloc(sizeof(int)*2);
		index[0]=-1;
		index[1]=-1;
		for(int i=0;i<numbersSize;i++)
		{
				for(int j=i+1;j<numbersSize;j++)
				{
						if( numbers[i]+numbers[numbersSize-j] == target)
						{
								index[0]= i;
								index[1]= numbersSize-1-i;
								*returnSize = 2;
								return index; 
						}
				}					
		}
		*returnSize =0;      
		return NULL;
}
int removeElement(int* nums, int numsSize, int val){
		if( numsSize == 0 || nums == NULL)
		{
			return 0;
		}	
		bool flag  = true;
		int tmp=0;
		for(int i=0;i<numsSize;i++)
		{
			        int j=i;
					while(j<numsSize && flag)
					{
					       j++;
					       if(nums[i]== val && nums[j] != val )
							{
									flag=  false;
									tmp = nums[j];
									nums[j]=nums[i];
									nums[i]=tmp;
							}
					}
					flag = true;
		}
		int i=0;
		while(i<numsSize)
		{
				if(nums[i] == val)
				{
                    nums[i+1]='\0';
					break;
				}
				i++;
		}
		return i;

}

void reverseString(char *s,int sSize)
{
        if(s == NULL || sSize == 0)
		{
		//	return NULL;
		}
        char tmp;
		for(int i=0;i<sSize/2;i++)
		{
			tmp = s[i];
			s[i]=s[sSize-1-i];
			s[sSize-1-i]=tmp;
		}
}

int minSubArrayLen(int s, int* nums, int numsSize){
		int  min_index=numsSize;
		int  flag_zero=false;
		int  i=0,j=0;
		int  sum=0;
		sum=nums[i];
		while(j<numsSize)
		{
				while(sum >= s)
				{
						flag_zero =true;
						if(min_index > (j-i+1))
								min_index = j-i+1;
						sum-=nums[i];
						i++;
				}
				j++;
				sum=(j<numsSize)?(nums[j]+sum):sum;
				printf("j = %d ",j);
		}
		if ( flag_zero == false )
				return 0;
		return min_index;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{ 
		if(nums == NULL || numsSize==0 || k > numsSize || k < 1 )
		{
				*returnSize =0;
				return NULL;
		}
		int  Max_i=(numsSize+1-k);
		int  * MaxValue = (int*)malloc(sizeof(int)*Max_i);
		int  flag_k= k;
		int  i=0;
		int  left=0;
		int  rigth =0;
		int  Min_index=0;
		#if 1
		while(left <(numsSize+1-k))
		{ 
				rigth = left+1;
				flag_k= k-1;
				MaxValue[i] = nums[left];
				printf("MaxValue= %d ",MaxValue[i]);
				while(rigth < numsSize && flag_k)
				{
						if(nums[rigth] >= MaxValue[i])
						{
								MaxValue[i] = nums[rigth];
								printf("MaxValue= %d ",MaxValue[i]);
						}
						rigth++;
						flag_k--;
				}
				printf(" MaxValue= %d  \n",MaxValue[i]);
				left++;
				i++;
		}
		#endif
        
		*returnSize = Max_i;
		return MaxValue;
}
int main (void)
{
		int NumsSize = get_int("sSize: ");
		int Nums[NumsSize];
		for(int i= 0;i<NumsSize;i++)
		{
		        Nums[i]=get_int("nums: ");
		}
		for(int i= 0;i<NumsSize;i++)
		{
				printf(" %d ",Nums[i]);
		}
		printf("\n");
#if 0
		int s = get_int("s: ");
		int min_index=minSubArrayLen(s,  Nums, NumsSize);     
		printf("min_index =  %d \n ", min_index);
#endif
		int k = get_int("k: ");
		int returnSize = 0 ;
		int *reMat =  maxSlidingWindow(Nums, NumsSize, k, &returnSize);
		for(int i= 0;i<returnSize;i++)
		{
				printf(" %d ",reMat[i]);
		}
		printf("\n");
				
//		string sStr  = get_string("string :");
//		printf(" %s \n",sStr);
//		printf("\n");
		//reverseString(sStr,NumsSize);
//		printf("\n");
		return 0;
}
