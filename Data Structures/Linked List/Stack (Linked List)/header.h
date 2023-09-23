#ifndef STACKLL_
#define STACKLL_
#include <iostream>

class Stack
{
    private:
      struct Node
      {
         int value;
         Node* next;
      };
      Node* top;

    public:
      Stack() : top(nullptr) {}
      ~Stack()
      {
         Node* temp;

         while (temp != nullptr)
         {
            temp = top;
            top = top->next;
            delete temp;
         }
      }
      bool isEmpty() {return (top == nullptr);}
      void push(int newValue);
      void pop();
      int peek();


};

void Stack::push(int newValue)
{
   Node* newNode = new Node;
   newNode->value = newValue;
   newNode->next = nullptr;

   if(isEmpty())
   {
      top = newNode;
   }
   else
   {
      newNode->next = top;
      top = newNode;
   }
}

void Stack::pop()
{
   Node* temp = nullptr;
   

   if(!isEmpty())
   {
      temp = top;
      top = top->next;
      delete temp;
   }
   else
   {
      std::cout << "The stack is empty." << std::endl;
   }

}

int Stack::peek()
{
    int poppedValue;

    if(isEmpty())
    {
       return -1;
    }
    else
    {
       poppedValue = top->value;
    }

    return poppedValue;
}

#endif
