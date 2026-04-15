class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        stack = []
        wmax = 0
        for i in range(len(height)):
            while stack and height[i] >= height[stack[-1]]:
                mid = height[stack.pop()]
                if stack:
                    print(height[i], height[stack[-1]], mid, i, stack[-1])
                    curw = (min(height[i], height[stack[-1]])-mid) * (i - stack[-1] - 1)
                    wmax += curw
            stack.append(i)
        return wmax
