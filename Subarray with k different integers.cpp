#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

int m2(vector<int> arr, int k)
{
    int l = 0, r = 0, n = arr.size(), cnt = 0;
    map<int, int> mpp;
    while (r < n)
    {
        mpp[arr[r]]++;
        while((int)mpp.size() > k)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    cout << "Number of subarray by m2 = " << cnt << endl;
    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4};
    int i, j, n = 5, k = 3, cnt = 0;

    for (i = 0; i < n; ++i)
    {
        set<int> st;
        for (j = i; j < n; ++j)
        {
            st.insert(arr[j]);
            if ((int)st.size() == k)
                cnt++;
            else if ((int)st.size() > k)
                break;
        }
    }
    cout << "Number of subarray by brute force = " << cnt << endl;
    int ans = m2(arr, k)-m2(arr, k-1);
    cout<<ans;
    return 0;
}