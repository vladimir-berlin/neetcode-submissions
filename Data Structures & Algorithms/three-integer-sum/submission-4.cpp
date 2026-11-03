class Solution {
   public:
    using Sums = vector<vector<int>>;

    Sums twoSum(const span<int> numbers, int target) {
        Sums result;
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            auto sum = numbers[left] + numbers[right];

            if (sum == target) {
                result.push_back({numbers[left], numbers[right]});
                ++left, --right;
                while (left < right && numbers[left] == numbers[left - 1]) {
                    ++left;
                }
                continue;
            }

            sum < target ? ++left : --right;
        }

        return result;
    }

    Sums threeSum(vector<int>& nums) {
        Sums result;
        if (nums.size() > 2) {
            ranges::sort(nums);

            for (auto i = 0; i < nums.size() - 2; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }

                auto target = -nums[i];
                auto subset = span(nums).subspan(i + 1);
                auto sum2 = twoSum(subset, target);

                for (auto sum : sum2) {
                    result.push_back({-target, sum[0], sum[1]});
                }
            }
            return result;
        }
    }
};
