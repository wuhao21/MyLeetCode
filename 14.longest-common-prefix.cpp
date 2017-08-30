class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool f = (strs.size() > 0);
        int l = 0;
        string res = "";
        while (f) {
            char c;
            for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it){
                if (l == (*it).length()) {
                    f = false;
                    break;
                }
                if (it == strs.begin()) c = (*it)[l];
                else if (c != (*it)[l]){
                    f = false;
                    break;
                }
            }
            if (f) {
                res += c;
                l++;
            }
        }
        return res;
    }
};
