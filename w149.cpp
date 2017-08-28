#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
//iostream 非常耗时

struct TrieNode {
    int ip;
    TrieNode *left, *right;
    bool status;
    bool set;
    TrieNode():ip(-1),left(NULL),right(NULL),status(false),set(false){}
};


struct Trie {
    TrieNode* root;
    bool ip[32];
    int mask;
    Trie(){
        root = new TrieNode;
        for (int i = 0; i < 32; ++i) {
            ip[i] = false;
        }
    }

    void ip2bin(string& line, int _mask) {
        stringstream ss;
        ss.str(line);
        int tmp;
        int m[8] = {128, 64, 32, 16, 8, 4, 2, 1};
        int count = 0;
        int offset = 0;
        mask = _mask;
        while(getline(ss, line, '.')) {
            tmp = stoi(line);
            for (int i = 0; i < 8; ++i) {
                ip[i + offset * 8] = bool((tmp&m[i])>0);
                ++count;
            }
            ++offset;
            if (count >= _mask) break;
        }
    }

    void insert(string& line, int _mask, bool s) {
        TrieNode* n = root;
        ip2bin(line, _mask);
        for (int i = 0; i < mask; ++i) {
            if (ip[i]) {
                if (!n->right) n->right = new TrieNode;
                n = n->right;
            } else {
                if (!n->left) n->left = new TrieNode;
                n = n->left;
            }
        }
        if (n->set) return;
        n->set = true;
        n->status = s;    
    }
    bool search(string& line) {
        ip2bin(line, 32);
        TrieNode* n = root;
        bool s = root->set?root->status:true;
        for (int i = 0; i < 32; ++i) {
            if (ip[i]) {
                if (n->right) {
                    n = n->right;
                    if (n->set) s = n->status;
                } else {
                    break;
                }
            } else {
                if (n->left) {
                    n = n->left;
                    if (n->set) s = n->status;
                } else {
                    break;
                }
            }
        }
        return s;
    }
};


int main(int argc, char const *argv[]) {
    int m, n, mask;
    string line, status;
    scanf("%d %d\n", &n, &m);
    Trie trie;
    char buffer[256];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buffer); status = buffer;
        scanf("%s", buffer); line = buffer;
        auto pos = line.find("/");
        if (pos != string::npos) {
            mask = stoi(line.substr(pos + 1));
            line = line.substr(0, pos);
        } else {
            mask = 32;
        }
        if (line=="0.0.0.0") {
            trie.root->set = true;
            trie.root->status =  status=="allow";
        } else {
            trie.insert(line, mask, status=="allow");
        }
    }


    for (int i = 0; i < m; ++i) {
        scanf("%s", buffer);
        line = buffer;
        bool is = trie.search(line);
        if (is) printf("YES\n");
        else printf("NO\n");
    }   
    return 0;
}