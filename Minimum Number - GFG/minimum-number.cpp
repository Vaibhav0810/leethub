//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        
        // priority_queue<int>pq;
        // for(auto it:arr) pq.push(it);
        // int second=pq.top();
        // while(second!=0){
        //     int first=pq.top();
        //     pq.pop();
        //      second=pq.top();
        //     pq.push(first-second);
            
        // }
        // return pq.top();
        
        // int gcd=0;
        // for(int i=0;i<n;i++){
        //     gcd=__gcd(gcd,arr[i]);
        // }
        // return gcd;
        
        int mn = arr[0];
        for (int i = 0; i < n; i++) {
            mn = min(mn, arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] % mn != 0) {
                return 1;
            }
        }
        return mn;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends