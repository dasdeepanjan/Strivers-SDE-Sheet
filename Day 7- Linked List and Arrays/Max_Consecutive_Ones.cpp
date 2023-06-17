class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int i=0, n=nums.size();
        int maxCnt=0,cnt=0;

        while(i<n){
            if(nums[i]==1){
                maxCnt=max(maxCnt,++cnt);
            }
            else{
                cnt=0;
            }
            i++;
        }

        return maxCnt;
        
    }
};