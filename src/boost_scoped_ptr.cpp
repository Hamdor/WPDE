#include <iostream>
#include "boost/scoped_ptr.hpp"
using namespace std;

struct mystruct {
  mystruct() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  ~mystruct() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

int main() {
  {
    cout << "Enter scope" << endl;
    boost::scoped_ptr<mystruct> ptr(new mystruct); // heap mem allokieren
    cout << hex << "Addr of boost::scoped_ptr: " << &ptr << " (Stack)" << endl
         << "Addr of mystruct Pointer:  " << &(*ptr) << " (Heap)"  << endl;
    cout << "About to leave scope" << endl;
  } // heap speicher von mystruct wird freigegeben sobald ptr vom stack gelöscht
  cout << "Scope left" << endl;
  return 0;
}
