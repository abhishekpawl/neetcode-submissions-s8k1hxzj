class Solution {
public:
    bool dfs(string node, unordered_map<string, vector<string>>& adj, int num, vector<string>& ans) {
        ans.push_back(node);
        if(ans.size() == num + 1) {
            return true;
        }

        vector<string>& nei = adj[node];
        
        for(int i = 0; i < nei.size(); i++) {
            string stop = nei[i];
            nei.erase(nei.begin()+i);
            if(dfs(stop, adj, num, ans)) {
                return true;
            }
            nei.insert(nei.begin()+i, stop);
        }

        ans.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        vector<string> ans;
        int num = tickets.size();

        for(vector<string>& ticket: tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for(auto& it: adj) {
            sort(adj[it.first].begin(), adj[it.first].end());
        }

        dfs("JFK", adj, num, ans);

        return ans;
    }
};
