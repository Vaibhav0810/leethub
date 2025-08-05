class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& health, string directions) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater < pair < int, int >>> pq;
        vector<int> ans;

        for (int i = 0; i < positions.size(); i++) {
            pq.push({positions[i], i});
        }
        int countR=0;
        
        stack<pair<char,int>> st;
        while (!pq.empty() && st.size()<positions.size()) {
            int idx=pq.top().second;
            char dir=directions[pq.top().second];
            if(countR<=0 && dir=='L'){
                // ans.push_back(health[idx]);
                pq.pop();
            }
            else if (dir == 'R') {
                countR++;
                st.push({dir,idx});
                pq.pop();
            }
            else if(st.top().first=='R' && dir=='L'){
                
                if(health[idx]>health[st.top().second]){
                    health[st.top().second]=0;
                    health[idx]=health[idx]-1;
                    st.pop();
                    countR--;
                }
                else if(health[idx]<health[st.top().second] && health[idx]!=0){
                    health[st.top().second]-=1;
                    health[idx]=0;
                    pq.pop();
                }
                else{
                    health[st.top().second]=0;
                    health[idx]=0;
                    st.pop();
                    pq.pop();
                    countR--;
                }
            }
            
            
            
        }
        for(auto it:health){
            if(it!=0) ans.push_back(it);

        }
        return ans;
    }
};