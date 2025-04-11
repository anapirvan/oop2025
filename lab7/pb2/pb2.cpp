#include <iostream>
#define MAX_CHILDREN 100
#include "Tree.h"

int main()
{
    Tree<int> t;
    t.addNode(t.getNode(nullptr, 0), 1);
    t.addNode(t.getNode(nullptr, 0), 2);
    t.addNode(t.getNode(nullptr, 0), 3);

    Nod<int>* root = t.getNode(nullptr, 0);

    t.addNode(t.getNode(t.getNode(nullptr, 0), 0), 4);
    t.addNode(t.getNode(t.getNode(nullptr, 0), 0), 5);
    t.addNode(t.getNode(t.getNode(nullptr, 0), 0), 6);

    t.delete_node(root->children[2]);
    t.insert(root, 2, 10);

    t.printNode(t.getNode(nullptr, 0));
    Nod<int>* pointer = t.find(4, compara);
    t.Sort(root, comparaElemente);
    t.printNode(root);
    t.count(nullptr);

    return 0;
}
