#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
 public:
  static Singleton& GetInstance();

 private:
  Singleton() {
  }

  virtual ~Singleton() {
    _isDestroyed = true;
  }

  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);

  // get called if dead reference is detected
  static void OnDeadReference();

  // to detect the potential dead reference to the singleton
  static bool _isDestroyed;
};

#endif
