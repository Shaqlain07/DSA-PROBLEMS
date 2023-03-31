class Solution {
public:
    struct Node {
        //member function
        Node* link[2];
        bool containerKey(int num) {
            return link[num]!=NULL;
        }
        void put(int num,Node* node) {
            link[num]=node;
        }
        Node* get(int num) {
            return link[num];
        }
    };
    class Trie {
        private:Node* root;
        public:
        Trie() {
            root=new Node();
        }
        void insert(int num) {
            Node* node=root;
            for(int i=31;i>=0;i--) {
                int bit=(num>>i)&1;//give the bit of ith index
                if(!node->containerKey(bit)) {
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int Xor(int X) {
            Node* node=root;
            int num=0;
            for(int i=31;i>=0;i--) {
                int bit=(X>>i) & 1;
                if(node->containerKey(1-bit)) {
                    num=num| (1<<i);//it will set the ith bit
                    node=node->get(1-bit);
                }
                else {
                    node=node->get(bit);
                }
            }
            return num;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
      Trie obj;//create an of class trie
      //now iterate on array & insert element on trie
      for(int i=0;i<nums.size();i++) {
          obj.insert(nums[i]);
      }
      int maxi=0;
      for(int i=0;i<nums.size();i++) {
          maxi=max(maxi,obj.Xor(nums[i]));
      }
      return maxi;

    }
};
