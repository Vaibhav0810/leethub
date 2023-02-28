//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    // void subsetsum(int arr[],int range,int n, int&dp[][]){
        
        
    //     for(int i=0;i<n+1;i++){
    //         for(int j=0;j<range+1;j++){
    //             if(i==0) dp[i][j]=false;
    //             if(j==0) dp[i][j]=true;
    //         }
    //     }
        
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<range+1;j++){
    //             if(arr[i-1]<=j){
    //                 dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
    //             }
    //             else{
    //                 dp[i][j]=dp[i-1][j];
    //             }
    //         }
    //     }
        
    // }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int range=0;
	    for(int i=0;i<n;i++) range+=arr[i];
	    
	    bool dp[n+1][range+1];
	    
	    for(int i=0;i<n+1;i++){
            for(int j=0;j<range+1;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<range+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
	    //subsetsum(arr,range,n,dp);
	    
	    // isme last line ko ik vector mei store kr dia h 
	    // to jo jo possible ni h unpr false hoga aur vo store hi ni honge
	    // then minimum nikalna h to vo mn=min(mn,range ) vali line se aajaega
	    
	    vector<int>v;
	    
	    for(int i=0;i<=range/2;i++){
	        if(dp[n][i]==true) v.push_back(i);
	    }
	    
	    int mn=INT_MAX;
	    
	    for(auto it:v){
	        mn=min(mn,range-(2*it));
	    }
	    
	    return mn;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends