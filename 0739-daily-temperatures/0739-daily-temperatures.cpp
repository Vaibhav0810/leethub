class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
                // brute force(tle)
        // vector<int>ans(temp.size(),0);
        // int n=temp.size();
        // int count=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(temp[i]<temp[j]){
        //             ans[i]=++count;
        //             count=0;
        //             break;
        //         }
        //         else{
        //             count++;
        //         }
        //     }
        //     count=0;
        // }

        // return ans;
        
        
        stack<int>st;
        vector<int>ans(temp.size(),0);
        
        for(int i=temp.size()-1;i>=0;i--){
            
            while(!st.empty() && temp[st.top()]<=temp[i]) st.pop();
            if(!st.empty()) ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};