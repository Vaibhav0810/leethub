class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>ans;
        for(int i=0;i<logs.size();i++){
            ans.push_back({logs[i][0],1});
            ans.push_back({logs[i][1],-1});
        }
        
        sort(ans.begin(),ans.end());
        int year=0,fin=0,curr=0;
        for(int i=0;i<ans.size();i++){
            curr+=ans[i].second;
            if(curr>fin){
                year = ans[i].first;
            }
            fin=max(fin,curr);
            
        }
        return year;
        
    }
};