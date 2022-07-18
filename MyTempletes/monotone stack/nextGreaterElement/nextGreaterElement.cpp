#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MxN = 1e5 + 3;
const int MxM = 1e5 + 3;

// 单调栈通常只用来解决一类问题，就是next greater element问题
vector<int> nextGreaterElement(vector<int> &nums) {
    vector<int> res(nums.size()); // 存放答案的数组
    stack<int> s;
    // 倒着往栈里放
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 判定个子高矮
        while (!s.empty() && s.top() <= nums[i]) {
            // 矮个起开，反正也被挡着了。。。
            s.pop();
        }
        // nums[i] 身后的 next great number
        res[i] = s.empty() ? -1 : s.top();
        //
        s.push(nums[i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {11, 4, 123, 4, 12, 34, 5, 1};
    vector<int> ans = nextGreaterElement(arr);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}
