#include<stdio.h>
#include<stdlib.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    
    int row=0;
    int col=0;
    int MatDat[matrixSize]; //定义行 标记
    int MatDatCol[*matrixColSize]; //定义 列标记
    //重新赋值
    for(row=0;row<matrixSize;row++)
       MatDat[row]=-1;  
    for(col=0;col<*matrixColSize;col++)
       MatDatCol[col]=-1;
    //行列标记
    for(row=0;row<matrixSize;row++)
    {
        for(col=0;col<*matrixColSize;col++)
        {  
           
            if(matrix[row][col] == 0)
            {
               MatDat[row]=row;
               MatDatCol[col]=col; 
            }
            printf("row =  %d, %d\n", row, MatDat[row]);
            printf("col =  %d, %d\n", col, MatDatCol[col]);
         }
    }
    //只是验证 两个值的不一样
    for(row=0;row<matrixSize;row++)
    {
        if(MatDat[row]==row)
        printf("row =  %d, %d\n", row, MatDat[row]);
        else
        {
             printf(" !!! row \n");
        }
        
    }
    for(col=0;col<*matrixColSize;col++)
    { 
        if(MatDatCol[col]==col)
        printf("col =  %d, %d\n", col, MatDatCol[col]);
        else
        {
              printf(" !!! col \n");
        }
              
    }
    //行列清零  列的问题
     printf(" \n");
    for(row=0;row<matrixSize;row++)
    {
        for(col=0;col<*matrixColSize;col++)
        { 
            
                  if(MatDat[row]==row)
                        matrix[row][col]=0;
                   if(MatDatCol[col]==col)
                        matrix[row][col]=0;  
                   printf("%d ",matrix[row][col]);         
        }
        printf(" \n");
    }
     
}

int main (void)
{
 
  int matrix[3][5] = {{-4,-2147483648,6,-7,0}, {-8,6,-8,-6,0}, {2147483648,-2147483648,-9,-6,10}};
  //用二级指针动态申请二维数组
  int row=3;
  int col=5;
    int **b = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++)
        b[i]=(int*) malloc(sizeof(int)*col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            b[i][j]=matrix[i][j];
            printf("%d ",b[i][j]);
        }
         printf(" \n");
    }
  int matrixSize=3;
  int matColSize=5;
  setZeroes( b, matrixSize, &matColSize);
 
 
 return 1;
}
