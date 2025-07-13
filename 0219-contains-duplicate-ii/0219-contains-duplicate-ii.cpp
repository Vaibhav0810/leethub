class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        set<int>st;
        while(i<n && j<n){
            if((j-i)<=k){
                if(st.find(nums[j])==st.end()){
                    st.insert(nums[j]);
                }
                else{
                    return true;
                }
                j++;
            }
            else{
                st.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};