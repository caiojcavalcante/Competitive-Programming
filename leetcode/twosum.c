#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* a = (int*) calloc(numsSize, sizeof(int));
    int* ans = (int*) malloc(2 * sizeof(int));

    for(int i = 0; i < numsSize; i++)
    {
        if(a[target - nums[i]])
        {
            ans[0] = a[target - nums[i]] - 1;
            ans[1] = i;
        }
        a[nums[i]]++;
    }
    *returnSize = 2;
    return ans;
}
int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize;
    int* ans = twoSum(nums, numsSize, target, &returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}