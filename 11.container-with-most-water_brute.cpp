class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, tmp;
        for (int i = 0; i < height.size() - 1; i++) {
            if (height[i] == 0 || res/height[i] >= height.size()-1-i) continue;
            for (int j = i + 1; j < height.size(); j++) {
                tmp = (j-i)*min(height[i], height[j]);
                res = tmp>res?tmp:res;
            }
        }
        return res;
    }
};
