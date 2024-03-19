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

template<typename T>
class SinglyLinkedList {

    struct Node {
        T value;
        Node *next;
    };

public:

    SinglyLinkedList() : head(nullptr), capacity(0u) {}; 
    explicit SinglyLinkedList(SinglyLinkedList const &other) : head(other.head), capacity(other.capacity) {};

    bool is_empty() const;
    std::size_t size() const;

    void push_front(T const value);
    void push_back(T const value);
    void pop_front();
    void pop_back();

    //T at(std::size_t const index) const;
    T& operator[](std::size_t const index);
   
    ~SinglyLinkedList();

private:
    Node *head;
    std::size_t capacity;

    void fill_head(T const value);
};

template<typename T>
bool SinglyLinkedList<T>::is_empty() const {
    return capacity == 0;
}

template<typename T>
std::size_t SinglyLinkedList<T>::size() const {
    return capacity;
}

template<typename T>
void SinglyLinkedList<T>::fill_head(T const value)
{
    capacity++;
    head = new Node();
    head->value = value;
    head->next = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::push_front(T const value)    {
    if (is_empty()) {
        fill_head(value);
        return;
    }
    
    capacity++;

    Node *node = new Node();
    node->value = value;
    node->next = head;
    head = node;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T const value)
{ 
    if (is_empty()) {
        fill_head(value);
        return;
    }
    
    capacity++;

    Node *headiter = head;
    while (headiter->next)  {
        headiter = headiter->next;
    }

    Node *node = new Node();
    node->value = value;
    node->next = nullptr;

    headiter->next = node;
}

template<typename T>
void SinglyLinkedList<T>::pop_front()
{
    if (is_empty()) {
        return;
        //TODO: std::excepted;
    }
    
    capacity--;

    Node *temp_head = head->next;
    delete head;
    head = temp_head;
}

template<typename T>
void SinglyLinkedList<T>::pop_back()
{
    if (is_empty()) {
        return;
        //TODO: std::excepted
    }
    
    capacity--;

    Node *headiter = head;
    Node *temp = nullptr;

    while (headiter)    {
        if (headiter->next) {
            if (headiter->next->next == nullptr)    {
                temp = headiter->next;
                break;
            }
            headiter = headiter->next;
        }
    }

    headiter->next = nullptr;
    delete temp;
}

template<typename T>
T& SinglyLinkedList<T>::operator[](std::size_t const index)  {
    Node *beginiter = head;

    for (std::size_t i = 0u; i < index; ++i) {
       beginiter = beginiter->next; 
    }

    return beginiter->value;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (head)   {
        Node *next = head->next;
        delete head;
        head = next;
    }
}

int main(int argc, const char * const argv[])
{
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.pop_back();

    for (auto i = 0u; i < list.size(); ++i) {
        std::cout << list[i] << "\n";
    }

    return 0;
}
