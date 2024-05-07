#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

class BackgroundWorker {
 public:
  BackgroundWorker() : counter(0), stop_thread(false) {
    worker = std::jthread([this](std::stop_token stoken) {
      while (!stoken.stop_requested()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        counter++;
        std::cout << "Counter incremented to " << counter << std::endl;
      }
    });
  }

  ~BackgroundWorker() {
    std::cout << "~BackgroundWorker()" << std::endl;
    stop_thread = true;
    if (worker.joinable()) {
      worker.request_stop();
      worker.join();
    }
  }

  int getCounter() const { return counter.load(); }

 private:
  std::jthread worker;
  std::atomic<int> counter;
  std::atomic<bool> stop_thread;
};
