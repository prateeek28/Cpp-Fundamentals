/*
This program demonstrate Const_cast, when to use how to use whats the need.
NOTE:
1.the expression const cast can be used to change the const or volatile qualifiers of pointers or refrences
2. Where T must be a pointer, refrences, or pointer to member type.
*/

#include <iostream>
using namespace std;
//1. when the actual referred object/ variable is not const

int main()
{
const int a1 =10;
const int *b1 = &a1;
/*
removing the const of b1 pointer so that we can change the a1
but you must know that b1 contains the address of a1 and a1 is a const var can't be changed right?
and then we are trying to pass value in it through assigning d1 = 15 thats WRONG it will compile but wont run.
*/
int *d = const_cast <int*> (b1);
int *d1 = const_cast<int*> (b1);
//now we changing that variable and its UB.
*d1 =15; //Invalid and undefine behaviour
cout<<a1<<endl;
cout<<*d1<<endl;
/*
Here we are confused that this must show UB but complier checks a1 at compile time and it sees its 10 so it replace that at the place of a1
where as d1 must be there are the place of a1 but thats not possible at compile time it replaces that valuse as it is we have assigned
*/

//Lets write a valid code
int a2 =20;
const int *b2 = &a2;
int *d2 = const_cast<int*>(b2);
*d2 =30;
cout<<a2; 
// as i said this is Valid see the output shows that its 30.
return 0;
}
//Demo library u cant change any library this is just for demo.
void thirdPartyLibrary(int*x){
    int k =10;
    cout<< k+*(x);
}
int main(){
    const int x =20;
    //Here is a situation where u have to pass the value to an int pointer where it is not taking constant int value so u have to cast that pointer value and then u have to send it.
    //And if we try to do this without const_cast then it will show error u cannot convert from const *int to int its Invalid. ex thirdPartyLibrary((px));
    const int *px = &x;
    thirdPartyLibrary(const_cast<int*>(px));
}
/*
Summery Bottomline-
1.Never use this use only when you have to like 2nd example.
2.use only when the actual refered object/variable is not const_cast
3.use with 3rd party libraries and some API want data in NON - CONST form but we have it in const form.
*/





