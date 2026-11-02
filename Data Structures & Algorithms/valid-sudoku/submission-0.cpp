class Solution {
   public:
    array<unordered_set<char>, 9> bucket_rows, bucket_cols, boxes;

    size_t get_box_index(size_t row, size_t col) { return row / 3 * 3 + col / 3; }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < board.size(); ++i)
            for (auto j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (!bucket_rows[i].emplace(c).second | !bucket_cols[j].emplace(c).second) {
                    return false;
                }

                auto box_ids = get_box_index(i, j);
                if (!boxes[box_ids].emplace(c).second) return false;
            }
        return true;
    }
};
