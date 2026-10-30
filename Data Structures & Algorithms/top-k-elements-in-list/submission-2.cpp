#include <ranges>
class Solution {
    
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        cout << "start: " << k <<endl;
        // -1000 <= nums[i] <= 1000
        constexpr size_t k_num_range = 1000;

        // int max_freq = 0;
        std::vector<int> frequency(k_num_range * 2 + 1, 0);
        for (auto i : nums) {
            // max_freq = std::max(++frequency[i + k_num_range], max_freq);
            ++frequency[i + k_num_range];
        }

        
        vector<vector<int>> weighted_nums(frequency.size());

        for (auto val = 0; val < frequency.size(); ++val) {
            auto f = frequency[val];
            if (f == 0)
                continue; 
            weighted_nums[f].emplace_back(val - k_num_range);
        }

        vector<int> result;    
        result.reserve(k);
        for ( auto val : weighted_nums | views::reverse | views::join ){
            result.emplace_back(val);   
            if (result.size() >= k)
                break;     
        }
        
        return result;    

        
    }
};
