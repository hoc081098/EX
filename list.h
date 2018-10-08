//
// Created by Peter Hoc on 10/1/2018.
//

#ifndef BAITAPOOP01_LIST_H
#define BAITAPOOP01_LIST_H

#include <iostream>
#include "book.h"

class List {
private:
    static constexpr int GROWTH_FACTOR = 2;
    static constexpr int DEFAULT_INITIAL_CAPACITY = 8;

    Book *books;
    int capacity;
    int size;

    void QuickSort(Book *books, int start, int end, bool compare(const Book &a, const Book &b)) const;

    std::pair<int, int>
    BinarySearch(Book books[], int start, int end, const string &name) const;

    int LowerBound(Book *pBook, int start, int end, const string &name) const;

    int UpperBound(Book *pBook, int start, int end, const string &name) const;

    void EnsureCapacity();

protected:

public:
    List();

    List(const List &other);

    virtual ~List();

    void ShowList() const;

    void AddFirst(const Book &book);

    void AddLast(const Book &book);

    void Add(int index, const Book &book);

    void Update();

    void RemoveFirst();

    void RemoveLast();

    void RemoveAt(int index);

    std::pair<Book *, std::size_t> BinarySearch(const string &name) const;

    void QuickSort(bool compare(const Book &a, const Book &b));

    int get_size() const;

    List& operator=(const List& other);

    friend ostream &operator<<(ostream &os, const List &list);
};


#endif //BAITAPOOP01_LIST_H
