#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono;

typedef duration<int, ratio<86400>> days;

void showDuration(const milliseconds& s) {
  int day = duration_cast<days>(s).count();
  int hour = duration_cast<hours>(s % days(1)).count();
  int minute = duration_cast<minutes>(s % hours(1)).count();
  int second = duration_cast<seconds>(s % minutes(1)).count();
  int millisecond = duration_cast<milliseconds>(s % seconds(1)).count();
  cout << setfill('0');
  cout << day << "day " << setw(2) << hour << "hr " << setw(2) << minute << "min " << setw(2) << second << "s "
       << setw(3) << millisecond << "ms" << endl;
}

void timeExecution() {
  /*
   *  The result is not reliable if system_clock::now() is used instead since the system_clock
   *  is associated with the real wall clock of the current system. e.g. The system clock is
   *  adjusted while the program is running.
   */
  time_point start = steady_clock::now();
  this_thread::sleep_for(seconds(5));
  time_point end = steady_clock::now();
  cout << "The program has been running for " << duration_cast<seconds>(end - start).count() << "s" << endl;
}

void showCalendarTime(const time_point<system_clock>& tp) {
  time_t t = system_clock::to_time_t(tp);
  // Note that ctime() takes the time zone into account
  cout << ctime(&t);
}

void showCurrentTime() {
  time_point<system_clock> tp = system_clock::now();
  cout << duration_cast<seconds>(tp.time_since_epoch()).count() << "s since epoch" << endl;
}

int main() {
  timeExecution();

  time_point<system_clock> tp_epoch;  // time_point consturctor defaults on epoch
  auto tp_max = time_point<system_clock>::max();
  cout << "Epoch calendar time: ", showCalendarTime(tp_epoch);
  cout << "Max calendar time: ", showCalendarTime(tp_max);
  cout << "Reach max time point in: ", showDuration(duration_cast<milliseconds>(tp_max - tp_epoch));

  cout << "Ready for sleep: ", showCurrentTime();
  time_point<steady_clock> tp_sdy = steady_clock::now();
  tp_sdy += seconds(5);
  this_thread::sleep_until(tp_sdy);
  cout << "Waken up: ", showCurrentTime();

  return 0;
}