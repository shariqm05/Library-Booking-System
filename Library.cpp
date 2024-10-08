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
          int pos; //int to track position while reading in the line

          // for finding an intialzing the year. Coverted to int using stoi
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

          //now take the extracted vars and make a Book object with it
          Book aBook(year, title, author, score);
          //put it int the book catalog array
          m_bookCatalog[i] = aBook;
          i++;
        }
        cout << "Catalog populated with " << i << " books." << endl;
    }
    else{ //input val
      cout << "File Does not exist" << endl;
    }
    file.close();
  }

//MainMenu()
void Library::MainMenu(){
  bool isRunning = true;
  do{
    int command;
    
    //main menu 
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Display All Books" << endl;
    cout << "2. Search Catalog for Book Title" << endl;
    cout << "3. Add Book to Waitlist" << endl;
    cout << "4. Display Waitlist" << endl;
    cout << "5. Quit" << endl;
    cin >> command;

    //for handling input
    switch(command){
      case 1: 
        DisplayBooks();
        break;
      case 2: 
        SearchCatalog();
        break;
      case 3: 
        AddBook();
        break;
      case 4: 
        DisplayWaitList();
        break;
      case 5: 
        isRunning = false; //ends program
        break;
      default: cout << "\n";//input val         
    }
  } while (isRunning); 
}

//AddBook()
void Library::AddBook(){
    //if waitlist is already full
    if (m_waitCount >= MAX_WAIT){
        cout << "No additional books can be added to the wait list." << endl;
      }
    else{
      int bookNum;
      bool Looping = true;
      do{
        cout << "Which book would you like to add? (-1 for list)" << endl;
        cin >> bookNum;

        //input val
        if((bookNum < -1) || (bookNum == 0) || bookNum > NUM_BOOKS){
          cout << "Invalid number" << endl;
        }

        //for displaying list
        else if (bookNum == -1){
          DisplayBooks();
        }

        //If its already on the waitlist
        else if(BookExist(m_bookCatalog[bookNum-1])){
          cout << m_bookCatalog[bookNum-1].GetTitle() << " is already on the waitlist." << endl;
        }

        else{
          m_waitList[m_waitCount] = m_bookCatalog[bookNum-1];
          m_waitCount++;
          Looping = false;
        }
      } while(Looping);
    } 
  }

//BookExist()
bool Library::BookExist(Book book){
    for (int i = 0; i < m_waitCount; i++){
      if (m_waitList[i].GetTitle() == book.GetTitle())
        return true;
    }
    return false;
  }

void Library::DisplayWaitList(){
    cout << "**Current WAitlist**" << endl;
    for (int i = 0; i < m_waitCount ; i++){
      cout << i+1 <<". ";
      m_waitList[i].DisplayBook();
    }
  }