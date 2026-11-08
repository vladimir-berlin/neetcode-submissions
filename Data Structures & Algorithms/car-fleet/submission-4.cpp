#include <ranges>
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        auto zipped = views::zip(position, speed);
        ranges::sort(zipped, greater{});

        auto result = 0;
        double last_tta = 0;
        for (auto [p, s] : zipped) {
            auto tta = (target - p) / double(s);

            if (last_tta < tta) {
                ++result;
                last_tta = tta;
            }
        }
        return result;
    }
};
