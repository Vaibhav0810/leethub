class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // brute tle time - O(N^3)
        // Space - O(1)
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]<nums[j] && nums[j]<nums[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        
        // optimised
        
//         bool check1=false,check2=false;
//         int maxi=nums[nums.size()-1];
//         for(int i=nums.size()-2;i>=0;i--){
            
//             if(check1==true && check2==true){
//                 return true;
//             }
            
//             if(nums[i]<maxi){
//                 if(check1==true) check2=true;
//                 else check1=true;
//                 //maxi=nums[i];
//             }
//             else if(nums[i]>maxi && nums.size()-1-i<=3){
//                 //check1=false;
//                 maxi=nums[i];
//             }
            
            
//         }
//         if(check1==true && check2==true){
//                 return true;
//             }
//         return false;
        // aise to ho ni paa rha but ye krte krte ik alg idea aa gya
        // we can start from mid
        
//         int mid=(nums.size()-1)/2;
        
//         int i=mid-1,j=mid+1;
//         bool check1=false;
//         bool check2=false;
        
//         while(i>=0 || j<=nums.size()-1){
//             if(nums[mid]>nums[i] && i>=0){
//                 if(check1==true){
//                     check2=true;
//                 }
//                 else check1=true;
//                 i--;
                
//             }
//             if(nums[mid]<nums[j] && j<=nums.size()-1){
//                 if(check1==true){
//                     check2=true;
//                 }
//                 else check1=true;
//                 j++;
                
//             }
            
//             if(nums[i]>nums[mid] && nums[mid]<nums[j]) return false;
            
//             if(nums[mid]==nums[i] && nums[mid]==nums[j]){
//                 i--;
//                 j++;
//             }
//             if(check1==true && check2==true) return true;
//         }
        
//         return false;
        
        // nhi chl rha h upr ka kuch bhi
        // isme hm aisa pta kr rhe h bs ki 3 aise elements jo ik dusre se condition ke hisab se suitable h
        int c1=INT_MAX,c2=INT_MAX;
        
        for(int x:nums){
            if(x<=c1){
                c1=x;
            }
            else if(x<=c2){
                c2=x;
            }
            else return true;
        }
        return false;
        
    }
};