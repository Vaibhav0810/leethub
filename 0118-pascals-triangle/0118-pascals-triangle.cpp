class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        int i =0 ;
        while(i<n){
            vector<int>check;
            if(i==0){
                check.push_back(1);
                ans.push_back(check);
            }
            else if(i==1){
                check.push_back(1);
                check.push_back(1);
                ans.push_back(check);
            }
            else{
                
                check.push_back(1);
                for(int a=1;a<ans[i-1].size();a++){
                    check.push_back(ans[i-1][a]+ans[i-1][a-1]);
                }
                check.push_back(1);
                ans.push_back(check);
            }
            i++;
        }
        return ans;
    }
};