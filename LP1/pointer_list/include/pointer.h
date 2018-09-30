#ifndef _POINTER_H
#define _POINTER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>

using byte = unsigned char;
using compare = bool (*)(const void *, const void *);

namespace generic{
  //Questão 1
	bool cmp( const void *x, const void *y);

	void *min( void *first,  void *last, size_t size, compare cmp);

}

#endif
