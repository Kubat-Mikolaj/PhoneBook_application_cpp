# PhoneBook_application_cpp
A C++ console-based application for storing, organizing, and managing contact information. It features a binary search tree for data organization, file handling for persistence, and implements object-oriented principles.

**Key Features and Technologies Used:**
1. C++ Programming Language:
Designed and implemented using modern C++ standards.

2. Object-Oriented Programming (OOP):
**Encapsulation:** Data is protected and accessed through getter and setter methods.
**Modular Design:** Classes like Contact, Node, and PhoneBook ensure separation of concerns.
**Overloaded Operators:** Custom operators (<<) for stream handling.

3. Binary Search Tree (BST):
Contacts are stored in a binary search tree for efficient searching and sorting.
Includes methods for insertion, traversal, and searching.

4.File Handling:
Contacts can be saved to and loaded from a CSV file for persistence.
Utilizes std::ofstream and std::ifstream for file I/O operations.

5. Data Sorting and Searching:
Contacts can be sorted alphabetically by surname using std::sort.
Searching is implemented using a restructured BST traversal for fast keyword matching.

6. Recurisve Algorithms:
In-order traversal of the BST for ordered data retrieval.
Recursive insertion and search methods.

7. Menu-driven User Interface:
Console-based menu system with options to add, display, search, sort, save, and load contacts.

8. Standard Template Library (STL):
Used containers like std::vector for temporary data manipulation.
Lambda functions for sorting operations.

9. Error Handling:
Built-in checks for file I/O failures (e.g., missing or unreadable files).
Validates user input in the console menu.

10. Expandable Design:
The project is modular and ready for extensions, such as:
Integration with a database (e.g., SQLite).
GUI development using libraries like Qt or GTK.
Advanced structures like AVL trees or hash tables.


**Next Steps to Implement:**

**1. Database (DBMS)**

**2. Multithreading**

**3. Graphical User Interface (GUI)**

**4. BST Enhancement** - Replacing the Binary Search Tree (BST) with an AVL tree or Red-Black tree to ensure balance and improve performance.
