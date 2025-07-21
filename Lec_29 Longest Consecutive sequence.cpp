#include <iostream>
#include <map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // header file for sort()
using namespace std;

bool linearsearch(vector<int> a,int x)
{
    int n = a.size();
    for(int i=0;i<n;++i)
    {
        if(a[i] == x) return true;
    }
    return false;
}

void LCS_Optimal(vector<int>arr,int n)
{
    if(n==0) return ;
    int longest = 1;
    unordered_set<int> st;
    for (int i=0;i<n;++i)
    {
        st.insert(arr[i]);
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt =1;
            int x = it;
            while(st.find(x+1)!=st.end())
            {
                cnt++;
                x++;

            }
            longest = max(longest,cnt);
        }
    }
    cout<<"LCS with optimal : " <<longest;
}

int main()
{
    vector<int> arr ={100,1,2,101,102,3,4,8,9,10,11,12,13,14};
    int counter = 1;
    int longest = 1;
    int i,j;
    int n = arr.size();
    for(i=0;i<n;++i)
    {
        int x =  arr[i];
        counter = 1;
        while(linearsearch(arr,x+1)==true)
        {
            counter++;
            x++;
        }
        longest = max(counter,longest);
    }
    cout<<"Longest consecutive sequence is : "<<longest;

    cout<<"\n ----\n Optimal approach :\n";
    LCS_Optimal(arr,n);

    return 0;

}