class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int k = 0;
        for (int i = 1; i <= n && k < target.size(); i++) {
            result.push_back("Push");
            if (target[k] != i) {
                result.push_back("Pop");
                k = k - 1;
            }
            k++;
        }
        return result;
    }
};