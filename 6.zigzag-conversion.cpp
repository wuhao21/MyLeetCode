class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        int L = s.size();
        for (int i = 0; i < numRows; i++){
            int y = 2*i, x = (numRows-1-i)*2, curr = i;
            if (curr < L) res.push_back(s[curr]);
            while (x != 0 || y != 0){
                if (x != 0) {
                    curr += x;
                    if (curr >= L) break;
                    res.push_back(s[curr]);
                }
                if (y != 0) {
                    curr += y;
                    if (curr >= L) break;
                    res.push_back(s[curr]);
                }
            }
        }
        return res;
    }
};
