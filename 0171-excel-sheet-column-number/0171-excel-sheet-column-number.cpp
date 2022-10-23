class Solution {
public:
    
    // AA -> 26*1 +1 =27 (A==1)
    // BA -> 26*2 +1 =53
    // if three cases occur
    // AAB -> A=1
    // AA = 26*1 +1
    // AAB = (26*1+1) * 26 +2
    
//     "B" = 2
//     "BC" = (2)26 + 3
//     "BCM" = (2(26) + 3)26 + 13
    
//     . For every additional digit of the string, we multiply the value of the digit by 26^n
// 2. here n is the number of digits it is away from the one's place.
// 3. This is similar to how the number 254 could be broken down as this:
// 	 (2 x 10 x 10) + (5 x 10) + (4).
// 4. The reason we use 26 instead of 10 is because 26 is our base.

// For s = "BCM" the final solution would be (2 x 26 x 26) + (3 x 26) + (13)
    
    int titleToNumber(string columnTitle) {
        int result=0;
        
        for(auto it:columnTitle){
            int d=(it-'A'+1);
            result=result*26+d;
        }
        return result;
    }
    
    
    
};