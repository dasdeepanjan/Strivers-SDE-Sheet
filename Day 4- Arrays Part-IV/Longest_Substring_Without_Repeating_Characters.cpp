class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> mp(256,-1);
        int len=0;

        int left=0,right=0;

        while(right<s.size()){

            if(mp[s[right]]!=-1){
                left= max(left, mp[s[right]]+1);
            }

            mp[s[right]]=right;

            len=max(len,right-left+1);
            right++;
        }
        
        return len;
        
    }
};