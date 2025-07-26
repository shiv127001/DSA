#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;
class Solution
{
public:
    void nextPermutation_Optimal_approach_2(vector<int> &nums)
    {
        int i, index=-1, j;
        int nextlargest=10000;
        int n = nums.size();
        for (i = n - 1; i > 0; ++i)
        {
            j = i - 1;
            if (nums[j] < nums[i])
            {
                index = i;
                nextlargest = nums[i];
                break;
            }
        }
        if(index==-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int id2;
        for(i=index+1;i<n;++i)
        {
            if(abs(nums[index]-nums[i])<nextlargest)
            {
                id2 = i;
                nextlargest = abs(nums[index]-nums[i]);
            }
        }
        swap(nums[index], nums[id2]);
    }

    void nextPermutation_Optimal_approach_1(vector<int> &nums)
    {
        vector<int> num2 = nums;
        int i, nextlargest, index, index2, j;
        int n = nums.size();
        if (n == 1)
            return;
        j = n - 2;
        for (i = n - 1; i > 0; --i)
        {
            if (nums[j] < nums[i])
            {
                index = j;
                nextlargest = nums[i];

                int x = nums[j];
                for (int k = i; k < n; ++k)
                {
                    index2 = k;
                    if (nums[j] < nums[k])
                    {
                        if (nums[k] < nextlargest)
                        {
                            nextlargest = nums[k];
                            index2 = k;
                        }
                    }
                }
                swap(nums[index], nums[index2]);
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> arr = {3, 2, 1};
    Solution obj;
    obj.nextPermutation_Optimal_approach_2(arr);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}
