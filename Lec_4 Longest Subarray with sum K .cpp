#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

int longestSubarrayWithSumK_BRUTE_FORCE(vector<int> arr, int n, int k)
{
    cout<<"\n---BRUTE_FORCE---\n";
    int i, j;
    int longest = 0;
    for (i = 0; i < n; ++i)
    {
        int sum = 0;
        for (j = i; j < n; ++j)
        {
            sum += arr[j];
            if (sum == k)
                longest = max(longest, j - i + 1);
        }
    }
    return longest;
}

int longestSubarrayWithSumK_OPTIMAL(vector<int> arr, int n, int k)
{
    cout<<"\n---OPTIMAL ONE---\n";
    int i, longest = 0, sum = 0;
    unordered_map<int, int> mpp;
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum == k) longest = max(longest, i + 1);
        int remain = sum - k;
        if (mpp.find(remain) != mpp.end())
        {
            int len = i - mpp[remain];
            longest = max(longest, len);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }
    return longest;
}

int longestSubarrayWithSumK(vector<int> arr, int n, int k)
{
    int a = 0, b = 0;
    int sum = arr[0];
    int longest = 0;
    for (int i = 0; i < n; ++i)
    {
        while (a < b && sum > k)
        {
            sum -= arr[a];
            a++;
        }
        if (sum == k)
        {
            longest = max(longest, b - a + 1);
        }
        b++;
        if (b < n)
        {
            sum += arr[b];
        }
    }
    return longest;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    int k = 4, n = 7;
    int sumk_with_BRUTE_FORCE = longestSubarrayWithSumK_BRUTE_FORCE(arr, n, k);
    cout << "Longest Subarray length (BRUTE FORCE) = " << sumk_with_BRUTE_FORCE;
    int sumk_with_optimal = longestSubarrayWithSumK_OPTIMAL(arr, n, k);
    cout << "Longest Subarray length (OPTIMAL) = " << sumk_with_optimal;
    return 0;
}