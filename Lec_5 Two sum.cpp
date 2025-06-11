#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main()
{
    vector<int> arr{2,6,5,8,11};
    int target = 14;
    map<int,int>mpp;int n=arr.size();
    for(int i=0;i<n;++i)
        mpp.insert({i,arr[i]});
    for(auto val : mpp)
        cout<<val.first<<":"<<val.second<<endl;
    int flag=0;
    for(int i=0;i<n;++i)
    {
        int more = target- arr[i];
        if(mpp.find(more)!=mpp.end())
        {
            cout<<"there is 2 values whch sums to target\n";
            flag++;
        }
    }
    if(flag==0) cout<<"None vaues found";
    return 0;
}