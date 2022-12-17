//Explanation
/*
using dfs, to find out if the graph is bipartite, we can color the node with red(1)and blue.  if the one node is blue, then it's neighbor will be red. 
at the end, we check if each node has a different color with its neighbor, then the graph
is bipartite. 
*/
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    // create the graph
    const int n = graph.size();
    vector<int> colors(n);
    // loop through the graph 
    for (int i = 0; i < n; ++i)
    //if the node has not been marked and coloring() is false, return false 
      if (!colors[i] && !coloring(graph, colors, 1, i))
        return false;
    return true; //else return true
  }
private:
  bool coloring(const vector<vector<int>>& graph, vector<int>& colors, int color, int node) {    
    if (colors[node]) return colors[node] == color;
    colors[node] = color; // mark the node with color. 
    for (int nxt : graph[node])// check the next node
    // if neighbor's node has the same color, return false, not bipartite. 
      if (!coloring(graph, colors, -color, nxt)) return false;
    return true;// else return true
  }
};
