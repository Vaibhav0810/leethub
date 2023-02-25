//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<cstring>
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    // recursive code
    
    // int recur(int W,int wt[],int val[],int n){
        
    //     if(W==0 || n==0) return 0;
        
    //     if(wt[n-1]<=W){
            
    //         return max(val[n-1]+recur(W-wt[n-1],wt,val,n-1),recur(W,wt,val,n-1));
    //     }
    //     else{
    //       return  recur(W,wt,val,n-1);
    //     }
        
        
    // }
    
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
       
    //   return recur(W,wt,val,n) ;
       
    // }
    
    
    // dp code meoization
    
    int dp(int W,int wt[],int val[],int n,vector<vector<int>>&t){
        if(W==0 || n==0) return 0;
        if(t[n][W]!=-1) return t[n][W];
        
        if(wt[n-1]<=W){
            return t[n][W]=max(val[n-1]+dp(W-wt[n-1],wt,val,n-1,t),dp(W,wt,val,n-1,t));
        }
        else{
            return t[n][W]=dp(W,wt,val,n-1,t);
        }
    }
    
    int knapSack(int W,int wt[], int val[],int n){
        
        vector<vector<int>>t(n+1,vector<int>(W+1,-1));
        return dp(W,wt,val,n,t);
        
    }

    
    
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends