class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int vertex){
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==false && isConnected[vertex][i]==1){
                visited[i]=true;
                dfs(isConnected,visited,i);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<bool> visited(len,false);
        int nums = 0;
        for(int i=0;i<len;i++){
            if(visited[i]==false){
                visited[i]=true;
                dfs(isConnected,visited,i);
                nums++;
            }
        }
        return nums;
    }
};