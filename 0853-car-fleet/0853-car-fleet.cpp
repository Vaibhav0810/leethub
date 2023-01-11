class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0 || position.size()==1) return position.size();
        
        vector<pair<int,int>>car(position.size());
        for(int i=0;i<speed.size();i++){
            car[i]={position[i],speed[i]};
        }
        
        sort(car.rbegin(),car.rend());
        stack<double>st;
        for(auto it:car){
            
            double dist=target-it.first;
            double time=dist/it.second;
            
            if(st.empty()|| time>st.top()){
                st.push(time);
            }
        }
        return st.size();
        
        
    }
};