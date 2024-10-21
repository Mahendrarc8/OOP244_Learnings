/*
Name: Mahendra Roka
ID: 143117232
Email: mroka1@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include <iostream>
#include "utils.h"
#include "movie.h"
using namespace std;
using namespace seneca;


int main() {
    bool done = false;
    char genre[128];
    loadMovies();
    cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
    while (!done) {
        cout << "Enter the movie genre to start the search: ";
        cin >> genre;
        flushkeys();
        displayMoviesWithGenre(genre);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
