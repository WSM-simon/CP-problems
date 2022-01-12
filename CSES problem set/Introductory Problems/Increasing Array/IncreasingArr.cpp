#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    long long sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sum += arr[i] - arr[i + 1];
            arr[i + 1] = arr[i];
        }
    }

    cout << sum;
    return 0;
}