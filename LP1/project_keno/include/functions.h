#ifndef FUNCTION_H
#define FUNCTION_H

#include "../include/kenoBet.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

namespace my{
void sort(set_of_numbers_type & vector);
void file_reader(std::string file_path, KenoBet &object);
}

set_of_numbers_type set_random(void);

#endif
