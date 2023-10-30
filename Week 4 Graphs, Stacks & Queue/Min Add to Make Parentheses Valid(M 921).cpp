class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0) return 0;
        //Two options ')' or '(' 
        //s only contains parentheses
        stack<char> pt;
        pt.push(s[0]);
        for(int i = 1; i < s.size(); i ++){
            if(pt.size() == 0) pt.push(s[i]);
            else if(pt.top() == '(' && s[i] == ')') pt.pop();
            else pt.push(s[i]);
        }
        return pt.size();
    }
};