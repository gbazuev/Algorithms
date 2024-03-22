/*  Double linked list
 *  1. template<typename T> (without Allocator and other stuff)
 *  2. Capacity: 
 *              isEmpty() { returns boolean value }
 *              Size() { return m_size field (how many elements list has) }
 *  3. Basic operations:
 *              Push(int index (or using Iterators), T const value)
 *              PushFront(T const value)
 *              PushBack(T const value)
 *              Pop(int index (or using Iterators))
 *              PopFront()
 *              PopBack()
 *              At(int index (or using Iterators))
 *
 *  4. Operators:
 *              [] (equals At)
 *              = (defining)
 *
 *  5. Iterators:
 *              begin() { returns list begin }
 *              end()   { retunst list end }
 */

#include <cstdlib>
#include <iostream>

template<typename T>
class DoublyLinkedList {

    struct Node {
        T value;
        Node *next;
        Node *prev;
    };

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), capacity(0u) {}; 
    //explicit SinglyLinkedList(SinglyLinkedList const &other) : head(other.head), tail(other.tail), capacity(other.capacity) {};

    inline bool is_empty() const;
    inline std::size_t size() const;

    void push_front(T const value);
    void push_back(T const value);
    void pop_front();
    void pop_back();
    
    T front() const;
    T back() const;

    //T at(std::size_t const index) const;
    T& operator[](std::size_t const index);
   
    ~DoublyLinkedList();

private:
    Node *head;
    Node *tail;
    std::size_t capacity;

    void init_push(T const &value);
};

template<typename T>
void DoublyLinkedList<T>::init_push(T const &value)   {
    capacity++;

    head = (Node*) malloc(sizeof *head);
    head->value = value;
    head->next = nullptr;
    head->prev = nullptr;
    tail = head;
}

template<typename T>
inline bool DoublyLinkedList<T>::is_empty() const {
    return capacity == 0;
}

template<typename T>
inline std::size_t DoublyLinkedList<T>::size() const {
    return capacity;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T const value)    {
    if (is_empty()) {
        init_push(value);
        return;
    }
    
    capacity++;

    Node *node = (Node*) malloc(sizeof *node);
    node->value = value;
    node->next = head;
    node->prev = nullptr;
    head = node;
}

template<typename T>
void DoublyLinkedList<T>::push_back(T const value)
{ 
    if (is_empty()) {
        init_push(value);
        return;
    }
    
    capacity++;

    Node *node = (Node*) malloc(sizeof *node);
    node->value = value;
    node->next = nullptr;
    node->prev = tail;

    tail->next = node;
    tail = node;
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (is_empty()) {
        return;
        //TODO: std::excepted;
    }
    
    capacity--;

    Node *temp = head->next;
    free(head);
    head = temp;
}

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (is_empty()) {
        return;
        //TODO: std::excepted
    }
    
    capacity--;
    
    Node *temp = head;
    while (temp->next != tail)   {
        temp = temp->next;
    }
    
    temp->next = nullptr;
    free(tail);
    tail = temp;
}

template<typename T>
T& DoublyLinkedList<T>::operator[](std::size_t const index)  {
    Node *beginiter = head;

    for (std::size_t i = 0u; i < index; ++i) {
       beginiter = beginiter->next; 
    }

    return beginiter->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T DoublyLinkedList<T>::front() const {
    return head->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T DoublyLinkedList<T>::back() const {
    return tail->value;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)   {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(int argc, const char * const argv[])
{
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_front(88);
    list.push_front(111);
    list.push_back(12);
    
    list.pop_back();
    list.pop_front();

    for (auto i = 0u; i < list.size(); ++i) {
        std::cout << list[i] << "\n";
    }

    return 0;
}
