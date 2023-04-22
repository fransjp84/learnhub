#include "observer_pattern.h"

#include <algorithm>

ObserverPattern::ObserverPattern() = default;

void ObserverPattern::Register(ObserverPattern::Client *new_client) {
  client_list_.push_back(new_client);

  const auto client_size = client_list_.size();
  for (const auto &client : client_list_) {
    client->OnNewClientAdded(client_size, new_client->GetName());
  }
}

void ObserverPattern::Unregister(ObserverPattern::Client *client) {
  auto it = std::find(client_list_.begin(), client_list_.end(), client);
  if (it != client_list_.end()) {
    client_list_.erase(it);
  }
}
