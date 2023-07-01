#ifndef LINKDEDLIST_H
#define LINKDEDLIST_H

#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
public:
  LinkedList(int);
  ~LinkedList();

  void appendNode(T value);
  void deleteNode(T value);
  T getNodeValue(int pos);
  void displayList() const;
  void destroyList();
  int getNodeSize();
  int getMaxNodeSize();

private:
  struct ListNode {
    T data;
    struct ListNode *next;
  };

  ListNode *head;
  int MAX_NODE;
  int node_size;
  
};

template <class T>
LinkedList<T>::LinkedList(int maxNode){
  MAX_NODE = maxNode;
  head = nullptr;
  node_size = 0;
}

//destructor
template<class T>
LinkedList<T>::~LinkedList(){
  destroyList();
}

template <class T>
void LinkedList<T>::destroyList() {
  ListNode* nodePtr = head;

  while (nodePtr) {
    ListNode* nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }

  head = nullptr;  // Set head to nullptr to indicate an empty list
  node_size = 0;
}

template <class T>
T LinkedList<T>::getNodeValue(int pos) {
  ListNode *nodePtr = head;

  if (!head) {
    cout << "List is empty" << endl;
    return T();  // Return a default-constructed value if the list is empty
  } else {
    int i = 1;
    while (nodePtr && i != pos) {
      nodePtr = nodePtr->next;
      i++;
    }

    if (nodePtr && i == pos) {
      return nodePtr->data;
    } else {
      cout << "Invalid position" << endl;
      return T();  // Return a default-constructed value for an invalid position
    }
  }
}

template <class T>
void LinkedList<T>::appendNode(T value) {

  if (node_size >= MAX_NODE){
    cout << "Max node list already please delete a node to add a new node" << endl;
    return;
  }

  ListNode* nodePtr; // declare nodePtr
  ListNode* newNode; // declare newNode

  nodePtr = head;

  // let newNode value with input num and the newNode->next to nullptr
  newNode = new ListNode;
  newNode->data = value;
  newNode->next = nullptr;

  if(!head){ // if the head is nullptr then head = newNode
    head = newNode;
    node_size++;
  }
  else {
    // initialize the nodePtr to head
    nodePtr = head;

    // traverse through the node until last node
    while (nodePtr->next)
      nodePtr = nodePtr->next;

    // insert newNode as the last node on the list
    nodePtr->next = newNode;

    node_size++;
  }
}

template <class T>
void LinkedList<T>::deleteNode(T value){
  ListNode *nodePtr;
  ListNode *nodePrevious;

  nodePtr = head;

  if (!head) { return; }
  if (head->data == value) {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
    node_size--;
  }

  else {
    nodePtr = head;

    while(nodePtr != nullptr && nodePtr->data != value){
      nodePrevious = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (nodePtr){
      nodePrevious->next = nodePtr->next;
      delete nodePtr;
      node_size--;
    }
  }
}

template <class T>
void LinkedList<T>::displayList() const {
  ListNode *nodePtr;
  nodePtr = head;

  if (!head){
    cout << "List is empty" << endl;
    return;
  }

  while(nodePtr != nullptr){
    cout << nodePtr->data << endl;
    nodePtr = nodePtr->next;
  }
}

template <class T>
int LinkedList<T>::getNodeSize(){
  return node_size;
}

template <class T>
int LinkedList<T>::getMaxNodeSize(){
  return MAX_NODE;
}

#endif // !LINKDEDLIST_H
