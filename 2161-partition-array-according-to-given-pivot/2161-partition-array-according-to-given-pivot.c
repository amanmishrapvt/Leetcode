/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma optimize("O3, unroll-loops")
static int* pivotArray(int* nums, int n, int pivot, int* returnSize) {
    *returnSize=n;
    if (n==1) return nums;
    int R[n];
    int l=0, r=0;
    for(int i=0; i<n; i++){
        const int x=nums[i];
        nums[l]=R[r]=x;
        l+=(x<pivot);
        r+=(x>pivot);
    }
    int m=n-r-l;
    for(int i=l; i<l+m; i++) nums[i]=pivot;
    for(int j=0; j<r; j++) nums[l+m+j]=R[j];
    return nums;
}