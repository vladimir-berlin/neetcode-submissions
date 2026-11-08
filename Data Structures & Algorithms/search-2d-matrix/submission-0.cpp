#include <ranges>

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto found_row =
            ranges::upper_bound(matrix, target, {}, [](const auto& row) { return row.front(); });

        return found_row != matrix.begin() &&
               ranges::find(*(--found_row), target) != found_row->end();
    }
};
