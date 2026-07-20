class Solution:
    def findParent(self, node: int, parent: dict) -> int:
        if node != parent[node]:
            parent[node] = self.findParent(parent[node], parent)
        return parent[node]

    def unionPair(self, a: int, b: int, parent: dict, size: dict) -> None:
        ulp_a = self.findParent(a, parent)
        ulp_b = self.findParent(b, parent)
        if ulp_a == ulp_b:
            return
        if size[ulp_a] >= size[ulp_b]:
            parent[ulp_b] = ulp_a
            size[ulp_a] += size[ulp_b]
        else:
            parent[ulp_a] = ulp_b
            size[ulp_b] += size[ulp_a]

    def longestConsecutive(self, nums: List[int]) -> int:
        parent = {}
        size = {}
        for x in nums:
            parent[x] = x
            size[x] = 1
        for key, _ in size.items():
            if key + 1 in size:
                self.unionPair(key, key + 1, parent, size)
            if key - 1 in size:
                self.unionPair(key, key - 1, parent, size)
        ans = 0
        for key, par in parent.items():
            ans = max(ans, size[par])
        return ans