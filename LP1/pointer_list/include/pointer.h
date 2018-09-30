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
	bool cmp(const void *x, const void *y);

	void *min(void *first,  void *last, size_t size, compare cmp);

	//Questão 2
	void swap(void *x, void *y, size_t * size);

	void reverse(void *first, void * last, size_t size);

	//Questão 3
	void *copy(void *first, void *last, void *d_first, size_t size);
}

#endif
