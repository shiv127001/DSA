#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, int n, int k)
{
    int a = 0, b = 0;
    int sum = arr[0];
    int longest = 0;
    for (int i = 0; i < n; ++i)
    {
        while(a<b && sum>k)
        {
            sum-= arr[a];
            a++;
        }
        if(sum == k) {
            longest = max(longest,b-a+1);
        }
        b++;
        if(b<n){
            sum+=arr[b];
        }
    }
    return longest;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1,1};
    int k = 4, n = 7;
    int sumk = longestSubarrayWithSumK(arr, n, k);
    cout<<"Longest Sum = " << sumk;
    return 0;
}