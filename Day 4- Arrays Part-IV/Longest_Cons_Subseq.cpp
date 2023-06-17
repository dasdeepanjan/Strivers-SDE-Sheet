class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        if(n==0){
            return 0;
        }

        unordered_set<int> st;

        for(auto i: nums){
            st.insert(i);
        }

        int longest=1;
        for(auto it: st){
            int cnt=1;
            if(st.find(it-1)==st.end()){
                while(st.find(it+1)!=st.end()){
                    it+=1;
                    cnt+=1;
                }
            }
            longest=max(longest,cnt);
        }

        return longest;
        
    }
};