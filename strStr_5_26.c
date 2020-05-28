/*
*作者：fish
*日期：2020年 05月 26日 星期二 15:54:30 CST
*功能：
*附加说明：
*记录  ：   leetcode strStr()
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
int strStr(char * haystack, char * needle){
		int index=0,i=0,j=0,k=0;
		int length1=strlen(haystack);
		int length2=strlen(needle);
		if(length2==0)
		{
			return 0;
		}
		printf(" length %d %d  \n",length1,length2);
		for( i=0;i<length1;i++)
		{
		        k=0;
				for(j=0;j<length2;j++)
				{
						if(haystack[j+i] != needle[j] )
						{
								k=1;
								break;
						}								
				}
				if (k==0)
				 return i;
		}
		return -1;
}
int main (void)
{
		string str1 = get_string("haystack: ");
		printf(" %s \n ",str1); 
		string str2 = get_string("needle: ");
		printf(" %s \n ",str2); 
		int index = strStr(str1,str2);
		printf("index %d\n ",index);
		return 0;
}
