#include "observer_pattern.h"
#include <iostream>
#include <string>

class ObserverPatternImpl {
public:
  void RegisterNewClient(ObserverPattern::Client *client) {
    pattern_.Register(client);
  }

private:
  ObserverPattern pattern_;
};

class MyClient : public ObserverPattern::Client {
public:
  MyClient(const std::string& name) : name_(name) {}

  std::string GetName() override { return name_; }
  void OnNewClientAdded(int client_size,
                        const std::string &new_client_name) override {
    std::cout << "[" << name_
              << "] Got OnNewClientAdded, current client: " << client_size
              << ", new_client_name: " << new_client_name << "\n";
  }

private:
  std::string name_;
};

int main() {
  MyClient my_client1("client1");
  MyClient my_client2("client2");
  MyClient my_client3("client3");

  ObserverPatternImpl impl;
  impl.RegisterNewClient(&my_client1);
  impl.RegisterNewClient(&my_client2);
  impl.RegisterNewClient(&my_client3);
  return 0;
}
