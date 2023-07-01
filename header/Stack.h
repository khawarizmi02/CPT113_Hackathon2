#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
  Stack();
  ~Stack();

  void push (T);
  void pop (T &);
  void top () const;
  bool isEmpty ();

private:
  struct StackNode
  {
    T value;
    StackNode *next;
  };
  StackNode *stackTop;
  
};

template <class T>
bool Stack<T>::isEmpty(){
  return stackTop == nullptr;
}

template <class T>
Stack<T>::Stack()
{
  stackTop = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
  StackNode *deleteStackTop;
  
  while (stackTop != NULL)
  {
    deleteStackTop = stackTop;
    stackTop = stackTop->next;
    delete deleteStackTop;
  }
}

template <class T>
void Stack<T>::push(T num){
  StackNode *newNode = nullptr;

  newNode = new StackNode;
  newNode->value = num;

  if (isEmpty()){
    stackTop = newNode;
    newNode->next = nullptr;
  }
  else {
    newNode->next = stackTop;
    stackTop = newNode;
  }
}

template <class T>
void Stack<T>::pop(T &num){
  StackNode *temp = nullptr;

  if (isEmpty()){
    cout << "stack is empty" <<endl;
    return;
  }
    num = stackTop->value;
    temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
}

template <class T>
void Stack<T>::top() const{

  cout << "value of top element of the stack: " << endl;
  cout << stackTop->value << endl;
}

#endif // !SATCK_H
