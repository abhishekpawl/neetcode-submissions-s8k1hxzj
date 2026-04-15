class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26);
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            freq[t[i] - 'a']--;
        }
        for(int f: freq) {
            if(f != 0) return false;
        }
        return true;
    }
};
