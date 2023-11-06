class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        isWord = false;
    }    
};
class Solution {
private:
    TrieNode* root = new TrieNode();
    void insert(string str){
        int curr = 0;
        TrieNode* node = root;
        for(int i = 0 ; i < str.size(); i++){
            curr = str[i] - 'a';
            if(!node->children[curr])
                node->children[curr] = new TrieNode();
            node = node->children[curr];    
        }
        node->isWord = true;
    }

public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word: wordDict){
            insert(word);
        }
        TrieNode* node = root;
        for(int i = 0; i < s.size(); i++){
            if(node->isWord ){
                node = root;
            }
            int curr = s[i] - 'a';
            if(node->children[curr] == nullptr){
                return false;
            }
            node = node->children[curr];
        }
        return node->isWord;
    }
};