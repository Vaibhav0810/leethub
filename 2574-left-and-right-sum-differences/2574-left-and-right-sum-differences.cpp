class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        for(int i=0;i<n;i++){
            if(i==0) continue;
            left[i]=nums[i-1]+left[i-1];
        }
        for(auto it:left){
            cout<<it<<" ";
        }
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1) continue;
            right[i]=nums[i+1]+right[i+1];
        }
        for(auto it:right){
            cout<<it<<" ";
        }
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
            
        }
        
        return ans;
        
        
    }
};