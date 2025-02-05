

/*
BFS or DFS bipartite graph determinor.

A graph is said to be bipartite if all its vertices can be partitioned into two 
disjoint subsets X and Y so that every edge connects a vertex in X with a vertex 
in Y. (One can also say that a graph is bipartite if its vertices can be colored 
in two colors so that every edge has its vertices colored in different colors; 
such graphs are also called 2-colorable.) 

Do either A or B.

A. Design a DFS-based algorithm for checking whether a graph is bipartite. Thus, 
let F be a DFS forest of a graph. It is not difficult to see that F is 
2-colorable if and only if there is no back edge connecting two vertices both on 
odd levels or both on even levels. It is this property that a DFS traversal 
needs to verify. Note that a DFS traversal can mark vertices as even or odd when 
it reaches them for the first time.

B.Design a BFS-based algorithm for checking whether a graph is bipartite. Thus, 
similarly to part (A), a graph is 2-colorable if and only if its BFS forest has 
no cross edge connecting.

*/