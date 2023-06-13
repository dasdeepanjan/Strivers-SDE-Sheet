class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int cnt1=0, cnt2=0, el1=0, el2=0;

        for(int i=0;i<nums.size();i++){

            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ls; // list of answers

        // Manually check if the stored elements in
        // el1 and el2 are the majority elements:
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size() ; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        int mini = int(nums.size() / 3) + 1;
        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini) ls.push_back(el2);

        if(el1==el2){
            ls.pop_back();
        }

        return ls;
        
    }
};