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

#include <iostream>
#include <new>
#include <stdexcept>

template<typename T>
class CircularLinkedList {

    struct Node {
        T value;
        struct Node *next;
        struct Node *prev;
    };

public:

    CircularLinkedList() : head(nullptr), tail(nullptr), capacity(0u) {}; 
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
   
    ~CircularLinkedList();

private:
    struct Node *head;
    struct Node *tail;
    std::size_t capacity;

    void init_push(T const &value);
};

template<typename T>
void CircularLinkedList<T>::init_push(T const &value)   {
    head = (struct Node*) std::malloc(sizeof *head);

    if (head == nullptr)  {
        throw std::bad_alloc();
    }

    capacity++;

    head->value = value;
    head->next = head;
    head->prev = head;
    tail = head;
}

template<typename T>
inline bool CircularLinkedList<T>::is_empty() const {
    return capacity == 0;
}

template<typename T>
inline std::size_t CircularLinkedList<T>::size() const {
    return capacity;
}

template<typename T>
void CircularLinkedList<T>::push_front(T const value)    {
    if (is_empty()) {
        init_push(value);
        return;
    }
    
    capacity++;

    struct Node *node = (struct Node*) std::malloc(sizeof *node);

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    node->value = value;
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head = node;
}

template<typename T>
void CircularLinkedList<T>::push_back(T const value)
{ 
    if (is_empty()) {
        init_push(value);
        return;
    }
    
    capacity++;

    struct Node *node = (struct Node*) std::malloc(sizeof *node);

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    node->value = value;
    node->next = head;
    head->prev = node;
    tail->next = node;
    tail = node;
}

template<typename T>
void CircularLinkedList<T>::pop_front()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }
    
    capacity--;

    struct Node *temp = head->next;
    free(head);
    tail->next = temp;
    temp->prev = tail;
    head = temp;
}

template<typename T>
void CircularLinkedList<T>::pop_back()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }
    
    capacity--;
    
    struct Node *temp = head;
    while (temp->next != head)   {
        temp = temp->next;
    }
    
    temp->next = head;
    head->prev = temp;
    free(tail);
    tail = temp;
}

template<typename T>
T& CircularLinkedList<T>::operator[](std::size_t const index)  {
    struct Node *head_iter = head;

    for (std::size_t i = 0u; i < index; ++i) {
       head_iter = head_iter->next; 
    }

    return head_iter->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T CircularLinkedList<T>::front() const {
    if (head == nullptr)    {
        throw std::runtime_error("List is empty!\n");
    }

    return head->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T CircularLinkedList<T>::back() const {
    if (tail == nullptr)    {
        throw std::runtime_error("List is empty!\n");
    }

    return tail->value;
}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    struct Node *next = head->next;
    do {
        free(head);
        head = next;
        next = next->next;
    } while (next != tail->next);
}

int main(int argc, const char * const argv[])
{
    CircularLinkedList<int> list;
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
