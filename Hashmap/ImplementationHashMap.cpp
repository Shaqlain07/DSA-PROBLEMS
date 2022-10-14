template<typename v>
class mapNode {//it will create LL at a index
    public:
    string key;
    v value;
    mapNode* next;

    mapNode(string key, v value) { //constructor
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~mapNode() { //destructor
        delete next;
    }
};

template<typename v>
class ourmap {
    mapNode<v>** bucket;//created a pointer array
    int count;
    int numBucket;
    public:
    ourmap() { //constructor
        count=0;//total no of enteries in map
        numBucket=5;//size of array
        bucket=new mapNode<v>*[numBucket];//array declared
        for(int i=0;i<numBucket;i++) {
            bucket[i]=NULL;
        }
    }
    ~ourmap() { //destructor
        for(int i=0;i<numBucket;i++) {
            delete bucket[i];//deleting index and its LL
        }
        delete [] bucket;
    }
    private:
    int getBucketIndex(string key) {//hash fn..This fn takes string(key) & return index where
        int hashcode=0;              //key has to be stored
        int coefficient=1;//p power 0
        for(int i=key.length();i>=0;i--) {
            hashcode+=key[i]*coefficient;
            hashcode=hashcode%numBucket;//compression
            coefficient*=37;//just taken 37 since its a prime no
            coefficient=coefficient%numBucket;
        }
        return hashcode%numBucket;//compression
    }
    public:
    void insert(string key,v value) {
        int bucketIndex=getBucketIndex(string key);
        mapNode<v>* head=bucket[bucketIndex];//declared head at that index
        while(head!=NULL) {
            if(head->key==key) {//we had a key,we r replacing the value
                head->value=value;
                return;
            }
        }
        //when key is not present earlier
        head=bucket[bucketIndex];//declared head at that index
        mapNode<v>* node=new mapNode<v>(key,value);//created a separed node
        node->next=head;
        bucket[bucketIndex]=node;//now head is pointing to new node
        count++;//increment the element in map
    }
    v remove(string key) {
        int bucketIndex=getBucketIndex(string key);
        mapNode<v>* head=bucket[bucketIndex];//declared head at that index
        mapNode<v>* prev=NULL;
        while(head!=NULL) {
            if(head->key==key) {
                if(prev==NULL) {//key is at first node
                    bucket[bucketIndex]=head->next;
                }
                else {
                    prev->next=head->next;
                }
                v value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;//if weee didn't gat the key
    }
    v getValue(string key) {
        int bucketIndex=getBucketIndex(string key);
        mapNode<v>* head=bucket[bucketIndex];//declared head at that index
        while(head!=NULL) {
            if(head->key==key) {
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }



}
