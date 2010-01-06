// RUN: %clang_cc1 -triple x86_64-apple-darwin -fsyntax-only -pedantic -verify -Wsign-compare %s

int test(char *C) { // nothing here should warn.
  return C != ((void*)0);
  return C != (void*)0;
  return C != 0;  
  return C != 1;  // expected-warning {{comparison between pointer and integer ('char *' and 'int')}}
}

int ints(long a, unsigned long b) {
  enum EnumA {A};
  enum EnumB {B};
  enum EnumC {C = 0x10000};
  return
         // (a,b)
         (a == (unsigned long) b) +  // expected-warning {{comparison of integers of different signs}}
         (a == (unsigned int) b) +
         (a == (unsigned short) b) +
         (a == (unsigned char) b) +
         ((long) a == b) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a == b) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a == b) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a == b) +  // expected-warning {{comparison of integers of different signs}}
         ((long) a == (unsigned long) b) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a == (unsigned int) b) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a == (unsigned short) b) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a == (unsigned char) b) +  // expected-warning {{comparison of integers of different signs}}
         (a < (unsigned long) b) +  // expected-warning {{comparison of integers of different signs}}
         (a < (unsigned int) b) +
         (a < (unsigned short) b) +
         (a < (unsigned char) b) +
         ((long) a < b) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a < b) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a < b) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a < b) +  // expected-warning {{comparison of integers of different signs}}
         ((long) a < (unsigned long) b) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a < (unsigned int) b) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a < (unsigned short) b) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a < (unsigned char) b) +  // expected-warning {{comparison of integers of different signs}}

         // (A,b)
         (A == (unsigned long) b) +
         (A == (unsigned int) b) +
         (A == (unsigned short) b) +
         (A == (unsigned char) b) +
         ((long) A == b) +
         ((int) A == b) +
         ((short) A == b) +
         ((signed char) A == b) +
         ((long) A == (unsigned long) b) +
         ((int) A == (unsigned int) b) +
         ((short) A == (unsigned short) b) +
         ((signed char) A == (unsigned char) b) +
         (A < (unsigned long) b) +
         (A < (unsigned int) b) +
         (A < (unsigned short) b) +
         (A < (unsigned char) b) +
         ((long) A < b) +
         ((int) A < b) +
         ((short) A < b) +
         ((signed char) A < b) +
         ((long) A < (unsigned long) b) +
         ((int) A < (unsigned int) b) +
         ((short) A < (unsigned short) b) +
         ((signed char) A < (unsigned char) b) +

         // (a,B)
         (a == (unsigned long) B) +
         (a == (unsigned int) B) +
         (a == (unsigned short) B) +
         (a == (unsigned char) B) +
         ((long) a == B) +
         ((int) a == B) +
         ((short) a == B) +
         ((signed char) a == B) +
         ((long) a == (unsigned long) B) +
         ((int) a == (unsigned int) B) +
         ((short) a == (unsigned short) B) +
         ((signed char) a == (unsigned char) B) +
         (a < (unsigned long) B) +  // expected-warning {{comparison of integers of different signs}}
         (a < (unsigned int) B) +
         (a < (unsigned short) B) +
         (a < (unsigned char) B) +
         ((long) a < B) +
         ((int) a < B) +
         ((short) a < B) +
         ((signed char) a < B) +
         ((long) a < (unsigned long) B) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a < (unsigned int) B) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a < (unsigned short) B) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a < (unsigned char) B) +  // expected-warning {{comparison of integers of different signs}}

         // (C,b)
         (C == (unsigned long) b) +
         (C == (unsigned int) b) +
         (C == (unsigned short) b) +
         (C == (unsigned char) b) +
         ((long) C == b) +
         ((int) C == b) +
         ((short) C == b) +
         ((signed char) C == b) +
         ((long) C == (unsigned long) b) +
         ((int) C == (unsigned int) b) +
         ((short) C == (unsigned short) b) +
         ((signed char) C == (unsigned char) b) +
         (C < (unsigned long) b) +
         (C < (unsigned int) b) +
         (C < (unsigned short) b) +
         (C < (unsigned char) b) +
         ((long) C < b) +
         ((int) C < b) +
         ((short) C < b) +
         ((signed char) C < b) +
         ((long) C < (unsigned long) b) +
         ((int) C < (unsigned int) b) +
         ((short) C < (unsigned short) b) +
         ((signed char) C < (unsigned char) b) +

         // (a,C)
         (a == (unsigned long) C) +
         (a == (unsigned int) C) +
         (a == (unsigned short) C) +
         (a == (unsigned char) C) +
         ((long) a == C) +
         ((int) a == C) +
         ((short) a == C) +
         ((signed char) a == C) +
         ((long) a == (unsigned long) C) +
         ((int) a == (unsigned int) C) +
         ((short) a == (unsigned short) C) +
         ((signed char) a == (unsigned char) C) +
         (a < (unsigned long) C) +  // expected-warning {{comparison of integers of different signs}}
         (a < (unsigned int) C) +
         (a < (unsigned short) C) +
         (a < (unsigned char) C) +
         ((long) a < C) +
         ((int) a < C) +
         ((short) a < C) +
         ((signed char) a < C) +
         ((long) a < (unsigned long) C) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a < (unsigned int) C) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a < (unsigned short) C) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a < (unsigned char) C) +  // expected-warning {{comparison of integers of different signs}}

         // (0x80000,b)
         (0x80000 == (unsigned long) b) +
         (0x80000 == (unsigned int) b) +
         (0x80000 == (unsigned short) b) +
         (0x80000 == (unsigned char) b) +
         ((long) 0x80000 == b) +
         ((int) 0x80000 == b) +
         ((short) 0x80000 == b) +
         ((signed char) 0x80000 == b) +
         ((long) 0x80000 == (unsigned long) b) +
         ((int) 0x80000 == (unsigned int) b) +
         ((short) 0x80000 == (unsigned short) b) +
         ((signed char) 0x80000 == (unsigned char) b) +
         (0x80000 < (unsigned long) b) +
         (0x80000 < (unsigned int) b) +
         (0x80000 < (unsigned short) b) +
         (0x80000 < (unsigned char) b) +
         ((long) 0x80000 < b) +
         ((int) 0x80000 < b) +
         ((short) 0x80000 < b) +
         ((signed char) 0x80000 < b) +
         ((long) 0x80000 < (unsigned long) b) +
         ((int) 0x80000 < (unsigned int) b) +
         ((short) 0x80000 < (unsigned short) b) +
         ((signed char) 0x80000 < (unsigned char) b) +

         // (a,0x80000)
         (a == (unsigned long) 0x80000) +
         (a == (unsigned int) 0x80000) +
         (a == (unsigned short) 0x80000) +
         (a == (unsigned char) 0x80000) +
         ((long) a == 0x80000) +
         ((int) a == 0x80000) +
         ((short) a == 0x80000) +
         ((signed char) a == 0x80000) +
         ((long) a == (unsigned long) 0x80000) +
         ((int) a == (unsigned int) 0x80000) +
         ((short) a == (unsigned short) 0x80000) +
         ((signed char) a == (unsigned char) 0x80000) +
         (a < (unsigned long) 0x80000) +  // expected-warning {{comparison of integers of different signs}}
         (a < (unsigned int) 0x80000) +
         (a < (unsigned short) 0x80000) +
         (a < (unsigned char) 0x80000) +
         ((long) a < 0x80000) +
         ((int) a < 0x80000) +
         ((short) a < 0x80000) +
         ((signed char) a < 0x80000) +
         ((long) a < (unsigned long) 0x80000) +  // expected-warning {{comparison of integers of different signs}}
         ((int) a < (unsigned int) 0x80000) +  // expected-warning {{comparison of integers of different signs}}
         ((short) a < (unsigned short) 0x80000) +  // expected-warning {{comparison of integers of different signs}}
         ((signed char) a < (unsigned char) 0x80000) +  // expected-warning {{comparison of integers of different signs}}

         // We should be able to avoid warning about this.
         (b != (a < 4 ? 1 : 2)) +

         10
    ;
}

