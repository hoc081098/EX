//
// Created by Peter Hoc on 10/1/2018.
//

#include <stdexcept>
#include <algorithm>
#include "book.h"

Book::Book(const string &id_number, const string &name, int published_year, int number)
        : id_number(id_number), name(name), published_year(published_year), number(number), state(number > 0) {
    if (id_number.length() != 9) {
        throw std::invalid_argument("Length of id must be 9");
    }
    const int first = id_number[0] - '0';
    if (first < 1 || 5 < first) {
        throw std::invalid_argument("First digit of id must be in 1..5");
    }
    string sub_string = id_number.substr(1);
    const bool is_valid = std::all_of(sub_string.begin(), sub_string.end(), [](char c) {
        const int digit = c - '0';
        return 0 <= digit && digit <= 9;
    });
    if (!is_valid) {
        throw std::invalid_argument("All digit from second of id must be in 0..9");
    }

    if (published_year < 1000 || 9999 < published_year) {
        throw std::invalid_argument("Published year must be have 4 digits");
    }

    if (number < 0) {
        throw std::invalid_argument("Number must be greater than or equal to zero");
    }
}

string Book::get_id_number() const {
    return id_number;
}

void Book::set_id_number(const string &id_number) {
    Book::id_number = id_number;
}

const string &Book::get_name() const {
    return name;
}

void Book::set_name(const string &name) {
    Book::name = name;
}

int Book::get_published_year() const {
    return published_year;
}

void Book::set_published_year(int published_year) {
    Book::published_year = published_year;
}

int Book::get_number() const {
    return number;
}

void Book::set_number(int number) {
    Book::number = number;
}

bool Book::is_state() const {
    return state;
}

void Book::set_state(bool state) {
    Book::state = state;
}

ostream &operator<<(ostream &os, const Book &book) {
    return os << "{ id_number: " << book.id_number
       << ", name: " << book.name
       << ", published_year: " << book.published_year
       << ", number: " << book.number
       << std::boolalpha << ", state: " << book.state
       << " }";
}

Book::Book() = default;
