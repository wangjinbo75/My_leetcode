/*
*作者：fish
*日期：2020年 05月 21日 星期四 20:53:42 CST
*功能：Merge sort
*附加说明：
*  了解递归，怎么运算 
*  但是这和Merge sort  关系呢？
*
2020年 05月 23日 星期六 10:51:22 CST
   letecode 88题 对于两个已经排好序的数组 倒车入库 太TM形象了
    我自己对于 合并排序 感觉 并没有完全 理解。

*/

#include<stdio.h>

void merge(int a[],int start,int mid,int end)
{
		int n1= mid -start+1;
		int n2= end -mid;
		int left[n1],right[n2];
		int i,j,k;
		for(i=0;i<n1;i++) 
				left[i]=a[start+i];
		for(j=0;j<n2;j++) 
				right[j]=a[mid+1+j];
		i=0;j=0;
		k=start;
		while(i<n1 && j<n2)
		{
				if(left[i]>right[j])
						a[k++]=right[j++];
				else
						a[k++]=left[i++];
		}
		while(i<n1)
				a[k++]=left[i++];
		while(i<n2)
				a[k++]=right[j++];
}
void merge_sort(int a[],int start ,int end)
{
		int mid;
		if(start<end)
		{
				mid =(start+end)/2;

				printf("mid = %d \n",mid);
				merge_sort(a,start,mid);
				merge_sort(a,mid+1,end);
				merge(a,start,mid,end);
				printf("merge (%d-%d, %d-%d) to \n",
								start, mid, mid+1, end);
				for(int i=0;i<=end;i++)
						printf("%d ",a[i]);
				printf("\n ");

		}	
}
int main (void)
{
	int Array[]={3,5,1,6,7,8,9,2};
	int a1[]={1,2,3,0,0,0};
	int a2[]={2,5,6};
	int a[6];
	int i=0,j=0,k=0;
	while(i<3 && j<3)
	{
			if(a1[i]<=a2[j])
			{
					a[k++]=a1[i++];
			}
			else 
			{
					a[k++]=a2[j++];
			}
	}
	while(j<3)
			a[k++]=a2[j++];
	printf("\n ");

	for(int i=0;i<6;i++)
			printf("%d ",a[i]);
	printf("\n ");
//	int nums1Size=3,nums2Size=3;
//	for(int i=0;i<nums2Size;i++)
//		a1[nums1Size+i]=a2[i];
//	for(int i=0;i<nums1Size+nums2Size;i++)
//			printf("%d ",a1[i]);
//	printf("\n ");
//	printf("Array sizeof = %ld \n", sizeof(Array)/sizeof(int) -1);
//	merge_sort(a1, 0, sizeof(a1)/sizeof(int)- 1 );
	return 0;

}
