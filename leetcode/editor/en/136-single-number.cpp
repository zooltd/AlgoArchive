#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    }
    //    int singleNumber(vector<int> &nums) {
    //        sort(nums.begin(), nums.end());
    //        for (int i = 0; i < nums.size() - 1; i += 2) {
    //            if (nums[i] != nums[i + 1]) return nums[i];
    //        }
    //        return *(nums.end() - 1);
    //    }
};
//leetcode submit region end(Prohibit modification and deletion)

/**
 Resources:
  a ^ b ^ c <=> a ^ c ^ b
  0 ^ n => n
  n ^ n => 0
  var a = [2,3,2,4,4]
  2 ^ 3 ^ 2 ^ 4 ^ 4 => (2 ^ 2) ^ (4 ^ 4) ^ 3 => 0 ^ 0 ^3 => 3
 */

int main() {
    Solution s;
    vector<int> v = {4, 1, 2, 1, 2};
    s.singleNumber(v);
}