#include <boost/interprocess/detail/os_thread_functions.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <fstream>
#include <iostream>
using namespace boost::interprocess;

int main() {
  try {
    int pid = ipcdetail::get_current_process_id();
    // Open or create the named mutex
    // https://github.com/boostorg/interprocess/blob/develop/include/boost/interprocess/sync/posix/named_mutex.hpp
    // boost named_mutex is implemented on top of the POSIX named semaphore
    named_mutex mutex(open_or_create, "/boost_named_mutex");
    {
      std::ofstream file;
      file.open("boost_named_mutex.log", std::fstream::out | std::fstream::app);
      scoped_lock<named_mutex> lock(mutex);

      for (int i = 0; i < 1000; ++i) {
        file << "pid=" << pid << " cnt=" << i << std::endl;
      }
    }
  }
  catch (interprocess_exception& ex) {
    std::cout << ex.what() << std::endl;
    return 1;
  }
  return 0;
}