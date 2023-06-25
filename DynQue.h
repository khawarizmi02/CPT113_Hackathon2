#ifndef DYNQUE_H
#define DYNQUE_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class DynQue
{
public:
  DynQue();
  ~DynQue();

  void enqueue(T);
  void dequeue(T &);
  bool isEmpty() const;
  void clear();

private:
  struct Node
  {
    T value;
    Node *next;
  };
  Node *front;
  Node *rear;
  int numItems;
  
};

template <class T>
DynQue<T>::DynQue(){
  front = nullptr;
  rear = nullptr;
  numItems = 0;
}

template <class T>
DynQue<T>::~DynQue(){
  clear();
}

template <class T>
void DynQue<T>::clear(){
  Node *temp = nullptr;

  if (isEmpty())
  {
    return;
  }
  else {
    while (!isEmpty())
    {
      temp = front;
      front = front->next;
      delete temp;
      numItems--;
    }
  }
}

template <class T>
bool DynQue<T>::isEmpty() const{
  return (numItems == 0);
}

template <class T>
void DynQue<T>::enqueue(T num){
  Node *newNode = nullptr;

  newNode = new Node;
  newNode->value = num;
  newNode->next = nullptr;

  if (isEmpty()){
    front = newNode;
    rear = newNode;
  }
  else {
    rear->next = newNode;
    rear = newNode;
  }

  numItems++;
}

template <class T>
void DynQue<T>::dequeue(T &num){
  Node *temp = nullptr;

  if (isEmpty()){
    cout << "Queue is empty" << endl;
  }
  else {
    num = front->value;

    temp = front;
    front = front->next;
    delete temp;
    numItems--;
  }
}
#endif // !DYNQUE_H
