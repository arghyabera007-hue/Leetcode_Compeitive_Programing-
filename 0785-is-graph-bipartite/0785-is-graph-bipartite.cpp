class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n=graph.size();
      // if the graph is not connected 
      vector<int>color(n,-1);
      for(int i=0;i<n;i++){
        if(color[i]!=-1)continue;
        // colored hai 
        queue<int>q;
        q.push(i);
        color[i]=0;
        // 0 -> colored 
        // -1 -> not colored
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // check either neigbour color or not colored
            for(auto neighbour:graph[node]){
                if(color[neighbour]==-1){
                    color[neighbour]=1-color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[node]){
                    return false; //means that the graph not bipartite
                }
            }
        }
      }return true;
    }
};


         // if color unique id of node different of neighbour of graph
        // if same then false 
        // else true;