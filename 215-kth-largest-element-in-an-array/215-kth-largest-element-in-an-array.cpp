class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // brute O(Nlog n)
        
        
        // priority queue o(nlog k)
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int prv=0;
        
        if(k==1) return pq.top();
        
        while(k>0){
            prv=pq.top();
            pq.pop();
            
            
            k--;
        }
        return prv;
        
    }
};