#include "list.h"
//List v 1.0.0 by Chris L

list::list() //instantiate an empty list
{
  size = 0; 
  data = new char* [size]; //what're we doing weith new and does it need to happen somehwere else
  data[size] = nullptr;
}

list::list(int size_int)
{
  size = 0;
  data = new char * [size_int];
  //char ** data = new char* [size_int]; //allocate space the size of the incoming int
  //for(int idx = 0; idx < (size_int - 1);  idx++)
  //{
  //  data[idx] = nullptr; //set each
  //}
}

void list::insert(const char *phrase) //adds c strings to the list
{
  char * temp = new char[strlen(phrase) + 1];
  strcpy(temp,phrase);
  if (data == nullptr)
  {
    size = 1;
    data = new char * [size];
    data[0] = temp;
  } else
  {
    char ** new_data = new char *[size + 1];
    for (int idx = 0; idx < size; idx++) new_data[idx] = data[idx];
    new_data[size++] = temp; //BUT DOESN'T THE LIST SIZE HAVE A MAXIMUM VALUES
    delete [] data; //data is 
    data = new_data;
  }

  //why don't we increment size immediately upon call?
  //int string_length = strlen(phrase); //know the size of a row
  //char ** temp = new char *[string_length + 1];       //make the array of envp values  +1 bigger
  //for(int idx = 0; idx < size; size++) temp[idx] = nullptr; //assign all values to null (so they're not junk)
  //for(int idx = 0; idx < size; idx++) temp[idx] = data[idx]; //write data -> temp
  //for(int idx = 0; idx < size; idx++) data[idx] = new char[string_length]; //make the strings bigger, which should empty everything //we could make it leave alone ones already good
  //for(int idx = 0; idx < size; idx++) data[idx] = temp[idx]; //put everything back into the improved array
  //if(data[0] != nullptr){
  //if((data[size][0] < 32) |(data[size][0] > 127)) //if there are no printable characters at point of insertion
  //{
  //for(int idx = 0; idx < (string_length - 1); idx++) data[size][idx] = phrase[idx]; //copy phrase into your new pointer
  //}
//}
//size++;
}

std::ostream & operator << (std::ostream &ugh, list &list_class)
{
  //std::cout << list_class.size << std::endl;
  //for(int idx = 0; idx < list_class.size; idx++) std::cout << list_class.data[idx];
  for(int idx = 0; idx < list_class.size; idx++)
  {
    ugh << list_class.data[idx] << std::endl;
  }
  return ugh;
}

list::~list()
{
  if (data != nullptr){
    for(int idx = 0; idx < size; idx++) delete data[idx];
    delete [] data;
  }
  size = 0;
  data = nullptr;
}

list::list(const list & val) //the copy function
{
  size = val.size; //size within the scope of this function has its own def?
  data = new char * [size]; //this one is mad
  for(int idx = 0; idx < size; idx++) data[idx] = val.data[idx];
}

list & list:: operator = (const list & ugh)
{
  if (this != &ugh)
  {
    if (data != nullptr)
    { //if data within the scope of this function
      for (int idx = 0; idx < size; idx++) delete data[idx]; //deleting the array doesn't delete values stored within!?
      delete [] data; //delete the array
    }
    size = ugh.size;
    data = new char *[size]; //ok, why does this get attributed to *this
    for (int idx = 0; idx < size; idx++) data[idx] = ugh.data[idx];

  }
  return *this;
}

void list::resize() { return; }
