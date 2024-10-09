# Library Booking System

### Overview
The **Library Booking System** is a C++ application that allows users to interact with a catalog of books stored in an external file. The system provides functionality to view the catalog, search for specific books by title, and add selected books to a waitlist. The program ensures that the waitlist capacity is respected and prevents duplicate entries. Additionally, users can load their own book catalog file of any size, as long as the constant `NUM_BOOKS` is adjusted accordingly to match the number of books in the file.

### Features
- **View Entire Catalog**: Display the entire list of books in increments of 10, allowing for easy navigation.
- **Search by Title**: Allows users to search the catalog for a specific book or partial title using a **linear search algorithm**.
- **Manage Waitlist**: Add books to a waitlist (up to 5 books), with checks to ensure no duplicate entries.
- **Display Waitlist**: View the books currently on the waitlist.
- **Customizable Catalog**: Users can load their own library book catalog input file of any size by updating the `NUM_BOOKS` constant to reflect the correct number of entries in the file.

### Technical Overview
- **Branching Structures**: This project uses extensive `if-else` and `switch` statements to manage the user input and program flow, ensuring the application can handle different user commands, such as displaying books, searching the catalog, and managing the waitlist.
- **Program Abstraction**: The project follows object-oriented principles by separating functionality into two fundamental classes: `Book` and `Library`. This abstraction improves code modularity and makes the system easier to maintain and extend.
- **File Parsing Algorithm**: The library catalog is loaded from an external file (`library_books.txt`) using a **file parsing algorithm**. Each file line is tokenized using a `|` delimiter, converting strings into their appropriate data types (year, title, author, and score).
- **Linear Search Algorithm**: The **linear search algorithm** searches for book titles within the catalog. The algorithm iterates through the catalog, comparing each book's title to the user’s query, allowing for partial matches.
- **Menu-Driven Interface**: The system utilizes a loop-driven menu with `switch` statements to guide user interactions, providing options such as viewing the catalog, searching, and adding books to the waitlist.

### Files
1. **Library.h / Library.cpp**: These files define and implement the `Library` class, which manages the catalog, waitlist, and user interaction. It also includes the main menu logic and functions like `SearchCatalog` and `AddBook`.
2. **Book.h / Book.cpp**: These files define and implement the `Book` class, which encapsulates the details of each book, such as title, author, year, and score.
3. **driver.cpp**: The main driver that starts the application and runs the `Library` system.
4. **library_books.txt**: This is the default input file containing the book data, with each book's details (year, title, author(s), and score) separated by the `|` delimiter. Users can substitute this with their own catalog file and adjust the `NUM_BOOKS` constant to match the size of the new file.

### How to Use
1. **Adjust the NUM_BOOKS Constant**: If you want to load your own book catalog, adjust the `NUM_BOOKS` constant in `Library.h` to match the number of books in your input file.
   ```cpp
   const int NUM_BOOKS = [number of books in your catalog file];
   ```

2. **Compile** the project using the following command:
   ```bash
   g++ driver.cpp Library.cpp Book.cpp -o library_system
   ```

3. **Run the Program**:
   ```bash
   ./library_system [your_catalog_file.txt]
   ```

4. **Main Menu**:
    - **1. Display All Books**: View the full catalog of books in increments of 10.
    - **2. Search Catalog for Book Title**: Search for a book by entering its title or a portion of it using the **linear search algorithm**.
    - **3. Add Book to Waitlist**: Add a book from the catalog (up to 5 books) to your waitlist.
    - **4. Display Waitlist**: View the books currently on the waitlist.
    - **5. Quit**: Exit the program.

### Sample Input Format (library_books.txt)
```plaintext
1987|Batman: Year One|Frank Miller, David Mazzucchelli, Richmond Lewis, Dennis O'Neil|4.23
2015|Go Set a Watchman|Harper Lee|3.31
2008|When You Are Engulfed in Flames|David Sedaris|4.04
...
```
Each line in the input file contains the **Year**, **Title**, **Author(s)**, and **Score**, separated by the `|` delimiter.

### Example Output
```plaintext
1. Batman: Year One (1987) by Frank Miller, David Mazzucchelli, Richmond Lewis, Dennis O'Neil with a score of 4.23
2. Go Set a Watchman (2015) by Harper Lee with a score of 3.31
...
```

### What I Learned
Through building the **Library Booking System**, I gained experience with:
- **Program Abstraction**: By separating functionality into distinct classes (`Book` and `Library`), I improved my understanding of object-oriented design, making the program more modular and maintainable.
- **Branching Structures**: I used a variety of branching structures (`if-else` and `switch` statements) to manage user input and program flow efficiently.
- **File Parsing Algorithm**: Implementing a **file parsing algorithm** to read and process data from an external file allowed me to strengthen my skills in handling file I/O operations and converting string data into usable formats.
- **Linear Search Algorithm**: I implemented a **linear search algorithm** to efficiently search the catalog for book titles, which improved my understanding of basic search techniques in arrays.
- **Menu-Driven Interface**: I developed a user-friendly menu system that handles multiple inputs and guides the user through the application's various features.
- **Custom Input Handling**: I learned how to make the system flexible, allowing users to input their own book catalog files, and ensuring the system adjusts accordingly by changing the `NUM_BOOKS` constant.
