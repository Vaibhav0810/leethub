class Solution {
public:
    int trap(vector<int>& height) {
        // brute force(tle)
        
        // isme jiss point pr h uski max legt height nikalo and then max right height
        // aur jo unka min h usme se jiss height pr ho vo minus krke ans mei addd 
        // bcoz agr ik container mei paani dalenge to vo utna hi paani store krega na
        // jitna max height h uski kisi side se
        
//         int ans=0;
//         for(int i=1;i<height.size()-1;i++){
//             int l_height=0,r_height=0;
            
//             for(int j=i;j<height.size();j++) r_height=max(r_height,height[j]);
            
//             for(int j=i;j>=0;j--) l_height=max(l_height,height[j]);
            
//             ans+=min(l_height,r_height)-height[i];
            
//         }
//         return ans;
        
        // using 2 pointer
        
        int left=0,right=height.size()-1,left_max=0,right_max=0,ans=0;
        
        // isme hm phle check krenge ki left right mei se kiski hight bdi h ab jiski bdi aagyi uski max se check krenge ki uski bdi h ya ni 
        // agr bdi h to max mei ye height daal do 
        // bdi ni h to ans mei max - current height daal do
        
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=left_max){
                    left_max=height[left];
                }
                else ans+=left_max-height[left];
                left++;
            }
            
            else{
                height[right]>=right_max ?  (right_max=height[right]):ans+=(right_max-height[right]);
                    right--;
            }
            
        }
        return ans;
    }
};