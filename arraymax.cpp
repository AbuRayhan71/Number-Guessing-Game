using namespace std;
#include <iostream>
int main()
{
    int A[9]={1,30,4,50,63,77,8,899};
    int n =9,max;
    max=A[0];
    for  (int i=0;i<n;i++)
    {
        if (A[i] > max){
       {
            max = A[i];}
       } 
     cout << "hello there fellow human , input a nymber ";
     cin >> n ;
     cout<< max; 
    }

    return 0;
}
