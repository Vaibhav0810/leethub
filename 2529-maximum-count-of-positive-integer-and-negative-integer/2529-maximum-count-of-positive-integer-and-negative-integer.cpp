class Solution {
public:
    

    
    int maximumCount(vector<int>& nums) {
        
        // brute
        
    //     int neg=0,pos=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]<0) neg++;
    //         if(nums[i]>0) pos++;
    //     }
    //     return max(neg,pos);
    // }
        
    // follow up (log n)
    // we know for log n we have to do binary search
        
        int n = nums.size();
        int negStart = lower_bound(begin(nums), end(nums), 0) - nums.begin();
        int posBegin = upper_bound(begin(nums), end(nums), 0) - nums.begin();        
        return max(negStart, (n  - posBegin ));

        
    }
};