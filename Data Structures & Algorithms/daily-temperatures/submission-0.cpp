    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> hotter_weathers(temperatures.size(), 0);
            stack<int> max_temp;
            for (auto i = 0; i < temperatures.size(); ++i) {
                if (max_temp.empty() || temperatures[i] <= temperatures[max_temp.top()]) {
                    max_temp.push(i);
                } else {
                    while (!max_temp.empty() && temperatures[max_temp.top()] < temperatures[i]) {
                        
                        auto j = max_temp.top();
                        hotter_weathers[j] = i - j;
                        max_temp.pop();
                    }
                    max_temp.push(i);
                }
            }

            return hotter_weathers;
        }
    };
