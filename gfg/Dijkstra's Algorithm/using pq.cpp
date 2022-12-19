// this algo is used to find shortest dist in weighted graph 
// it can be done using three data structures queue, priority queue, set   queue is most slow and set is most fast
// it cant be used when there are negative weights in graph

// basically hm isme ik min pq lete h aur firr bffs ki trh graph pr traverse krte h aur jo min dist hota h usse dist mei daalte rhte h aur queue mei weight
// and node push krte rhte h min heap h to apne aap jo sbse min h vo starting mei aajati


public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it[0];
                int adjweight=it[1];
                if(dist[adjnode]>weight+adjweight){
                    dist[adjnode]=weight+adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
            
        }
        return dist;
        
    }
