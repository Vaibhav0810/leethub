If closely analyze the given matrix, we can notice one interesting property (╭ರ_•́): elements on the left are always smaller than the current element, and elements on the bottom are always greater. It reminds us of the Binary Search Tree, doesn't it (๏็ટૄ◟๏็ )? Just look at this matrix from this angle and everything will become clear to you (our target, say, is 11):
​

![image](https://user-images.githubusercontent.com/73460717/200114944-55ed9fba-e793-4bd5-a0c4-e34bbbf37f11.png)


​
Woooooow!!! ٩(ˊᗜˋ*)و
​
Time: O(n) - in the case we have just one row
Space: O(1) - nothing stored
​
Runtime: 3 ms, faster than 88.01% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.6 MB, less than 52.00% of C++ online submissions for Search a 2D Matrix.
​
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int rows = matrix.size(),
cols = matrix[0].size(),
row = 0, col = cols - 1;
while (row < rows && col > -1) {
int cur = matrix[row][col];
if (cur == target) return true;
if (target > cur) row++;
else col--;
}
return false;
}
};
