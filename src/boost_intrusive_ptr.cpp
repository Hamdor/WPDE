#include <sstream>
#include <iostream>
#include <boost/intrusive_ptr.hpp>

using namespace std;

struct my_type {
  my_type() : m_refcount(0) { cout << __PRETTY_FUNCTION__ << endl; }
  ~my_type() { cout << __PRETTY_FUNCTION__ << endl; }
  long m_refcount;
};

inline void intrusive_ptr_add_ref(my_type* ptr) {
  cout << __PRETTY_FUNCTION__ << endl;
  ++ptr->m_refcount;
}

inline void intrusive_ptr_release(my_type* ptr) {
  cout << __PRETTY_FUNCTION__ << endl;
  if (--ptr->m_refcount == 0) {
    delete ptr;
  }
}

int fun(boost::intrusive_ptr<my_type> b) {
  cout << __PRETTY_FUNCTION__ << endl;
  return b.get()->m_refcount;
}

void recrusive_add_references(int n, boost::intrusive_ptr<my_type> ptr,
                              stringstream& ss) {
  if (n > 0) {
    recrusive_add_references(n-1, ptr, ss);
  } else {
    ss << "... Refcount: " << ptr.get()->m_refcount << endl;
  }
}

int main() {
  stringstream ss;
  { // lifetime scope of `ptr`
    boost::intrusive_ptr<my_type> ptr(new my_type);
    ss << "refcount after new : " << ptr.get()->m_refcount << endl;
    ss << "refcount after fun() call: " << fun(ptr)        << endl;
    ss << "refcount after fun() call II: " << fun(ptr)     << endl;
    ss << "Add 20 more references";
    recrusive_add_references(20, ptr, ss);
  }
  cout << "\nProgram output: " << endl << ss.str() << endl;
  return 0;
}
