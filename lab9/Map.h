#pragma once

template<class K, class V>
struct Pair
{
    K key;
    V value;
    unsigned int index;
};

template<class K, class V>
class Map
{
private:
    Pair<K, V>* pairs;
    unsigned int count;
public:
    Map();
    V& operator[](const K& key);
    Pair<K, V>* begin();
    Pair<K, V>* end();
    void Print();
    void Set(const K& key, const V& value);
    bool Get(const K& key, V& value);
    int Count();
    void Clear();
    bool Delete(const K& key);
    bool Includes(const Map<K, V>& map);
};

template<class K, class V>
Map<K, V>::Map()
{
    pairs = new Pair<K, V>[10];
    count = 0;
}

template<class K, class V>
V& Map<K, V>::operator[](const K& key)
{
    /*for (auto& it : (*this))
        if (it.key == key)
            return it.value;*/
    for (int i = 0;i < count;i++)
        if (pairs[i].key == key)
            return pairs[i].value;
    pairs[count].key = key;
    pairs[count].index = count;
    count++;
    return pairs[count - 1].value;
}

template<class K, class V>
void Map<K, V>::Print()
{
    for (int i = 0;i < count;i++)
        std::cout << pairs[i].key << " " << pairs[i].value << "\n";
}

template<class K, class V>
Pair<K, V>* Map<K, V>::begin()
{
    return &pairs[0];
}

template<class K, class V>
Pair<K, V>* Map<K, V>::end()
{
    return &pairs[count];
}

template<class K, class V>
void Map<K, V>::Set(const K& key, const V& value)
{
    for (int i = 0;i < count;i++)
        if (pairs[i].key == key)
        {
            pairs[i].value = value;
            return;
        }
    pairs[count].key = key;
    pairs[count].index = count;
    count++;
    pairs[count - 1].value=value;
}

template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
    for(int i=0;i<count;i++)
        if (pairs[i].key == key)
        {
            value = pairs[i].value;
            return true;
        }
    return false;
}

template<class K, class V>
int Map<K, V>::Count()
{
    return this->count;
}

template<class K, class V>
void Map<K, V>::Clear()
{
    count = 0;
}

template<class K, class V>
bool Map<K, V>::Delete(const K& key)
{
    for (int i = 0;i < count;i++)
        if (pairs[i].key == key)
        {
            for (int j = i ;j < count - 1;j++)
                pairs[j] = pairs[j + 1];
            count--;
            return true;
        }
    return false;
}

template<class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{
    int cnt=0;
    int i;
    for( i=0;i<map.count;i++)
        for(int j=0;j<count;j++)
            if(map.pairs[i].key==pairs[j].key)
            {
                cnt++;
                break;
            }
    if (cnt == map.count)
        return true;
    return false;

}