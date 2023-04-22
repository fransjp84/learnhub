#pragma once

#include <string>
#include <vector>

class ObserverPattern {
public:
  class Client {
  public:
    virtual ~Client() = default;
    virtual std::string GetName() = 0;
    virtual void OnNewClientAdded(int client_num,
                                  const std::string &new_client_name) = 0;
  };

  ObserverPattern();
  void Register(ObserverPattern::Client *client);
  void Unregister(ObserverPattern::Client *client);

private:
  std::vector<ObserverPattern::Client *> client_list_;
};
