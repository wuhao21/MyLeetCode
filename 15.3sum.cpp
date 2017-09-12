class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map <int, int> h;
        set <vector<int> > res;
        vector<vector<int> > ans;
        int l = nums.size();
        for (int i = 0; i < l; i ++) 
            if (h.count(nums[i]) == 0) h[nums[i]] = 1;
            else h[nums[i]]++;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < l-2; i ++) {
                if (nums[i] > 0) break;
                h[nums[i]]--;
                for (int j = i+1; j < l-1; j++) {
                        h[nums[j]]--;
                        if (h.count(0-nums[i]-nums[j]) != 0 && h[0-nums[i]-nums[j]] != 0 && 0-nums[i]-nums[j]>=nums[j]) {
                            vector <int> tmp;
                            tmp.push_back(nums[i]);
                            tmp.push_back(nums[j]);
                            tmp.push_back(0-nums[i]-nums[j]);
                            res.insert(tmp);
                        }
                        h[nums[j]]++;
                        if (nums[j] == 0-nums[i]-nums[j]) break;
                    }
                h[nums[i]]++;
            }
        for (set <vector<int> >::iterator it = res.begin(); it != res.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};