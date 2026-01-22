class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, k = -1;
        int n = nums.size();
        if(n==1) return 1;
        for (int i = 0; i < nums.size();) {
            while (j < n && nums[i] == nums[j]) {
                j++;
            }
            j--;
            if (k != -1) {
                if (j - i == 0) {
                    nums[k] = nums[j];
                    k++;
                } else {
                    nums[k] = nums[j];
                    nums[k + 1] = nums[j];
                    k+=2;
                }  
            }
            if (j - i > 1) {
                if (k == -1) {
                    k = i + 2;
                } else {
                }
            }

            j++;
            i = j;
        }
        return k==-1?n:k;
    }
};