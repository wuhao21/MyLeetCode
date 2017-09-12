class Solution {
public:
    int myAtoi(string str) {
        long long res = 0, mul = 1;
        int i = 0;
        while (i < str.size() && str[i] == ' ') i++;
        if (str[i] == '-') {
            i++;
            mul = -1;
        } else if (str[i] == '+') i++;
        while (i < str.size()) {
            if (str[i] < '0' || str[i] > '9') break;
            res = res * 10 + (str[i]-'0');
            if (res*mul > INT_MAX) return INT_MAX;
            if (res*mul < INT_MIN) return INT_MIN;
            i++;
        }
        res *= mul;
        return (int)res;
    }
};