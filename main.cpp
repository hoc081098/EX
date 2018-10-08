#include <iostream>
#include <algorithm>
#include "book.h"
#include "list.h"

int main() {

    List list;

    list.AddLast(Book("122222225", "name4", 2000, 23));
//    list.AddLast(Book("122222222", "name4", 2000, 44));
//    list.AddLast(Book("122222226", "name4", 2000, 44));
    list.AddLast(Book("122222222", "name1", 2000, 20));
    list.AddLast(Book("122222223", "name2", 2000, 2));
    list.AddLast(Book("122222224", "name3", 2000, 0));
    list.AddLast(Book("122222220", "name6", 2000, 9999));
    list.AddLast(Book("199999999", "name7", 2000, 99));

    std::cout << "Original:" << '\n';
    list.ShowList();

    list.QuickSort([](const Book &l, const Book &r) {
        return l.get_number() < r.get_number();
    });
    std::cout << "Sorted by number:" << '\n';
    list.ShowList();

    list.QuickSort([](const Book &l, const Book &r) {
        return l.get_name() < r.get_name();
    });
    std::cout << "Sorted by name:" << '\n';
    list.ShowList();


    const pair<Book *, size_t> &pair = list.BinarySearch("name@");
    if (pair.first == nullptr) {
        std::cout << "Not found" << '\n';
    } else {
        std::cout << "Found result:" << '\n';
        for (int i = 0; i < pair.second; ++i) {
            std::cout << pair.first[i] << '\n';
        }
        delete[] pair.first;
    }

    std::cout << "Add first:\n" << '\n';
    try {
        list.Add(7, Book("199992999", "name99", 2010, 2));
    } catch (const std::out_of_range &ex) {
        std::cout << ex.what() << '\n';
    }

    list.ShowList();


    std::cout << "Delete..." << '\n';
    list.RemoveFirst();
    list.RemoveAt(2);
    list.ShowList();


    for (int j = 0; j < 30; ++j) {
        list.AddLast(Book("199999999", "name7", 2000, 99));
    }
    for (int j = 0; j < 27; ++j) {
        list.RemoveLast();
    }
    for (int j = 0; j < 4; ++j) {
        list.AddLast(Book("199999999", "name7", 2000, 99));
    }


    List other = list;
    other.AddLast(Book("199999999", "name7", 2000, 99));
    std::cout << other.get_size() << '\n';
    std::cout << list.get_size() << '\n';


    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();
    other.RemoveLast();

    list.ShowList();

    return 0;
}