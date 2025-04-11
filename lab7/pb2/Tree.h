#pragma once


template <class T>
struct Nod
{
    T value;
    int nrChildren;
    Nod<T>** children;
};

template <class T>
class Tree
{
private:
    Nod<T> root;
public:
    Tree();
    void addNode(Nod<T>* parent, T value);
    Nod<T>* getNode(Nod<T>* parent, int index);
    void printNode(Nod<T>* nod);
    void delete_node(Nod<T>* nod);
    Nod<T>* find(T value, bool (*compareFunc) (T, T));
    void insert(Nod<T>* nod, int index, T value);
    void Sort(Nod<T>* parent, bool (*compareFunc)(Nod<T>*, Nod<T>*));
    void count(Nod<T>* nod);
};

template <class T>
Tree<T>::Tree()
{
    root.value = 0;
    root.nrChildren = 0;
    root.children = new Nod<T>*[MAX_CHILDREN];
}

template <class T>
void Tree<T>::addNode(Nod<T>* parent, T value)
{

    Nod<T>* newNod;
    newNod = new Nod<T>;
    newNod->value = value;
    newNod->nrChildren = 0;
    newNod->children = new Nod<T>*[MAX_CHILDREN];
    /*
    parent->children[parent->nrChildren]=newNod;
    parent->children[parent->nrChildren] = new Nod<T>;
    parent->children[parent->nrChildren]->value = value;
    parent->children[parent->nrChildren]->nrChildren = 0;
    parent->children[parent->nrChildren]->children = new Nod<T>*[MAX_CHILDREN];
    */
    parent->children[parent->nrChildren] = newNod;
    parent->nrChildren++;
}

template <class T>
Nod<T>* Tree<T>::getNode(Nod<T>* parent, int index)
{
    if (parent == nullptr)
        return &root;
    return parent->children[index];
}

template <class T>
void Tree<T>::printNode(Nod<T>* nod)
{
    for (int i = 0; i < nod->nrChildren; i++)
    {
        std::cout << nod->children[i]->value << " ";
        std::cout << '\n';
    }
}

template <class T>
void Tree<T>::delete_node(Nod<T>* nod)
{
    if (nod->nrChildren > 0)
        for (int i = 0; i < nod->nrChildren; i++)
            delete_node(nod->children[i]);
    delete[] nod->children;
    delete nod;
}

template<class T>
Nod<T>* Tree<T>::find(T value, bool (*compareFunc)(T, T))
{
    return recursive_find(&root, value, compareFunc);
}

template<class T>
Nod<T>* recursive_find(Nod<T>* nod, T value, bool (*compareFunc) (T, T))
{
    Nod<T>* rez = nullptr;
    if (compareFunc(value, nod->value))
        return nod;
    if (nod->nrChildren == 0)
        return nullptr;
    for (int i = 0; i < nod->nrChildren; i++)
    {
        rez = recursive_find(nod->children[i], value, compareFunc);
        if (rez != nullptr)
            return rez;
    }
    return nullptr;
}

template <class T>
bool compara(T n1, T n2)
{
    return n1 == n2;
}

template <class T>
void Tree<T>::insert(Nod<T>* nod, int index, T value)
{
    Nod<T>* newNod = new Nod<T>;
    newNod->value = value;
    newNod->nrChildren = 0;
    newNod->children = new Nod<T>*[MAX_CHILDREN];

    nod->children[index] = newNod;
}

template <class T>
void Tree<T>::Sort(Nod<T>* parent, bool (*compareFunc)(Nod<T>*, Nod<T>*))
{
    bool sorted;
    do
    {
        sorted = 1;
        for (int i = 0; i < parent->nrChildren - 1; i++)
        {
            bool ord;
            if (compareFunc == nullptr)
                ord = (parent->children[i]->value < parent->children[i + 1]->value);
            else ord = compareFunc(parent->children[i], parent->children[i + 1]);

            if (!ord)
            {
                sorted = 0;
                Nod<T>* aux = parent->children[i];
                parent->children[i] = parent->children[i + 1];
                parent->children[i + 1] = aux;
            }
        }
    } while (!sorted);
}

template <class T>
bool comparaElemente(Nod<T>* t1, Nod<T>* t2)
{
    return (t1->value > t2->value);
}

template <class T>
void Tree<T>::count(Nod<T>* nod)
{
    if (nod == nullptr)
        count(&root);
    else
    {
        std::cout << "Nodul " << nod->value << " are " << nod->nrChildren << " copii\n";
        if (nod->nrChildren > 0)
            for (int i = 0; i < nod->nrChildren; i++)
                count(nod->children[i]);
    }
}



