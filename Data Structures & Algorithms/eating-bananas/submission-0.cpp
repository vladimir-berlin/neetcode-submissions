#include <ranges>

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        auto mid = [](int hi, int lo) { return (hi - lo) / 2 + lo; };
        auto time = [](vector<int>& piles, int eating_speed) {
            auto div = [](int p, int k) { return (p + k - 1) / k; };
            auto result = 0;
            for (auto p : piles) {
                result += div(p, eating_speed);
            }
            return result;
        };

        auto hi = ranges::max(piles);
        auto lo = 1;//ranges::min(piles);
        auto mi = mid(hi, lo);
        auto result = 0;

        while (lo < hi)
        {
            auto mi = mid(hi, lo);
            if (time(piles, mi) <= h)
                hi = mi;        // mi fits, try smaller
            else
                lo = mi + 1;   
        }

        return lo;
    }
};
