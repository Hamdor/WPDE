#ifndef OWN_RC_HPP
#define OWN_RC_HPP

class own_rc {
 private:
  int m_count;
 public:
  void addref() {
    ++m_count;
  }

  int release() {
    return --m_count;
  }
};

#endif // OWN_RC_HPP
