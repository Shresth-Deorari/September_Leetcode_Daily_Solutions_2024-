struct Node{
    Node * num[10];
    bool flag = false;

    void insert(char a, Node * node){
        num[a-'0'] = node;
    }

    bool exists(char a){
        return num[a-'0']!=NULL;
    }

    Node * getNext(char a){
        return num[a-'0'];
    }

    void setFlag(){
        flag = true;
    }

};
class Trie{
    Node * root = new Node();
    public :
    void build(unordered_set<string>&set1){
        for(auto j : set1){
            Node * node = root;
            for(auto i : j){
                if(!node->exists(i)){
                    node->insert(i,new Node());
                }
                node = node->getNext(i);
            }
            node->setFlag();
        }
    }

    int lengthMatch(string a){
        Node * node = root;
        int count = 0;
        for(auto i : a){
            if(!node->exists(i))return count;
            count++;
            node = node->getNext(i);
        }
        return count;
    }

};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie * trie = new Trie();
        unordered_set<string>set1,set2;
        for(auto i : arr1)set1.insert(to_string(i));
        for(auto i : arr2)set2.insert(to_string(i));
        trie->build(set1);
        int len = 0;
        for(auto i : set2){
            len = max(len, trie->lengthMatch(i));
        }
        return len;
    }
};