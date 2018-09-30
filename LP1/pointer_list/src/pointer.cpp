#include "../include/pointer.h"


//Questão 1:
bool generic::cmp(const void *x, const void *y){
	int a = *(int *)x;
	int b = *(int *)y;

	if(a < b) return true;
	return false;
}

void *generic::min( void *first,  void *last, size_t size, compare cmp){
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
