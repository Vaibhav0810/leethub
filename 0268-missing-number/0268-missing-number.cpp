class Solution {
public:
    // brute
    // int missingNumber(vector<int>& nums) {
    //     vector<int>check;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<=nums.size();i++){
    //         check.push_back(i);
    //     }
    //     bool shi=false;
    //     for(int i=0;i<nums.size();i++){
    //         if(check[i]!=nums[i]){
    //             shi=true;
    //             return check[i];
    //         }
    //     }
    //     if(shi==false){
    //         return check[check.size()-1];
    //     }
    //     return 0;
    // }
    
    // optimised 
    // time-O(N) space -O(1)
    // using sum
    
    int missingNumber(vector<int>& nums) {
        int n=nums.size()-1;
        int sum1=((n+1)*(2*1+(n)*1))/2; //
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            sum2=sum2+nums[i];
        }
        return sum1-sum2;
    }
    
};