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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	//初始化 二维指针
	int **res =(int**)malloc(sizeof(int*)*numRows);
	memset(res,0x00,sizeof(int*)*numRows);

	for(int i=0;i<numRows;i++)			 //算出有多少个元素
	{
		res[i]=(int*)malloc(sizeof(int)*(i+1));
		res[i][0]=1;
		res[i][i]=1;
		for(int j=1;j<i;j++)
		{
				res[i][j]=res[i-1][j-1]+res[i-1][j];
		}

	}
	*returnSize=numRows;
    *returnColumnSizes =(int *)malloc(numRows*sizeof(int));
	return res;
}

int* spiralOrder(int ** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL)
    {
		*returnSize = 0;
        return NULL;
    }
    int m = matrixSize;
    int n =*matrixColSize;
	*returnSize=m*n;
    int *res=(int *)malloc(m*n*sizeof(int));
    memset(res, 0, m*n*sizeof(int));
    int k=0;
    int i=0;
    while(k<m*n)
	{
	    int y1=i;
		while(y1<n-i && k<m*n)	
		{
			res[k++]=matrix[i][y1++];
		}
		int x1=i+1;
		while(x1<m-i && k<m*n)
		{
			res[k++]=matrix[x1++][n-1-i];
		}
		y1-=2;
		while(y1>=i && k<m*n)
		{
			res[k++]=matrix[m-i-1][y1--];
		}
		x1-=2;
		while(x1>i && k<m*n)
		{
			res[k++]=matrix[x1--][i];
		}
		i++;
	}
	*returnSize =k;
	return res;
}
int* findDiagonalOrder(int** matrix, int matrixSize, int *matrixColSize, int* returnSize){
   if (matrixSize == 0 || *matrixColSize == 0 || matrix == NULL)
   {
		*returnSize = 0;
       return NULL;
   }
    int m = matrixSize;
    int n = (*matrixColSize);
	*returnSize=m*n;
    int *res=(int *)malloc(m*n*sizeof(int));
    memset(res, 0, m*n*sizeof(int));
	printf("m=%d  n=%d  returnSize=%d\n",m,n,*returnSize);
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
        int matrix1[3][3]={{1,2,3},{4,5,6},{7,8,9} };
        //用数组指针形式 申请一个二维指针
		int (*a)[2]=(int(*)[2])malloc(sizeof(int)*3*2);
	    for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
			    a[i][j]=matrix1[i][j],
				printf("a = %p  %d \n",&a[i][j],a[i][j]);
			}
	    }
		printf("\n");
		//用二级指针动态申请二维数组
		int **b = (int**)malloc(sizeof(int*)*3);
	    for(int i=0;i<3;i++)
			b[i]=(int*) malloc(sizeof(int)*3);
	    for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
			    b[i][j]=matrix1[i][j],
				printf("b = %p  %d \n",&b[i][j],b[i][j]);
			}
	    }
		printf("\n");
	    // 计算机给的内存地质 不连续 ，方法可以，但是并不对   记得输入
	    int m[3][3]={{1,2,3},{4,5,6},{7,8,9} };
		int *Time=&m[0][0];

		///
		int matrixColSize=3;    
		int returnSize;
//		int *reMat=find(&Time,3,&matrixColSize,&returnSize);
		int *reMat=findDiagonalOrder(b,3,&matrixColSize,&returnSize);
		printf(" \n 1 \n");
		for(int i= 0;i<returnSize;i++)
		{
			printf(" %d ", reMat[i]); 
		} 
		printf(" \n 1 \n");
		int* reMat1= spiralOrder(b,3,&matrixColSize,&returnSize);
		printf(" \n 2 \n");
		for(int i= 0;i<returnSize;i++)
		{
			printf(" %d ", reMat1[i]); 
		} 
		printf(" \n 2 \n");
		int ** returnColumnSizes;
		int** S = generate(3, &returnSize, returnColumnSizes);

		free(b);	
	    for(int i=0;i<3;i++)
				free(b[i]);	
		return 0;
}
