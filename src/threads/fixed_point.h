
    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  Mariam and Nada $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44


#ifndef FIXED_POINT_ARITHMETIC_H
#define FIXED_POINT_ARITHMETIC_H

#include <stdint.h>

// Define the fixed-point type as a 32-bit signed integer
typedef int32_t fixed_point_t;

// Define the scaling factor as a power of 2
#define FIXED_POINT_SHIFT 14

// Define fixed-point constants for the coefficients
#define COEFF_1 INT_TO_FIXED_POINT(59) / 60
#define COEFF_2 INT_TO_FIXED_POINT(1) / 60

// Convert an integer n to fixed-point representation
#define TO_FIXED_POINT(n) ((fixed_point_t)((n) << FIXED_POINT_SHIFT))

// Convert a fixed-point value x to an integer (rounding towards zero)
#define TO_INTEGER_ZERO(x) ((x) >> FIXED_POINT_SHIFT)

// Convert a fixed-point value x to an integer (rounding to nearest)
#define TO_INTEGER_NEAREST(x) (((x) >= 0) ? (((x) + (1 << (FIXED_POINT_SHIFT - 1))) >> FIXED_POINT_SHIFT) : (((x) - (1 << (FIXED_POINT_SHIFT - 1))) >> FIXED_POINT_SHIFT))

// Add two fixed-point values x and y
#define ADD(x, y) ((x) + (y))

// Subtract a fixed-point value y from x
#define SUBTRACT(x, y) ((x) - (y))

// Add a fixed-point value x and an integer n
#define ADD_INTEGER(x, n) ((x) + ((n) << FIXED_POINT_SHIFT))

// Subtract an integer n from a fixed-point value x
#define SUBTRACT_INTEGER(x, n) ((x) - ((n) << FIXED_POINT_SHIFT))

// Multiply two fixed-point values x and y
#define MULTIPLY(x, y) (((int64_t)(x) * (y)) >> FIXED_POINT_SHIFT)

// Multiply a fixed-point value x by an integer n
#define MULTIPLY_INTEGER(x, n) ((x) * (n))

// Divide a fixed-point value x by a fixed-point value y
#define DIVIDE(x, y) (((int64_t)(x) << FIXED_POINT_SHIFT) / (y))

// Divide a fixed-point value x by an integer n
#define DIVIDE_INTEGER(x, n) ((x) / (n))

#endif // FIXED_POINT_ARITHMETIC_H
