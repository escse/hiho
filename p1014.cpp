//trie 树

#include <cstdio>
#include <string>
#include <cstring>

template <int n>
class TrieNode {
public:
    TrieNode(char c): s(c), set(false),value(0) {
        std::memset(next, 0, sizeof(TrieNode *) * n);
    }

    ~TrieNode() {
        for (int i = 0; i < n; ++i) {
            delete next[i];
        }
    }

    inline TrieNode*& operator[](int index) {
        return next[index];
    }
    
    inline const TrieNode*& operator[](int index) const{
        return next[index];
    }

    bool set;
    int value;
private:
    TrieNode *next[n];
    char s;
};


template <int n>
class Trie {
public:
    inline Trie() {
        root = new TrieNode<n>(0);
    }

    ~Trie() {
        delete root;
    }

    void insert(const std::string& input) {
        auto node = root;
        size_t size = input.size();
        for (int i = 0; i < size; ++i) {
            int index = indexAt(input[i]);
            if (!(*node)[index]) (*node)[index] = new TrieNode<n>(input[i]);
            node = (*node)[index];
            ++(node->value);
        }
        node->set = true;
    }

    int search(const std::string& input) {
        auto node = root;
        size_t size = input.size();
        for (int i = 0; i < size; ++i) {
            int index = indexAt(input[i]);
            if (!(*node)[index]) return 0;
            node = (*node)[index];
        } 
        return node->value;
    }

private:
    inline int indexAt(char c) {
        return (c | 32)- 'a';
    }

    TrieNode<n>* root;
};


int main(int argc, char const *argv[]) {
    int n;
    char word[256];
    // char input[]= "5\nbabaab\nbabbbaaaa\nabba\naaaaabaa\nbabaababb\n5\nbabb\nbaabaaa\nbab\nbb\nbbabbaab\n";
    // auto fp = fopen("./input.txt","w");
    // fprintf(fp, "%s", input);
    // fflush(fp);
    // freopen("./input.txt","r",stdin);
    scanf("%d", &n);
    Trie<26> trie;
    for (int i = 0; i < n; ++i) {
        scanf("%s", word);
        trie.insert(std::string(word));
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", word);
        printf("%d\n", trie.search(std::string(word)));
    }
    return 0;
}