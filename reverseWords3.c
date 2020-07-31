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
 翻转字符串的单词3 II
 为啥程序会少一个空格 呢？ 真是想不明白
*/
void swap(char*s ,int right,int left)
{
            while (left < right)
            {
                char  tmp=0;
                tmp =s[left];
                s[left++]=s[right];
                s[right--]=tmp;
            }
}
char * reverseWords(char * s){
    int left =0, right =0;
    int  len = strlen(s);
    for( int i=0 ;i<len;i++)
    {
        if (s[i] == ' ' || i==len-1)
        {
            right = (s[i] == ' ')?i-1:i;
            swap(s ,right,left);
            left=i+1;
        }
    }
  // printf("s=%s\n",s);
   return s;
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
   char   s0[] = "123 123 89";
   printf("s0= %s\n ",s0);
   char * s1 = s0;
   char * s2=reverseWords(s1);
   printf("s2=%s\n ",s2);
 
    return 1;
}
