//
// Created by Peter Hoc on 10/14/2018.
//

#ifndef BAITAPOOP01_FUNCTIONS_H
#define BAITAPOOP01_FUNCTIONS_H

#include "book.h"

/**
 * SELECTORS
 * @param const Book&
 * @return const V&
 */

const string &select_name(const Book &b);

const string &select_id_number(const Book &b);

const int &select_number(const Book &b);

const int &select_published_year(const Book &b);


/**
 * COMPARE BOOK
 * @param l const Book&
 * @param r const Book&
 * @return bool
 */

bool compare_book_by_number_ascending(const Book &l, const Book &r);

bool compare_book_by_number_descending(const Book &l, const Book &r);

bool compare_book_by_name_ascending(const Book &l, const Book &r);

bool compare_book_by_name_descending(const Book &l, const Book &r);

bool compare_book_by_id_descending(const Book &l, const Book &r);

bool compare_book_by_id_ascending(const Book &l, const Book &r);

bool compare_book_by_published_year_ascending(const Book &l, const Book &r);

bool compare_book_by_published_year_descending(const Book &l, const Book &r);

/**
 * COMPARE V
 * @param a const V&
 * @param b const V&
 * @return bool
 */

bool compare_string_ascending(const string &a, const string &b);

bool compare_string_descending(const string &a, const string &b);

bool compare_int_ascending(const int &a, const int &b);

bool compare_int_descending(const int &a, const int &b);

#endif //BAITAPOOP01_FUNCTIONS_H
