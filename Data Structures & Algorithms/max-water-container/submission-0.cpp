class Solution {
   public:
    int maxArea(vector<int>& h) {
        auto result = 0;
        for (auto i = 0, j = int(h.size()) - 1; i < j;) {
            auto current = (j - i) * min(h[i], h[j]);
            result = max(current, result);
            h[i] < h[j] ? ++i : --j;
        }
        return result;
    }
};
