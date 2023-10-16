class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, max_length = 0; 
        unordered_set<char> curr;
        for(int i = 0; i < s.size(); i++){
            while(curr.find(s[i]) != curr.end()){
                curr.erase(s[left]);
                left++;
            }
            max_length = max(max_length, i - left + 1);
            curr.insert(s[i]);
        }
        return max_length;
    }
};