#ifndef POINTERSLL_
#define POINTERSLL_

#include <iostream>

template <typename T>
class LinkedList
{
    private:
      struct Node
      {
         T value;
         Node* next;
      };
      Node* head;

    public:
      LinkedList() : head(nullptr) {}
      ~LinkedList()
      {
         Node* temp;

         while (temp != nullptr)
         {
            temp = head;
            head = head->next;
            delete temp;
         }
      }
      void append(T newValue);
      void display();
      void addBeginning(T newValue);
      void deleteIndex(int targetIndex);
      void addAtIndex(int index, T newVal);
      void displayFast();
};

template <typename T>

void LinkedList<T>::append(T newValue)
{
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;

        while(current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

template <typename T>

void LinkedList<T>::display()
{
    if(head == nullptr)
    {
        return;
    }
    else
    {
        Node* current = head;

        while(current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
}

template <typename T>
void LinkedList<T>::addBeginning(T newValue)
{
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void LinkedList<T>::deleteIndex(int targetIndex)
{
    int currentIndex = 0;
    Node* current;
    Node* prev;

    if(head == nullptr)
    {
        return;
    }

    if(currentIndex == targetIndex)
    {
       current = head->next;
       delete head;
       head = current;
    }
    else
    {
        current = head;
        prev = nullptr;

        while(currentIndex != targetIndex)
        {
            prev = current;
            current = current->next;
            currentIndex++;
        }

        if(current != nullptr)
        {
           prev->next = current->next;
           delete current;
           std::cout << "Element deleted at index " << currentIndex << std::endl;
        }
    }
}

template <typename T>
void LinkedList<T>::addAtIndex(int index, T newVal)
{
   Node* newNode = new Node;
   newNode->value = newVal;
   newNode->next = nullptr;

   int currentIndex = 0;

   if(index < 0)
   {
     std::cout << "Invalid index." << std::endl;
     return;
   }

   else if(index == 0)
   {
     newNode->next = head;
     head = newNode;
   }
   else
   {
      Node* current = head;
      Node* prev;

      while(currentIndex != index && current != nullptr)
      {
        prev = current;
        current = current->next;
        currentIndex++;
      }

      if(current == nullptr)
      {
        std::cout << "Index out of bounds." << std::endl;
        return;
      }

      if(current->next == nullptr)
      {
        current->next = newNode;
        return;
      }

      prev->next = newNode;
      newNode->next = current;
   }
}

template <typename T>
//Using Fast Pointers

void LinkedList<T>::displayFast()
{
    Node* current = head;

    while(current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next->next;
    }
    
    std::cout << std::endl;
}


#endif