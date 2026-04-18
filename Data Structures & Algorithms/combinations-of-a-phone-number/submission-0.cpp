class Solution {
public:
    void solve(int ind, string& temp, string& s, vector<string>& ans, unordered_map<int, string>& mp) {
        if(ind == s.size()) {
            ans.push_back(temp);
            return;
        }
        int key = s[ind] - '0';
        for(int i = 0; i < mp[key].size(); i++) {
            temp.push_back(mp[key][i]);
            solve(ind+1, temp, s, ans, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;
        string temp;
        solve(0, temp, digits, ans, mp);
        return ans;
    }
};
