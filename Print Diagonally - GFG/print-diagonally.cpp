//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		
		// DRY RUN
		// {1,2,3,4,5,6,7,8,9}
		// first we set j and i =0 
		// then l = i and  k = j 
		//  then while k< n 
		
		vector<int> ans; // for storing vector diagonal
		int j=0;
		for(int i=0;i<n;i++){
		    int l=i;
		    int k=j;
		    while(k<n && l>=0){
		        ans.push_back(A[k][l]);
		        k++;
		        l--;
		    }
		    if(i==n-1 && j==n-1) break;
		    if(i==n-1){
		        j++;
		        i=n-2;
		    }
		    
		}
		return ans;
		
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends