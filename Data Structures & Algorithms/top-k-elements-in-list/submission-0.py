class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        heap = []
        for x, cnt in freq.items():
            heapq.heappush(heap, [cnt, x])
            if len(heap) > k:
                heapq.heappop(heap)
        return [num for _, num in heap]
                