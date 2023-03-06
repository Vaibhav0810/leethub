class Solution {
public:
    // brute force O(N)
//     int findKthPositive(vector<int>& arr, int k) {
//         int i=0,j=0;
        
//         while(k>=0){
//             if(i<arr.size() && arr[i]==j+1){
//                 i++;
//                 j++;
//             }
//             else if(i==arr.size() && k!=0){
//                 k--;
//                 j++;
//             }
//             else{
//                 k--;
//                 j++;
//             }
//             if(k==0){
//                 return j;
//             }
//         }
//         return 0;
//     }
    
    // Optimised O(log n)
//     Intuition of this Problem:
// First thing is how we can find number of mission element ?, so below is the magic statement :
// arr[i] - (i + 1) : this statement will give us number of missing element before each arr[i] element, here i is nothing but mid used in the code.
// For example, for the array [2,3,4,7,11], the number of missing positive integers before each element is [1,1,1,3,6] using above statement.
// Second thing is after finding number of missing element before each element, how we can find that element which is missing ? :
// We then use binary search to find the first index start such that the number of missing positive integers before arr[start] is greater than or equal to k. Once we have found this index start, we know that the kth smallest missing positive integer is between arr[start - 1] and arr[start]. Therefore, we can compute the kth smallest missing positive integer as arr[start - 1] + (k - (arr[start - 1] - (start - 1) - 1)) = start + k.

// Let's break down this expression:

// arr[start - 1] is the last element before the kth missing positive integer, so we start with this value.
// (k - (arr[start - 1] - (start - 1) - 1)) is the number of missing positive integers between arr[start - 1] and the kth missing positive integer. We subtract arr[start - 1] - (start - 1) - 1 from k to account for the missing positive integers before arr[start - 1]. We then add this value to arr[start - 1] to get the kth missing positive integer.
// I know its bit confusing but if you will read two or three times or dry run this code to above statement then you will understand better.

// Approach for this Problem:
// Initialize start to 0 and end to n-1, where n is the size of the input array arr.
// Use binary search to find the index i of the kth missing positive integer.
// While start is less than or equal to end, calculate the midpoint mid as start + (end - start) / 2.
// If the number of missing positive integers before arr[mid] is less than k, set start to mid + 1.
// Otherwise, set end to mid - 1.
// After the binary search is complete, calculate the kth missing positive integer as start + k, where start is the index found by binary search.

    // https://leetcode.com/problems/kth-missing-positive-number/discuss/3262334/Day-65-oror-Binary-Seach-oror-O(logn)-time-O(1)-space-oror-Easiest-Beginner-Friendly-Sol
    
    int findKthPositive(vector<int>& arr, int k){
        int n=arr.size();
        int start=0,end=n-1,mid=0;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]-(mid+1)<k){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
        }
        return start+k;
    }
    
    
};