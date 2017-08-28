#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

template<typename T>
struct Node{
    Node<T>(): l(nullptr), r(nullptr), p(nullptr), ls(0), rs(0), s(0){}
    Node<T>(T v): Node(){
        val = v;
    }
    Node<T> *l, *r, *p;
    int ls, rs, s;
    T val;
};

template<typename T>
struct Tree {
    Tree<T>(): root(nullptr){}
    Node<T> *root;
    Node<T>* insert(T n) {
        if (root == nullptr) return root = new Node<T>(n);
        else return insert(n, root);
    }
    
    int count(Node<T> *p) {
        return count(p, root);
    }

private:
    void update(Node<T> *r) {
        while (r->p) {
            ++r->p->s;
            if (r->p->l == r) ++r->p->ls;
            else ++r->p->rs;
            r = r->p;
        }
    }

    int count(Node<T> *p, Node<T> *r) {
        T n = p->val;
        if (!p || (!r->l && !r->r)) return 0;
        if (n >= r->val) return count(p, r->r);
        else return count(p, r->l) + r->rs + 1;
    }

    Node<T>* insert(T n, Node<T> *r) {
        if (n >= r->val) {
            if (r->r) {
                return insert(n, r->r);
            } else {
                Node<T> *p = new Node<T>(n);
                r->r = p;
                p->p = r;
                update(p);
                return p;
            }
        } else {
            if (r->l) {
                return insert(n ,r->l);
            } else {
                Node<T> *p = new Node<T>(n);
                r->l = p;
                p->p = r;
                update(p);
                return p;
            }
        }
    }

};

int main () {
    vector<int> v{9,8,7,6,5,4,3,2,1};
    Tree<int> r;
    for (auto i: v) {
        auto p = r.insert(i);
        cout << r.count(p) << " ";
    }
    return 0;
}