#include "../include/pointer.h"

int main(){
	//Teste da função min -------------------------------------------------

	/*
	int A[] = {3, 4, 5, 1, -5, 4};
	compare cmp = generic::cmp;
	auto *small = generic::min(std::begin(A), std::end(A), sizeof(A[0]), cmp);
	std::cout << *(int *)small << std::endl;
	*/

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
	std::cout << "Address: " << (int *)d << std::endl;
	std::cout << "Value of address position: " << *(int *)d << std::endl;
	*/

	//Teste da função clone -------------------------------------------------

 	/*
	int A[] = {3, 4, 5, 1, 5, 4};
	auto *d = generic::clone(std::begin(A), std::end(A), sizeof(A[0]));
	byte *d_new = static_cast<byte *> (d);
	byte *d_it = static_cast<byte *> (d);
	std::cout << "[";
	for(int i = 0; i < (int)(std::end(A) - std::begin(A)); i++){
		std::cout << " " << *(int *)d_it << " ";
		d_it+=sizeof(A[0]);
	}
	std::cout << "]" << std::endl;
	delete[] d_new;
	*/

	//Teste da função find_if -------------------------------------------------

	/*
	int A[] = {3, 4, 5, 1, -5, 4};
	predicate p = generic::even;
	predicate pp = generic::odd;
	auto *r  = generic::find_if(std::begin(A), std::end(A), sizeof(A[0]), p);
	std::cout << "Even: " << *(int *)r << std::endl;
	auto *rr  = generic::find_if(std::begin(A), std::end(A), sizeof(A[0]), pp);
	std::cout << "Odd: " <<*(int *)rr << std::endl;
	*/

	//Teste da função find -------------------------------------------------

	/*
	int A[] = {3, 4, 5, 1, 5, 7, 4};
	compare eq = generic::equal;
	int value = 1;
	auto *r  = generic::find(std::begin(A), std::end(A), sizeof(A[0]), &value, eq);
	std::cout << "Key '" << *(int *)r << "' found" << std::endl;
	*/

	//Teste das funções  all_of any_of e none of -------------------------------------------------

	/*
	int A[] = {3, 4, 5, 1, 5, 4};
	predicate p = generic::negative;
	std::cout << "all_of:";
	if(generic::all_of(std::begin(A), std::end(A), sizeof(A[0]), p)){
		std::cout << " true" << std::endl;
	}else{
		std::cout << " false" << std::endl;
	}
	std::cout << std::endl << "any_of:";
	if(generic::any_of(std::begin(A), std::end(A), sizeof(A[0]), p)){
		std::cout << " true" << std::endl;
	}else{
		std::cout << " false" << std::endl;
	}
	std::cout << std::endl << "none_of:";
	if(generic::none_of(std::begin(A), std::end(A), sizeof(A[0]), p)){
		std::cout << " true" << std::endl;
	}else{
		std::cout << " false" << std::endl;
	}

	*/
	return 0;
}
