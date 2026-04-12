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
        for(int i = pos; i < nums.size(); i++) {
            if(nums[i] > sum) continue;
            if(i > pos and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1, sum-nums[i], temp, nums, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, target, temp, candidates, ans);
        return ans;
    }
};
