/*
 * univariate_polynomial_gcd.h
 *
 *  Created on: Nov 17, 2013
 *      Author: dejan
 */

#pragma once

#include "upolynomial.h"

/**
 * Compute the GCD using Euclid's algorithm. Degree of A should be >= than the
 * degree of B. This one only works with exact division, i.e. in Z_p rings.
 *
 * If U and V are not 0, then the extended gcd is computed, i.e. we solve
 *
 *   U*A + V*B = gcd(A, B) = D
 *
 * with deg(U) < deg(B) - deg(D) and deg(V) < deg(A) - deg(D).
 */
upolynomial_t* upolynomial_gcd_euclid(const upolynomial_t* A, const upolynomial_t* B, upolynomial_t** U, upolynomial_t** V);

/**
 * Compute the GCD using the Subresultant algorithm. Degree of A should be >= than the
 * degree of B.
 */
upolynomial_t* upolynomial_gcd_subresultant(const upolynomial_t* A, const upolynomial_t* B);


/**
 * Heuristic GCD computation. Pick a large value v, evaluate A(v), B(v), and
 * compute g = gcd(A(v), B(v)). Then reconstruct gcd from g. The method returns
 * 0 if the gcd compuation failed (heuristic!). Only on Z[x] polynomials.
 *
 * @param tries how many attempts
 */
upolynomial_t* upolynomial_gcd_heuristic(const upolynomial_t* A, const upolynomial_t* B, int attempts);

