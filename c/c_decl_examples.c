
// Example program
#include <iostream>
#include <string>
using namespace std;


int * f1() {
    int *a = new int;
    *a = 1;
    return a;
}
typedef int* foo ();

foo* f2() {
    return f1;
}
typedef foo* func ();

typedef int Array_tt [13];
Array_tt ga;
typedef Array_tt& array_ref_t;
array_ref_t f3() {
    for (int i = 0; i < sizeof(Array_tt)/sizeof(ga[0]); ++i) {
        ga[i] = i;
    }
    return ga;
}

typedef int (*foo_array[4])();
typedef foo* (*func_array[3])();

int* f4() {
    for (int i = 0; i < sizeof(Array_tt)/sizeof(ga[0]); ++i) {
        ga[i] = i;
    }
    return ga;
}

void print_array(int *arr, int len) {
        for (int i = 0;i < len; ++i) {
        static char separator = ' ';
        
        printf("%c%d", separator, arr[i]);
        separator = ',';
    }
    printf("\n");
}

void (*ptr_to_func)(int) typedef;

int main()
{
    array_ref_t my_ga3 = f3();
    print_array(my_ga3, sizeof(my_ga3)/sizeof(my_ga3[0]));
    int *my_ga4 = f4();
    print_array(my_ga4, sizeof(my_ga4)/sizeof(my_ga4[0]));
    return 0;
  func* my_f2 = f2;
  foo* my_f1 = f1;
  cout << sizeof(long double) <<endl;
  cout << sizeof(double) << endl;
  cout << sizeof(float) <<endl;
  cout << sizeof(unsigned long int)<<endl;
  cout << sizeof(long int)<<endl;
  cout << sizeof(unsigned int)<<endl;
  cout << sizeof(int)<<endl;
  cout << sizeof(unsigned short)<<endl;
  cout << sizeof(short)<<endl;
  cout << sizeof(unsigned char)<<endl;
  cout << sizeof(char)<<endl;
  
  switch(2) {
    //   int c = 3;
      case 2: 
        // printf("c=%d\n", c);
        printf("case2\n");
        break;
      default:
        break;
  }
  
  const char* lstr = "hello"
  "this is a really long string"
  "that has 3 lines";
  printf("%s\n", lstr);
  
  char cc = 10;
  char* p = &cc;
  unsigned int sz = sizeof((int) * p);
  printf("sz:%u\n", sz);
  unsigned int sz1 = sizeof(* p);
  printf("sz:%u\n", sz1);
  printf("%u\n", sizeof (int));
  
  
  
}