Medium

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:

![download](https://user-images.githubusercontent.com/73460717/187185543-53c74a10-c514-4666-a4fa-426e7d1aef83.png)


Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:

![download](https://user-images.githubusercontent.com/73460717/187185573-ae413227-7886-4002-a112-18f0fa10177c.png)


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
