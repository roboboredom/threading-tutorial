#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


extern int iValueA; //example data
extern int iValueB;

extern std::mutex mServerClientShareGuard;

#endif