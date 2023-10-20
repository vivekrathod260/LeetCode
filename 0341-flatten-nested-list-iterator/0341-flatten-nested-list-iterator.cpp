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
    vector<int> lst;
    int ind;

    vector<int> f(vector<NestedInteger> &v)
    {
        vector<int> lst;

        for(auto x : v)
        {
            if(x.isInteger())
            {
                lst.push_back(x.getInteger());
            }
            else
            {
                vector<int> temp = f(x.getList());
                for(int val : temp)
                {
                    lst.push_back(val);
                }
            }
        }

        return lst;
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        lst = f(nestedList);
        ind  = 0;
    }
    
    int next() {
        return lst[ind++];
    }
    
    bool hasNext() {
        return ind<lst.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */