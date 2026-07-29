class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int len=2;len<=n;len++){
            for(int l=0;l+len<=n;l++){
                int r=l+len;
                dp[l][r]=l+1+dp[l+1][r];
                for(int i=l+1;i<r;i++){
                    dp[l][r]=min(dp[l][r],i+1+max(dp[l][i],dp[i+1][r]));
                }
            }
        }
        return dp[0][n];
    }
};