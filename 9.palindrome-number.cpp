class Solution {
public:
    bool isPalindrome(int x){ 
        if (x < 0) return 0;
        long long res = 0, X = x;
        while (x){
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX)?0:(res==X);
    }
};
