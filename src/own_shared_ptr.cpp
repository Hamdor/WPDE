#include "own_sp.hpp"
#include <iostream>

struct my_struct {
  int value = 0;
  my_struct() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
  ~my_struct() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

int main() {
  own_sp<my_struct> sp = own_sp<my_struct>(new my_struct);
  sp->value = 42;
  std::cout << sp->value << std::endl;
  std::cout << "sp sollte gleich gelöscht werden..." << std::endl;
  return 0;
}
