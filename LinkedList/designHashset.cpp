class MyHashSet {
public:
   vector<list<int>> mp;
    int size;
    MyHashSet() {
        size=1e+6+1;
        mp.resize(size);
    }
    int hash(int key) { //it will return the index at which data has to be present
        return key%size;//we are taking module if the size is greater
    }
    //it will return iterator in list on that index 
    list<int>  :: iterator search(int key) {
        int i=hash(key);//at which index our key is available
        return find(mp[i].begin(),mp[i].end(),key);
    }
    void add(int key) {
        if(!contains(key)) {
            int i=hash(key);
            mp[i].push_back(key);
        }
        else {
            return;
        }
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        mp[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=mp[i].end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
