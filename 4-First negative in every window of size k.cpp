// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<ll> ans;
    deque<ll> dq;

    int i = 0;
    int j = 0;

    while (j < N)
    {
        if (A[j] < 0)
        {
            dq.push_back(A[j]);
        }

        if (j - i + 1 == K)
        {
            // checking window and filling negative number
            if (!dq.empty())
            {
                ans.push_back(dq.front());
            }
            else
            {
                ans.push_back(0);
            }

            // shifting window

            if (A[i] < 0 && !dq.empty())
            {
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
