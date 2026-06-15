#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e6+1;

struct node {
    char c;
    int pri, l_sz, r_sz;
    node *lc, *rc, *p;
} nodes[maxN+1], *last = nodes, *root;

//

// make a rotation at r and one of its children node
// -- 0: left, 1: right
// return the new parent node of r
node *rotate_dir( node *r, bool dir );

// rebuild the heap property at r
// return the new root of the subtree
// (assumption: heap property holds for subtrees of r)
node *max_heapify( node *r );

// to insert the node nde
// as the (pos+1)-th element in the BST rooted at r
void BST_insert_after( node *r, int pos, node *nde );

// to insert the node nde
// as the pos-th element in the BST rooted at r
void BST_insert_before( node *r, int pos, node *nde );

// to split the treap r at the pos-th position
tuple<node*,node*> split_before( node *r, int pos );

// to merge the treaps r1 and r2
node *merge_treap( node *r1, node *r2 );

// to build a treap rooted at r
// (as a child node of p)
// for the substring s[left...right]
node *build_treap( node *r, string &s, int left, int right, node *p );