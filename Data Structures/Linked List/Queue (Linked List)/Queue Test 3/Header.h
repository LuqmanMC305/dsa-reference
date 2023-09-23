#ifndef MYQUEUE_
#define MYQUEUE_
#include <iostream>

template <typename T>
class Queue
{
    private:
      struct Node
      {
          T value;
          Node* next;
      };
      Node* front;
      Node* rear;
      int numItems;

    public:
      Queue() : front(nullptr), rear(nullptr), numItems(0) {}
      ~Queue()
      {
        while (!isEmpty())
        {
            dequeue();
        }
      }
      bool isEmpty() {return (front == nullptr);}
      void enqueue(T newValue);
      T dequeue();
      T peek();
};

template <typename T>
void Queue<T>::enqueue(T newValue)
{
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;

    if(isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++;
}

template <typename T>
T Queue<T>::dequeue()
{
    Node* temp = nullptr;
    T dequeueValue;

    if(isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
        return T();
    }
    else
    {
       dequeueValue = front->value;
       temp = front;
       front = front->next;
       delete temp;
       temp = front;
       numItems--;
    }

    return dequeueValue;



}

template <typename T>
T Queue<T>::peek()
{
    Node* temp = nullptr;
    T dequeueValue;

    if(isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
        return T();
    }
    else
    {
        dequeueValue = front->value;

    }

    return dequeueValue;
}

#endif