#include <iostream>

using namespace std;

int main()
 {

   int A [5] {6,7,2,2,5};
   int *P=A;
   cout<<*P<<endl;
   P++;
   cout<<*P<<endl;
   P--;
    cout<<*P<<endl;
    return 0;
 }