class Solution {
public:

    vector<int> solve(int row){

        vector<int> temp;
        int element=1;
        temp.push_back(1);
        for(int col=1;col<row;col++){
            element*=(row-col);
            element/=col;
            temp.push_back(element);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};