#include <iostream>
#include <stdexcept>

template<typename T>
class SinglyLinkedList {

    struct Node {
        T value;
        Node *next;
    };

public:

    SinglyLinkedList() : head(nullptr), tail(nullptr), capacity(0u) {}; 
    //explicit SinglyLinkedList(SinglyLinkedList const &other) : head(other.head), tail(other.tail), capacity(other.capacity) {};

    inline bool is_empty() const;
    inline std::size_t size() const;

    void push_front(T const value);
    void push_back(T const value);
    void pop_front();
    void pop_back();
    
    inline T front() const;
    inline T back() const;

    //T at(std::size_t const index) const;
    T& operator[](std::size_t const index);
   
    ~SinglyLinkedList();

private:
    Node *head;
    Node *tail;
    std::size_t capacity;

    void init_push(T const &value);
};

template<typename T>
void SinglyLinkedList<T>::init_push(T const &value)   {
    head = static_cast<Node*>(std::malloc(sizeof *head));

    if (head == nullptr)    {
        throw std::bad_alloc();
    }

    capacity++;
    head->value = value;
    head->next = nullptr;
    tail = head;
}

template<typename T>
inline bool SinglyLinkedList<T>::is_empty() const {
    return capacity == 0;
}

template<typename T>
inline std::size_t SinglyLinkedList<T>::size() const {
    return capacity;
}

template<typename T>
void SinglyLinkedList<T>::push_front(T const value)    {
    if (is_empty()) {
        init_push(value);
        return;
    }
    
    Node *node = static_cast<Node*>(std::malloc(sizeof *node));

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    capacity++;
    node->value = value;
    node->next = head;
    head = node;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T const value)
{ 
    if (is_empty()) {
        init_push(value);
        return;
    }

    Node *node = static_cast<Node*>(std::malloc(sizeof *node));

    if (node == nullptr)    {
        throw std::bad_alloc();
    }

    capacity++;
    node->value = value;
    node->next = nullptr;

    tail->next = node;
    tail = node;
}

template<typename T>
void SinglyLinkedList<T>::pop_front()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }
    
    capacity--;
    Node *temp = head->next;
    free(head);
    head = temp;
}

template<typename T>
void SinglyLinkedList<T>::pop_back()
{
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
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
T& SinglyLinkedList<T>::operator[](std::size_t const index)  {
    Node *iter = head;

    for (std::size_t i = 0u; i < index; ++i) {
       iter = iter->next; 
    }

    return iter->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T SinglyLinkedList<T>::front() const {
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }

    return head->value;
}

//TODO: if list is empty, then std::expected<T, std::runtime_error> or throw exception
template<typename T>
T SinglyLinkedList<T>::back() const {
    if (is_empty()) {
        throw std::runtime_error("List is empty!\n");
    }

    return tail->value;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (head)   {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(int argc, const char * const argv[])
{
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_front(88);
    list.push_front(111);
    list.push_back(12);
    
    list.pop_back();
    list.pop_front();

    for (std::size_t i = 0u; i < list.size(); ++i) {
        std::cout << list[i] << "\n";
    }

    return 0;
}
