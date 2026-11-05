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
        for (auto s : tokens) {
            if (isdigit(s.back())) {
                nums.push(stoi(s));
            } else {
                
                auto second = nums.top();
                nums.pop();
                auto first = nums.top();
                nums.pop();

                auto fn = ops.at(s);    
                auto res = (fn)(first, second);
                nums.push(res);
            }
        }
        return nums.top();
    }
};
