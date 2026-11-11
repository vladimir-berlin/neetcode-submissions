#include <ranges>

class TimeMap {
   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        auto& timed_values = data_[key];
        if (!timed_values.empty() && timed_values.back().first >= timestamp) {
            throw invalid_argument("timestamp must be non-decreasing");
        }
        timed_values.emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (auto found = data_.find(key); found != data_.end()) {
            const auto& t_vals = found->second;
            auto it = ranges::upper_bound(t_vals, timestamp, {}, &TimedValue::first);

            if (it != t_vals.begin()) {
                return (--it)->second;
            }
        }
        return string();
    }

   private:
    using TimedValue = pair<int, string>;
    // using TimedVector<string>

    unordered_map<string, vector<TimedValue> > data_;
};
