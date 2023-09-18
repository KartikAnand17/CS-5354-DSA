#include <iostream>
#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;

//Class for a Node in a Linked List
class Node{
  public:
  int data;
  Node *next;

  Node(){
    this->data =0;
    this->next = NULL;
  }
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

// function to print the LinkedList
void printLinkedList(Node* head){
  Node* temp = head;
  if(head == 0){return;}
  while(temp!=NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// function to insert nodes at the end of the LinkedList
void insertnode(Node* &head,int data)
{
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find length of the Linked List
int Length(Node* head){
  Node* temp = head;
  int length = 0;
  while(temp!=NULL){
    length++;
    temp = temp->next;
  }
  return length;
}

// Function to swap nodes
void swap(Node* &node1, Node* &node2){
  Node* temp = node2->next;
  node2->next = node1;
  node1->next = temp;
}

// Bubble Sort Function by swapping nodes
void BubbleSort(Node* &head){
  int length = Length(head);
  int i=0;
  int iteration = 1;
  while(i<length){
    Node*curr = head;
    Node* prev = head; // Node to update the head after every swap
    while(curr->next!=NULL){
      Node* nextNode = curr->next;
      if(curr->data>nextNode->data){
        if(curr == head){
          curr->next = nextNode->next;
          nextNode->next = curr;
          prev = nextNode;
          head = prev;
        }
        else{
          curr->next = nextNode->next;
          nextNode->next = curr;
          prev->next = nextNode;
          prev = nextNode;
        }
        continue;
      }
      prev = curr;
      curr = curr->next;
    }
    cout << "LinkedList after " << iteration << "th iteration" << endl;
    printLinkedList(head);
    cout << endl;
    iteration++;
    i++;
  }
}


int main() {
  Node* head = NULL;
  vector<int> LLelements {20,10,30,4,122,12332,41,543,12,44,35,987,23,212,332,112112,1};
  for(int i=0;i<LLelements.size();i++){
    insertnode(head,LLelements[i]);
  }
  BubbleSort(head);
  cout << "Final Sorted Linked List" << endl;
  printLinkedList(head);
}