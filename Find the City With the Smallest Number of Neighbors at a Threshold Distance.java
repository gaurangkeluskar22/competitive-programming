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
