//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int>dist(1e5,1e9);
        queue<pair<int,int>>q;
        // start steps
        q.push({start,0});
        dist[start]=0;
        while(!q.empty()){
            int num=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++){
                int modu=(num*arr[i])%100000;
                
                if(steps+1<dist[modu]){
                    dist[modu]=steps+1;
                    if(modu==end){
                    return steps+1;
                    }
                    q.push({modu,steps+1});
                
                }
                
                
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends