class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n < m) {
            vector <int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            swap(n,m);
        }
        int l = -1, r = n - 1, i, j;
        while (l < r) {
            i = (l+r) / 2;
            j = ((n+m+1) / 2) - 2 - i;
            if (j < -1) {
                r = i - 1;
                continue;
            }
            if (j >= m) {
                l = i + 1;
                continue;
            }
            if (i != -1 && j != m-1 && nums1[i] > nums2[j+1]) {
                r = i - 1;
                continue;
            }
            if (i != n-1 && j != -1 && nums2[j] > nums1[i+1]) {
                l = i + 1;
                continue;
            }
            break;
        }
        i = (l+r) / 2;
        j = ((n+m+1) / 2) - 2 - i;
        int lmax = 0, rmin = INT_MAX;
        if (i != -1) lmax = max(lmax, nums1[i]);
        if (j != -1) lmax = max(lmax, nums2[j]);
        if (i != n-1) rmin = min(rmin, nums1[i+1]);
        if (j != m-1) rmin = min(rmin, nums2[j+1]);
        if ((n+m)&1) return lmax;
        else return (lmax+rmin)/2.0;
    }
};