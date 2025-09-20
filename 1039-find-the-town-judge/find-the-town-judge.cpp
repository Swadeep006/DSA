class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.empty()) return 1;
       vector<int>indegree(n+1,0);
       vector<int>outdegree(n+1,0);
       for(auto edge: trust){
            outdegree[edge[0]]++;
            indegree[edge[1]]++;
       }
       for(int i=0;i<=n;i++){
        if(outdegree[i]==0 && indegree[i]==n-1){
            return i;
        }
       }
        return -1;
    }
};