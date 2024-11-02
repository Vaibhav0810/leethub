class Solution {
public:
    void setZeroes(vector<vector<int>>& n) {
        vector<pair<int,pair<int,int>>> vp;
        
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n[0].size();j++){
                vp.push_back({n[i][j],{i,j}});
            }
        }
        // for(auto it:vp){
        //     cout<<it.first;
        //     cout<<it.second.first;
        //     cout<<it.second.second;
        //     cout<<" ";
        // }
        int count=0;
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n[0].size();j++){
                if(vp[count].first==0){
                    int store=vp[count].second.first;
                    int store2= vp[count].second.second;
                    int zero = 0;
                    while(zero!=n[0].size()){
                        n[store][zero]=0;
                        zero++;
                    }
                    zero=0;
                    while(zero!=n.size()){
                        n[zero][store2]=0;
                        zero++;
                    }
                }
                count++;
            }
        }
        return;
        
    }
};