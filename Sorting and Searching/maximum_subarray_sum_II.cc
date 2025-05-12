#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int low, high;
    cin >> low >> high;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int64_t> prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    vector<int64_t> max_sum(n + 1, 0);
    deque<int64_t> dq;
    int64_t maxSum = LLONG_MIN;
    for (int i = 1; i <= n; ++i)
    {
        int l = high - low;
        // Maintain window of size ≤ l
        while (!dq.empty() && dq.front() < i - l)
            dq.pop_front();

        // Add prefix[i - 1] as potential starting point
        while (!dq.empty() && prefix[dq.back()] >= prefix[i - 1])
            dq.pop_back();
        dq.push_back(i - 1);

        // Compute max sum ending at i - 1
        maxSum = max(maxSum, prefix[i] - prefix[dq.front()]);
        max_sum[i - 1] = maxSum;
    }

    int64_t ans = INT_MIN;

    for (int i = 0; i + low <= n; i++)
    {
        int64_t subarray_sum = prefix[i + low] - prefix[i];
        int64_t max_sum_before = i > 0 ? max_sum[i - 1] : 0;
        ans = max(ans, subarray_sum + max_sum_before);
        // cout << i << ' ' << subarray_sum << ' ' << max_sum_before << endl;
    }

    cout << ans << endl;
}
