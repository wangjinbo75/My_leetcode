#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>
//  string作为类型使用是 c++中的，c语言中没有。，使用前bai要#include <string>,C里面用du的是C风格的字符zhi串
//  char * s1 = (char*) malloc(sizeof(char)* ); //不用malloc 开辟空间 太好了。
// string.h  里面有拷贝复制东西strle我觉得可以了
// 字符数组  char str0[row] = {"h","e","l","l","o"};
//
/*
寻找峰值
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞。  这想说明什么呢？
示例 1:
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
      或者返回索引 5， 其峰值元素为 6。
说明: 你的解法应该是 O(logN) 时间复杂度的。
*/
void printf_Array(int * nums,int numsSize,int left,int right)
{
    int mid = left +(right-left) /2 ;
    printf("| ");
    for(int i=0;i<numsSize;i++)
    {
        if(i< left)
        {    
              printf("    ");
        }
        else if(i >=left && i<=right)
        {
            if(i != mid) 
                    printf(" %2d ", nums[i]);
            else
                    printf(" %2d_", nums[i]);
        }
        else
            printf("    ");
    }
    printf("| \n");
}
int findPeakElement(int* nums, int numsSize){
     int  left  = 0;
     int  right = numsSize-1;
    // qsort(nums,numsSize, sizeof(int), comp);
   int index = 0;
    // 判断 是否 为空数组
      if( !nums || !numsSize)
           return -1;
    printf_Array(nums,numsSize,left,right);
    // 二分法
     while (left<right)
     {
         int mid = left +(right-left) /2 ;
         if(nums[mid] > nums[mid+1])
            right = mid;
         else
            left= mid+1;
        printf_Array(nums,numsSize,left,right);
     }
     return left;
   // return -1;
}
int main (void)
{
   // memset(str1, '\0', sizeof(str1));
   //strcpy(str1,matrix);
#if 0
   int nums[]={4,5,6,7,0,1,2};
   int numsSize =  sizeof(nums)/sizeof(nums[0]);
   int ret =  search(nums, numsSize, 6);
   for(int i=0;i<numsSize;i++)
   {
         printf(" %d ",nums[i]);
   }
   printf("\n");
   printf("ret=%d\n ",ret);

   printf("\n");
   int  ret1=mySqrt(2147395599);
   printf("mySqrt = %d\n",ret1);
#endif
   int nums[]={1,2,1,3,5,6,12,7,2,4,7,8,9,7,10,66};
   int numsSize =  sizeof(nums)/sizeof(nums[0]);
   int ret2 = findPeakElement(nums,numsSize);
   printf("ret2 = %d\n",ret2);
 

   return 1;
}
