#define _CRT_SECURE_NO_DEPRECATE 1
#include "stdio.h"
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double ret;
	if (nums1Size == 0 && nums2Size != 0){
		return ret = (double)(nums2[(nums2Size - 1) / 2] + nums2[nums2Size / 2]) / 2;
	}
	if (nums2Size == 0 && nums1Size != 0){
		return ret = (double)(nums1[(nums1Size - 1) / 2] + nums1[nums1Size / 2]) / 2;
	}

	int k = 0;
	int i = 0;
	int j = 0;
	int* nums = (int *)malloc(sizeof(int)*(nums1Size+nums2Size));
	int temp;
	for (k = 0; i < nums1Size && j < nums2Size && (k < (nums1Size + nums2Size)); k++){

		if (i < nums1Size && nums1[i] <= nums2[j]){
			temp = nums1[i];
			i++;
		}
		else{
			temp = nums2[j];
			j++;
		}
		nums[k] = temp;
	}
	if (i < nums1Size && j >= nums2Size){
		for (i; i < nums1Size; i++){
			nums[k++] = nums1[i];
		}
	}
	if (j < nums2Size && i >= nums1Size){
		for (j; j < nums2Size; j++){
			nums[k++] = nums2[j];
		}
	}

	return ret = (double)(nums[(k - 1) / 2] + nums[k / 2]) / 2;
}

int main()
{
	int nums1[] = {1,3};
	int nums2[] = {2};
	int size1 = sizeof(nums1) / sizeof(int);
	int size2 = sizeof(nums2) / sizeof(int);
	double ret = findMedianSortedArrays(nums1, size1, nums2, size2);
	printf("%1f\n", ret);
	return 0;
}