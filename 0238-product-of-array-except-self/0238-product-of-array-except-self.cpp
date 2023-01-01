class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // using extra space
        // learned new concept suffix and prefix array
        
        // begi(prefix array)  A prefix sum array is another array prefixSum[]          of the same size, such that the value of prefixSum[i] is arr[0] +               arr[1] + arr[2] . . . arr[i].
        
        // Input: arr[] = {10, 20, 10, 5, 15}
        //Output: prefixSum[] = {10, 30, 40, 45, 60}

        
//         int n=nums.size();
        
//         vector<int>begi(n),end(n);
//         begi[0]=1,end[0]=1;
        
//         vector<int>ans(n);
        
//         for(int i=1;i<nums.size();i++){
//             begi[i]=begi[i-1]*nums[i-1];
//             end[i]=end[i-1]*nums[n-i];
//         }
        
//         for(int i=0;i<n;i++){
//             ans[i]=begi[i]*end[n-1-i];
//         }
        
        
        
//        return ans;
        
        
        // without extra space
        // ye upr vala same kaam kr rha h bina extra space ke
        
        int n=nums.size();
        
        int begi=1,end=1;
        vector<int>ans(n,1);
        
        for(int i=0;i<nums.size();i++){
            ans[i]=begi*ans[i];
            begi*=nums[i];
            ans[n-i-1]*=end;
            end*=nums[n-i-1];
        }
        return ans;
    }
};