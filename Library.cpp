#include "Library.h"

//Constructor Definitions
//Default
Library::Library(){}
//overloaded
Library::Library(string filename){
  LoadCatalog(filename);
}

//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file into the m_bookCatalog (as books)
//Note: You are permitted to use stoi (string to integer) and stod
// (string to double) to convert during loading of catalog
void Library::LoadCatalog(string filename){

    ifstream file(filename);

    string line; //represents a a single line, for a single book's info
    int i = 0;
    //opening and processing book into m_bookCatalog
    if (file.is_open()){
        while(getline(file, line) && i < NUM_BOOKS){
          //variabels for a single book
          int year; //Year
          string title; //Title
          string author; //Author
          double score; //Score
          string strYear, strScore; //convert these to int and double using stoi and stod

          int endPos; //int to track end Position of substring while reading in the line
          int startPos = 0; //int to track start Position of substring while reading in the line

          // for finding an intialzing the year. Coverted to int using stoi
          endPos = line.find(DELIMETER, startPos);
          year = stoi(line.substr(startPos,endPos-startPos));
          startPos = endPos + 1; //reset startPos for extractin next variable
          
          // for title
          endPos = line.find(DELIMETER, startPos);
          title = line.substr(startPos,endPos-startPos);
          startPos = endPos + 1; //reset startPos for extractin next variable
          
          // for author
          endPos = line.find(DELIMETER, startPos);
          author = line.substr(startPos,endPos-startPos);
          startPos = endPos + 1; //reset startPos for extractin next variable
          
          //for score: used stod to convert to souble
          score = stod(line.substr(startPos));

          //now take the extracted vars and make a Book object with it
          Book aBook(year, title, author, score);
          //put it in the book catalog array
          m_bookCatalog[i] = aBook;
          i++;
        }
        cout << "Catalog populated with " << i << " books." << endl;
    }
    else{ //input val (technically it should always load the same file every time, but just in case)
      cout << "File Does not exist" << endl;
    }
    file.close();
  }

//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu
void Library::MainMenu(){
  bool isRunning = true; // var for keeping the program running
  do{ 
    int command; //var for handling input commands
    
    //main menu  (output)
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Display All Books" << endl;
    cout << "2. Search Catalog for Book Title" << endl;
    cout << "3. Add Book to Waitlist" << endl;
    cout << "4. Display Waitlist" << endl;
    cout << "5. Quit" << endl;
    cin >> command;
    cin.ignore(); //ignores potential newline charaters

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
      default: cout << "\n";//input val (reprompts)        
    }
  } while (isRunning); 
}

//Name: DisplayBooks
  //Precondition: Displays the master list of all books in catalog
  //Postcondition: Lists all books (numbered starting at 1)
  //Note: Displays 10 books per screen using constant INCR
  //If the user enters Q or q, the program stops displaying
  //  books and returns to main menu else displays next 10 books
  void Library::DisplayBooks(){
    int spacer = 0; // for incrementing the bounds of books to be displayed
    bool isRunning = true; //var to keep the list displayed until user quits
    
    while (isRunning){
      for (int i = spacer; i < spacer + INCR && i < NUM_BOOKS; i++){
        cout << i+1 << ". "; //displays book number in the catalog
        m_bookCatalog[i].DisplayBook(); 
      }
      //prompt
      cout << "N for next, Q to quit" << endl;
      char command;
      cin >> command;
      
      //input val
      while (command != 'N' && command != 'n' && command != 'Q' && command != 'q'){
        cout << "Invalid input" << endl;
        cout << "N for next, Q to quit" << endl;
        cin >> command;
      }
      //for advancing list
      if (command == 'N' || command == 'n'){
        spacer += INCR; //increment the bounds 
        if (spacer >= NUM_BOOKS)
          isRunning = false; //ends function if all books are already displayed
        }

      else{  //only remaining poosible input after input val and N/n is Q/q
        isRunning = false; //ends function
      }
    }
  }

//Name: SearchCatalog()
  //Precondition: Requires m_bookCatalog
  //Postcondition: Searches m_bookCatalog by title
  //Note: Use string function of .find to search for any part of string
void Library::SearchCatalog(){
    string input;
    cout << "What title would you like to search for?" << endl;
    cin.ignore(); //clear any possible newline characters
    getline(cin, input);

    bool found = false; //flag

    for (int i = 0; i < NUM_BOOKS; i++){
      //checks if the term exists in the the title by seeing if find() will return anything between 0-256.
      //Its just a random range assigned since find() always returns the index of the found sub-string. 
      if (m_bookCatalog[i].GetTitle().find(input) >= 0 && m_bookCatalog[i].GetTitle().find(input) < 256){ 
        cout << "\t" << i+1 << ". ";
        m_bookCatalog[i].DisplayBook();
        found = true; //set the flag to true
      }
    }
  if (found == false) //if the title was never found in the catalog
        cout << "No books with that title found." << endl;
  }
  

//Name: AddBook
//Precondition: m_bookCatalog is populated
//Postcondition: Displays the current list and copies a book to m_waitList
//               Increments m_waitCount and limits capacity to MAX_WAIT
void Library::AddBook(){
    //if waitlist is already full
    if (m_waitCount >= MAX_WAIT){
        cout << "No additional books can be added to the wait list." << endl;
      }
    else{  
      int bookNum;
      bool Looping = true; //var for looping for reprompts
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

        else{ //For actaully adding it to the waitlist
          m_waitList[m_waitCount] = m_bookCatalog[bookNum-1];
          m_waitCount++;
          Looping = false;
        }
      } while(Looping);
    } 
  }

//Name: BookExist(Book)
//Precondition: m_bookCatalog is populated
//Postcondition: Helper function to check if passed book exists in m_waitList. Returns true if exists in m_waitList else false
bool Library::BookExist(Book book){
    for (int i = 0; i < m_waitCount; i++){
      if (m_waitList[i].GetTitle() == book.GetTitle()) //if the title of the book from the wailist to the catalog its already in the wailist.
        return true;
    }
    return false;
  }

//Name: DisplayWaitList
//Precondition: m_bookCatalog is populated
//Postcondition: Displays the WaitList using DisplayBook
void Library::DisplayWaitList(){
    cout << "**Current Waitlist**" << endl;
    for (int i = 0; i < m_waitCount ; i++){
      cout << i+1 <<". "; //Waitlist Book number
      m_waitList[i].DisplayBook(); //prints book info message
    }
  }