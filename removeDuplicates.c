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
 删除排序数组中的重复项
 为啥程序会少一个空格 呢？ 真是想不明白

 示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度5, 并且原数组nums的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
难点 在于：对于这个问题刨析
和就是 双遍历 可以解决
如果这个 两个元素相等 咋整呀？是要记录下相等 元素的位置
快速排序之后 //交换
其实不用排序也可以的
*/

int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int removeDuplicates(int* nums, int numsSize){
   if (!nums || !numsSize)
        return 0;
  qsort(nums,numsSize, sizeof(int), comp);
  int index=0;
  nums[index]=nums[0];
  for(int i=0; i<numsSize-1; i++)
  {
    if(nums[i] != nums[i+1])
    {
        index++;
        nums[index]=nums[i+1];
    }
  };
  return index+1;
}
int main (void)
{
   // memset(str1, '\0', sizeof(str1));
   //strcpy(str1,matrix);
   int nums[]={1,4,3,2,0,0,1,1,1,2,2,3,5,3,4};
   int len =sizeof(nums)/sizeof(nums[0]);
   int ret = removeDuplicates(nums,len);
   for(int i=0;i<len;i++)
   {
         printf(" %d ",nums[i]); 
   }
   printf("\n");
   printf("ret=%d\n ",ret); 
   return 1;
}
