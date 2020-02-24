#include "list.h"
//List v 1.0.0 by Chris L

list::list() //instantiate an empty list
{
  int const MAX_CHAR = 0;
  size = 0; 
  char ** data = new char* [MAX_CHAR]; //what're we doing weith new and does it need to happen somehwere else
  data[MAX_CHAR] = NULL;
}

list::list(int size_int)
{
  int size = size_int;
  char ** data = new char* [size]; //allocate space the size of the incoming int
  for(int idx = 0; idx < (size - 1);  idx++)
  {
    data[idx] = NULL; //set each
  }
}

void list::insert(const char *phrase) //adds c strings to the list
{
  int length = strlen(phrase); //know the size of a row
  int position = 0;
  
  //how do we detirmine whether a row is empty
  while(data[position] != NULL) //we're filling from top to bottom  
  {
    position++;
  }

  for(int idx = 0; idx < (length - 1); idx++)
  {
    // *(list::data[idx]) = *phrase;
  }
}

std::ostream & operator << (std::ostream &ugh, list &list_class)
{
  std::cout << &ugh << std::endl;
}

list::~list()
{}

list::list(const list&) //the copy function
{}

