class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= heights.size(); ++i){
            while(!st.empty() and (i == heights.size() or heights[i] <= heights[st.top()] )){
                int topheight = heights[st.top()];
                st.pop();
                int width = (st.empty()) ? i : i - st.top()-1;
                maxArea = max(topheight * width, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};
