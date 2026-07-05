class Solution {
public:
    typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(auto& time: times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> res(n+1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> minheap;

        res[k] = 0;
        minheap.push({res[k], k});

        while(!minheap.empty()) {
            auto [cost, node] = minheap.top();
            minheap.pop();

            if(cost > res[node]) {
                continue;
            }

            for(auto& [nei, c]: adj[node]) {
                if(cost + c < res[nei]) {
                    res[nei] = cost + c;
                    minheap.push({res[nei], nei});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i < n+1; i++) {
            ans = max(ans, res[i]);
        }

        if(ans == INT_MAX) return -1;

        return ans;
    }
};
