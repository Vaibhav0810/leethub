class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // first solu
        
        // sort(nums.begin(),nums.end());
        
        // second solu
        
        //using priority queue
        
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};