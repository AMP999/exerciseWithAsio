#include <iostream>
#include <chrono>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/executor.hpp>

int main() {
  asio::error_code ec;
  asio::io_context context;
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34", ec),80);
  asio::ip::tcp::socket socket(context);
  socket.connect(endpoint, ec);

  if(!ec) {
    std::cout << "Connected!" << std::endl;
  } else {
    std::cout << "Connection couldn't be stablished!" << std::endl << ec.message() << std::endl;
  }

  if(socket.is_open()) {
    std::string request = 
    "GET /index.html HTTP/1.1\r\n"
    "Host: example.com\r\n"
    "Connection: close\r\n\r\n";

    socket.write_some(asio::buffer(request.data(), request.size()), ec);

    using namespace std::chrono_literals;
    // std::this_thread::sleep_for(200ms);
    socket.wait(socket.wait_read);

    size_t bytes = socket.available();
    std::cout << "Bytes Available: " << bytes << std::endl;

    if(bytes > 0) {
      std::vector<char> buffer(bytes);
      socket.read_some(asio::buffer(buffer.data(), buffer.size()), ec);

      for(char c : buffer) {
        std::cout << c;
      }
    }
  }
  return 0;
}