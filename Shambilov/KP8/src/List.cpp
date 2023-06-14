#include "../include/List.hpp"

template<typename T>
List<T>::List() {
    this->start = new node<T>();
    this->start->nextNode = this->start;
}

template<typename T>
List<T>::List(const size_t size, const T& value): List() {
    for (size_t currentValue = 0; currentValue < size; ++currentValue) {
        this->push_front(value);
    }
}

template<typename T>
List<T>::List(const List<T>& other) {
    iterator<T> it = other.begin();
    while (it != other.end()) {
        this->push_back(*it);
        ++it;
    }
}

template<typename T>
void List<T>::push_back(const T& value) {
    if (this->begin() == this->end()) {
        this->begin().currentNode->nextNode = new node(value, this->start);
        this->start = this->begin().currentNode->nextNode;
        return;
    }

    iterator<T> it = this->begin();
    while(it.currentNode->nextNode->nextNode != this->start){
        ++it;
    }

    it.currentNode->nextNode = new node(value, it.currentNode->nextNode);
}

template<typename T>
void List<T>::push_front(const T& value) {
    if (this->begin().currentNode->nextNode == this->start) {
        this->begin().currentNode->nextNode = new node(value, this->start);
        this->start = this->begin().currentNode->nextNode;
        return;
    }

    this->begin().currentNode->nextNode = new node(*(this->begin()), this->begin().currentNode->nextNode);
    *(this->begin()) = value;
}

template<typename T>
template <typename... Args>
void List<T>::emplace_back(const Args&...args) {
    this->push_back(T(args...));
}

template<typename T>
template <typename... Args>
void List<T>::emplace_front(const Args&...args) {
    this->push_front(T(args...));
}

template<typename T>
void List<T>::pop_back() {
    if(this->begin().currentNode->nextNode == this->start) {
        return;
    }

    iterator<T> it = this->begin();
    while(it.currentNode->nextNode->nextNode != this->start) {
        ++it;
    }
    delete it.currentNode->nextNode;
    it.currentNode->nextNode = this->start;
}

template<typename T>
void List<T>::pop_front() {
    if (this->begin().currentNode->nextNode == this->start) {
        return;
    }

    iterator<T> it = ++(this->begin());
    this->begin().currentNode->data = (++(this->begin())).currentNode->data;
    this->begin().currentNode->nextNode = (++(this->begin())).currentNode->nextNode;
    delete it.currentNode;
}

template<typename T>
void List<T>::insert(const iterator<T>& it, const T& data) {
    it.currentNode->nextNode = new node(data, it.currentNode->nextNode);
}

template<typename T>
void List<T>::erase(const iterator<T>& start, const iterator<T>& end) {
    iterator<T> eraseIt = start;
    ++eraseIt;
    start.currentNode->nextNode = end.currentNode;

    while (eraseIt != end) {
        if (eraseIt == this->begin()) {
            this->start = end.currentNode;
        }
        node<T>* deleteNode = eraseIt.currentNode;
        ++eraseIt;
        delete deleteNode;
    }
}

template <typename T>
void List<T>::swapNodes(int k) {
    if (k < 1 || k >= size - 1) {
        return;
    }

    Node* prev = nullptr;
    Node* current = start;

    for (int i = 0; i < k - 1; i++) {
        prev = current;
        current = current->next;
    }

    Node* next = current->next;
    current->next = next->next;
    next->next = current;

    if (prev == nullptr) {
        head = next;
    }
    else {
        prev->next = next;
    }
}

template<typename T>
iterator<T> List<T>::begin() const {
    return iterator(*this);
}

template<typename T>
iterator<T> List<T>::end() const {
    node<T>* endNode = this->start;
    while (endNode->nextNode != this->start) {
        endNode = endNode->nextNode;
    }
    return iterator(endNode);
}

template<typename T>
List<T>::~List() {
    iterator<T> curIt = ++(this->begin());
    iterator<T> delIt = curIt;
    while (curIt.currentNode != this->start) {
        ++curIt;
        delete delIt.currentNode;
        delIt = curIt;
    }
    delete curIt.currentNode;
}

template<typename T>
std::ostream& List<T>::operator<<(std::ostream& os) {
    node<T>* currentNode = this->start;
    while (currentNode->nextNode != this->start) {
        os << currentNode->data << ' ';
        currentNode = currentNode->nextNode;
    }
    return os;
}