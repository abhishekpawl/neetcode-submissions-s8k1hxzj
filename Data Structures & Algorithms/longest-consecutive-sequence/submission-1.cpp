class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionPair(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for(int x: nums) {
            parent[x] = x;
            size[x] = 1;
        }
        for(auto& it: size) {
            int x = it.first;
            if(size.count(x-1)) {
                unionPair(x-1, x);
            } else if(size.count(x+1)) {
                unionPair(x+1, x);
            }
        }
        int ans = 0;
        for(int x: nums) {
            int par = findParent(x);
            ans = max(ans, size[par]);
        }
        return ans;
    }
};
