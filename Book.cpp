#include "Book.h"

//GETTERS AND SETTERS
    int Book::GetYear() {return m_year;} //return year
    string Book::GetTitle() {return m_title;} // return title
    string Book::GetAuthor() {return m_author;} // return author(s)
    double Book::GetScore() {return m_score;} // return rating score
    void Book::SetYear(int year) {m_year = year;} //sets year
    void Book::SetTitle(string title) {m_title = title;} //sets title
    void Book::SetAuthor(string author) {m_author = author;} //sets author(s)
    void Book::SetScore(double score) {m_score = score;} //sets score

//DisplayBook()
    void Book::DisplayBook(){
        cout << GetTitle() << " (" << GetYear() << ") by " << GetAuthor() << " with a score of " << GetScore() << endl;
    }


