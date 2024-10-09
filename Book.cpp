#include "Book.h"
//CONSTRUCTOR 
//Default
Book::Book(){}
//Overloaded
Book::Book(int year, string title, string author, double score){
  m_year = year;
  m_title = title;
  m_author = author;
  m_score = score;
}

//GETTERS AND SETTERS
    int Book::GetYear() {return m_year;} //return year
    string Book::GetTitle() {return m_title;} // return title
    string Book::GetAuthor() {return m_author;} // return author(s)
    double Book::GetScore() {return m_score;} // return rating score
    void Book::SetYear(int year) {m_year = year;} //sets year
    void Book::SetTitle(string title) {m_title = title;} //sets title
    void Book::SetAuthor(string author) {m_author = author;} //sets author(s)
    void Book::SetScore(double score) {m_score = score;} //sets score

//Name: DisplayBook
//Precondition: Requires book variables to be populated
//Postcondition: None
//Desc: Displays the information about the book
    void Book::DisplayBook(){  // uses the getters to print the statement
        cout << GetTitle() << " (" << GetYear() << ") by " << GetAuthor() << " with a score of " << GetScore() << endl;
    }


