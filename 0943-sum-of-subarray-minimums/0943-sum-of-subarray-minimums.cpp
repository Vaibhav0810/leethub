class Solution {
public:

    // in this we will just find if the first smallest element to right and their first smallest element to left and store it in a array. Then we know that number will be present in that many sub arrays so we will just take that count and multiply it with number and store it in ans

    // Eg    3   1 2 4
    // left  -1 -1 1 2
    // right 1   4 4 4

    // 4 n -1 means that we didnt found anything and ran out of array now for 1
    //  ans will be  (4-1)*(1--1) =6 *1 =6
    //                  1= index      1= number

    int sumSubarrayMins(vector<int>& arr) {

        // Time - O(N^2) Space - O(N);

        // int n=arr.size();
        // vector<int>left(n,-1),right(n,n);
        // long long sum=0;
        // for(int i=0;i<arr.size();i++){
        //     int j=i-1;
        //     while(j>=0 && arr[j]>=arr[i]){
        //         j--;
        //     }
        //     left[i]=j;
        //     j=i+1;
        //     while(j<n && arr[j]>arr[i]){
        //         j++;
        //     }
        //     right[i]=j;
        // }

        // for(int i=0;i<n;i++){
        //     long long prod = abs(i-left[i])*abs(i-right[i]);
        //     sum+=arr[i]*prod;
        // }
        // int mod=1e9+7;

        // return sum%mod;

        // Optimised Version O(N) and O(N)

        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Previous Less Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear and reuse stack
        while (!s.empty())
            s.pop();

        // Next Less or Equal Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate result
        long long result = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long count = (i - left[i]) * (right[i] - i) % mod;
            result = (result + arr[i] * count) % mod;
        }

        return result;
    }
};