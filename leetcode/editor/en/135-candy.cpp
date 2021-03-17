#include<bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        if (n <= 1) return n;
        vector<int> candies(n, 1);
        //the first loop makes sure children with a higher rating get more candy than its left neighbor
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        //the second loop makes sure children with a higher rating get more candy than its right neighbor
        for (int i = n - 1; i > 0; --i)
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/**
 Resources:
 https://leetcode-cn.com/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/
 */
 
int main() {
    Solution s;
}