#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        const int total = m + n;

        // trick:
        // ans(m+n)==odd/even => medium = (m+n+1) / 2 + (m+n+2) / 2
        // return find_kth(nums1.begin(), m, nums2.begin(), n, (total + 1) / 2) + find_kth(nums1.begin(), m, nums2.begin(), n, (total + 2) / 2);

        // odd
        if (total & 0x1)
            return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
        // even
        else
            return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }

    double find_kth(const vector<int> &nums1, int i, const vector<int> &nums2, int j, int k) {
        if (i >= nums1.size())
            return nums2[j + k - 1];//nums1为空数组
        if (j >= nums2.size())
            return nums1[i + k - 1];//nums2为空数组
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int mid_val1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int mid_val2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (mid_val1 < mid_val2)
            return find_kth(nums1, i + k / 2, nums2, j, k - k / 2);
        else
            return find_kth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/**
 Resources:
 https://leetcode-cn.com/problems/median-of-two-sorted-arrays/comments/36497
 */

int main() {
    Solution s;
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    auto res = s.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}