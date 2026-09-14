class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.begin());
        sort(nums2.begin(),nums2.begin());
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            int start = 0 , end = nums2.size() - 1;
            while(start <= end)
            {
                int mid = start + (end - start) / 2;
                if(nums2[mid] == nums1[i])
                    return nums1[i];
                else if(nums2[mid] > nums1[i])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};