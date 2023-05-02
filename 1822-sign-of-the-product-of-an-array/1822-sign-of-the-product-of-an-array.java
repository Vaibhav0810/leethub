class Solution {
    public int arraySign(int[] nums) {
        int count_0=0;
        int count_neg=0;
        for(int it:nums){
            if(it<0) count_neg++;
            if(it==0) count_0++;
        }

        if(count_0>0) return 0;
        else if(count_neg%2!=0) return -1;
         return 1;
    }
}