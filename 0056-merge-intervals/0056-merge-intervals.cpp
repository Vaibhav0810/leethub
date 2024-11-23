class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        if(ans.size()==0){
            ans.push_back(intervals[0]);
        }
        
        for(int i=1;i<intervals.size();i++){
            int s=intervals[i][0];
            int e= intervals[i][1];
            
            if(s<=ans[ans.size()-1][1]){
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],e);
            }
            else{
                ans.push_back({s,e});
            }
            
        }
        return ans;
        
    }
};