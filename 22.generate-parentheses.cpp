class Solution {
private:
    vector<string> res;
    void generate_helper(int dep, int remain_left, int now_left, string s) {
        if (dep == 0) res.push_back(s);
        if (remain_left) generate_helper(dep-1, remain_left-1, now_left+1, s+'(');
        if (now_left) generate_helper(dep-1, remain_left, now_left-1, s+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        generate_helper(n*2, n, 0, "");
        return res;
    }
};