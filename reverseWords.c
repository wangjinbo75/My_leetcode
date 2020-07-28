#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//  string作为类型使用是 c++中的，c语言中没有。，使用前bai要#include <string>,C里面用du的是C风格的字符zhi串
//  char * s1 = (char*) malloc(sizeof(char)* ); //不用malloc 开辟空间 太好了。
/*
请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
1. 检验空格的位置
   是不是可以弄成 二维数组，倒序岂不是很简单
2. 标记单词 直接操作 S
这个时候有意思的是，
        先删除单词间隔之间多余的空格（难呀）
            再设一个字符串，这样的话，是不是
        倒序就可以完成（交换即可,这个之后 还是个大问题）
*/
char * reverseWords(char * s){
    //char *s1 ;
    
    //消除前面的空格
    while (*s == ' ')   { 
        s++; 
    }
    //剔除后面的空格
    int len =strlen(s)-1;
    if(len<0) return s;
    while (s[len] == ' ')
    {
        s[len] ='\0';
        len--;
    }
    printf("s =%s0 strlen = %d\n",s,strlen(s));
   int flag =0;
   int j=0;
    //去掉多余空格
    for(int i= 0;i<strlen(s);i++)
    {
        if(s[i] == ' ')
        {
            flag++;
            if(flag == 1 )
            {
                s[j++] =s[i];
            }
        }
        else
        {
            s[j++] =s[i];
            flag =0;
        }
    }
    s[j] ='\0';
    printf("s =%s0 strlen = %d\n",s,strlen(s));
    //倒序
    char start =0;
    char end=strlen(s)-1;
    int  k=0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i] ==' ')
        {
            start = i;
            //交换
            while (start<end)
            {
                char tmp=0;
                tmp=s[k];
                s[k++]=s[++start];
                s[start]=tmp;
            }
            s[k++]=' ';
            end=i;
            printf("end= %d\n",end);
        }
    }
    printf("s2 =%s0 strlen = %d\n",s,strlen(s));
    //倒序
    start = 0;
    k--;
    while (start<end)
    {
        char tmp=0;
        tmp = s[k];
        s[k++]=s[start];
        s[start++]=tmp;
    }
    s[k]='\0';
    printf("   return s2 =%s\n ",s);
    //*s1 = '\0';
return s;
}
void reverse(char *s, int start, int end) {
    char temp;
    while (start < end) {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

void trimSpace(char *s, int start) {
    // 将中间多余的空格移到最后，同时把字符串结束符\0向前搬一个
    do {
        s[start] = s[start+1];
        start++;
    } while (s[start]);  // 在字符串结束符停止
}

char * reverseWords2(char * s){
    // 1.消除前面多余空格
    while (*s == ' ') s++;
    // 2.消除后面的空格，且长度-1
    int len = strlen(s) - 1;
    if (len < 0) return s;
    while (s[len] == ' ') {
        s[len] = '\0';
        len--;
    }
    reverse(s, 0, len);  // 整体翻转

    // 3.消除中间多余空格并反转局部
    int i, idx = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {  // 遇到空格表示单词结束
            reverse(s, idx, i - 1);  // 注意区间[idx,i-1]是单词
            // 准备删除第二个空格
            while (s[i+1] && s[i+1] == ' ') {
                trimSpace(s, i + 1);
                len--;  // 修改字符数组长度
            }
            idx = i + 1;  // 最后idx移到新的单词开头这里
        }
    }
    // 处理最后单词
    reverse(s, idx, len);
    return s;
}


int main (void)
{
 // string s1="babad";
   char   s0[] = "a good   example";
   printf("s0= %s0\n ",s0); 
   char * s1 = s0;
   char * s2=reverseWords(s1);
   printf("   return =%s\n ",s2); 

  return 1;
}
