class Solution {
public:
    
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
       
        vector<vector<int>> adj(n);
        vector<int> dist(n,0);
        vector<int> indegree(n,0);

        vector<int> visited(n,false);
        for(int i=0; i<n; i++){
            adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
            dist[i]=1;
        }

        

        for(int i=0; i<n; i++){
            if(indegree[i]==0 && !visited[i]){
                queue<int> q;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    auto top=q.front();
                    q.pop();
                    for(auto neighbour:adj[top]){
                        dist[neighbour]=max(dist[neighbour],dist[top]+1);
                        
                        if(--indegree[neighbour]==0 && !visited[neighbour]){
                            q.push(neighbour);
                            visited[neighbour]=true;
                            
                        }
                    }
                }
            }
        }
        int maxCycle=0,twoLengthcycle=0;
        for(int i=0; i<n; i++){
            int cycleLength=0;
            if(indegree[i] && !visited[i]){
                queue<int> q;
                q.push(i);
                indegree[i]--;
                visited[i]=true;
                while(!q.empty()){
                    auto top=q.front();
                    q.pop();
                    cycleLength++;
                    for(auto neighbour:adj[top]){
                        if(indegree[neighbour] && !visited[neighbour]){
                            q.push(neighbour);
                            indegree[neighbour]--;
                            visited[neighbour]=true;
                        }
                    }
                }
                if(cycleLength>2){
                    maxCycle=max(maxCycle,cycleLength);
                }
                else{
                    twoLengthcycle+=dist[i]+dist[adj[i][0]];
                }
            }

        }
        return max(maxCycle,twoLengthcycle);
       
    }
};