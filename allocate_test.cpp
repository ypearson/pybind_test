#include <chrono>
#include <iostream>
#include <list>
#include <vector>

int main() {
  // Timing variables for vector
  auto startVectorAlloc = std::chrono::high_resolution_clock::now();
  std::vector<int> myVector(1024);
  auto endVectorAlloc = std::chrono::high_resolution_clock::now();

  auto startVectorDealloc = std::chrono::high_resolution_clock::now();
  myVector.clear();
  myVector.shrink_to_fit();
  auto endVectorDealloc = std::chrono::high_resolution_clock::now();

  // Timing variables for list
  auto startListAlloc = std::chrono::high_resolution_clock::now();
  std::list<int> myList(1024);
  auto endListAlloc = std::chrono::high_resolution_clock::now();

  auto startListDealloc = std::chrono::high_resolution_clock::now();
  myList.clear();
  auto endListDealloc = std::chrono::high_resolution_clock::now();

  // Calculate durations
  std::chrono::duration<double, std::milli> durationVectorAlloc =
      endVectorAlloc - startVectorAlloc;
  std::chrono::duration<double, std::milli> durationVectorDealloc =
      endVectorDealloc - startVectorDealloc;
  std::chrono::duration<double, std::milli> durationListAlloc =
      endListAlloc - startListAlloc;
  std::chrono::duration<double, std::milli> durationListDealloc =
      endListDealloc - startListDealloc;

  // Output results
  std::cout << "Vector - Time taken to allocate: "
            << durationVectorAlloc.count() << " milliseconds." << std::endl;
  std::cout << "Vector - Time taken to deallocate: "
            << durationVectorDealloc.count() << " milliseconds." << std::endl;
  std::cout << "List - Time taken to allocate: " << durationListAlloc.count()
            << " milliseconds." << std::endl;
  std::cout << "List - Time taken to deallocate: "
            << durationListDealloc.count() << " milliseconds." << std::endl;

  return 0;
}
