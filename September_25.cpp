struct Node{
    Node * characters [26];
    int flag = 0;

    bool exists(char ch){
        return characters[ch-'a']!=0;
    }

    void insert(char ch){
        Node * newNode = new Node();
        characters[ch-'a'] = newNode;
    }

    Node * getNext(char ch){
        return characters[ch-'a'];
    }

    void incrementFlag(){
        flag++;
    }

    int getFlag(){
        return flag;
    }
};
class Trie{
    private:
    Node * root = new Node();
    public:
    void build(vector<string>&words){
        for(auto word : words){
            Node * node = root;
            for(auto ch : word){
                if(!node->exists(ch)){
                    node->insert(ch);
                }
                node = node->getNext(ch);
                node->incrementFlag();
            }
        }
    }

    int findScore(string & word){
        int score = 0;
        Node * node = root;
        for(auto ch : word){
            node = node->getNext(ch);
            score += node->getFlag();
        }

        return score;
    }

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie * trie = new Trie();
        trie->build(words);
        
        vector<int>ans(n);

        for(int i = 0;i<n;i++){
            ans[i] = trie->findScore(words[i]);
        }

        return ans;
    }
};