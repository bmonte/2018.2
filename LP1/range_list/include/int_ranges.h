#ifndef  RANGES_LIB_H
#define RANGES_LIB_H

#include <iterator> // distance
#include <algorithm> // swap, remove_if

namespace ir {
  using value_type = int;

  /// Negate all integer values in [first;last).
  void negate(value_type * first, value_type * last);
  /// Find min integer value in [first;last).
  const value_type * min (const value_type * first , const value_type * last);

  void reverse ( value_type * first , value_type * last );

  void scalar_multiplication (value_type * first , value_type * last , value_type scalar);

  int dot_product ( const value_type * a_first , const value_type * a_last , const value_type * b_first );

  value_type * compact (value_type * first , value_type * last);

  value_type * copy ( const value_type * first , const value_type * last , value_type * d_first );

  value_type * unique( value_type *first, value_type *last);

  value_type * sort_marbles(value_type * first, value_type *last);

  void partition ( value_type * first, value_type * last, value_type * pivot );

  void rotate (value_type * first , value_type * n_first , value_type * last );
}
#endif
