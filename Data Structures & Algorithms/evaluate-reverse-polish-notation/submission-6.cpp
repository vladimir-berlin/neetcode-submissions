class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        // static const unordered_map<string, function<int(int, int)>> ops = {
        //     {"+", plus<>()},
        //     {"-", minus<>()},
        //     {"*", multiplies<>()},
        //     {"/", divides<>()},
        // };

        auto ops =
            [](const string& oper, int first, int second) {
                switch (oper[0]) {
                    case '-':
                        return first - second;
                    case '+':
                        return first + second;
                    case '*':
                        return first * second;
                    case '/':
                        return first / second;
                }
                return 0;
            };

        stack<int>
            nums;
        for (const auto& s : tokens) {
            if (isdigit(s.back())) {
                nums.push(stoi(s));
            } else {
                auto second = nums.top();
                nums.pop();
                auto first = nums.top();
                nums.pop();

                nums.push(ops(s, first, second));
            }
        }
        return nums.top();
    }
};
