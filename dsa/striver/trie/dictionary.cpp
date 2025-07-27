struct Node {
    Node* links[26];
    bool end;

    Node() {
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
        end = false;
    }

    void setEnd() { end = true; }
    bool isEnd() { return end; }
    Node* getNode(char ch) { return links[ch - 'a']; }
    void setNode(char ch, Node* node) { links[ch - 'a'] = node; }
    bool isNull(char ch) { return links[ch - 'a'] == nullptr; }
};
class Trie {
private:

public:
    Node* head;
    Trie() { head = new Node(); }

    void insert(string& str) {
        Node* curr = head;

        for (int i = 0; i < str.size(); i++) {
            if (curr->isNull(str[i])) {
                curr->setNode(str[i], new Node());
            }
            curr = curr->getNode(str[i]);
        }
        curr->setEnd();
    }


    bool recursivePresent(int index, string &word, Node* node) {
        if(!node) return 0; 
        if (index == word.size()) {
                return node->isEnd();
        }

        if (word[index] != '.') {
            if(node)
                return recursivePresent(index + 1, word,
                                    node->getNode(word[index]));
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->isNull('a' + i))
                    continue;

                if (recursivePresent(index + 1, word,
                                     node->getNode(i + 'a'))) {
                    return true;
                }
            }
        }
        return false;
    }
};
class WordDictionary {
public:
    Trie* tr;
    WordDictionary() { this->tr = new Trie(); }

    void addWord(string word) { tr->insert(word); }

    bool search(string word) {
        if(tr->head)
            return tr->recursivePresent(0 , word, tr->head);
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */