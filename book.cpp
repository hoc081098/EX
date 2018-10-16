//
// Created by Peter Hoc on 10/1/2018.
//

#include "book.h"

Book::Book(const string &id_number, const string &name, int published_year, int number)
    : id_number(id_number), name(name), published_year(published_year), number(number), state(number > 0) {
  Book::check_id(id_number);
  Book::check_published_year(published_year);
  Book::check_number(number);
}

const string &Book::get_id_number() const { return id_number; }

void Book::set_id_number(const string &id_number) {
  check_id(id_number);
  this->id_number = id_number;
}

const string &Book::get_name() const { return name; }

void Book::set_name(const string &name) { this->name = name; }

const int &Book::get_published_year() const { return published_year; }

void Book::set_published_year(int published_year) {
  Book::check_published_year(published_year);
  this->published_year = published_year;
}

const int &Book::get_number() const { return number; }

void Book::set_number(int number) {
  Book::check_number(number);
  this->number = number;
  state = number > 0;
}

bool Book::is_state() const { return state; }

ostream &operator<<(ostream &os, const Book &book) {
  return os << "{ Ma sach: " << book.id_number
            << ", ten: " << book.name
            << ", nam xuat ban: " << book.published_year
            << ", so luong: " << book.number
            << boolalpha << ", trang thai: " << book.state
            << " }";
}

istream &operator>>(istream &is, Book &book) {

  while (true) {
    try {
      cout << "Ma sach: ";
      string id_number;
      getline(is, id_number);
      book.set_id_number(id_number);
      break;
    } catch (const exception &e) {
      cout << e.what() << '\n';
    }
  }

  while (true) {
    try {
      cout << "Ten: ";
      string name;
      getline(is, name);
      book.set_name(name);
      break;
    } catch (const exception &e) {
      cout << e.what() << '\n';
    }
  }
  while (true) {
    try {
      cout << "Nam xuat ban: ";
      int published_year;
      if (!(is >> published_year)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      book.set_published_year(published_year);
      break;
    } catch (const exception &e) {
      cout << e.what() << '\n';
    }
  }
  while (true) {
    try {
      cout << "So luong: ";
      int number;
      if (!(is >> number)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      book.set_number(number);
      break;
    } catch (const exception &e) {
      cout << e.what() << '\n';
    }
  }
  return is;
}

Book::Book() : id_number("100000000"), name(""), published_year(1000), number(0), state(false) {}

bool Book::check_id_elem(const string &s) {
  for (int i = 0; i < s.length(); ++i) {
    const int digit = s[i] - '0';
    if (!(0 <= digit && digit <= 9)) {
      return false;
    }
  }
  return true;
}

void Book::check_id(const string &id_number) {
  if (id_number.length() != 9) {
    throw invalid_argument("Ma sach phai co do dai 9");
  }
  const int first = id_number[0] - '0';
  if (first < 1 || 5 < first) {
    throw invalid_argument("Chu so dau tien cua ma sach phai trong khoang 1..5");
  }
  if (!check_id_elem(id_number.substr(1))) {
    throw invalid_argument("8 chu so sau cung cua ma sach phai trong khoang 0..9");
  }
}

void Book::check_published_year(int published_year) {
  if (published_year < 1000 || 9999 < published_year) {
    throw invalid_argument("Nam xuat ban phai co 4 chu so");
  }
}

void Book::check_number(int number) {
  if (number < 0) {
    throw invalid_argument("So luong phai lon hon hoac bang 0");
  }
}

void Book::update() {
  cin >> *this;
}
