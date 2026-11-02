class Solution {
   public:
    // array<unordered_set<char>, 9> bucket_rows, bucket_cols, boxes;
    array<uint16_t, 9> bucket_rows{}, bucket_cols{}, boxes{};

    static constexpr auto get_bit = [](char number) { return 1u << (number - '1'); };
    static constexpr auto get_box_index = [](auto row, auto col) { return row / 3 * 3 + col / 3; };

    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < board.size(); ++i)
            for (auto j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                uint16_t bit = get_bit(c);

                if ((bucket_rows[i] | bucket_cols[j]) & bit) return false;

                auto box_ids = get_box_index(i, j);
                if (boxes[box_ids] & bit) return false;

                bucket_rows[i] |= bit;
                bucket_cols[j] |= bit;
                boxes[box_ids] |= bit;
            }
        return true;
    }
};
