vector<vector<int>> threeSum(vector<int>& nums) {
        
        // it is like two sum but in this we can fix one and then other two pointer can move
        //First, you can sort the input vector nums in ascending order. Then, you can iterate through nums with a loop and use two pointers to find the other two elements of the triplet that sum to 0 with the current element.



        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // for duplicates
            int left=i+1;
            int right=n-1;
            while(left<right){
                int eq=nums[i]+nums[left]+nums[right];
                if(eq==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(eq>0){
                    right--;
                }
                else left++;
            }
        }   
        return ans;
    }
