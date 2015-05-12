// Implementierung eines Eigenen Shared Pointers
#ifndef OWN_SP_HPP
#define OWN_SP_HPP

#include "own_rc.hpp"

template<typename T>
class own_sp {
 private:
  T*      m_data;      // RAW Pointer auf Daten
  own_rc* m_reference; // RAW Pointer auf Referenzzähler
 public:
  own_sp() : m_data(nullptr), m_reference(new own_rc) {
    m_reference->addref();
  }

  own_sp(T* value) : m_data(value), m_reference(new own_rc) {
    m_reference->addref();
  }

  // Copy CTOR
  own_sp(const own_sp<T>& other)
      : m_data(other.m_data), m_reference(other.m_reference) {
    m_reference->addref();
  }

  ~own_sp() {
    if(m_reference->release() == 0) {
      delete m_data;
      delete m_reference;
    }
  }

  T& operator*() {
    return *m_data;
  }

  T* operator-> () {
    return m_data;
  }

  // Assignment operator
  own_sp<T>& operator = (const own_sp<T>& other) {
    if (this != &other) { // Self assignment ignorieren...
      if(m_reference->release() == 0) {
        delete m_data;
        delete m_reference;
      }
      m_data = other.m_data;
      m_reference = other.m_reference;
      m_reference->addref();
    }
    return *this;
  }
};

#endif // OWN_SP_HPP
