#include "../include/int_ranges.h"

namespace ir
{
//Questão 1:
    void negate( value_type * first, value_type * last )
    {
        while( first != last )
            *first++ *= -1;
    }
//Questão 2:
    const value_type * min (const value_type * first, const value_type * last)
    {
      const value_type *menor;

      for ( ; first < last; first++) {
        if (*first < *menor) {
          menor = first;
        }
      }
      return menor;
    }
//Questão 3:
    void reverse (value_type * first, value_type * last)
    {
      while (first < last) {
        last--;
        std::swap(*first, *last);
        first++;
      }
    }
//Questão 4:
    void scalar_multiplication (value_type * first , value_type * last , value_type scalar){
      while( first != last )
          *first++ *= scalar;
    }
//Questão 5:
    value_type dot_product ( const value_type * a_first , const value_type * a_last , const value_type * b_first ){
      value_type result(0), n(std::distance(a_first, a_last));

      for (value_type i(0); i < n; i++) {
        result = result + (*a_first * *b_first);
        a_first++, b_first++;
      }

      return result;
    }
//Questão 6:
    bool isPositive(int i){
      return (i <= 0);
    }

    value_type * compact (value_type * first , value_type * last){
      last = std::remove_if (first, last, isPositive);
      return last;
    }
//Questão 7:
    value_type * copy ( const value_type * first , const value_type * last , value_type * d_first ){
      value_type *d_last;
        for ( ; first < last; first++ ) {
          *d_first = *first;
          d_first++;
        }
        d_last = d_first;
      return d_last;
    }
//Questão 8:
    value_type * unique( value_type *first, value_type *last){
      for ( ; first < last; first++) {
        for (auto * i = first + 1; i < last; i++) {
          if (*i == *first) {
            last--;
            //std::swap(*i, *last);
            for (auto * j = i; j < last; j++) {
              auto *prox = j + 1;
              std::swap(*j, *prox);
            }
          }
        }
      }
      return last;
    }
//Questão 9:
  //value_type * sort_marbles(value_type * first, value_type *last){}
//Questão 10:
  //void partition ( value_type * first, value_type * last, value_type * pivot ){}
//Questão 11:
  //void rotate (value_type * first , value_type * n_first , value_type * last ){}
}
