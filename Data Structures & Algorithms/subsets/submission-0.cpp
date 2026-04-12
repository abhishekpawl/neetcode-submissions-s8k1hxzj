class Solution {
public:
    void solve(int pos, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for(int i = pos; i < nums.size(); i++) {
            if(i > pos && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1, temp, nums, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, temp, nums, ans);
        return ans;
    }
};
