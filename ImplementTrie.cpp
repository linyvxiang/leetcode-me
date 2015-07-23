class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : num(1), terminal(false) {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
public:
    int num;
    bool terminal;
    TrieNode* child[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur_node = root;
        for (int i = 0; i < word.size(); i++) {
            cur_node->num++;
            TrieNode* next_node = cur_node->child[word[i] - 'a'];
            if (!next_node) {
                next_node = new TrieNode();
                cur_node->child[word[i] - 'a'] = next_node;
            }
            cur_node = next_node;
        }
        cur_node->terminal = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur_node = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode* next_node = cur_node->child[word[i] - 'a'];
            if (!next_node) {
                return false;
            } else {
                cur_node = next_node;
            }
        }
        return cur_node->terminal;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;
        for (int i = 0; i < prefix.size(); i++) {
            TrieNode* next_node = cur_node->child[prefix[i] - 'a'];
            if (!next_node) {
                return false;
            } else {
                cur_node = next_node;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
