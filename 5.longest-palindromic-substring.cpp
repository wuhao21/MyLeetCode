class Solution {
public:
    string longestPalindrome(string s) {
        int L = s.length(), reslen = 0, resl, resr;
        for (int i = 0; i < L; i++) {
            int l = i-1, r = i+1, len = 1;
            while (l >= 0 && r < L && s[l] == s[r]){
                len += 2;
                l--, r++;
            }
            if (len > reslen) {
                reslen = len;
                resl = l;
                resr = r;
            }
            l = i, r = i+1, len = 0;
            while (l >= 0 && r < L && s[l] == s[r]){
                len += 2;
                l--, r++;
            }
            if (len > reslen) {
                reslen = len;
                resl = l;
                resr = r;
            }
        }
        string res = "";
        for (int i = resl+1; i < resr; i++) res += s[i];
        return res;
    }
};
