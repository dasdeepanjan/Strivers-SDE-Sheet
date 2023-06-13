class Solution {
public:

int merge(vector<int>& nums, int low,int mid, int high){

    int cnt=0;
    int j= mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && nums[i]>2LL*nums[j]){
            j++;
        }
        cnt+=j-(mid+1); 
    }

    vector<int> temp;
    int start=low, end=mid+1;
    while(start<=mid && end<=high){
        if(nums[start]<=nums[end]){
            temp.push_back(nums[start++]);
        }
        else{
            temp.push_back(nums[end++]);
        }
    }

    while(start<=mid){
        temp.push_back(nums[start++]);
    }

    while(end<=high){
        temp.push_back(nums[end++]);
    }

    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int>& nums, int low, int high){

    if(low>=high){
        return 0;
    }

    int mid=low+(high-low)/2;

    int inv= mergeSort(nums,low,mid);
    inv+= mergeSort(nums,mid+1,high);
    inv+= merge(nums,low,mid,high);
    return inv;
}

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums,0,nums.size()-1);
        
    }
};