//
// Created by Peter Hoc on 10/14/2018.
//

#include "functions.h"

const string &select_name(const Book &b) { return b.get_name(); }

const string &select_id_number(const Book &b) { return b.get_id_number(); }

bool compare_string_ascending(const string &a, const string &b) { return a < b; }

bool compare_book_by_number_ascending(const Book &l, const Book &r) { return l.get_number() < r.get_number(); }

bool compare_book_by_number_descending(const Book &l, const Book &r) { return l.get_number() > r.get_number(); }

bool compare_book_by_name_descending(const Book &l, const Book &r) { return l.get_name() > r.get_name(); }

bool compare_book_by_id_descending(const Book &l, const Book &r) { return l.get_id_number() > r.get_id_number(); }

bool compare_book_by_name_ascending(const Book &l, const Book &r) { return l.get_name() < r.get_name(); }

bool compare_book_by_id_ascending(const Book &l, const Book &r) { return l.get_id_number() < r.get_id_number(); }

const int &select_number(const Book &b) { return b.get_number(); }

const int &select_published_year(const Book &b) { return b.get_published_year(); }

bool compare_book_by_published_year_ascending(const Book &l, const Book &r) {
  return l.get_published_year() < r.get_published_year();
}

bool compare_book_by_published_year_descending(const Book &l, const Book &r) {
  return l.get_published_year() > r.get_published_year();
}

bool compare_int_ascending(const int &a, const int &b) { return a < b; }

bool compare_string_descending(const string &a, const string &b) { return a > b; }

bool compare_int_descending(const int &a, const int &b) { return a > b; };


