struct Node {
    int key, value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class MyHashMap {
    vector<Node*> hashMap;
    int N = 1000;

    int hash(int n) {
        return n % N;
    }

public:
    MyHashMap() {
        hashMap.resize(N, nullptr);
    }

    void put(int key, int value) {
        int h = hash(key);
        Node* curr = hashMap[h];

        while (curr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        Node* temp = new Node(key, value);
        temp->next = hashMap[h];
        hashMap[h] = temp;
    }

    int get(int key) {
        int h = hash(key);
        Node* curr = hashMap[h];

        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node* curr = hashMap[h];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    hashMap[h] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
