//1804
#include <bits/stdc++.h> 
struct Node {
    //member fn
    Node* link[26];
    int ew=0;//end with
    int cp=0;//count prefix

    bool containerKey(char ch) {
        return (link[ch-'a']!=NULL);
    }
    void put(char ch,Node* node) {
        link[ch-'a']=node;
    }
    Node* get(char ch) {
        return link[ch-'a'];
    }
    void endingWith() {
        ew++;
    }
    void countPrefix() {
        cp++;
    }
    void endingWithD() {
        ew--;
    }
    void countPrefixD() {
        cp--;
    }
    int getEnd() {
        return ew;
    }
    int getPrefix() {
        return cp;
    }

};
class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
         root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->containerKey(word[i])) {
                node->put(word[i],new Node());
            }
            node->get(word[i]);
            node->countPrefix();
        }
        node->endingWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(node->containerKey(word[i])) {
                node=node->get(word[i]);
            }
            else {
                return 0;
            }
            
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(node->containerKey(word[i])) {
                node=node->get(word[i]);
            }
            else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            node->get(word[i]);
            node->countPrefixD();
        }
        node->endingWithD();
    }
};
