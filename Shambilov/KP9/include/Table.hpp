#ifndef KP9_TABLE_HPP
#define KP9_TABLE_HPP
#include "../../KP7/include/MyVector.hpp"

template<typename T>
class Table {
private:
    myVector<T> keys;
    myVector<std::string> lines;

public:

    Table() = default;
    ~Table() = default;

    int partition(int start, int end);
    void insertInfo(const T &key, const std::string &input_data);
    std::string binarySearch(const T &key);
    void sortOfKhoar();

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, Table<U> &line);
    template<typename U>
    friend std::istream &operator>>(std::istream &in, Table<U> &line);
};

#include "../src/Table.cpp"

#endif //KP9_TABLE_HPP