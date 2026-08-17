class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 1) return 1LL * nums[0] * nums[0];
        
        vector<int> preMin(n, nums[n-1]), preMax(n, nums[n-1]);
        
        for (int i = n-2; i >= 0; i--) {
            preMin[i] = min(preMin[i+1], nums[i]);
            preMax[i] = max(preMax[i+1], nums[i]);
        }

        long long ans = LLONG_MIN;
        
        for (int i = 0; i < n-m+1; i++) {
            if (nums[i] > 0) {
                ans = max(ans, 1LL * nums[i] * preMax[i+m-1]);
            } else {
                ans = max(ans, 1LL * nums[i] * preMin[i+m-1]);
            }
        }

        return ans;
        
    }
};