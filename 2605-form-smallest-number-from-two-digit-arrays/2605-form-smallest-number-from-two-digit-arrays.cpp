class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mini1=INT_MAX,mini2=INT_MAX;
        
        set<int>st(nums1.begin(),nums1.end());
        int store=INT_MAX;
        for(auto it:nums2){
            if(st.find(it)==st.end()){
                
            }
            else{
                store=min(store,it);
            }
            
        }
        
        for(auto it:nums1){
            if(it<mini1) mini1=it;
        }
        
        for(auto it:nums2){
            if(it<mini2) mini2=it;
        }
        int ans;
        if(mini1<mini2) ans= mini1*10+mini2;
        else ans= mini2*10+mini1;
        return store<ans ? store:ans; 
    }
};