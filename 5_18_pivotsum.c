#include<stdio.h>

int pivotIndex(int* nums, int numsSize){
  int sum=0;
  int leftsum=0;
  static int k=0;
  if(numsSize  %  2 != 0 )
  {
     printf("pivotIndex error \n ");
	return -1;
  }
  for(int i=0;i<numsSize;i++)
  {
        sum+=nums[i];
		printf("pivotIndex %d  %d \n ",i,sum);
  }
  for(int i=0;i<numsSize;i++)
  {
       leftsum+=nums[i];
	   if(leftsum*2 == sum)
		{ 
          printf("pivotIndex %d \n ",i);
		  return k=i; 

		}
  }
}

int main(void)
{ 
  int test_date[]={0,19,4,11,7,8,9,10};
  int test_date1[]={1,7,3,6,5,6};
  pivotIndex(test_date,8);
  return 0;
}
