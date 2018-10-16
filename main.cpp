//
// Created by Peter Hoc on 10/1/2018.
//

#include <iostream>
#include "list.h"

using namespace std;

void ShowSelections();

void AddBook(List &list);

void UpdateBook(List &list);

void DeleteBook(List &list);

void SearchBook(List &list);

void Sort(List &list);

void ClearInputStream();

void PrintSearchResult(const pair<Book *, size_t> &res);

int main() {
  List list;

//  list.AddLast(Book("122222226", "name4", 2000, 44));
//  list.AddLast(Book("122222225", "name4", 2000, 23));
//  list.AddLast(Book("122222222", "name4", 2000, 44));
//  list.AddLast(Book("122222222", "name1", 2000, 20));
//  list.AddLast(Book("122222223", "name2", 2000, 2));
//  list.AddLast(Book("122222224", "name3", 2000, 0));
//  list.AddLast(Book("122222220", "name6", 2000, 9999));
//  list.AddLast(Book("199999999", "name7", 2000, 99));

  while (true) {
    ShowSelections();

    int selection;
    if (!(cin >> selection)) {
      ClearInputStream();
      break;
    }
    if (!(1 <= selection && selection <= 7)) {
      break;
    }

    switch (selection) {
      case 1:
        list.ShowList();
        break;
      case 2:
        AddBook(list);
        break;
      case 3:
        UpdateBook(list);
        break;
      case 4:
        DeleteBook(list);
        break;
      case 5:
        SearchBook(list);
        break;
      case 6:
        Sort(list);
        break;
      case 7:
        cin >> list;
        std::cout << "Danh sach sau khi nhap" << '\n';
        list.ShowList();
        break;
    }
    cout << "\n\n";
  }

  return 0;
}

void SearchBook(List &list) {
  cout << "Chon thuoc tinh de tim kiem:" << '\n';
  cout << " 1. Tim kiem bang ma sach" << '\n';
  cout << " 2. Tim kiem bang ten" << '\n';
  cout << " 3. Tim kiem bang so luong" << '\n';
  cout << " 4. Tim kiem bang nam xuat ban" << '\n';
  cout << "    Nhap bat ki de thoat muc tim kiem sach" << '\n';


  int selection;
  if (!(cin >> selection)) {
    return ClearInputStream();
  }
  if (!(1 <= selection && selection <= 4)) {
    return;
  }

  if (selection == 1) {
    cout << "Can sap xep danh sach theo ma sach truoc khi tim kiem? (y/n) ";
    char agree;
    cin >> agree;
    if (agree != 'y') return;

    list.QuickSortByIdAscending();

    string id;
    cout << "Nhap ma sach can tim kiem: ";
    cin.ignore();
    getline(cin, id);

    PrintSearchResult(list.BinarySearchById(id));
  } else if (selection == 2) {
    cout << "Can sap xep danh sach theo ten sach truoc khi tim kiem? (y/n) ";
    char agree;
    cin >> agree;
    if (agree != 'y') return;

    list.QuickSortByNameAscending();

    string name;
    cout << "Nhap ten sach can tim kiem: ";
    cin.ignore();
    getline(cin, name);

    PrintSearchResult(list.BinarySearchByName(name));
  } else if (selection == 3) {
    cout << "Can sap xep danh sach theo so luong truoc khi tim kiem? (y/n) ";
    char agree;
    cin >> agree;
    if (agree != 'y') return;

    list.QuickSort(compare_book_by_number_ascending);

    int number;
    cout << "Nhap so luong can tim kiem: ";
    cin >> number;

    PrintSearchResult(list.BinarySearch(number, select_number, compare_int_ascending));
  } else if (selection == 4) {
    cout << "Can sap xep danh sach theo nam xuat ban truoc khi tim kiem? (y/n) ";
    char agree;
    cin >> agree;
    if (agree != 'y') return;

    list.QuickSort(compare_book_by_published_year_ascending);

    int published_year;
    cout << "Nhap nam xuat ban can tim kiem: ";
    cin >> published_year;

    PrintSearchResult(list.BinarySearch(published_year, select_published_year, compare_int_ascending));
  }
}

void PrintSearchResult(const pair<Book *, size_t> &res) {
  if (res.first == NULL) {
    cout << "Khong tim thay!" << '\n';
  } else {
    cout << "Co " << res.second << " ket qua tim kiem duoc: " << '\n';
    for (int i = 0; i < res.second; ++i) {
      cout << i + 1 << ".    " << res.first[i] << '\n';
    }
  }
}

void DeleteBook(List &list) {
  cout << "Chon vi tri xoa:" << '\n';
  cout << " 1. Xoa dau danh sach" << '\n';
  cout << " 2. Xoa cuoi danh sach" << '\n';
  cout << " 3. Xoa vi tri bat ki" << '\n';
  cout << "    Nhap bat ki de thoat muc xoa sach" << '\n';

  int selection;
  if (!(cin >> selection)) {
    return ClearInputStream();
  }
  if (!(1 <= selection && selection <= 3)) {
    return;
  }

  if (selection == 1) {
    list.RemoveFirst();
    std::cout << "Danh sach sau khi xoa" << '\n';
    list.ShowList();
  } else if (selection == 2) {
    list.RemoveLast();
    std::cout << "Danh sach sau khi xoa" << '\n';
    list.ShowList();
  } else if (selection == 3) {
    while (true) {
      try {
        cout << "Nhap vi tri: ";
        int index;
        if (!(cin >> index)) {
          ClearInputStream();
          continue;
        }
        list.RemoveAt(index);
        std::cout << "Danh sach sau khi xoa" << '\n';
        list.ShowList();
        break;
      } catch (const out_of_range &e) {
        cout << e.what() << '\n';
      }
    }
  }
}

