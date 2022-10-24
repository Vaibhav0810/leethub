class Solution {
public:
    // bool isPowerOfThree(int n) {
    //     for(int i=0;i<n;i++){
    //         if(pow(3,i)==n) return true;
    //         else if(pow(3,i)>n) return false;
    //     }
    //     return false;
    // }
    // doing it without pow
    // follow up solve without loops/ recursion
//     bool isPowerOfThree(int n){
//         if(n<=0) return false;
//         while(n>1){
//             if(n%3!=0) return false;
//             else{
//                 n=n/3;
//             }
//         }
//         return true;
//     }
    
//     3 is a prime number. So, any power of 3 will only be divisible by lower or equal powers of 3.

// The largest power of 3 less than 2^31 is 1162261467 (can be found by 3^( log3(2^31 - 1) ) = 3^19 = 1162261467 ). So, this number will only be divisible by a power of 3.

// Thus, we can only check if the above number is divisible by n. If n is a power of 3, then only it will be completely divisible by n.

bool isPowerOfThree(int n) {
	return n > 0 && 1162261467 % n == 0;
	// pow(3, floor(log(INT_MAX)/log(3))) = 1162261467 
}
// Time Complexity : O(1)
// Space Complexity : O(1)

// Note: This solution worked because 3 is a prime number and will work for any other prime number power checks as well. It won't work for non-prime numbers because its largest power will also get divided by some non-powers of that number as well.
    
};