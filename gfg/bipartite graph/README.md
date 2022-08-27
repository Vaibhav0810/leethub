Bipartite Graph
MediumAccuracy: 40.1%Submissions: 81949 Points: 4
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 
![download](https://user-images.githubusercontent.com/73460717/187045212-b507c130-c0cc-43c7-b8b3-56383cb806f0.png)

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.

Example 2:
![download](https://user-images.githubusercontent.com/73460717/187045216-5566e6a5-dadd-4cef-b6bb-f9c67e437246.png)

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
