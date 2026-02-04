class Solution {
public:
    vector<int>ans;
    void find(vector<int>&nums,int target,int st,int end){
        if(nums[st]==target){
            ans[0]=st;
            if(nums[end] == target) ans[1]=end;
            else{
                search(nums,target,st,end-1);
            }
        }
        else{
            ans[1]=end;
            search(nums,target,st+1,end);
        }

        // if(end==target)
    }

    void search(vector<int>& nums, int target, int st, int end) {
        if (st <= end) {
            int mid = (end + st) / 2;
            if (target == nums[mid]) {
                find(nums,target,st,end);
            } else if (target > nums[mid]) {
                search(nums, target, mid + 1, end);
            } else {
                search(nums, target, st, mid - 1);
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        ans.resize(2);
        ans[0]=-1;
        ans[1]=-1;
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        if(n==1 && nums[0]==target) return {0,0};
        search(nums, target, 0, n - 1);
        return ans;
    }
};