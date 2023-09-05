#pragma once

#include "includes.h"

namespace network {

template <typename T> struct MessageHeader {
  T id{};
  uint32_t size;
};

template <typename T> struct Message {
  MessageHeader<T> header;
  std::vector<uint8_t> body;

  size_t size() const { return sizeof(MessageHeader<T>) + body.size(); }

  friend std::ostream &operator<<(std::ostream &os, const Message<T> &msg) {
    os << "ID: " << int(msg.header.id) << "Size: " << msg.header.size;
    return os;
  }

  template <typename DataType>
  friend Message &operator<<(Message<T> &msg, const DataType &data) {}
};
} // namespace network