#include "main.h"
using namespace std;

int main(int argc, char **argv, char **envp)
{
     // List Control
     list      my_list;

     // Create the list
     for (int idx = 0; envp[idx] != nullptr; idx++)
     {
          if (envp[idx][0] >= 'a' && envp[idx][0] <= 'z') my_list.insert(envp[idx]);
     }

     // Display the list
    cout << "List of Environment Variables That Start With Lower Case Character:\n" << my_list << endl;

     return 0;
}
