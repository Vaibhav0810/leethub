//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        
        int count = 0;
        if(seats[0] == 0 && seats[1] == 0)
        {
            seats[0] = 1;
            count++;
        }
        if(seats[m-1] == 0 && seats[m-2] == 0)
        {
            seats[m-1] = 1;
            count++;
        }
        for(int i = 0;i<m;i++)
        {
            if(seats[i] == 0)
            {
                if((i-1) >= 0 && seats[i-1] == 0 && (i+1) < m && seats[i+1] == 0)
                {
                    count++;
                    seats[i] = 1;
                }
            }
        }
        if(count >= n) return true;
        return false;

        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends