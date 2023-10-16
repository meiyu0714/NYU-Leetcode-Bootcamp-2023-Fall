class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //s.length == t.length
        if(s.length() != t.length()) return false;
        unordered_map<char, char> s_curr;
        unordered_map<char, char> t_curr;
        for(int i = 0; i < s.size(); i++){
            if(s_curr[s[i]] && s_curr[s[i]] != t[i]){
                return false;
            }
            if(t_curr[t[i]] && t_curr[t[i]] != s[i]){
                return false;
            }
            s_curr[s[i]] = t[i];
            t_curr[t[i]] = s[i];
        }
        return true;
    }
};