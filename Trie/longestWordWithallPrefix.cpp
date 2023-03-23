#include <bits/stdc++.h> 
struct Node {
    Node* link[26];
    bool flag=false;

    bool containerKey(char ch) {
        return (link[ch-'a']!=NULL);
    }
    void put(char ch,Node* node) {
        link[ch-'a']=node;
    }
    Node* get(char ch) {
        return link[ch-'a'];
    }
    void setEnd() {
        flag=true;
    }
    bool checkFlag() {
        return flag;
    }
};
class Trie {
    private:Node* root;
    public:
    Trie() {
        root=new Node();
    }
    

    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->containerKey(word[i])) {
                node->put(word[i],new Node);
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

//it will it has all prefix of word present in trie
bool checkPrefix(string word) {
    bool flag=true;
    Node* node=root;
    for(int i=0;i<word.size();i++) {
        if(node->containerKey(word[i])) {
            node=node->get(word[i]);
            flag = flag & node->checkFlag();
        } else {
          return false;
        }
    }
    return flag;
}
};string completeString(int n, vector<string> &a) {
  // Write your code here.
  Trie *obj = new Trie(); // object created
  // it will insert all the word to trie
  for (int i = 0; i < a.size(); i++) {
    obj->insert(a[i]);
  }
  string longest = "";
  for (int i = 0; i < a.size(); i++) {
    if (obj->checkPrefix(a[i])) {
      // then update the longest prefix
      if (a[i].size() > longest.size()) {
        longest = a[i];
      } else if (a[i].size() == longest.size() && a[i] < longest) {
        longest = a[i];
      }
    }
  }
  if (longest == "")
    return "None";
  return longest;
}
