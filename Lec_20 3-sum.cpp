#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm> // library for the function sort()
using namespace std;

vector<vector<int>> triplets_sum_to_target(vector<int> arr, int target,int * s)
{
    int i, j, k;
    set<vector<int>> st;
    int n = arr.size();
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; i < n; ++i)
        {
            for (k = j + 1; i < n; ++i)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    // for (auto x : st)
    // {
    //     for (int p = 0; p < x.size(); ++p)
    //     {
    //         cout << x[p] << ", ";
    //     }
    // }
    // s = st.size();
    return ans;
}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -2};
    int target = 0;
    int s;
    vector<vector<int>> ans = triplets_sum_to_target(arr, target,&s);
    int n = ans.size();
    for (int i = 0; i < n; ++i)
    {
        int m = ans[i].size();
        for (int j = 0; j < m; ++j)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}