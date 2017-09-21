class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int j = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin();
        vector <int> res;
        if (i == j) {res.push_back(-1); res.push_back(-1);}
        else {res.push_back(i), res.push_back(j-1);}
        return res;
    }
};