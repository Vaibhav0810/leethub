class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0,j=numbers.size()-1;
        // we first see what can we do
        // brute lgakr basicallly hrr element ke lie check kr skte h O(n2) mei hoga vo
        
        // thda sa optimise krke map use kr skte h but vo O(N) space and time lega
        
        // firr hmne dekha ki array sorted h to we can use two pointers
// ye O(N) time lega and const space
        
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else j--;
        }
        return {};
    }
};