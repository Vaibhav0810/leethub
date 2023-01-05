class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0;
        int last=points[0][1];
        for(auto it:points){
            if(it[0]>last){
                ans++;
                last=it[1];
            }
            last=min(it[1],last);
        }
        return ans+1;
    }
};