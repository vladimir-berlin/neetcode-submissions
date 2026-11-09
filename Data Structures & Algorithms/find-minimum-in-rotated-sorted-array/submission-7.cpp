#include <ranges>
#include <span>

class Solution {
    void log(std::span<const int> s, const char* tag = "find_min") {
        std::cerr << tag << " [";
        for (size_t i = 0; i < s.size(); ++i) std::cerr << (i ? "," : "") << s[i];
        std::cerr << "] size=" << s.size() << " mid=" << s.size() / 2 << '\n';
    }

   public:
    int find_min(const span<int>& nums) {
        // log(nums);

        if (nums.front() <= nums.back()) return 0;       
        if (nums.size() == 2){
            return nums.front() < nums.back() ? 0 : 1; 
        }

        auto mid = nums.size() / 2;

        if (mid < 1) return mid;

        auto l = nums | ranges::views::take(mid);
        auto r = nums | ranges::views::drop(mid);

        auto result = (l.front() > l.back()) ? find_min(l) : mid + find_min(r);
        return result;
    }
    int findMin(vector<int>& nums) {
        auto i = find_min(nums);
        return nums[i];
    }
};
