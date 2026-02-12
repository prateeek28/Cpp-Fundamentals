/*
* @file Static_cast
1. Following performs implicit conversion between two types 
*/

int main(){
  float f =3.5;
  int a;
  // normal way to cast at compile type silently without knowing.
  a=f; 
  // explicit way to cast knowing this can cause data loss 
  a = static_cast<int>(f); 
  return 0;


/*
Why to use styatic cast when implicit conversion is involved?
->Because C_style casting is hard to find in big projects thats 
why we do static cast which is easier to find.
*/


/*
EXAMPLE 2
2. Use static_cast when conversion between types is provided
 through conversion operator or conversion constructor.
 

 class Int {

 int x;

 public:
Int(int x=0):x{x} {}
 operator string () {
return to_string(x);
}
 };
 int main() {
 Int obj(3);
 string str1 = obj; // Implicit at compile time
 obj = 20;          // Implicit at compile time
 
//Explicit mst be written for better understanding in big projects 
 obj static_cast<Int>(30); 

string str2 = static_cast<string>(obj);
}
*/