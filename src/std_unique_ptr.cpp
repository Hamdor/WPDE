#include <memory>
#include <iostream>

#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

auto getaddrinfo(const string& host) {
  struct addrinfo info;
  struct addrinfo* res = NULL;
  std::memset(&info, 0, sizeof(addrinfo));
  info.ai_family   = AF_INET;
  info.ai_socktype = SOCK_STREAM;
  getaddrinfo(host.c_str(), NULL, &info, &res);
  //                  typ            deleter
  return unique_ptr<addrinfo, decltype(freeaddrinfo)*> { res, freeaddrinfo };
}

int main(int argc, char* argv[]) {
  {
    string host = argc == 2 ? argv[1] : "google.de";
    auto uptr = getaddrinfo(host);
    // print list
    for (addrinfo* ptr = &(*uptr); ptr != nullptr; ptr=ptr->ai_next) {
      char address_buffer[INET_ADDRSTRLEN + 1] = { 0 };
      auto tmp = reinterpret_cast<sockaddr_in*>(ptr->ai_addr);
      auto ok  = inet_ntop(tmp->sin_family, &tmp->sin_addr, address_buffer,
                           INET_ADDRSTRLEN);
      address_buffer[INET_ADDRSTRLEN] = '\0';
      if (ok) {
        cout << address_buffer << endl;
      }
    }
  } // uptr wird nach verlassen dieses scopes gelöscht durch freeaddrinfo
}
