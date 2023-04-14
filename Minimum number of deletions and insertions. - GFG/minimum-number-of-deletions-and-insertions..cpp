//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int minOperations(string str1,string str2){
	    
	    int n=str1.size(), m=str2.size();
	    int dp[n+1][m+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<m+1;j++){
	            if(i==0 || j==0) dp[i][j]=0;
	        }
	    }
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	                
	            }
	            else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return (n-dp[n][m]+m-dp[n][m]);
	}
	
// 	int minOperations(string str1, string str2) 
// 	{ 
// 	    // Your code goes here
	    
// 	    int n=str2.size(),m=str1.size();
// 	    int dp[n+1][m+1];
	    
// 	    for(int i=0;i<n+1;i++){
// 	        for(int j=0;j<m+1;j++){
// 	            if(i==0) dp[i][j]=0;
// 	            if(j==0) dp[i][j]=i;
// 	        }
// 	    }
	    
// 	    for(int i=1;i<n+1;i++){
// 	        for(int j=1;j<m+1;j++){
// 	            if(str1[i-1]==str2[j-1]){
// 	                if((min(dp[i-1][j],dp[i][j-1]))!=0){
// 	                dp[i][j]=min(dp[i-1][j],dp[i][j-1])-1;
// 	                }
// 	                else dp[i][j]=0;
// 	            }
// 	            else{
// 	                dp[i][j]=dp[i][j-1]+1;
// 	            }
// 	        }
// 	    }
// 	    return dp[n][m];
// 	} 
	
	
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends