#include "../include/pointer.h"


//Questão 1:
bool generic::cmp(const void * x, const void * y){
	int a = *(int *)x;
	int b = *(int *)y;

	if(a < b) return true;
	else return false;
}

void *generic::min(void * first,  void * last, size_t size, compare cmp){
	byte *smallest = static_cast<byte *> (first);
	byte *forward = static_cast<byte *> (first);

	forward += size;

	while(forward != last){
		if(cmp(forward, smallest)){
			smallest = forward;
		}
		forward += size;
	}
 	return smallest;
}

//Questão 2
void generic::swap(void * x, void * y, size_t * size){
	byte aux[*size];

	memcpy(aux, x, *size);
	memcpy(x, y, *size);
	memcpy(y, aux, *size);
}

void generic::reverse(void * first, void * last, size_t size){
	byte *begin = static_cast<byte *> (first);
	byte *end = static_cast<byte *> (last);

	while (begin < end) {
		end -= size;
		swap(begin, end, &size);
		begin += size;
	}
}

//Questão 3
void *generic::copy(void *first, void *last, void *d_first, size_t size){
	byte *begin = static_cast<byte *> (first);
	byte *forward = static_cast<byte *> (d_first);

	while (begin < last) {
		memcpy(forward, begin, size);
		begin += size;
		forward += size;
	}
	forward -= size;
	return forward;
}

//Questão 4
void *generic::clone(void *first, void *last, size_t size){
	byte *begin = static_cast<byte *> (first);
	byte *end = static_cast<byte *> (last);

	int length = (int)(end - begin);

	byte *clone = new byte[length - size];
	byte *aux = clone;

	while(begin < last){
		memcpy(aux, begin, size);
		begin += size;
		aux += size;
	}
	return clone;
}

//Questão 5
bool generic::even(const void *x){
	int num = *(int*)x;
	if (num % 2 == 0) return true;
 	else return false;
}

bool generic::odd(const void *y){
	int num = *(int*)y;
	if (num % 2 == 1) return true;
 	else return false;
}

void *generic::find_if(void *first, void *last, size_t size, predicate p){
	byte *begin = static_cast<byte *> (first);

	while (begin < last && !p(begin)) {
		begin += size;
	}
	return begin;
}
