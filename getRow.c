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
 杨辉三角 II
  1
  1  1
  1 2 1
  1 3 3 1
  1 4 6 4 1
  1 5  10  10 5 1
  我的第一个念头是 递归呢？ 真是奇怪了
  一定可以做成一个递归嵌套
  当前层，去计算上一层 ，这个思路没错  怎么能改造 成递归的 找到最小单位

*/

int* getRow(int rowIndex, int* returnSize){
    int* array = (int *)malloc(sizeof(int) * (rowIndex+1));
    for(int i=0; i<=rowIndex; i++){
        array[0] = 1;
        array[i]=1;
        for(int j=i-1; j>0; j--)
        {
            array[j] = array[j] + array[j-1];
        }
        for(int p=0;p<=i;p++)
            printf(" %d ",array[p]);
        printf(" \n ");
    }
    *returnSize = rowIndex + 1;
    return array;
}
/*
 i=0 array[0]=1; 继续加
 i=1 array[1]=1;
 i=2 arr[2]=1; a[1]=a[1]+a[0]=2;
现在的关键问题 不知道为啥这么做  这么做的原由是啥
*/
int main (void)
{
   // memset(str1, '\0', sizeof(str1));
    //strcpy(str1,matrix);
    int  rowIndex = 9;
    int  row=rowIndex+1;
    int  col=1;
    int* nums = getRow(rowIndex, &row);
    return 1;
}
