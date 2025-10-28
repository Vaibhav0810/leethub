class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int>pre;
        if(nums.size()==1) return 2;


        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i==0) pre.push_back(nums[i]);
            else{
                pre.push_back(pre[i-1]+nums[i]);
            }
        }
        int ans= 0;
        if(nums[0]==0 && pre[n-1]==1) ans+=1;
        if(nums[n-1]==0 && pre[n-2]==1) ans+=1;
        if(nums[0]==0 && pre[n-1]==0) ans+=2;
        if(nums[n-1]==0 && pre[n-2]==0) ans+=2;
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1 && nums[i]==0){
                if(pre[i-1]==(pre[n-1]-pre[i])){
                    ans+=2;
                }
                else if(pre[i-1]+1==(pre[n-1]-pre[i])){
                    ans+=1;
                }
                else if(pre[i-1]-1==(pre[n-1]-pre[i])){
                    ans+=1;
                }
                
            }
        }
        return ans;
    }
};