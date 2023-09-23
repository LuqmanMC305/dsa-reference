#ifndef CDLL_H
#define CDLL_H
#include <iostream>

template <typename T>
class CDLL{
   private:
     struct Node{
        T data;
        Node* next;
        Node* prev;
     };
     Node* head;

   public:
     CDLL() : head(nullptr) {}
     ~CDLL();
     void append(T newData);
     void insert(T newData);
     void display();
     void deleteNode(T targetData);

};

template <typename T>
CDLL<T>::~CDLL(){
    Node* current = head;

    do{
        Node* temp = current;
        current = current->next;
        delete temp;

    }while (current != head);

    head = nullptr;
}

template <typename T>
void CDLL<T>::append(T newData){
   Node* newNode = new Node;
   newNode->data = newData;
   newNode->prev = nullptr;
   newNode->next = nullptr;

   if (head == nullptr){
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
   }

   else{
       
       Node* current = head;

       while (current->next != head){
          current = current->next;
       }

       current->next = newNode;
       newNode->prev = current;
       head->prev = newNode;
       newNode->next = head;

   }
}

template <typename T>
void CDLL<T>::display(){
    
    if (head == nullptr){
        std::cout << "The list is empty." << std::endl;
    }
    else{
       Node* current = head;

        do{
          std::cout << current->data << std::endl;
          current = current->next;

        }while (current != head);
    }


}

template <typename T>
void CDLL<T>::insert(T newData){
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr){
        head = newNode;
        head->prev = newNode;
        head->next = newNode;
    }
    else{
        Node* current = head;
        Node* prev = nullptr;

        while (current->next != head && current->data < newData){
            prev = current;
            current = current->next;
        }

        if (prev == nullptr){
            newNode->next = head;
            head->prev = newNode;
            head->next = newNode;
            newNode->prev = head;

        }
       
        else{
            newNode->next = current;
            newNode->prev = prev;
            prev->next = newNode;
            current->prev = newNode;
        }
    }


}

template <typename T>
void CDLL<T>::deleteNode(T targetData){
     if(head == nullptr){
        std::cout << "The list is empty." << std::endl;
        return;
     }
     else{
        Node* current = head;

        while (current->next != head && current->data != targetData){
           current = current->next;
        }

        if (current == head){
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        else{
            current->prev->next = current->next;
            current->next = current->prev;
        }

        delete current;
     }

     
}


#endif