/*
*作者：fish
*日期：2020年 05月 26日 星期二 07:47:40 CST
*功能：
*附加说明：
*记录  ：
		 1. leetcode 67  二进制求和
		 2. 二进制 旋转为 十进制
		 3. 直接相加， 字符串是双冒号还是 单冒号
		 4. 要倒着来， 要转化为1
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
char * addBinary(char * a, char * b){
	int carry=0;
	int length = strlen(a)>=strlen(b) ? strlen(a)+2 : strlen(b)+2;
	char *c=(char *)malloc(sizeof(char)*length);
	printf("length %d \n",length);
    c[length-1] = '\0';
	int i=strlen(a)-1,j=strlen(b)-1,k=length-2;
	while( (i>=0)||(j>=0) ) 
	{
		int sum=carry;
		sum += (i >= 0 ? a[i--]-'0':0);
		sum += (j >= 0 ? b[j--]-'0':0);
		printf(" %d ",sum); 
		carry=sum/2;
		c[k--]='0'+sum%2;
	}
	printf(" \n "); 
	if(carry == 0)
	     return c+1;
	c[0]= '1';
	return c;
}
int main (void)
{
		char *a= "1010";
		char *b= "1011";
        char *c= addBinary( a,  b);
        int i=0;
		while(c[i] != '\0')
		{
				printf(" %c ",c[i++]); 
		} 
		printf("\n");
		return 0;
}
