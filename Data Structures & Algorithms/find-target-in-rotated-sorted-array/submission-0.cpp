#include <ranges>

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        auto pivot = ranges::partition_point(nums, [&nums](int x) { return x >= nums[0]; });

        auto range = target >= nums[0] ? ranges::subrange(nums.begin(), pivot)
                                       : ranges::subrange(pivot, nums.end());

        auto found = ranges::lower_bound(range, target);

        return found != nums.end() && *found == target ? -distance(found, nums.begin()) : -1;
    }
};
