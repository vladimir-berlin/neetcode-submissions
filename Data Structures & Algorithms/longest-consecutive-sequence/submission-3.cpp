class Solution {
   public:
    int find(const unordered_map<int, int>& parents, int x) {
        while (parents.at(x) != x) {
            x = parents.at(x);
        }
        return x;
    }

    int unite(unordered_map<int, int>& parents, unordered_map<int, int>& group_sizes, int val,
              int neighbor) {
        // If neighbor does not exists. case val - 1 ro val + 1
        if (!parents.contains(neighbor)) return 0;

        // Assuming val already inserted
        val = find(parents, val);
        neighbor = find(parents, neighbor);

        auto [small, big] =
            group_sizes[val] < group_sizes[neighbor] ? pair{val, neighbor} : pair{neighbor, val};

        auto val_size = group_sizes[val];
        auto neighbor_size = group_sizes[neighbor];

        parents[small] = big;

        return group_sizes[big] += group_sizes[small];
    }

    int longestConsecutive(vector<int>& nums) {
        // key: val
        // val: parent
        unordered_map<int, int> parents;

        // key: root of te group
        // size of the group
        unordered_map<int, int> group_sizes;

        int max_length = 0;

        for (auto val : nums) {
            if (parents.contains(val)) continue;

            parents[val] = val;
            group_sizes[val] = 1;
            max_length = max(max_length, 1);

            max_length = max(max_length, unite(parents, group_sizes, val, val - 1)),
            max_length = max(max_length, unite(parents, group_sizes, val, val + 1));
        }
        return max_length;
    }
};
