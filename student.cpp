#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->name = NULL;
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber;
}

void Student::setName(const char * const name) {
  delete [] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

Student::Student(const Student &orig) {
  this->name = NULL;
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
  delete [] name;
}

Student & Student::operator=(const Student &right) {
  if (&right == this) 
    return (*this);

  this->setName(right.name);
  this->setPerm(right.perm);

  return (*this); 
}

std::string Student::toString() const {
  return "[" + std::string(name) + "," + std::to_string(perm) + "]";
}

