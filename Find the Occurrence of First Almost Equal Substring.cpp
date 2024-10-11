class Solution {
public:
    // Function to calculate the Z-array for a given string
    vector<int> calculateZArray(string s) {
        int n = s.size();
        vector<int> z(n); // Z-array to store lengths of matches
        int l = 0, r = 0; // Left and right pointers for the Z-box
        for(int i = 1; i < n; i++) {
            // Check if current index is within the Z-box
            if(i <= r) {
                // Minimize z[i] based on Z-box boundary
                z[i] = min(r - i, z[i - l]);
            }
            // Expand the match from index i
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            // Update the Z-box if the match extends beyond the current right boundary
            if(i + z[i] > r) {
                l = i; // Move left pointer to current index
                r = i + z[i]; // Update right pointer to the end of the match
            }
        }
        return z; // Return the computed Z-array
    }
    
    // Function to find the minimum starting index of an almost equal substring
    int minStartingIndex(string s, string p) {
        string combined = p + s; // Combine pattern and string for forward search
        vector<int> forwardZ = calculateZArray(combined); // Calculate forward Z-array
        
        combined.clear(); // Clear the combined string for the next step
        reverse(p.begin(), p.end()); // Reverse the pattern
        reverse(s.begin(), s.end()); // Reverse the string
        combined = p + s; // Combine again for backward search
        vector<int> backwardZ = calculateZArray(combined); // Calculate backward Z-array
        
        int n = forwardZ.size(); // Get size of the Z-array
        int j = p.size(); // Start index for backward match
        j = n - j; // Adjust index for backward matching
        
        // Iterate through the Z-array to find the valid starting index
        for(int i = p.size(); i < n; i++) {
            if(j == n) break; // If j reaches the end, break
            if(j < p.size()) break; // If j is out of bounds, break
            
            int forwardMatch = forwardZ[i]; // Get forward match length
            int backwardMatch = backwardZ[j]; // Get backward match length
            
            // Check if the total match length is sufficient
            if(forwardMatch + backwardMatch >= p.size() - 1) {
                return i - p.size(); // Return the starting index
            }
            j--; // Move backward in the second Z-array
        }
        return -1; // If no valid index is found, return -1
    }
};
