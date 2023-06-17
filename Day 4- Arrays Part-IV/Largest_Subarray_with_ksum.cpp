#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int xr=0;
    unordered_map<int,int> mp;
    mp[xr]++; //{0,1}

    int cnt=0;
    for(int i=0;i<arr.size();i++){
        xr^=arr[i];

        int k=xr^x;
        cnt+=mp[k];
        mp[xr]++;
    }

    return cnt;
}