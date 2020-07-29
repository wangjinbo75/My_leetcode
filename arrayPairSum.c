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
*/
int mymin(int a,int b){
    return (a>b?b:a);
}
int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int compare(const void *arg1, const void *arg2) {
    int a = *(int*)arg1;
    int b = *(int*)arg2;
    if (a > b) {
        return 1;
    }
    else if (a < b) {
        return -1;
    }
    else {
         return 0;
    }
}
int arrayPairSum(int* nums, int numsSize){
    int  MaxVal =0;
    qsort(nums,numsSize, sizeof(int), compare);
    for(int i=0;i<numsSize;i=i+2)
    {
        MaxVal=MaxVal+nums[i];
    }
    return  MaxVal;
}
int main (void)
{
    int nums[]={1,4,3,2};
    int len =sizeof(nums)/sizeof(nums[0]);
    
    int *nums1 = (int *)malloc(sizeof(nums));
    memset(nums1,0, len);
    for (int i=0;i<len;i++)
        nums1[i]=nums[i];
    for (int i=0;i<len;i++)
        printf(" %d ",nums1[i]);
    printf(" \n ");
    int MaxVal=arrayPairSum(nums1,len);
    for (int i=0;i<len;i++)
        printf(" %d ",nums1[i]);
    printf(" \n ");
    printf("MaxVal = %d \n",MaxVal);
   // memset(str1, '\0', sizeof(str1));
    //strcpy(str1,matrix);

  return 1;
}
