#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *n = new Node;
  n->s = new Student(s);
  n->next = NULL;
  if (tail == NULL) {
    head = tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
}

std::string StudentRoll::toString() const {
  std::string result = "[";
  for (Node *curr = head; curr != NULL; curr = curr->next) {
    result += curr->s->toString();
    if (curr->next != NULL)
      result += ",";
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  for (Node *curr = orig.head; curr != NULL; curr = curr->next) {
    insertAtTail(*(curr->s));
  }
}

StudentRoll::~StudentRoll() {
  Node *curr = head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    delete temp->s;
    delete temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  if (&right == this) 
    return (*this);

  Node *curr = head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    delete temp->s;
    delete temp;
  }
  head = tail = NULL;

  for (Node *curr = right.head; curr != NULL; curr = curr->next) {
    insertAtTail(*(curr->s));
  }

  return (*this); 
}





