class Trie {
    struct Node {
        //member fn
        Node* link[26];
        bool flag=false;
        //to check a particular character is present in particular node of trie
        bool containerKey(char ch) {
            return (link[ch-'a']!=NULL);
        }
        //making a new node for a particular ch that is present in the node
        void put(char ch,Node* node) {
            link[ch-'a']=new Node();
        }
        //linking to the reference variable
        Node* get(char ch) {
            return link[ch-'a'];
        }
        //set end node to true
        void setEnd() {
            flag=true;
        }
        bool isEnd() {
            return flag;
        }
    };
private:Node* root;
public:
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            //if that character is empty in that node then on that char position make a node
            if(!node->containerKey(word[i])) {
                node->put(word[i],new Node());
            }
            //move to references trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->containerKey(word[i])) {
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->containerKey(word[i])) {
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
