#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> num_set{nums.begin(), nums.end()};
        int res = 0;
        for (const int &num : num_set) {
            // find the begin of a sequence
            if (!num_set.count(num - 1)) {
                int curr_num = num;
                int cnt = 1;
                while (num_set.count(curr_num + 1)) {
                    curr_num++;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
    //    int longestConsecutive(vector<int> &nums) {
    //        int res;
    //        const int n = nums.size();
    //        if (n <= 1) return n;
    //        sort(nums.begin(), nums.end());
    //        int cnt = 1, p = 0;
    //        while (p < n - 1) {
    //            while (p < n - 1 && nums[p] == nums[p + 1]) p++;
    //            if (p >= n - 1) break;
    //            if (nums[p] + 1 == nums[p + 1]) {
    //                cnt++;
    //            } else {
    //                res = max(res, cnt);
    //                cnt = 1;
    //            }
    //            p++;
    //        }
    //        res = max(res, cnt);
    //        return res;
    //    }
};
//leetcode submit region end(Prohibit modification and deletion)

/**
 Resources:
 */

int main() {
    Solution s;
    vector<int> v{100, 1, 200, 2, 5, 3, 3, 4};
    auto res = s.longestConsecutive(v);
    cout << res << endl;
}