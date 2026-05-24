class Solution {
    vector<int> size, parent;
public:
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void union_pair(int a, int b) {
        int ulp_a = findParent(a);
        int ulp_b = findParent(b);
        if(ulp_a == ulp_b) {
            return;
        }
        if(size[ulp_a] > size[ulp_b]) {
            parent[ulp_b] = ulp_a;
            size[ulp_a] += size[ulp_b];
        } else {
            parent[ulp_a] = ulp_b;
            size[ulp_b] += size[ulp_a];
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        size.resize(n, 1);
        parent.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(auto& edge: edges) {
            if(findParent(edge[0]) == findParent(edge[1])) return false;
            union_pair(edge[0], edge[1]);
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                root = findParent(i);
            } else {
                if(findParent(i) != root) {
                    return false;
                }
            }
        }
        return true;
    }
};
