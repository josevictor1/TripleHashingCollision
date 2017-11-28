// string::shrink_to_fit
#include <iostream>
#include <string>
#include "md5.h"

using namespace std;

int main ()
{


  /*  
  std::string str (100,'x');
  std::cout << "1. capacity of str: " << str << '\n';

  str.resize(10);
  std::cout << "2. capacity of str: " << str << '\n';
*/

string string1 = "jose victor";
string string2 = "teste";

if("jose victor" == string2)
    cout << "Ok compara"<< endl;
else
    cout<< "realmente compara" << endl;

string result = md5("grape");
cout << result.size() <<endl;
  //str.shrink_to_fit();
  //std::cout << "3. capacity of str: " << str.capacity() << '\n';

  return 0;
}