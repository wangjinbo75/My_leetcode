/*
*作者：fish
*日期：2020年 05月 21日 星期四 20:53:42 CST
*功能：
*附加说明：
*记录  ：
*/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
		int index=0;
		int flag=0;
		char *ans=strs[0];
		for(int j=0;j<strlen(strs[0]);j++)
		{
				for(int i=1;i<strsSize;i++)
				{
						if(strs[0][j] != strs[i][j])
						{
								printf("break\n");
								ans[j]='\0';
								flag=1;
								break;
						}
				}
				if(flag==1) 
						break;
				index++;
				printf("index = %d\n",index);
		}
		if(index ==0)
		   return "";
//		char * returnPrefix=malloc(sizeof(char)*index);
//		printf("index = %d\n",index);
//		memcpy(returnPrefix,strs[0],index);
		return ans;
}

int main (void)
{
        int Size=get_int("numsSize:");
		char *str[Size];
		for(int i=0;i<Size;i++)
		{
			string s=get_string("str:");
            str[i]=(char *)s;
		}
		char *reStr=longestCommonPrefix(str,Size);	
		for(int i= 0;i<strlen(reStr);i++)
		{
				printf(" %c ",reStr[i]); 
		} 
		printf("\n");
		return 0;
}
