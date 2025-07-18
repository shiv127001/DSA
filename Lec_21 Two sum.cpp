#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

void optimal_two_sum(vector<int> arr, int n, int target)
{
    int left = 0;
    int right = n - 1;
    sort(arr.begin(), arr.end());
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            cout << "there are two elements whose sum goes to target";
            return;
        }
        else if (arr[left] + arr[right] > target)
            right--;
        else if (arr[left] + arr[right] < target)
            left++;
    }
    cout << "There are no elements ";
}

void better_two_sum(vector<int> arr, int n, int target)
{
    map<int, int> mpp;
    int left;
    for (int i = 0; i < n; ++i)
    {
        int a = arr[i];
        left = target-a;
        if(mpp.find(left)!=mpp.end())
        {
            cout << "there are two elements whose sum goes to target";
            return;
        }
        mpp[a] = i;
    }
    cout << "There are no elements ";
}

int main()
{
    int userinput;
    cout << "Enter 1 for optimal approach or enter 2 for better appraoch : ";
    cin >> userinput;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    if (userinput == 1)
        optimal_two_sum(arr, n, target);
    if (userinput == 2)
        better_two_sum(arr, n, target);
    return 0;
}