int equal(char *a, const char *b) {
    return a == b;
}

int arrays(char (*a)[5], char(*b)[10], char(*c)[5]) {
  int d = (a == c);
  return a == b; // expected-warning {{comparison of distinct pointer types}}
}

int pointers(int *a) {
  return a > 0; // expected-warning {{ordered comparison between pointer and zero ('int *' and 'int') is an extension}}
  return a > 42; // expected-warning {{ordered comparison between pointer and integer ('int *' and 'int')}}
  return a > (void *)0; // expected-warning {{comparison of distinct pointer types}}
}

int function_pointers(int (*a)(int), int (*b)(int), void (*c)(int)) {
  return a > b; // expected-warning {{ordered comparison of function pointers}}
  return function_pointers > function_pointers; // expected-warning {{ordered comparison of function pointers}}
  return a > c; // expected-warning {{comparison of distinct pointer types}}
  return a == (void *) 0;
  return a == (void *) 1; // expected-warning {{equality comparison between function pointer and void pointer}}
}

int void_pointers(void* foo) {
  return foo == (void*) 0;
  return foo == (void*) 1;
}

int test1(int i) {
  enum en { zero };
  return i > zero;
}

// PR5937
int test2(int i32) {
  struct foo {
    unsigned int u8 : 8;
    unsigned long long u31 : 31;
    unsigned long long u32 : 32;
    unsigned long long u63 : 63;
    unsigned long long u64 : 64;
  } *x;
  
  if (x->u8 == i32) { // comparison in int32, exact
    return 0;
  } else if (x->u31 == i32) { // comparison in int32, exact
    return 1;
  } else if (x->u32 == i32) { // expected-warning {{comparison of integers of different signs}}
    return 2;
  } else if (x->u63 == i32) { // comparison in uint64, exact because ==
    return 3;
  } else if (x->u64 == i32) { // expected-warning {{comparison of integers of different signs}}
    return 4;
  } else {
    return 5;
  }
}

// PR5887
void test3() {
  unsigned short x, y;
  unsigned int z;
  if ((x > y ? x : y) > z)
    (void) 0;
}
