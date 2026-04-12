class Solution {
public:
    void solve(vector<int>& temp, vector<bool>& used, vector<int>& nums, vector<vector<int>>& ans) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                solve(temp, used, nums, ans);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size());
        solve(temp, used, nums, ans);
        return ans;
    }
};
