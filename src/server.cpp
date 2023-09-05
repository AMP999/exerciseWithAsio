#include <lib_network/message.h>

enum class RPControlMsgType : uint32_t{
    ShutDown,
    Restart,
    OpenBrowser
};

int main() {
  network::Message<RPControlMsgType> msg;
  msg.header.id = RPControlMsgType::ShutDown;
}