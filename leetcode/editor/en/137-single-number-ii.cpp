#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // x ^ 0 = x, x ^ x = 0
    // FSM:
    // Initiation                     : once = 0, twice = 0
    // First time the number x appears: once = x, twice = 0
    // Second time                    : once = 0, twice = x
    // Third time(Initiation)         : once = 0, twice = 0
    int singleNumber(vector<int> &nums) {
        int once = 0, twice = 0;
        for (auto x : nums) {
            once = (once ^ x) & (~twice);
            twice = (twice ^ x) & (~once);
        }
        return once;
    }
    //    int singleNumber(vector<int> &nums) {
    //        const int n = sizeof(int) * 8;
    //        int count[n] = {0};
    //        for (int num : nums) {
    //            for (int i = 0; i < n; ++i) {
    //                count[i] += (num >> i) & 1;
    //            }
    //        }
    //        int result = 0;
    //        for (int i = 0; i < n; i++) {
    //            count[i] %= 3;
    //            result += (count[i] << i);
    //        }
    //        return result;
    //    }
};
//leetcode submit region end(Prohibit modification and deletion)

/**
 Resources:
 1. 3×(a+b+c)−(a+a+a+b+b+b+c)=2c
 2. https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
 3. http://graphics.stanford.edu/~seander/bithacks.html#OperationCounting
 */

int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 2};
    auto res = s.singleNumber(nums);
    cout << res << endl;
}