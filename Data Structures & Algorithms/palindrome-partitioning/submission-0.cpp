class Solution {
public:
    bool check(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int ind, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if(ind == s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(check(s, ind, i)) {
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(!s.size()) return {{}};
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0, s, temp, ans);
        return ans;
    }
};
