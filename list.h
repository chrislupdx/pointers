#pragma once
// List Header
#include <iostream>
#include <cstring>

// List class definition

class     list
{
     public:
          list();                                 // Default constructor
          list(const list &);                     // Copy constructor
          list(int);                              // Parm constructor
          ~list();                                // Default destructor
          list & operator = (const list &);       // Copy assignment operator
          void insert(const char *);              // Ordered Insertion
          void resize();                          // Rightsize the memory
          
          friend std::ostream & operator << (std::ostream &, list &);

     private:
          int       size;                         // List size
          char      **data;                       // Dynamic list array
};

