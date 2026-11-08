class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        auto result = 0;
        stack<int> growing_index;

        heights.emplace_back(0);
        
        for (auto i = 0; i < heights.size(); ++i) {

            while (!growing_index.empty() && heights[growing_index.top()] > heights[i]) {
                
                auto top = growing_index.top();
                growing_index.pop();

                auto width = growing_index.empty() ? i : i - growing_index.top() - 1;
                auto area = width * heights[top];

                result = max(area, result);
                // cout << "result: " << result << ", i:" << i << ", top: "<<  top << endl;
                
            }
            growing_index.push(i);
        }
        return result;
    }
};
