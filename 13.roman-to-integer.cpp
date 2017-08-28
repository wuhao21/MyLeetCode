class Solution {
public:
    int romanToInt(string s) {
        int l = s.length(), curr = 0, sum = 0;
        int v[26];
        v['I'-'A'] = 1;
        v['V'-'A'] = 5;
        v['X'-'A'] = 10;
        v['L'-'A'] = 50;
        v['C'-'A'] = 100;
        v['D'-'A'] = 500;
        v['M'-'A'] = 1000;
        curr = v[s[0]-'A'];
        for (int i = 1; i < l; i++){
            if (s[i] == s[i-1])
                curr += v[s[i]-'A'];
            if (v[s[i]-'A'] > v[s[i-1]-'A']) {
                sum += v[s[i]-'A']-curr;
                curr = 0;
            }
            if (v[s[i]-'A'] < v[s[i-1]-'A']) {
                sum += curr;
                curr = v[s[i]-'A'];
            }
        }
        return sum + curr;
    }
};
