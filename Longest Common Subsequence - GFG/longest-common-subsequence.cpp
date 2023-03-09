//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    
    int recur(int n,int m, string s1,string s2,vector<vector<int>>&dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]= 1+recur(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m]=max(recur(n-1,m,s1,s2,dp),recur(n,m-1,s1,s2,dp));
        }
        
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        // recursion
        vector<vector<int>>dp (x+1,vector<int>(y+1,-1));
        return recur(x,y,s1,s2,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends