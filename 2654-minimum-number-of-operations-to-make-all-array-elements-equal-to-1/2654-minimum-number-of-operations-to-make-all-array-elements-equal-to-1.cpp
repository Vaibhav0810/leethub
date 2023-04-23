class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(auto it:nums){
            if(it==1) c++;
        }
        int n=nums.size();
        if(c>0) return n-c;


        int res=1e7;        // just a dummy value
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    res=min(res,j-i); // number of operations to make this element 1+ number of non ones (i.e. n-1) .
                    break;
                } 
            }
        }
        return res==1e7?-1:res+n-1;
    }
};