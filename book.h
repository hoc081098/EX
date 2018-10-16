//
// Created by Peter Hoc on 10/1/2018.
//

#ifndef BAITAPOOP01_BOOK_H
#define BAITAPOOP01_BOOK_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

class Book {
private:
    string id_number;
    string name;
    int published_year;
    int number;
    bool state;

    static bool check_id_elem(const string &s);

    static void check_id(const string &id_number);

    static void check_published_year(int published_year);

    static void check_number(int number);

public:
    Book();

    Book(const string &id_number, const string &name, int published_year, int number);

    const string &get_id_number() const;

    void set_id_number(const string &id_number);

    const string &get_name() const;

    void set_name(const string &name);

    const int &get_published_year() const;

    void set_published_year(int published_year);

    const int &get_number() const;

    void set_number(int number);

    bool is_state() const;

    friend ostream &operator<<(ostream &os, const Book &book);

    friend istream &operator>>(istream &is, Book &book);

    void update();

};

#endif //BAITAPOOP01_BOOK_H