void UpdateBook(List &list) {
  cout << " 1. Cap nhat bang ma sach" << '\n';
  cout << " 2. Cap nhat bang ten" << '\n';
  cout << "    Nhap bat ki de thoat muc nay" << '\n';

  int selection;
  if (!(cin >> selection)) {
    return ClearInputStream();
  }
  if (!(1 <= selection && selection <= 2)) {
    return;
  }

  if (selection == 1) {
    cout << "Nhap ma sach doi tuong can cap nhat: ";
    string id;
    cin.ignore();
    getline(cin, id);

    list.UpdateById(id);
    std::cout << "Danh sach sau khi cap nhat" << '\n';
    list.ShowList();
  } else if (selection == 2) {
    cout << "Nhap ten doi tuong can cap nhat: ";
    string name;
    cin.ignore();
    getline(cin, name);

    list.UpdateByName(name);
    std::cout << "Danh sach sau khi cap nhat" << '\n';
    list.ShowList();
  }
}

void AddBook(List &list) {
  cout << "Chon vi tri them:" << '\n';
  cout << " 1. Them vao dau danh sach" << '\n';
  cout << " 2. Them vao cuoi danh sach" << '\n';
  cout << " 3. Them vao vi tri bat ki" << '\n';
  cout << "    Nhap bat ki de thoat muc them sach" << '\n';

  int selection;
  if (!(cin >> selection)) {
    return ClearInputStream();
  }
  if (!(1 <= selection && selection <= 3)) {
    return;
  }


  Book book;
  cin.ignore();
  if (!(cin >> book)) return;

  if (selection == 1) {
    list.AddFirst(book);
    std::cout << "Danh sach sau khi them" << '\n';
    list.ShowList();
  } else if (selection == 2) {
    list.AddLast(book);
    std::cout << "Danh sach sau khi them" << '\n';
    list.ShowList();
  } else if (selection == 3) {
    while (true) {
      try {
        cout << "Nhap vi tri: ";
        int index;
        if (!(cin >> index)) {
          ClearInputStream();
          continue;
        }
        list.Add(index, book);
        std::cout << "Danh sach sau khi them" << '\n';
        list.ShowList();
        break;
      } catch (const out_of_range &e) {
        cout << e.what() << '\n';
      }
    }
  }
}

void ClearInputStream() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ShowSelections() {
  cout
      << "======================================================================================================"
      << '\n';
  cout << " 1. Hien thi danh sach doi tuong" << '\n';
  cout << " 2. Them doi tuong" << '\n';
  cout << " 3. Cap nhap thong tin doi tuong" << '\n';
  cout << " 4. Xoa doi tuong" << '\n';
  cout << " 5. Tim kiem doi tuong" << '\n';
  cout << " 6. Sap xep danh sach" << '\n';
  cout << " 7. Nhap moi hoan toan danh sach" << '\n';
  cout << "    Phim bat ki de thoat chuong trinh" << '\n';
}

void Sort(List &list) {
  cout << " 1. Sap xep theo ma sach tang dan" << '\n';
  cout << " 2. Sap xep theo ma sach giam dan" << '\n';
  cout << " 3. Sap xep theo ten sach tang dan" << '\n';
  cout << " 4. Sap xep theo ten sach giam dan" << '\n';
  cout << " 5. Sap xep theo so luong tang dan" << '\n';
  cout << " 6. Sap xep theo so luong giam dan" << '\n';
  cout << " 7. Sap xep theo nam xuat ban tang dan" << '\n';
  cout << " 8. Sap xep theo nam xuat ban giam dan" << '\n';
  cout << "    Phim bat ki de thoat muc sap xep" << '\n';

  int selection;
  if (!(cin >> selection)) {
    return ClearInputStream();
  }
  if (!(1 <= selection && selection <= 8)) {
    return;
  }

  switch (selection) {
    case 1:
      list.QuickSortByIdAscending();
      break;
    case 2:
      list.QuickSort(compare_book_by_id_descending);
      break;
    case 3:
      list.QuickSortByNameAscending();
      break;
    case 4:
      list.QuickSort(compare_book_by_name_descending);
      break;
    case 5:
      list.QuickSort(compare_book_by_number_ascending);
      break;
    case 6:
      list.QuickSort(compare_book_by_number_descending);
      break;
    case 7:
      list.QuickSort(compare_book_by_published_year_ascending);
      break;
    case 8:
      list.QuickSort(compare_book_by_published_year_descending);
      break;
  }

  cout << "Danh sach sau khi sap xep: " << '\n';
  cout << list << '\n';
}
