//
// Created by Peter Hoc on 10/1/2018.
//

#include "list.h"

const int List::GROWTH_FACTOR = 2;
const int List::DEFAULT_INITIAL_CAPACITY = 8;

List::List(const List &other) {
  capacity = other.capacity;
  size = other.size;
  books = new Book[capacity];
  copy(other.books, other.books + size, books);
}

List::List() {
  capacity = DEFAULT_INITIAL_CAPACITY;
  size = 0;
  books = new Book[capacity];
}

List::~List() {
  delete[] books;
}

void List::ShowList() const {
  cout << *this;
}

void List::AddLast(const Book &book) {
  Add(size, book);
}

void List::EnsureCapacity() {
  if (size == capacity) {
    capacity *= GROWTH_FACTOR;

    Book *const temp = new Book[capacity];
    copy(books, books + size, temp);
    delete[](books);
    books = temp;
  }
}

void List::AddFirst(const Book &book) {
  Add(0, book);
}

void List::QuickSort(Book *pBook, const int L, const int H, bool (*compare)(const Book &, const Book &)) {
  if (L >= H) return;
  int low = L;
  int high = H;
  const Book pivot = pBook[low + (high - low) / 2];

  do {
    while (compare(pBook[low], pivot)) ++low;
    while (compare(pivot, pBook[high])) --high;

    if (low <= high) {
      if (low < high) swap(pBook[low], pBook[high]);
      ++low;
      --high;
    }
  } while (low <= high);

  QuickSort(pBook, L, high, compare);
  QuickSort(pBook, low, H, compare);
}

void List::QuickSort(bool compare(const Book &, const Book &)) {
  List::QuickSort(books, 0, size - 1, compare);
}

pair<Book *, size_t> List::BinarySearchByName(const string &name) const {
  return BinarySearch(name, select_name, compare_string_ascending);
}

void List::Add(int index, const Book &book) {
  Book *const found = FindBookById(book.get_id_number());
  if (found != NULL) {
    std::cout << "Doi tuong sach da ton tai, tang so luong len 1" << '\n';
    found->set_number(found->get_number() + 1);
    return;
  }
  CheckIndex(index, 0, size + 1);
  EnsureCapacity();
  for (int i = size - 1; i >= index; --i) {
    books[i + 1] = books[i];
  }
  books[index] = book;
  ++size;
}

void List::RemoveFirst() {
  RemoveAt(0);
}

void List::RemoveLast() {
  RemoveAt(size - 1);
}

void List::RemoveAt(int index) {
  CheckIndex(index, 0, size);

  if (books[index].get_number() > 1) {
    std::cout << "Doi tuong sach da ton tai, giam so luong xuong 1" << '\n';
    books[index].set_number(books[index].get_number() - 1);
    return;
  }

  copy(books + index + 1, books + size, books + index);
  --size;

  if (size * GROWTH_FACTOR * GROWTH_FACTOR == capacity) {
    capacity /= GROWTH_FACTOR;

    Book *const temp = new Book[capacity];
    copy(books, books + size, temp);
    delete[](books);
    books = temp;
  }
}

const size_t List::get_size() const { return size; }

List &List::operator=(const List &other) {
  if (this != &other) {
    if (other.size != size) {
      delete[] books;
      size = 0;
      books = NULL;
      books = new Book[other.size];
      size = other.size;
    }
    copy(other.books, other.books + other.size, books);
  }
  return *this;
}

ostream &operator<<(ostream &os, const List &list) {
  os << "List: size = " << list.size << ", books = [\n";
  for (int i = 0; i < list.size; ++i) {
    os << "    " << i << ". " << list.books[i];
    if (i < list.size - 1) {
      os << ',';
    }
    os << '\n';
  }
  return os << "]\n";
}

istream &operator>>(istream &is, List &list) {
  int size;
  do {
    cout << "Nhap so luong danh sach (lon hon hoac bang 0): " << '\n';
    if (!(is >> size)) {
      is.clear();
      is.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    if (size < 0) {
      cout << "So luong danh sach phai lon hon hoac bang 0" << '\n';
    }
  } while (size < 0);

  list.clear();

  for (int i = 0; i < size; ++i) {
    Book book;

    while (true) {
      cout << "Nhap sach thu " << i + 1 << ": " << '\n';
      is.ignore();
      if (!(is >> book)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      } else {
        break;
      }
    }
    list.AddLast(book);
  }

  return is;
}

pair<Book *, size_t> List::BinarySearchById(const string &id) const {
  return BinarySearch(id, select_id_number, compare_string_ascending);
}

Book *const List::FindBookById(const string &id) const {
  for (int i = 0; i < size; ++i) {
    if (books[i].get_id_number() == id) {
      return &books[i];
    }
  }
  return NULL;
}

Book &List::operator[](size_t index) {
  CheckIndex(index, 0, size);
  return books[index];
}

const Book &List::operator[](size_t index) const {
  CheckIndex(index, 0, size);
  return books[index];
}

void List::CheckIndex(int index, int start, int end) const {
  if (!(start <= index && index <= end - 1)) {
    ostringstream oss;
    oss << "Chi so phai trong doan " << start << ".." << end - 1;
    throw out_of_range(oss.str());
  }
}

void List::UpdateById(const string &id) { Update(id, select_id_number); }

void List::UpdateByName(const string &name) { Update(name, select_name); }

void List::QuickSortByNameAscending() { QuickSort(compare_book_by_name_ascending); }

void List::QuickSortByIdAscending() { QuickSort(compare_book_by_id_ascending); }

void List::clear() {
  delete[] books;
  capacity = DEFAULT_INITIAL_CAPACITY;
  size = 0;
  books = new Book[capacity];
}
