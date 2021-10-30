// standard exceptions
#include <iostream>
#include <exception>
using namespace std;
class myexception: public exception
{
 const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;
int main () {

  try
{
  int * myarray= new int[1000000000054545];
}
catch (bad_alloc&)
{
cout << "Error allocating memory." << endl; 
}

  try
{
throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << endl;
  }
return 0; }