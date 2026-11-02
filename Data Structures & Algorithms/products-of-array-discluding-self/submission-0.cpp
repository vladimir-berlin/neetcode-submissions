class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size(), 0);
        vector<int> zero_indexes;

        int m = 1;
        for(auto i = 0; i < nums.size(); ++i){
            if (!nums[i])
                zero_indexes.emplace_back(i);

            if (zero_indexes.size() >= 2){
                return result;
            }

            if (nums[i])
                m *= nums[i];
        }

        if(zero_indexes.size() == 1)
        {
            result[zero_indexes[0]] = m;
            return result;
        }
        
        for (auto i  = 0; i < nums.size(); ++i) {
            result[i] = m / nums[i]; 
        }
        return result;
    }
};
