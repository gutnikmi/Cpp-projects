#include <iostream>
#include<vector>

class SomeClass {
public:
    SomeClass(int a, std::vector<int> &vc) : a(a), vect(vc) {}

    void cfunc() const
    {
        //++a;//Cannot assign to non-static data member within const member function 'func'
        //vect[4] = a;//Cannot assign to return value because function 'operator[]' returns a const value
        //A[3] = 6;//Cannot assign to non-static data member within const member function 'cfunc'
    };
    void func()
    {
        ++a;
        vect[4] = a;
        A[3] = 6;
    }
private:
    int a;
    static const unsigned MAX_SIZE = 4;
    std::vector<int> vect;
    int A [MAX_SIZE] = {1,2,3,4};
};


int func(const int a) // 'a' won't be changed
{
    //a = a+1; - forbidden
    return a + 1; // legal (rvalue)
}

int main() {
    const int a = 10;
    //const int a; //- forbidden, must be initialized

    int b = 5;
    int *b_ptr = &b; // pointer

    const int *c_b_ptr = &b; // указатель на константу
    int *const p_const = &b; // константа типа «указатель»
    const int *const f_const = &b;// константа типа «указатель» на константу

    ++*b_ptr;// ok (6)

    //++*c_b_ptr; // forbidden Read-only variable is not assignable
    c_b_ptr = &a; // ok

    ++*p_const; // ok, can change value
    //++p_const;// forbidden pointer is a constant

    //++*f_const; // read-only variable is not assignable
    //++f_const; // cannot assign to variable 'f_const' with const-qualified type 'const int *const'


    //int* ptr = &a; //forbidden Cannot initialize a variable of type 'int *' with a rvalue of type 'const int *'
    const int *c_ptr = &a;//constant pointer
    c_ptr = &b;// ok

    constexpr double g = 9.8;// compile-time constant
    int age{};
    std::cin >> age;
    const int usersAge { age };//run-time constant

#define NOT_GONNA_USE = 1337; //bad practice ignores namespaces, bad for debugger
constexpr int useful_const = 1337;//good practice

    //std::cout << *b_ptr << std::endl;

}
