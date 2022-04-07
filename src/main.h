#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm> // std::generate_n()
#include <stdlib.h> // std::rand()


/* Generates std::string of random chars, of size_t length. */
std::string random_string(size_t length);


template<typename T> // see: Curiously Recurring Template Pattern
class CUniqueKeyRegistry
{
public:
  /* adds new value at unique id, returns the unique id */
  static int register(std::string value);

  /* returns true if key exists */
  static bool isRegistered(int key);

  /* returns value at key */
  static std::string getValue(int key);

  // /* returns the full registry std::map */
  // static const std::map<int, std::string>& getRegistry() { return mRegistry; }

private:
  /* std::map registry of keys (int) to values (std::string) */
  static std::map<int, std::string> mRegistry;

  /* key incrementor */
  static int iKeyCounter;
};
//template<typename T> std::map<int, std::string> CUniqueKeyRegistry<T>::mRegistry;
template<typename T> int CUniqueKeyRegistry<T>::iKeyCounter = 0;


class FruitRegistry final : public CUniqueKeyRegistry<FruitRegistry> {
  this::register("apple");
  this::register("pear");
  this::register("melon");
  this::register("orange");
};

int main();

#endif