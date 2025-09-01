class Solution {
public:

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;

        auto calculateGain = [](int passes, int totalStudents) {
            return (double)(passes + 1) / (totalStudents + 1) -
                   (double)passes / totalStudents;
        };

        int n=classes.size();
        for(auto it:classes){
            pq.push({calculateGain(it[0],it[1]), {it[0],it[1]}});
        }

        while(extraStudents--){
            auto x=pq.top();
            pq.pop();
            int gain=x.first;
            int pass=x.second.first;
            int total=x.second.second;
            pq.push({calculateGain(pass+1,total+1),{pass+1,total+1}});
        }

        double ans=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            ans+= (double)x.second.first/x.second.second;
        }

        return ans/n;
    }
};