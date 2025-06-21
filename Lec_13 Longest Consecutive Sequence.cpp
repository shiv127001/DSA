#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 100, 101,103,104, 2, 1, 3, 3, 4, 101, 102};
    sort(arr.begin(), arr.end());
    int currcount = 0;
    int lastsmaller = -1;
    int longest = 1, n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        if (lastsmaller == arr[i] - 1)
        {
            currcount++;
            lastsmaller = arr[i];
        }
        else if (lastsmaller != arr[i])
        {
            currcount = 1;
            lastsmaller = arr[i];
        }
        // cout << "currcount : " << currcount << ", " << endl;
        // cout << "lastsmaller: " << lastsmaller << ", " << endl;
        longest = max(longest, currcount);
    }
    cout << "LCS : " << longest;
    return 0;
}