class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int>st;
        int n = heights.size();

        int largestRect = 0;

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];

                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }

                else{
                    width = i - st.top() - 1;
                }

                largestRect = max(largestRect, height * width);
            }
            st.push(i);
        }
        return largestRect;
    }
};