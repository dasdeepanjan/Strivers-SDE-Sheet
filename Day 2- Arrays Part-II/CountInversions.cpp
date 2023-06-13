#include <bits/stdc++.h> 

long long merge(long long *arr, int low,int mid, int high){

    long long cnt=0;
    int j= mid+1;

    vector<int> temp;
    int start=low, end=mid+1;
    while(start<=mid && end<=high){
        if(arr[start]<=arr[end]){
            temp.push_back(arr[start++]);
        }
        else{
            cnt+=mid-start+1;
            temp.push_back(arr[end++]);
        }
    }

    while(start<=mid){
        temp.push_back(arr[start++]);
    }

    while(end<=high){
        temp.push_back(arr[end++]);
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

long long mergeSort(long long *arr, int low, int high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}