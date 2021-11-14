
#include<bits/stdc++.h>
using namespace std;
unordered_map <int,int> mp;
vector<int> v;
int cansum(int sum,int arr[],int size)
{       
    
    if(sum==0)
    return 1;

    if(sum<0)
    return 0;

    if(mp.find(sum)!=mp.end())
    return mp[sum];
 
    int x=0;
    for(int i=0;i<size;i++)
    {   
        if(x==1)
        return 1;

        x=(x|cansum(sum-arr[i],arr,size));
        
    }
    mp[sum]=x;
    return x;
    
}
int main()
{
    int sum;
    cout<<"Enter sum : ";
    cin>>sum;
    int size;
    cout<<"Enter size : ";
    cin>>size;
    int arr[size];
    cout<<"Feed the array :\t";
    for(int i=0;i<size;i++)
    cin>>arr[i];
    
    if(cansum(sum,arr,size))
    cout<<"Sum Possible\n";
    else
    cout<<"Sum Not Possible\n";

    for(auto i:v)
    cout<<i<<" ";
}