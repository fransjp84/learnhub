#include <iostream>
#include <string.h>

class Base {
   public:
     virtual void Print(int x) = 0;
};

// Derived class
class Fibo: public Base {
  public:
    void Print(int x) {
      int prev = 0;
      int next = 1;
      int temp;
    
      std::cout << "Fibo number : " << std::endl;
      std::cout << prev << std::endl;
      std::cout << next << std::endl;
      for (int i=0; i<x-2; i++) {
          temp = prev + next;
          prev = next;
          next = temp;
          std::cout << next << std::endl;
       }   
    }
};

class Odd: public Base {
  public:
    void Print(int x) {
      int start = 1;
      std::cout << "Odd number : " << std::endl;
      for (int i=0; i<x; i++) {
          std::cout << start << std::endl;
          start += 2;
      }
    }
};

class Even: public Base {
  public:
    void Print(int x) {
      int start = 2;
      std::cout << "Even number : " << std::endl;
      for (int i=0; i<x; i++) {
          std::cout << start << std::endl;
          start += 2;
      }
    }
};

int main(int argc, char** argv) {
  if ( argc <= 2 ) {
    std::cout << "No arguments were passed.\n";
    return 0;
  }                 
   
   int num = atoi(argv[2]);
   Base *b;
   if (strcmp(argv[1], "Fibo") == 0) {
    b = new Fibo;
   } else if (strcmp(argv[1], "Odd") == 0) {
    b = new Odd;
   } else if (strcmp(argv[1], "Even") == 0) {
    b = new Even;
   }
   b->Print(num);
   delete b;

   return 0;
}

