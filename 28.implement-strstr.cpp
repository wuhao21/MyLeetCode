class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int* next = new int[needle.size()];
        int res = -1, j = -1;
        next[0] = -1;
        for (int i = 1; i < needle.size(); i++) {
            while (j != -1 && needle[i] != needle[j+1]) j = next[j];
            if (needle[i] == needle[j+1]) j++;
            next[i] = j;
        }
        j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j != -1 && haystack[i] != needle[j+1]) j = next[j];
            if (haystack[i] == needle[j+1]) j++;
            if (j == needle.size()-1) {
                res = i-needle.size()+1;
                break;
            }
        }
        delete[] next;
        return res;
    }
};