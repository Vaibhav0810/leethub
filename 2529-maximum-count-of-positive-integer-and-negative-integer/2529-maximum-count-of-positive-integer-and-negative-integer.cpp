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
        
        // lower bound return kr rha hjha pr phla 0 aayega aur agr 0 ni h usme to jha 0 se bda kuch bhi aayega
        // jaise [-2,-1,-1,1,2,3] isme 3 return krega index
        
        // upper bound jha 0 ki last vaulue hogi ya jha 0 se bda hoga
        // jaise [5,20,66,1314] isme 0 return krega
        
        // uske bdd unka max
        
        int n = nums.size();
        int negStart = lower_bound(begin(nums), end(nums), 0) - nums.begin();
        cout<<negStart;
        int posBegin = upper_bound(begin(nums), end(nums), 0) - nums.begin();        
        return max(negStart, (n  - posBegin ));

        
    }
};