class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s= countAndSay(n-1);
        string ans="";
        for(int i=0; i<s.size(); i++){
            int cnt=1;
            while(i < (s.size() - 1) and (s[i] == s[i + 1])){
                i++;
                cnt++;
            }
            ans.append(to_string(cnt) + s[i]);
        }
        return ans;
    }
};
