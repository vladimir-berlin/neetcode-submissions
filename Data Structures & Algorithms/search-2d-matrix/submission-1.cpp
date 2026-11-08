#include <ranges>

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto found_row =
            ranges::upper_bound(matrix, target, {}, [](const auto& row) { return row.front(); });

        if (found_row != matrix.begin()) {
            --found_row;
            return ranges::find(*found_row, target) != found_row->end();
        }
        return false;
    }
};
