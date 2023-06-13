#ifndef KP8_ITERATOR_HPP
#define KP8_ITERATOR_HPP
#include "../include/Node.hpp"
#include "../include/List.hpp"
template<typename T>
class List;

template<typename T>
class iterator {
private:
    node<T>* currentNode;
public:
    friend class List<T>;
    iterator();
    iterator(const List<T>& list);
    iterator(node<T>* node);

    iterator<T>& operator++();
    T& operator*() const;
    iterator<T> operator+(size_t);
    bool operator==(const iterator<T>& other) const;
    bool operator!=(const iterator<T>& other) const;
};

#include "../src/Iterator.cpp"


#endif //KP8_ITERATOR_HPP
