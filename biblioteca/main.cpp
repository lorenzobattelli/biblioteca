//
//  main.cpp
//  biblioteca
//
//  Created by Lorenzo Battelli on 06/08/22.
//

#include <iostream>
#include <string>
#include <vector>

#define N_KEYS 3

using namespace std;


typedef struct _book {
    string id;                          // stringa identificativa del libro
    string title;                       // stringa titolo
    string author;                      // stringa autore
    vector<string> keywords;            // numero parole chiave per ogni libro
} book;


void print_book(book b) {
    cout << b.id << " " << b.author << " " << b.title << endl;
    unsigned long len = b.keywords.size();
    if (len) {
        for (int i = 0; i < len; i++) {
            cout << b.keywords[i] << " ";
        }
        cout << endl;
    }
}


void print_library(vector<book> books) {
    for (int i = 0; i < books.size(); i++) {
        print_book(books[i]);
        cout << endl;
    }
}


int main(int argc, char* argv[]) {

    char stop = 'n';
    vector<book> books;
    
    do {
        book new_book;
        
        cout << "Inserisci codice: ";
        cin >> new_book.id;
        
        cout << "Inserisci titolo: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline (cin, new_book.title);
        
        cout << "Inserisci autore: ";
        getline(cin, new_book.author);
        
         for (int i = 0; i < N_KEYS; i++) {
             cout << i+1 << "° parole chiave: ";
             string word;
             cin >> word;
             new_book.keywords.push_back(word);
         }

        
        books.push_back(new_book);
        
        cout << "Continuare? [y/n]" << endl;
        cin >> stop;
        
    } while (stop == 'y');
    
    cout << endl << "-----------------------------------------------------" << endl;
    print_library(books);
    

    return 0;
}
