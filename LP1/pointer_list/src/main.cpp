#include "../include/pointer.h"

int main(){
	//Teste da função min -------------------------------------------------



	int A[] = {3, 4, 5, 1, -5, 4};
	compare cmp = generic::cmp;
	auto *small = generic::min(std::begin(A), std::end(A), sizeof(A[0]), cmp);
	std::cout << *(int *)small << std::endl;

	

	//Teste da função reverse ---------------------------------------------

	/*

	int A[] = {5, 3, 1 , 4, 6, 1, 7};
	generic::reverse(std::begin(A), std::end(A), sizeof(A[0]));
	std::cout << "[";
	for(int i = 0; i < (int)(std::end(A) - std::begin(A)); i++){
		std::cout << " " << A[i] << " ";
	}
	std::cout << "]" << std::endl;

	*/

	//Teste da função copy -------------------------------------------------

	/*

	int A[] = {3, 4, 5, 1, 5, 4};
	int B[] = {0, 0, 0, 0, 0, 0};
	auto *d = generic::copy(std::begin(A), std::end(A), std::begin(B), sizeof(A[0]));
	std::cout << "[";
	for(int i = 0; i < (int)(std::end(B) - std::begin(B)); i++){
		std::cout << " " << B[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << *(int *)d << std::endl;

	*/

	//Teste da função clone -------------------------------------------------

	/*

	int A[] = {3, 4, 5, 1, 5, 4};
	auto *d = generic::clone(std::begin(A), std::end(A), sizeof(A[0]));
	byte *dd = static_cast<byte *> (d);
	byte *d_it = static_cast<byte *> (d);
	std::cout << "[";
	for(int i = 0; i < (int)(std::end(A) - std::begin(A)); i++){
		std::cout << " " << *(int *)d_it << " ";
		d_it+=sizeof(A[0]);
	}
	std::cout << "]" << std::endl;
	delete[] dd;

	*/

	//Teste da função find_if -------------------------------------------------

	/*

	int A[] = {3, 4, 5, 1, -5, 4};
	predicate p = generic::p;
	auto *r  = generic::find_if(std::begin(A), std::end(A), sizeof(A[0]), p);
	std::cout << *(int *)r << std::endl;

	*/

	//Teste da função find -------------------------------------------------

	/*

	// int A[] = {3, 4, 5, 1, 5, 7, 4};

	// equal eq = generic::eq;
	// int value = 1;

	// auto *r  = generic::find(std::begin(A), std::end(A), sizeof(A[0]), &value, eq);

	// std::cout << *(int *)r << std::endl;

	*/



	return 0;
}
