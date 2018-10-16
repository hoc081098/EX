//
// Created by Peter Hoc on 10/1/2018.
//

#ifndef BAITAPOOP01_LIST_H
#define BAITAPOOP01_LIST_H

#include <iostream>
#include <sstream>
#include <functional>
#include "functions.h"
#include "book.h"

using namespace std;

class List {
private:
    static const int GROWTH_FACTOR;
    static const int DEFAULT_INITIAL_CAPACITY;

    Book *books;
    int capacity;
    size_t size;

    static void QuickSort(Book *books, int L, int H, const function<bool(const Book &, const Book &)> &compare);

    template<typename V>
    static int LowerBound(Book *pBook, int start, int end, const V &target,
                          const function<const V &(const Book &)> &selector,
                          const function<bool(const V &, const V &)> &compare) {
      int low = 0, high = end - 1;
      int start_index = -1;
      while (low <= high) {
        int mid = (high - low) / 2 + low;
        const V &mid_value = selector(pBook[mid]);

        if (compare(target, mid_value)) {
          high = mid - 1;
        } else if (compare(mid_value, target)) {
          low = mid + 1;
        } else {
          start_index = mid;
          high = mid - 1;
        }
      }
      return start_index;
    }

    template<typename V>
    static int UpperBound(Book *pBook, int start, int end, const V &target,
                          const function<const V &(const Book &)> &selector,
                          const function<bool(const V &, const V &)> &compare) {
      int end_index = -1;
      int low = 0;
      int high = end - 1;
      while (low <= high) {
        int mid = (high - low) / 2 + low;
        const V &mid_value = selector(pBook[mid]);

        if (compare(target, mid_value)) {
          high = mid - 1;
        } else if (compare(mid_value, target)) {
          low = mid + 1;
        } else {
          end_index = mid;
          low = mid + 1;
        }
      }
      return end_index;
    }

    template<typename V>
    static pair<Book *, size_t>
    BinarySearch(Book *pBook, int start, int end,
                 const V &target,
                 const function<const V &(const Book &)> &selector,
                 const function<bool(const V &, const V &)> &compare
    ) {
      const int startIndex = LowerBound(pBook, start, end, target, selector, compare);
      const int endIndex = UpperBound(pBook, start, end, target, selector, compare);

      if (startIndex != -1 && endIndex != -1) {
        const auto size = static_cast<const size_t>(endIndex - startIndex + 1);
        return {pBook + startIndex, size};
      } else {
        return {nullptr, 0};
      }
    }

    void EnsureCapacity();

    Book *const FindBookById(const string &book) const;

    void CheckIndex(int index, int start, int end) const;

protected:

public:
    List();

    List(const List &other);

    virtual ~List();

    void ShowList() const;

    void AddFirst(const Book &book);

    void AddLast(const Book &book);

    void Add(int index, const Book &book);

    template<typename V>
    void Update(const V &target, const V &selector(const Book &book)) {
      for (int i = 0; i < size; ++i) {
        if (target == selector(books[i])) {
          books[i].update();
          cin.ignore();
        }
      }
    }

    void UpdateById(const string &id);

    void UpdateByName(const string &name);

    void RemoveFirst();

    void RemoveLast();

    void RemoveAt(int index);

    pair<Book *, size_t> BinarySearchByName(const string &name) const;

    pair<Book *, size_t> BinarySearchById(const string &id) const;

    template<typename V>
    pair<Book *, size_t>
    BinarySearch(const V &target,
                 const function<const V &(const Book &)> &selector,
                 const function<bool(const V &, const V &)> &compare = less<>()) const {
      return List::BinarySearch(books, 0, size, target, selector, compare);
    }

    void QuickSort(const function<bool(const Book &, const Book &)> &compare);

    void QuickSortByIdAscending();

    void QuickSortByNameAscending();

    const size_t get_size() const;

    List &operator=(const List &other);

    friend ostream &operator<<(ostream &os, const List &list);

    friend istream &operator>>(istream &is, List &list);

    Book &operator[](size_t index);

    const Book &operator[](size_t index) const;

    void clear();
};

#endif //BAITAPOOP01_LIST_H
