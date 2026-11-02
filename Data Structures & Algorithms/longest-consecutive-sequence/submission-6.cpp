class Solution {
   public:
    using Nodes = unordered_map<int, pair<int, int>>;

    // returns root of te group
    int find(const Nodes& nodes, int val) {
        while (nodes.at(val).first != val) {
            val = nodes.at(val).first;
        }
        return val;
    }

    int unite(Nodes& nodes, int val, int neighbor) {
        if (!nodes.contains(neighbor)) {
            return 0;
        }

        val = find(nodes, val);
        neighbor = find(nodes, neighbor);

        auto [small, big] = nodes[val].second < nodes[neighbor].second ? pair{val, neighbor}
                                                                           : pair{neighbor, val};

        nodes[small].first = big;
        return nodes[big].second += nodes[small].second;
    }

    int longestConsecutive(const vector<int>& nums) {
        Nodes nodes;
        nodes.reserve(nums.size());

        int max_length = 0;

        for (auto val : nums) {
            if (nodes.contains(val)) {
                continue;
            }

            nodes[val] = {val, 1};
            max_length = max(max_length, 1);
            max_length = max(max_length, unite(nodes, val, val - 1)),
            max_length = max(max_length, unite(nodes, val, val + 1));
        }
        return max_length;
    }
};
