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
  int string_length = strlen(phrase); //know the size of a row

  char ** temp = new char * [string_length + 1];       //make the array of envp values  +1 bigger
  for(int idx = 0; idx < size; idx++) temp[idx] = data[idx]; //write everything over
  delete [] data; //clean up
  data = temp;

  if((data[size][0] < 32) |(data[size][0] > 127)) //if there are no printable characters at point of insertion
  {
    for(int idx = 0; idx < (string_length - 1); idx++) data[size][idx] = phrase[idx]; //copy phrase into your new pointer
  }

}

std::ostream & operator << (std::ostream &ugh, list &list_class)
{
  //print the whole thing out
  for(int idx = 0; idx < list_class.size; idx++) std::cout << list_class.data[idx];
}

list::~list()
{}

list::list(const list&) //the copy function
{}

