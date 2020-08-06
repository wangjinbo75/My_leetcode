#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//  string作为类型使用是 c++中的，c语言中没有。，使用前bai要#include <string>,C里面用du的是C风格的字符zhi串
//  char * s1 = (char*) malloc(sizeof(char)* ); //不用malloc 开辟空间 太好了。
// string.h  里面有拷贝复制东西strle我觉得可以了
// 字符数组  char str0[row] = {"h","e","l","l","o"};
//
/*
二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

开平方
 二分查找
 16 
 0 16 
*/
int mySqrt(int x){
  int left  = 1;
   int right = x/2+1;
   while (left<=right)
   {
      int mid = left+(right-left)/2;
      if (mid == x/mid)
         return mid;
      if(mid > x/mid )
      {
         right = mid-1;
      }
      else
      {
         left= mid+1;
      }
   }
   return  right;
}
int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int search(int* nums, int numsSize, int target){
     int  left  = 0;
     int  right = numsSize-1;
    // qsort(nums,numsSize, sizeof(int), comp);
   int index = 0;
    // 判断 是否 为空数组
    if( !nums || !numsSize)
           return -1;
   // 寻找 旋转点
    for (int i = 0; i < numsSize-1; i++)
    {
        if(nums[i+1] < nums[i])
        {
            index = i+1;
            break;
        }
    }
    //分为两段
    if( target >= nums[index]  &&  nums[numsSize-1] >=target)
            left = index;
    else
            right =index-1;
     //printf("left %d right  %d \n",left,right);
    // 二分法
     while (left<right)
     {
         int mid = left +(right-left) /2 ;

         if(nums[mid] == target)
            return mid;
         else if(nums[mid] > target)
            right = mid-1;
         else
            left= mid+1;
     }
    if(nums[left]==target) return left;
    return -1;
}
int main (void)
{
   // memset(str1, '\0', sizeof(str1));
   //strcpy(str1,matrix);
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
    printf("mySqrt = %d",ret1);
   return 1;
}
