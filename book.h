//
// Created by Peter Hoc on 10/1/2018.
//

#ifndef BAITAPOOP01_BOOK_H
#define BAITAPOOP01_BOOK_H

#include <string>
#include <ostream>

using namespace std;

class Book {
private:
    string id_number;
    string name;
    int published_year;
    int number;
    bool state;
public:
    Book();

    Book(const string &id_number, const string &name, int published_year, int number);

    string get_id_number() const;

    void set_id_number(const string &id_number);

    const string &get_name() const;

    void set_name(const string &name);

    int get_published_year() const;

    void set_published_year(int published_year);

    int get_number() const;

    void set_number(int number);

    bool is_state() const;

    void set_state(bool state);

    friend ostream &operator<<(ostream &os, const Book &book);
};

#endif //BAITAPOOP01_BOOK_H
