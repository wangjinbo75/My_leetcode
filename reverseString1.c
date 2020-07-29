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

void reverseString(char* s, int sSize){
    if (sSize == 0 || s ==NULL )
           return ;
    char tmp = 0;
    for(int i=0;i<sSize/2 ;i++)
    {
        tmp = s[i];
        s[i] =s[sSize-1-i];
        s[sSize-1-i]=tmp;
    }
    printf("s = %s \n ",s);
}
int main (void)
{
    // string s1="babad";
    int row= 5;
    //char str0[][] = {"h","e","l","l","o"};reverseString
    char str0[] = {'h','e','l','l','o'};//reverseString
    char s[] = {'h','e','l','l','o'};//reverseString
    char * str1=str0;
   // memset(str1, '\0', sizeof(str1));
    //strcpy(str1,matrix);
    printf("str1 = %s\n",str1);
    reverseString(str1,row);
    int i=0,j=row-1;
    while(i<j){
        printf("s[i]= %c s[j]=%c \n ",s[i],s[j]);
        s[i] = s[i] ^ s[j];
        printf("s[i]= %c\n",s[i]);
        s[j] = s[i] ^ s[j];
        printf("s[j]= %c\n",s[j]);
        s[i] = s[i] ^ s[j];
        ++i,--j;
    }

  return 1;
}
