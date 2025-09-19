class Path{
    vector<int>parent;
    public:
        Path(int n){
            parent.resize(n+1);
            for(int i=1;i<=n;i++){
                parent[i] = i;
            }
        }
        int findset(int u){
            if(u == parent[u]) return u;
            return parent[u]=findset(parent[u]);
        }
        void unionset(int u,int v){
            int uLead = findset(u);
            int vLead = findset(v);
            if(uLead!=vLead){
                parent[uLead]=vLead;
            }
        }

};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        Path* p = new Path(edges.size()+2);
        vector<int>degree(edges.size()+2,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            p->unionset(u,v);
            degree[u]++;
            degree[v]++;
        }
        for(int i=1;i<=edges.size()+1;i++){
            if(degree[i]>1) return i;
        }
        return -1;
    }
};