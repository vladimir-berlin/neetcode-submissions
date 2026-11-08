#include <ranges>
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        ranges::sort(views::zip(position, speed), greater{});

        auto result = 0 ;
        double last_tta = 0;
        for (auto [p, s] : views::zip(position, speed)) {
            auto tta = (target - p) / double(s);
            
            if (last_tta < tta) {
                ++result;
                last_tta = tta;
            }
        }
        return result;
    }
};
