class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int,int>mp1;
        
        for(auto it:tasks){
            mp1[it]++;
        }
        int count=0;
//         for(auto it:mp1){
            
            
            
//             if(it.second%3==0){
//                 int c=it.second/3;
//                 ans=ans+c;
//                 it.second=0;
//             }
//             else if(it.second%2==0 && it.second!=0){
//                 int c=it.second/2;
//                 ans=ans+c;
//                 it.second=0;
//             }
            
//             else{
//                 int x=it.second;
//                 while(x%3!=0 && x>0){
//                     x=x-2;
                    
//                     count++;
//                 }
//                 if(x%3==0 && x>=0){
//                     int c=x/3;
//                     ans=ans+c+count;
//                     count=0;
//                 }
//                 else return -1;
//             }

            
//        }
        
        for(auto it:mp1){
            if(it.second==1) return -1;
            
            else if(it.second%3==0){
                int c=it.second/3;
                ans+=c;
            }
            else{
                int c=it.second;
                ans+=c/3+1;
            }
        }
        
        return ans;
    }
};