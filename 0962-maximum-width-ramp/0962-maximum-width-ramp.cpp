class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> idx(n);
        // for (int i = 0; i < n; i++) {
        //     idx[i] = i;
        // }
        // sort(idx.begin(), idx.end(), [&](int i, int j) {
        //     return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        // });

        // int maxWidth = 0,minIndex = n;
        // for(int i=0;i<n;i++){
        //     maxWidth = max(maxWidth,idx[i]-minIndex);
        //     minIndex = min(minIndex,idx[i]);
        // }
        // return maxWidth;

        // with stack (optmized)

        stack<int>st;
        int n = nums.size();
        //insert element in stacks in decreasing order
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        int maxWidth = 0;
        //traverse array from behind
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                maxWidth = max(maxWidth, i-st.top());
                st.pop();
            }
        }

        return maxWidth;

    }
};