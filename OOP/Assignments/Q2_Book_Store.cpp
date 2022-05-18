/*
A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher, and stock position. Whenever a customer wants a book, the salesperson inputs the title and author, and the system searches the list and displays whether it is available or not. If it is not, an appropriate message must be displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message " Required copies not in stock" is displayed.
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// declaration of class books
class books
{

    // data members of books class
public:
    char author[20];
    char title[20];
    char publisher[50];
    int price;
    int copies;
    int stock;

    // setData() function to set data of books
    void setData()
    {
        cout << "\nEnter the following details:\nAuthor's Name:";
        gets(author);
        cout << "\nTitle :";
        gets(title);
        cout << "\nPublisher :";
        gets(publisher);
        cout << "\nPrice :";
        cin >> price;
        cout << "\nNumber of copies:";
        cin >> copies;
        stock = 1;
    }

    // check() function to check if a book is available or not
    void check()
    {
        char t[20], aut[20];
        int cop;
        cout << "\nEnter the following details to search for book:\n";
        cout << "\nTitle of the book:";
        gets(t);
        cout << "\nEnter Author's Name :";
        gets(aut);
        cout << "\nNumber of copies:";
        cin >> cop;
        if (strcmp(t, title) & strcmp(aut, author) & (cop <= copies))
        {
            cout << "\nBook is availabe in store\nPrice = " << cop * price;
            copies -= cop;
        }
        else
        {
            cout << "Not available";
        }
    }
};

void main()
{
    books bk;
    bk.setData();
    bk.check();
    getch();
}
