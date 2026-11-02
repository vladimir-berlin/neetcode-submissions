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

        auto [small, big] =
            nodes[val].second < nodes[neighbor].second ? pair{val, neighbor} : pair{neighbor, val};

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
        //print(nodes);
        return max_length;
    }

    void print(const unordered_map<int, pair<int, int>>& nodes) {
    // parent → дети, корни отдельно
    map<int, vector<int>> children;
    vector<int> roots;
    for (auto& [val, ps] : nodes) {
        if (ps.first == val) roots.push_back(val);
        else children[ps.first].push_back(val);
    }
    sort(roots.begin(), roots.end());
    for (auto& [_, v] : children) sort(v.begin(), v.end());

    // рекурсивный вывод поддерева с отступами
    auto dump = [&](auto&& self, int x, const string& prefix, bool last) -> void {
        cout << prefix << (last ? "└─ " : "├─ ") << x << '\n';
        auto it = children.find(x);
        if (it == children.end()) return;
        const auto& kids = it->second;
        for (size_t i = 0; i < kids.size(); ++i)
            self(self, kids[i], prefix + (last ? "   " : "│  "), i + 1 == kids.size());
    };

    for (int r : roots) {
        cout << "root " << r << " (size " << nodes.at(r).second << ")\n";
        auto it = children.find(r);
        if (it == children.end()) continue;
        const auto& kids = it->second;
        for (size_t i = 0; i < kids.size(); ++i)
            dump(dump, kids[i], "", i + 1 == kids.size());
    }
}
};
