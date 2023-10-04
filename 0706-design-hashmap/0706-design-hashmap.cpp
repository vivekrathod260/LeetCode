class Node
{
    public:
        pair<int,int> p;
        Node *next;

        Node()
        {
            p.first = -1;
            p.second = -1;
            next = NULL;
        }

        Node(int key, int val)
        {
            p.first = key;
            p.second = val;
            next = NULL;
        }

        Node(int key, int val, Node *nxt)
        {
            p.first = key;
            p.second = val;
            next = nxt;
        }

        ~Node()
        {
            delete next;
        }
};

class MyHashMap {
private:
    Node **hmap;
    int size;
    int capacity;

    int hash(int key)
    {
        return(key%capacity);
    }

    void reHash()
    {
        Node **newhmap = new Node*[capacity*2];

        Node **oldhmap = hmap;
        int oldcap = capacity;
        int oldsize = size;
        

        hmap = newhmap;
        capacity = capacity*2;
        size = 0;

        for(int i = 0; i<capacity; i++)
        {
            hmap[i] = NULL;
        }

        for(int i = 0; i<oldcap; i++)
        {
            if(oldhmap[i] == NULL) continue;

            Node *p = oldhmap[i];
            while (p != NULL) 
            {
                put(p->p.first, p->p.second);
                p = p->next;
            }

            delete oldhmap[i];
        }

        delete []oldhmap;
    }

public:
    MyHashMap() {
        size = 0;
        capacity = 10;
        hmap = new Node*[capacity];
        for(int i = 0; i<capacity; i++)
        {
            hmap[i] = NULL;
        }
    }

    void put(int key, int value) {
        int ind = hash(key);
        if(hmap[ind] == NULL)
        {
            hmap[ind] = new Node(key, value);
            size++;
        }
        else
        {
            Node *p = hmap[ind];
            while(p->next!=NULL)
            {   
                if(p->p.first == key)
                {
                    p->p.second = value;
                    return;
                }
                p = p->next;
            }

            if(p->p.first == key)
            {
                p->p.second = value;
                return;
            }

            p->next = new Node(key, value);
            size++;
        }

        if(size>(capacity/3))
        {
            reHash();
        }
    }
    
    int get(int key) {
        int ind = hash(key);
        if(hmap[ind] == NULL)
        {
            return -1;
        }
        else
        {
            Node *ptr = hmap[ind];
            while(ptr->next!=NULL)
            {
                if(ptr->p.first == key)
                {
                    
                    return ptr->p.second;
                }
                ptr = ptr->next;
            }

            if(ptr->p.first == key)
            {
                
                return ptr->p.second;
            }

            return -1;
        }
    }
    
    void remove(int key) {
        int ind = hash(key);
        Node *prev = hmap[ind];
        if(hmap[ind]==NULL)
        {
            return;
        }
        else if(hmap[ind]->p.first == key)
        {
            Node *tmp = hmap[ind];
            hmap[ind] = tmp->next;
            tmp->next = NULL;
            delete tmp;
            size--;
        }
        else
        {
            Node *p = hmap[ind]->next;
            while(p!=NULL)
            {
                if(p->p.first == key)
                {
                    prev->next = p->next;
                    p->next = NULL;
                    delete p;
                    size--;
                    return;
                }
                prev = p;
                p = p->next;
            }
        }
    }
};