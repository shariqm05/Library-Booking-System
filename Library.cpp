#include "Library.h"

//LoadCatalog()
void Library::LoadCatalog(string filename){
    ifstream file(filename);

    string line; //represents a a single line, for a single book's info
    int i = 0;
    //opening and processing book into m_bookCatalog
    if (file.is_open()){
        while(getline(file, line) && i < NUM_BOOKS){
          //variabels for a single book
          int year; //Year of book
          string title; //Title of book
          string author; //Author(s) of book
          double score; //Aggregated score (rating)
          string strYear, strScore; //convert these to int and double using stoi and stod
          size_t pos;

          // for finsing an intialzing the year. Coverted to int using stoi
          pos = line.find(DELIMETER);
          year = stoi(line.substr(0,pos));
          line.erase(0,pos+1); //erase that part of the line
          // for title
          pos = line.find(DELIMETER);
          title = line.substr(0,pos);
          line.erase(0,pos+1); //erase that part of the line
          // for author
          pos = line.find(DELIMETER);
          author = line.substr(0,pos);
          line.erase(0,pos+1); //erase that part of the line
          //for score: used stod to convert to souble
          score = stod(line);

          //now take the extracte varaiables and mak a Book object with it
          Book aBook(year, title, author, score);
          //put it int the book catalog array
          m_bookCatalog[i] = aBook;
          i++;
        }
    }
    else{ //input val
      cout << "File Does not exist" << endl;
    }
    file.close();
  }
