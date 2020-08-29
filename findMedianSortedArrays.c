
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

// #define INT_MAX 2147483647
// #define INT_MIN (-INT_MAX - 1)

/**寻找两个正序数组的中位数
 *  这两种 思路都很好 
 */

 #define INT_MAX 2147483647
 #define INT_MIN (-INT_MAX - 1)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
		int n = nums1Size;
		int m = nums2Size;
		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2,m,nums1,n);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}

double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size,i,m=0,n=0;
    size = nums1Size + nums2Size;
    int num[size];
    for(i=0; i<size; i++){
        if(m<nums1Size && n<nums2Size){
            if(nums1[m]<nums2[n])
                num[i] = nums1[m++];
            else
                num[i] = nums2[n++];
        }
        else if(m<nums1Size)
            num[i] = nums1[m++];
        else
            num[i] = nums2[n++];
    }
    if(size%2 == 0){
        return ((double)num[size/2]+(double)num[size/2-1])/2;
    }
    else
        return (double)num[(size-1)/2];

}
int main(int argc, char *argv[])
{
	int nums1[] = { 2,3,5 };
	int nums2[] = { 1,4,7,9 };
    int nums1Size =  sizeof(nums1)/sizeof(nums1[0]);
    int nums2Size =  sizeof(nums2)/sizeof(nums2[0]);
	double ret = findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
    printf("ret = %f",ret);
	return 0;
}
