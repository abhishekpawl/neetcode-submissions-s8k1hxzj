class Solution {
public:
    void solve(int pos, int sum, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) {
        if(sum == 0) {
            ans.push_back(temp);
            return;
        }
        if(pos == nums.size()) {
            return;
        }
        solve(pos+1, sum, temp, nums, ans);
        if(nums[pos] <= sum) {
            temp.push_back(nums[pos]);
            solve(pos, sum-nums[pos], temp, nums, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, target, temp, nums, ans);
        return ans;
    }
};
