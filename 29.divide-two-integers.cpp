class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0|| (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if (dividend == 0) return 0;
        int res = 0, flag = 1;
        long long factor = 1, dend = dividend, dsor = divisor;
        if (dend < 0) dend = -dend, flag = -flag;
        if (dsor < 0) dsor = -dsor, flag = -flag;
        while (dsor<<1 <= dend) {
            dsor = dsor << 1;
            factor = factor << 1;
        }
        for (;factor; dsor = dsor >> 1, factor = factor >> 1) if (dend >= dsor) {
                dend -= dsor;
                res += factor;
                if (dend == 0) break;
        }
        return res*flag;
    }
};