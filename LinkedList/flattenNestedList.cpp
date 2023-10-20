/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    //It will have elements after flattening the list
    vector<int> flattenList;
    int currIndex;

    //fn for traversing in the particular list
    void flatten(vector<NestedInteger> &list) {
        for(int i=0;i<list.size();i++) {
            if(list[i].isInteger()) {
                flattenList.push_back(list[i].getInteger());
            }
            else {
                flatten(list[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
         currIndex=0;
    }
    
    int next() {
        return flattenList[currIndex++];
    }
    
    bool hasNext() {
        return currIndex<flattenList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
