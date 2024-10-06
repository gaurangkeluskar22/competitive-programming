/* Problem Overview:- The goal is to find the city with the smallest number of neighbors within a given distance threshold. If there are multiple such cities, return the city with the greatest number.*/


//------------------CODE----------------------//

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = Integer.MAX_VALUE / 2;
            }
            
            matrix[i][i] = 0;
        }
        
        for (int[] edge : edges) {
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int cur = matrix[i][k] + matrix[k][j];
                    
                    if (cur < matrix[i][j]) {
                        matrix[i][j] = cur;
                    }
                }
            }
        }
        
        int answer = Integer.MAX_VALUE;
        int bestCity = 0;
        for (int i = 0; i < n; i++) {
            int citiesCount = 0;
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= distanceThreshold) {
                    citiesCount++;
                }
            }
            
            if (citiesCount <= answer) {
                answer = citiesCount;
                bestCity = i;
            }
        }
        
        return bestCity;
    }
}


/* Summary:- This solution uses the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities. It then finds the city with the smallest number of neighbors within the given distance threshold. If there are multiple such cities, it returns the one with the greatest number. */