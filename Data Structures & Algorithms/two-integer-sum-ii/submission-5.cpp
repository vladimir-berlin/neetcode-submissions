class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            auto sum = numbers[left] + numbers[right];
            
            if (sum == target) return { ++left, ++right };
            
            sum < target ? ++left : --right;
        }
        return {};
    }
};
