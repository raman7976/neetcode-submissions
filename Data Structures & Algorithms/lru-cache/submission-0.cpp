#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    std::unordered_map<int, Node*> mpp;
    Node *head; 
    Node *tail; 

    
    void deleteNode(Node *delnode) {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }


    void insertAtMRU(Node *newnode) {
        Node *prevTail = tail->prev;
        prevTail->next = newnode;
        newnode->prev = prevTail;
        newnode->next = tail;
        tail->prev = newnode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node *resNode = mpp[key];
            int res = resNode->val;
            
            
            deleteNode(resNode);
            insertAtMRU(resNode);
            
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
       
        if (mpp.find(key) != mpp.end()) {
            Node *existingNode = mpp[key];
            existingNode->val = value;
            deleteNode(existingNode);
            insertAtMRU(existingNode);
        } 
        // Case 2: New Key
        else {
            // Cache full: Evict LRU node (node right after dummy head)
            if (mpp.size() == cap) {
                Node *lru = head->next;
                mpp.erase(lru->key);
                deleteNode(lru);
                delete lru; // Free memory
            }
            
            Node *newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAtMRU(newNode);
        }
    }
};