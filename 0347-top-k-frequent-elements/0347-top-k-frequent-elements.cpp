class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // extreme brute force(tle)
        // unordered_map<int,int>mp1;
        // for(int i=0;i<nums.size();i++){
        //     mp1[nums[i]]++;
        // }
        // vector<int>ans;
        // int x=1e5;
        // while(x-- && k>0){
        //     for(auto it:mp1){
        //         if(it.second==x){
        //             k--;
        //             ans.push_back(it.first);
        //         }
        //     }
        // }
        // return ans;
        
        // little optimised O(Nlog k)
        // using mapp and priority queue
        
        unordered_map<int,int>mp1;
        for(auto it:nums) mp1[it]++;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        
        for(auto &it:mp1){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty() && k>0){
            int x=pq.top().second;
            ans.push_back(x);
            pq.pop();
            k--;
        }
        return ans;
    }
};