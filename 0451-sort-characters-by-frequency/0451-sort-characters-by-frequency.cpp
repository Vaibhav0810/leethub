class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for (auto it:mp){
            pq.push({it.second,it.first}); // will be in descending order of freq
        }
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int freq=curr.first;
            while(freq>0){
                ans.push_back(curr.second);
                freq--;
            }
        }
        return ans;
    }
};