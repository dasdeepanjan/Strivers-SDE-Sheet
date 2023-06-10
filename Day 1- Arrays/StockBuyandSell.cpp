class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minNo=prices[0];
        int maxProfit=0;

        for(auto i:prices){
            
            int profit=i-minNo;
            
            maxProfit = profit>maxProfit ? profit: maxProfit;

            minNo = minNo>i ? i: minNo;
            
        }

        return maxProfit;
    }
};