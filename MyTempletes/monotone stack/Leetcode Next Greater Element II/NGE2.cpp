// https://leetcode.cn/problems/next-greater-element-ii/
// 503. Next Greater Element II
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int sz = nums.size();
        vector<int> ans(sz);
        stack<int> stk;
        for (int i = 2 * sz + 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i % sz])
                stk.pop();
            ans[i % sz] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i % sz]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v1 = {1, 2, 1};
    Solution s;
    for (int v : s.nextGreaterElements(v1))
        cout << v << ' ';

    return 0;
}