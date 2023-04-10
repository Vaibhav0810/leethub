class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(),stones.end());
        
        while(pq.size()!=0){
            if(pq.size()==1) return pq.top();
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            
            pq.push(first-second);
            
            
        }
        return 0;
        
    }
};