//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    
    static bool cmp(int a,int b)

    {

        return a>b;

    }

    int maximizeSum(int a[], int n) 

    {

        sort(a,a+n,cmp);

        unordered_map<int,int>m;

        for(int i=0;i<n;i++)

        {

            m[a[i]]++;

        }

        int sum=0;

        int i=0;

        while(i<n)

        {

            

            if(m[a[i]]!=0)

            {

                 sum+=a[i];
                 //cout<<a[i]<<" ";
                

            

                m[a[i]]--;

                if(m[a[i]-1]!=0)

                {

                    

                    m[a[i]-1]--;

                }

            }

            i++;

        }

        return sum;

    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends