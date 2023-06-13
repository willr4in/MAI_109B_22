#ifndef KP8_LIST_HPP
#define KP8_LIST_HPP
#include "../include/Iterator.hpp"
#include <iostream>
template<typename T>
class List {
private:
    node<T>* start;
public:
    friend class iterator<T>;
    List();
    List(const size_t, const T& = T());
    List(const List<T>&);

    std::ostream& operator<<(std::ostream& stream);

    void push_back(const T&);
    void push_front(const T&);
    template<typename... Args>
    void emplace_back(const Args&...);
    template<typename... Args>
    void emplace_front(const Args&...);
    void pop_back();
    void pop_front();
    void insert(const iterator<T>&, const T& data);
    void erase(const iterator<T>&, const iterator<T>&);
    void swaNodes(int k);

    iterator<T> begin() const;
    iterator<T> end() const;

    ~List();

#include "../src/List.cpp"

#endif //KP8_LIST_HPP
