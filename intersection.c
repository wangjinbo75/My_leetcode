#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//  string作为类型使用是 c++中的，c语言中没有。，使用前bai要#include <string>,C里面用du的是C风格的字符zhi串
//  char * s1 = (char*) malloc(sizeof(char)* ); //不用malloc 开辟空间 太好了。
// string.h  里面有拷贝复制东西strle我觉得可以了
// 字符数组  char str0[row] = {"h","e","l","l","o"};
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 两个数组的交集
 * 示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]

 */
// 比较函数的 大于号 还有学问
int comp(const void*a,const void*b){
    return *(int*)a > *(int*)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(!nums1Size || !nums1Size) {
        *returnSize = 0;
        return 0;
    }
    //排序完
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);
    
    int *ans = (int *) malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int count = 0;
    for(int i=0,j=0;i<nums1Size&&j<nums2Size;)
    {
        if(nums1[i] >nums2[j])
        {
            j++;
        }
        else if (nums1[i] <nums2[j])
        {
            i++;
        }
        else
        {
            ans[count++] =nums1[i];
            i++;
            j++;
            if (count > 1 && ans[count-1] == ans[count-2])
                --count;
        }
    }
    ans = (int *)realloc(ans, count * sizeof(int));
    *returnSize = count;
    return ans; 
}
int main (void)
{
   //memset(str1, '\0', sizeof(str1));
   //strcpy(str1,matrix);
   //[-2147483648,1,2,3]
//[1,-2147483648,-2147483648]
   int nums1[] = {-2147483648,1,2,3};
   int nums2[] = {1,-2147483648,-2147483648};
   int nums1Size=sizeof(nums1)/sizeof(nums1[0]);
   int nums2Size=sizeof(nums2)/sizeof(nums2[0]);
   int returnSize;
   int *ans = intersection( nums1,  nums1Size, nums2, nums2Size, &returnSize);
   int ansSize = sizeof(ans)/sizeof(ans[0]);
   for(int i=0;i<returnSize;i++)
   {
       printf("%d \n",ans[i]);
   }
   printf("\n");
   //char * s1 = s0;
   //char * s2=reverseWords(s1);
   //printf("s2=%s\n",s2);
    return 1;
}
