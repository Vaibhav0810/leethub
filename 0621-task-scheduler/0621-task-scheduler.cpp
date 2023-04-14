class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int>pq;
        unordered_map<char,int>mp;
        
        
        for(auto it:tasks){
            mp[it]++;
        }
        
        for(auto it:mp){
            pq.push(it.second);
        }
        int time=0;
        while(pq.size()!=0){
            vector<int>v;

            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                v.push_back(pq.top());
                pq.pop();
                }
            }

            
            for(int i=0;i<v.size();i++){
                if(--v[i]>0) pq.push(v[i]);
            }
            
            time+=pq.empty() ? v.size() : n+1;
            
        }
        return time;
    }
};