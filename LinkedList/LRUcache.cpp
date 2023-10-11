class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int key,int value) {
            this->key=key;
            val=value;
        }

    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    int cap;//current size of cache
    unordered_map<int,node*> m;//It will store key,address of cache
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    //adding node at the start of list
    void addnode(node* newnode) {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    //delete the given node
    void deletenode(node* newnode) {
        node* nxt=newnode->next;
        node* prev=newnode->prev;
        prev->next=nxt;
        nxt->prev=prev;
    }

    int get(int key) {
        if(m.find(key)!=m.end()) {
            node* address=m[key];//address of that key
            int data=address->val;//value of that key
            m.erase(key);//erase that value
            deletenode(address);
            addnode(address);
            m[key]=head->next;//iterator where the value is present
            return data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) {
             node* it=m[key];
            m.erase(key);
            deletenode(it);
        }
        if(m.size()==cap) {
            //delete the least used node
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
