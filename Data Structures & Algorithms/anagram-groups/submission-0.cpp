#include <unordered_map>
#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> result;
        for (auto word : strs) {
            auto key = word;
            ranges::sort(key);

            result[key].emplace_back(word);
        }
        return result | views::values | ranges::to<std::vector>();
    }
};
