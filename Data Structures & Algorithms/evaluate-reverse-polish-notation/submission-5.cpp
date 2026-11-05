class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        static const unordered_map<string, function<int(int, int)>> ops = {
            {"+", plus<>()},
            {"-", minus<>()},
            {"*", multiplies<>()},
            {"/", divides<>()},
        };

        stack<int> nums;
        for (const auto& s : tokens) {
            if (isdigit(s.back())) {
                nums.push(stoi(s));
            } else {
                auto second = nums.top();
                nums.pop();
                auto first = nums.top();
                nums.pop();

                auto res = ops.at(s)(first, second);
                nums.push(res);
            }
        }
        return nums.top();
    }
};
