//
// Created by Peter Hoc on 10/1/2018.
//


#include "list.h"

List::List() {
    capacity = DEFAULT_INITIAL_CAPACITY;
    size = 0;
    books = new Book[capacity];
}

List::~List() {
    delete[] books;
}

void List::ShowList() const {
    std::cout << *this;
}

void List::AddLast(const Book &book) {
    Add(size, book);
}

void List::EnsureCapacity() {
    if (size == capacity) {
        capacity *= GROWTH_FACTOR;

        Book *const temp = new Book[capacity];
        std::copy(books, books + size, temp);
        delete[](books);
        books = temp;
    }
}

void List::AddFirst(const Book &book) {
    Add(0, book);
}

void List::QuickSort(Book *books, int start, int end, bool (*compare)(const Book &, const Book &)) const {
    if (start >= end - 1) {
        return;
    }

    int low = start;
    int high = end - 1;
    Book &pivot = books[low + (high - low) / 2];

    do {
        while (compare(books[low], pivot)) {
            ++low;
        }
        while (compare(pivot, books[high])) {
            --high;
        }
        if (low <= high) {
            if (low < high) {
                std::swap(books[low], books[high]);
            }
            ++low;
            --high;
        }
    } while (low <= high);

    QuickSort(books, start, high + 1, compare);
    QuickSort(books, low, end, compare);
}

void List::QuickSort(bool (*compare)(const Book &, const Book &)) {
    QuickSort(books, 0, size, compare);
}

std::pair<Book *, std::size_t> List::BinarySearch(const string &name) const {
    const pair<int, int> &pair = BinarySearch(books, 0, size, name);
    const int start = pair.first;
    const int end = pair.second;

    if (start != 1 && end != -1) {
        const std::size_t size = static_cast<const size_t>(end - start + 1);
        Book *const res = new Book[size];
        std::copy(books + start, books + end + 1, res);
        return {res, size};
    } else {
        return {nullptr, 0};
    }
}

std::pair<int, int>
List::BinarySearch(Book *books, int start, int end, const string &name) const {
    return make_pair(LowerBound(books, start, end, name), UpperBound(books, start, end, name));
}

int List::LowerBound(Book *pBook, int start, int end, const string &name) const {
    int low = 0, high = end - 1;
    int start_index = -1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (pBook[mid].get_name() > name) {
            high = mid - 1;
        } else if (pBook[mid].get_name() == name) {
            start_index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return start_index;
}

int List::UpperBound(Book *pBook, int start, int end, const string &name) const {
    int end_index = -1;
    int low = 0;
    int high = end - 1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (pBook[mid].get_name() > name) {
            high = mid - 1;
        } else if (pBook[mid].get_name() == name) {
            end_index = mid;
            low = mid + 1;
        } else {
            low = mid + 1;
        }
    }
    return end_index;
}

void List::Add(int index, const Book &book) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
    }
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
    std::copy(books + index + 1, books + size, books + index);
    --size;

    if (size * GROWTH_FACTOR * GROWTH_FACTOR == capacity) {
        capacity /= GROWTH_FACTOR;

        Book *const temp = new Book[capacity];
        std::copy(books, books + size, temp);
        delete[](books);
        books = temp;
    }
}

List::List(const List &other) {
    capacity = other.capacity;
    size = other.size;
    books = new Book[capacity];
    std::copy(other.books, other.books + size, books);
}

int List::get_size() const {
    return size;
}

List &List::operator=(const List &other) {
    if (this != &other) {
        if (other.size != size) {
            delete[] books;
            size = 0;
            books = nullptr;
            books = new Book[other.size];
            size = other.size;
        }
        std::copy(other.books, other.books + other.size, books);
    }
    return *this;
}

ostream &operator<<(ostream &os, const List &list) {
    os << "List [\n";
    for (int i = 0; i < list.size; ++i) {
        os << "    " << list.books[i];
        if (i < list.size - 1) {
            os << ',';
        }
        os << '\n';
    }
    return os << "]\n";
}
