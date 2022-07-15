#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

int N, M;

class Solution {
    stack<int> stk;
    vector<int> res, ans;

public:
    Solution() {
        ans.resize(MxN);
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums2[i] > stk.top())
                stk.pop();
            ans[nums2[i]] = (stk.empty() ? -1 : stk.top());
            stk.push(nums2[i]);
        }
        for (int i : nums1)
            res.push_back(ans[i]);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> a = {4, 1, 2}, b = {1, 3, 4, 2};
    for (int i : s.nextGreaterElement(a, b))
        cout << i << ' ';
    return 0;
}