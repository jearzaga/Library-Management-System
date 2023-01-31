#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void title() {
    cout << "\n\tWelcome to the Library Management System!\n";
}

void line() {
    cout << "_______________________________________________________\n";
}

void menu() {
    cout << "\n";
    cout << "1. Add a new book\n";
    cout << "2. Search books by prefix\n";
    cout << "3. Borrow a book\n";
    cout << "4. Return a book\n";
    cout << "5. Display all books\n";
    cout << "6. Display all borrowed books\n";
    cout << "7. Display all returned books\n";
    cout << "8. Exit\n";
}

void addBook(vector<string> &books, vector<int> &bookQuantity) {//add books
    string book;
    int quantity;
    cout << "Enter the name of the book: ";
    getline(cin >> ws, book);
    cout << "Enter the quantity of the book: ";
    cin >> quantity;
    books.push_back(book);
    bookQuantity.push_back(quantity);
}

void searchBook(vector<string> &books, vector<int> &bookQuantity, string prefix) { //search books
    cout << "Enter the prefix of the book: ";
    getline(cin >> ws, prefix);
    for (int i = 0; i < books.size(); i++) {
        if (books[i].find(prefix) != string::npos) {
            cout << "\nBook name: " << books[i] << "\nTotal Quantity: " << bookQuantity[i] << endl;
        }
    }
}

void borrowBook(vector<string> &books, vector<int> &bookQuantity, vector<string> &names, vector<string> &book_borrowed) { // borrow books
    string name, book;
    cout << "Enter your name: ";
    getline(cin >> ws, name);
    cout << "Enter the name of the book you want to borrow: ";
    getline(cin >> ws, book);
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == book) {
            if (bookQuantity[i] > 0) {
                bookQuantity[i] -= 1;
                names.push_back(name);
                book_borrowed.push_back(book);
                cout << "You have successfully borrowed the book!\n";
            }
            else {
                cout << "Sorry, the book is not available.\n";
            }
        }
    }
}

void returnBook(vector<string> &books, vector<int> &bookQuantity, vector<string> &names, vector<string> &book_borrowed, vector<string> &book_returned, vector<string> &name_returned) { //return books
    string name, book;
    cout << "Enter your name: ";
    getline(cin >> ws, name);
    cout << "Enter the name of the book you want to return: ";
    getline(cin >> ws, book);
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == book) {
            if (names[i] == name) {
                    names.erase(names.begin() + i);
                    book_borrowed.erase(book_borrowed.begin() + i);
                
                    if (bookQuantity[i] < 4) {
                        bookQuantity[i] += 1;
                        book_returned.push_back(book);
                        name_returned.push_back(name);
                        cout << "You have successfully returned the book!\n";
                    }else{
                        cout << "Sorry, the book is not available.\n";
                    }
            }else{
                cout << "Sorry, you have not borrowed this book.\n";
            }   
        }
    }
}

void displayAllBooks(vector<string> &books, vector<int> &bookQuantity) { //display all books
    line();
    for (int i = 0; i < books.size(); i++) {
        cout << "\nBook name: " << books[i] << "\nTotal Quantity: " <<  bookQuantity[i] << endl;
        line();
    }
}

void displayBorrowedBooks(vector<string> &names, vector<string> &book_borrowed) { //display borrowed books
    line();
    for (int i = 0; i < names.size(); i++) {
        cout << "\nName: " << names[i] << "\nBook Borrowed: " << book_borrowed[i] << endl;
        line();
    }
}

void displayReturnedBooks(vector<string> &name_returned, vector<string> &book_returned) { //display returned books
    line();
    for (int i = 0; i < name_returned.size(); i++) {
        cout << "\nName: " << name_returned[i] << "\nBook Returned: " << book_returned[i] << endl;
        line();
    }
}

int main() {
    vector<string> books = {"Project Management", "All in Startup", "The Lean Startup", "As a Man Thinketh"};
    vector<int> bookQuantity = {1, 3, 2, 4};
    vector<string> names = {};
    vector<string> book_borrowed = {};
    vector<string> book_returned = {};
    vector<string> name_returned = {};
    int choice;

    system("cls");
    line();
    title();
    line();

    while (choice != 8) { //main loop
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        

        switch (choice) {
        case 1:
            addBook(books, bookQuantity);
            break;
        case 2:
            searchBook(books, bookQuantity, " ");
            break;
        case 3:
            borrowBook(books, bookQuantity, names, book_borrowed);
            break;
        case 4:
            returnBook(books, bookQuantity, names, book_borrowed, book_returned, name_returned);
            break;
        case 5:
            displayAllBooks(books, bookQuantity);
            break;
        case 6:
            displayBorrowedBooks(names, book_borrowed);
            break;
        case 7:
            displayReturnedBooks(name_returned, book_returned);
            break;
        case 8:
            cout << "Thank you for using this program!\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
    return 0;
}