class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> h;
        vector <int> res;
        for (int i = 0; i < nums.size(); i++) h[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) 
            if (h.count(target - nums[i]) > 0 && h[target - nums[i]] > i){
                res.push_back(i);
                res.push_back(h[target - nums[i]]);
                return res;
            }
    }
};