#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//  string作为类型使用是 c++中的，c语言中没有。，使用前bai要#include <string>,C里面用du的是C风格的字符zhi串
//  char * s1 = (char*) malloc(sizeof(char)* ); //不用malloc 开辟空间 太好了。
char * longestPalindrome(char * s){
    int len =strlen(s);
     if(len < 2) return s;
    int flag=0, flag_i=0,flag_j=0;
    int max=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(s[i] == s[j])
            {
                flag = j-i;
                if(flag>max)
                {
                    flag_i =i;
                    flag_j =j;
                    max=flag;
                } 
            }
        }
    }
    max++;
    char * s1 = (char*) malloc(sizeof(char)*(max));
    for(int i=0;flag_i<=flag_j;flag_i++,i++)
    {
        s1[i] =s[flag_i];
    }
    printf("   return =%s \n ",s1); 
    return s1;
}
void help(char *s, int N, int left, int right, int *start, int *len) {
    while (left >= 0 && right < N && s[left] == s[right])
        left--, right++;
    if (right - left - 1 > *len) {  // 如果找到更长的子串，保存其信息
        *start = left + 1;
        *len = right - left - 1;
    }
}
char * longestPalindrome2(char * s){
    int N = strlen(s), start = 0, len = 0;  // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 0; i < N; i++)     // 奇数长度的回文子串
        help(s, N, i-1, i+1, &start, &len);
    for (int i = 0; i < N; i++)     // 偶数长度的回文子串
        help(s, N, i, i+1, &start, &len);
    s[start + len] = '\0';          // 原地修改返回
    return s + start;
}

char * longestPalindrome1(char * s){
    int N = strlen(s), start = 0, len = 0;  // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 1; i < N; i++) {   // 奇数长度的回文子串
        int  left = i - 1;
        int  right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right]){
            left--; right++;            // 以 i 为中心，向两侧延伸，直到不再满足回文
        }                               // left+1 ~ right-1 则为以i为中心的最大回文子串
        if (right - left - 1 > len) {   // 若更长，则保存该子串信息
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++) {   // 偶数长度的回文子串
        int left = i, right = i + 1;    // 以 i+0.5 为中心，向两侧延伸
        while (left >=0 && right < N && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0';      // 原地修改返回
    return s + start;
}

int main (void)
{
 // string s1="babad";
   char   s0[] = "cbbdbabad";
  printf("s0= %s \n ",s0); 
   char * s1 = s0;
   char * s2=longestPalindrome(s1);
   char * s3=longestPalindrome1(s1);
   printf("   return =%s \n ",s3); 

 return 1;
}
