/*// Interfacing with the Host Platform
// my_prg.cpp

#include <iostream>

int main(int argc, char* argv[])
{
    int i;

    std::cout << "Application: " << argv[0] << std::endl;
    for (i = 1; i < argc; i++)
        std::cout << "- " << argv[i] << std::endl;
}*/

/*/int main()
{
    return 0; // inserted by the C++ compiler if the return statement is missing 
}*/

/*// Compiler-Evaluated Expressions
// constexpr.cpp
#include <iostream>

constexpr int N = 8; // constant variable

constexpr int factorial(int i) // constant function
{
    return i > 1 ? i * factorial(i - 1) : 1;
}

int main()
{
    std::cout << N << "! = " << factorial(N) << std::endl;
}*/
/*
// Static Assertion
// static_assert.cpp
#include <iostream>

constexpr int N = 0;

constexpr int factorial(int i)
{
    return i > 1 ? i * factorial(i - 1) : 1;
}

int main()
{
    static_assert (N > 0, "N <=  0");
    static_assert (N < 20, "N >= 20");

    std::cout << N << "! = " << factorial(N) << std::endl;
}*/
/*
#include <iostream>

int main()
{
    int n0 = 7;   // C-style
    int n1 = 7.2; // C-style - narrowing (loss of information)
    int n2{ 6 };   // universal form braces-enclosed list
    int n3 = { 5 }; // = is redundant

    std::cout << "n0 = " << n0 << std::endl;
    std::cout << "n1 = " << n1 << std::endl;
    std::cout << "n2 = " << n2 << std::endl;
    std::cout << "n3 = " << n3 << std::endl;
}*/
/*
// Type Inference
// auto.cpp

#include <iostream>

int main()
{
    int a[]{7,8,9,5,2,3  };
    const auto n = 5;

    for (auto i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}*/
/*
// Alignment of a Type
// alignment.cpp

#include <iostream>

int main()
{
    std::cout << alignof() << std::endl;
    std::cout << alignof(double) << std::endl;
}*/
/*
// Type Alignment
// align.cpp

#include <iostream>

// A is allocated at 4-byte boundaries
struct A
{
    int n;  // size 4 alignment 4
    char c; // size 1 alignment 1
};        // size 8 alignment 4

// B is allocated at 16-byte boundaries
struct alignas(16) B
{
    int n;  // size 4 alignment 4
    char c; // size 1 alignment 1
};        // size 8 alignment 16

int main()
{
    A a[]{ 1, 'a', 2, 'b', 3, 'c' };
    std::cout << "align of A = "
        << alignof(A) << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << &a[i] << ": "
            << a[i].n << ", " << a[i].c << std::endl;
    }


    B b[]{ 1, 'a', 2, 'b', 3, 'c' };
    std::cout << "align of B = "
        << alignof(B) << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << &b[i] << ": "
            << b[i].n << ", " << b[i].c << std::endl;
    }
}*/
/*
// Generic Pointer Type
// void.cpp

#include <iostream>

int main()
{
    int i;
    void* v = &i;
    int* j;
    j = static_cast<int*>(v);  // OK - j now holds the address of i
    std::cout << &i << std::endl;
    std::cout << j << std::endl;
}*/
// Aggregate Initialization
// initializers.cpp
#include <iostream>

int main()
{
    const int n = 6;
    int  a[] = { 1,2,3 };
    int  b[]{ 1,2,3 };
    int  c[5]{ 1,2,3 };
    int  d[5]{};
    int* f = new int[n] { 1, 2, 3 };
    int* g = new int[n] {};

    for (int e : a) // range-based for (see below)
        std::cout << e;
    std::cout << '|' << std::endl;

    for (int e : b)
        std::cout << e;
    std::cout << '|' << std::endl;

    for (int e : c)
        std::cout << e;
    std::cout << '|' << std::endl;

    for (int e : d)
        std::cout << e;
    std::cout << '|' << std::endl;

    for (int i = 0; i < n; ++i) // cannot use range-based for with pointers
        std::cout << f[i];
    std::cout << '|' << std::endl;

    for (int i = 0; i < n; ++i)
        std::cout << g[i];
    std::cout << '|' << std::endl;

    delete[] f;
    delete[] g;
}