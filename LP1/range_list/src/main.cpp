#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each

#include "../include/int_ranges.h"

std::string print( const int* first, const int* last )
{
    std::ostringstream oss;

    oss << "[ ";
    std::for_each(first, last, [&](const int & a){ oss << a << " ";} );
    oss << "]";
    return oss.str();
}

int main (void)
{
  int A[] = {1, 0, 0, 1, 1, 0, 1};
  std::cout << ">>>>> A: " << print(std::begin(A), std::end(A)) << '\n';
  ir::negate(std::begin(A), std::end(A));
  std::cout << ">>>>> A: " << print(std::begin(A), std::end(A)) << '\n';
  return 0;

}
