include<bits/stdc++.h>

using namespace std;

class node              // creating a node
{
  public:
    int data;
  node * next;
  node * prev;
  node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insertAtHead(node * & head, int val) {
  node * ptr = new node(val);
  ptr -> next = head;
  if (head != NULL) {
    head -> prev = ptr;
  }
  head = ptr;
}

void display(node * head)               // to print the linked list
{
  node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << "<-->";
    temp = temp -> next;
  }
  cout << "NULL\n";
}

int main() {
  node* head=NULL;
  insertAtHead(head,1);
  insertAtHead(head,2);
  insertAtHead(head,3);
  insertAtHead(head,4);
  insertAtHead(head,5);
  display(head);

}

//TC : O(1)
//SC : O(1)
