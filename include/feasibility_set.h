/*
 * feasibility_set.h
 *
 *  Created on: Feb 24, 2015
 *      Author: dejan
 */

#pragma once

#include "poly.h"
#include "sign_condition.h"

/**
 * Set of disjoint intervals representing an algebraic set, ordered from
 * left to right (-inf to +inf).
 */
struct lp_feasibility_set_struct {

  /** Number of intervals */
  size_t size;

  /** Capacity of the intervals table */
  size_t capacity;

  /** Vector feasibility intervals */
  lp_interval_t* intervals;

};

/**
 * Create a new feasibility set [-inf, inf].
 */
lp_feasibility_set_t* lp_feasibility_set_new();

/**
 * Construct a copy.
 */
lp_feasibility_set_t* lp_feasibility_set_new_copy(const lp_feasibility_set_t* set);

/**
 * Delete the given feasibility set.
 */
void lp_feasibility_set_delete(lp_feasibility_set_t* set);

/**
 * Assignment.
 */
void lp_feasibiliy_set_assign(lp_feasibility_set_t* set, const lp_feasibility_set_t* from);


/**
 * Check if the given set is empty.
 */
int lp_feasibility_set_is_empty(const lp_feasibility_set_t* set);

/**
 * Check if the given value belongs to the set.
 */
int lp_feasibility_set_contains(const lp_feasibility_set_t* set, const lp_value_t* value);

/**
 * Pick a value from the feasible set (must be non-empty).
 */
void lp_feasibility_set_pick_value(const lp_feasibility_set_t* set, lp_value_t* v);

/**
 * Get intersection of the two sets, returns the status in the given variable.
 */
lp_feasibility_set_t* lp_feasibility_set_intersect(const lp_feasibility_set_t* s1, const lp_feasibility_set_t* s2);

typedef enum {
  LP_FEASIBILITY_SET_INTERSECT_S1,
  LP_FEASIBILITY_SET_INTERSECT_S2,
  LP_FEASIBILITY_SET_NEW,
  LP_FEASIBILITY_SET_EMPTY
} lp_feasibility_set_intersect_status_t;

/**
 * Get intersection of the two sets, returns the status in the given variable.
 * The set s1 is given precedence so LP_FEASIBILITY_SET_INTERSECT_S2 is the
 * status only if the intersect is not s1.
 */
lp_feasibility_set_t* lp_feasibility_set_intersect_with_status(const lp_feasibility_set_t* s1, const lp_feasibility_set_t* s2, lp_feasibility_set_intersect_status_t* status);

/**
 * Print the set.
 */
int lp_feasibility_set_print(const lp_feasibility_set_t* set, FILE* out);

/**
 * Return the string representation of the set.
 */
char* lp_feasibility_set_to_string(const lp_feasibility_set_t* set);
