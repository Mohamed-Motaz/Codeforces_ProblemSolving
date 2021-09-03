class Solution {
public:
    int dp[100007];
    int solve(vector<int>& v, int idx){
        int &ans = dp[idx];
        if (ans != -1)
            return ans;
        ans = 0;
        ans = 1 + solve(v, v[idx]);
        return ans;
    }
    int arrayNesting(vector<int>& nums) {
        int mx = 0;
        memset(dp, -1, sizeof dp);
        for (auto e: nums){
            mx = max(mx, solve(nums, e));
        }
        cout << mx;
        return mx;
    }
};