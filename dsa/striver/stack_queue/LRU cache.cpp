class LRUCache {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        int key;
        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

public:
    int c;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        c = capacity;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAtFront(Node* node) {
        Node* headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* temp = mpp[key];
        remove(temp);
        insertAtFront(temp);
        return temp->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->val = value;
            remove(temp);
            insertAtFront(temp);
        } else {
            if (mpp.size() == c) {
                Node* toReuse = tail->prev;
                remove(toReuse);
                mpp.erase(toReuse->key);

                toReuse->key = key;
                toReuse->val = value;

                insertAtFront(toReuse);
                mpp[key] = toReuse;

            } else {
                Node* nn = new Node(key, value);
                insertAtFront(nn);
                mpp[key] = nn;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
