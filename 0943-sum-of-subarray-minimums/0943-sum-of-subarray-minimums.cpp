class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,-1),right(n,n);
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int j=i-1;
            while(j>=0 && arr[j]>=arr[i]){
                j--;
            }
            left[i]=j;
            j=i+1;
            while(j<n && arr[j]>arr[i]){
                j++;
            }
            right[i]=j;
        }

        for(int i=0;i<n;i++){
            long long prod = abs(i-left[i])*abs(i-right[i]);
            sum+=arr[i]*prod;
        }
        int mod=1e9+7;

        return sum%mod;
    }
};