#define _CRT_SECURE_NO_DEPRECATE 1


#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target) {
	int *p = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize -1; i++){
		for (int j = i + 1; j < numsSize; j++){
			if (target == nums[i] + nums[j])
			{
				p[0] = i;
				p[1] = j;
				return p;
			}
		}
	}
	return NULL;
}


int main()
{

	int nums[] = { 2, 7, 11, 15 };
	int target = 9;
	int size = sizeof(nums) / sizeof(int);
	int* ret = twoSum(nums, size, target);
	return 0;
}
