//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        vector<int>ans;
        unordered_map<int,vector<int>>mp1;
        int mini=INT_MAX;
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                int sum=A[i]+A[j];
                if(mp1.find(sum)!=mp1.end() && mp1[sum][0]!=i && mp1[sum][1]!=j && mp1[sum][0]!=j && mp1[sum][1]!=i){
                    vector<int>temp={mp1[sum][0],mp1[sum][1],i,j};
                
                
                if(ans.empty() or ans>temp){
                    ans=temp;
                }
                }
                else{
                    mp1[sum].push_back(i);
                    mp1[sum].push_back(j);
                }
                
                
            }
        }
        if(ans.empty()){
            return{-1,-1,-1,-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends