#include <iostream>
#include <stdexcept>

template<typename T>
class LinkedList
{
    struct Node 
    {
        T value;
        struct Node *next;
        struct Node *prev;
    };

public:

    LinkedList() : head(nullptr), tail(nullptr), capacity(0u) {}; 
    //explicit SinglyLinkedList(SinglyLinkedList const &other) : head(other.head), tail(other.tail), capacity(other.capacity) {};

    inline bool is_empty() const noexcept;
    inline std::size_t size() const noexcept;

    void push_front(T const value);
    void push_back(T const value);
    void pop_front();
    void pop_back();
    
    T front() const;
    T back() const;

    //T at(std::size_t const index) const;
    T& operator[](std::size_t const index);
   
    ~LinkedList();

private:
    struct Node *head;
    struct Node *tail;
    std::size_t capacity;

    void init_push(T const &value);
};

template<typename T>
void LinkedList<T>::init_push(T const &value)   {
    head = static_cast<Node*>(std::malloc(sizeof *head));

    if (head == nullptr)  {
        throw std::bad_alloc();
    }

    head->value = value;
    head->next = head;
    head->prev = head;
    tail = head;
    capacity++;
}

template<typename T>
inline bool LinkedList<T>::is_empty() const noexcept 
{
    return capacity == 0;
}

template<typename T>
inline std::size_t LinkedList<T>::size() const noexcept
{
    return capacity;
}

template<typename T>
void LinkedList<T>::push_front(T const value)    
{
    if (is_empty()) {
        init_push(value);
        return;
    }

    struct Node *node = static_cast<Node*>(std::malloc(sizeof *node));

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    node->value = value;
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head = node;
    capacity++;
}

template<typename T>
void LinkedList<T>::push_back(T const value)
{ 
    if (is_empty()) {
        init_push(value);
        return;
    }

    struct Node *node = static_cast<Node*>(std::malloc(sizeof *node));

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    node->value = value;
    node->next = head;
    head->prev = node;
    tail->next = node;
    tail = node;
    capacity++;
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }
    
    struct Node *temp = head->next;
    free(head);
    tail->next = temp;
    temp->prev = tail;
    head = temp;
    capacity--;
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }

    struct Node *temp = head;
    while (temp->next != head)   {
        temp = temp->next;
    }
    
    temp->next = head;
    head->prev = temp;
    free(tail);
    tail = temp;
    capacity--;
}

template<typename T>
T& LinkedList<T>::operator[](std::size_t const index)
{
    struct Node *iter = head;

    for (std::size_t i = 0u; i < index; ++i) {
       iter = iter->next; 
    }

    return iter->value;
}

template<typename T>
T LinkedList<T>::front() const
{
    if (head == nullptr)    {
        throw std::runtime_error("List is empty!\n");
    }

    return head->value;
}

template<typename T>
T LinkedList<T>::back() const
{
    if (tail == nullptr)    {
        throw std::runtime_error("List is empty!\n");
    }

    return tail->value;
}

template<typename T>
LinkedList<T>::~LinkedList()
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
    LinkedList<int> list;
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
