class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         
         int i=0,j=1, n=nums.size();
         int k=0;

         while(j<n){
             if(nums[j]==nums[j-1]){
                 k++;
             }
             else{
                 nums[j-k]=nums[j];
             }
             j++;
         }

         return n-k;
        
    }
};