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
/*
输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/
double myPow(double x, int n){
   if(n == 0) 
      return 1;
   if(x==1.0)
      return x;
   if(x==-1) 
      return n % 2 == 0 ? 1: -1;
   if(n == -2147483648)
      return 0;
   if(n<0)
        return 1 / myPow(x, -n);
   double res = 1;
   while(n)
   {
      if (n & 1 == 1)
      {
         res *= x;
         
      }
      x *= x;
      n >>= 1;
   }
   return res;
}
/*
* 找到 K 个最接近的元素
* 
*示例 1:
输入: [1,2,3,4,5], k=4, x=3
输出: [1,2,3,4]
示例 2:
输入: [1,2,3,4,5], k=4, x=-1
输出: [1,2,3,4]
*/
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
#if 0   
   int  left  = 0;
   int  right = arrSize-k;
   printf_Array(arr,arrSize,left,right+k);
   if(k==arrSize)
     return arr;
   if(1==arrSize)
 
     *returnSize =1;
     int* array = (int *)malloc(sizeof(int) );
     array[0] =arr[0];
     return array;
   }
      int flag= 10;
    while (left<right && flag--)
   {
      printf_Array(arr,arrSize,left,right);
      int mid = (right+left) /2 ;
      if( arr[mid+k]-x > x-arr[mid] )
         right = mid;
      else
         left= mid+1;
   }
   *returnSize =k;
   int* array = (int *)malloc(sizeof(int)*k);
   for(int i=0;i<k;i++)
   {
      array[i]=arr[left+i-1];
   }
   return array;
#endif
   *returnSize = k;
   int left = 0;
   int right = arrSize - 1;
   while (right - left >= k) {
      printf_Array(arr,arrSize,left,right);
      if (x * 2 <= arr[right] + arr[left]) {
            --right;
      } 
      else {
            ++left;
        }
   }
   return &arr[left];
}
/*
*
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
   int  left  = 0;
   int  right = numsSize-1;
   *returnSize =2;
   int* array = (int *)malloc(sizeof(int) * (2));
   array[0]=-1;
   array[1]=-1;
   if( !nums || !numsSize || target < nums[0] || target > nums[numsSize-1] )
      return array;
   if(numsSize == 1) 
   {
       int i=0;
      if(nums[0] != target)
         i=-1;
      array[0] = i;
      array[1] = i;
      return array;
   }
   printf_Array(nums,numsSize,left,right);
   // 二分法

   while (left<=right) 
   {
         int mid = (right+left) /2 ;
         if(nums[mid] > target)
            right = mid-1;
         else if(nums[mid] < target)
            left= mid+1;
         else 
         {  
            left =mid;
            right=mid;
            while ( left >=0 && nums[left--]==target)   
            {array[0]=left+1;}
            while ( right < numsSize && nums[right++]==target)
            {array[1]=right-1;} 
            printf_Array(nums,numsSize,array[0],array[1]);
            return array;
         }
         //if(nums[left] ==target && nums[right] == target)
         //break;
   }
   return array;
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
   int nums[]={-1,0,1,2,3,4,5,6};
   int numsSize =  sizeof(nums)/sizeof(nums[0]);
   //int ret2 = findPeakElement(nums,numsSize);
   //int ret2 = findMin(nums,numsSize);
   int returnSize=0;
   //int *target = searchRange(nums,numsSize,4, &returnSize);
   //int* ret3 =findClosestElements(nums,numsSize,4, 2, &returnSize);
   for (int i = 0; i < returnSize; i++)
   {
     // printf("ret3 = %d \n",ret3[i]);
      /* code */
   }
   double ret5 = myPow(2.0,-2147483648);
   printf("ret5 = %lf \n",ret5);
   //printf("ret2 = %d %d\n",target[0],target[1]);
 

   return 1;
}
