class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 0) return 0;

        auto left_max = 0, right_max = 0, result = 0;

        for (auto i = 0, j = int(height.size()) - 1; i < j;) {
            left_max = max(left_max, height[i]);
            right_max = max(right_max, height[j]);

            if (left_max < right_max) {
                result += left_max - height[i];
                ++i;
            } else {
                result += right_max - height[j];
                --j;
            }
        }
        return result;
    }
};
