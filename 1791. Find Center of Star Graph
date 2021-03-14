class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]]++;
            m[edges[i][1]]++;
        }
        
        int size=edges.size();
        for(auto it:m){
            if(it.second==size){
                return it.first;
            }
        }
        return 0;
    }
};
