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
//int* spiralOrder(int ** matrix, int matrixSize, int* matrixColSize, int* returnSize){
//
//    if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL)
//    {
//		*returnSize = 0;
//        return NULL;
//    }
//    int m = matrixSize;
//    int n =*matrixColSize;
//	*returnSize=m*n;
//    int *res=(int *)malloc(m*n*sizeof(int));
//    memset(res, 0, m*n*sizeof(int));
//    int k=0;
//    int i=0;
//    while(k<m*n)
//	{
//	    int y1=i;
//		while(y1<n-i && k<m*n)	
//		{
//			res[k++]=matrix[i][y1++];
//		}
//		int x1=i+1;
//		while(x1<m-i && k<m*n)
//		{
//			res[k++]=matrix[x1++][n-1-i];
//		}
//		y1-=2;
//		while(y1>=0 && k<m*n)
//		{
//			res[k++]=matrix[m-i-1][y1--];
//		}
//		x1-=2;
//		while(x1>=0 && k<m*n)
//		{
//			res[k++]=matrix[x1--][i];
//		}
//		i++;
//	}
//	*returnSize =k;
//	return res;
//}
int* find(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	printf("m=  n= "); 
    int m = matrixSize;
    int n = (*matrixColSize);
	*returnSize=m*n;
    int *res=(int *)malloc(m*n*sizeof(int));
    memset(res, 0, m*n*sizeof(int));
    
	//if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL)
    //{
	//	*returnSize = 0;
    //    return NULL;
    //}
    int i=0;
    int k=0;
    int x1,y1,x2,y2;
    while(i< m+n-1)
    {
        // 偶数行  0，2，4  方向下   m-1
        x1=(i<m)?i:m-1;
        y1=i-x1;
        while( x1 >= 0 && y1 <n)
        {
            res[k]=matrix[x1][y1];
			printf(" %d ",res[k]); 
			k++;
            x1--; 
            y1++;
        }
        i++;
        if(i>=n+m-1)
            break;
        // 奇数行 1，3，5  方向上 n-1
        y2=(i<n)?i:n-1;
        x2=i-y2;
        while( y2 >= 0 && x2 <m)
        {
            res[k]=matrix[x2][y2];
			printf(" %d ",res[k]);
			k++;
            y2--; 
            x2++;
        }
        i++;
    }
    return res;
}
int main (void)
{
        int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9} };
		int matrixColSize[]={3};
		int returnSize[1];
		int *reMat=find((int **)matrix,3,matrixColSize,returnSize);
//		for(int i= 0;i<returnSize[0];i++)
		{
//			printf(" %d ", reMat[i]); 
		} 
		printf("\n");
		return 0;
}
