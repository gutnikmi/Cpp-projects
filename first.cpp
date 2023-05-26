#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
using namespace std;

int random_comparator(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,6000);
    int a = dist(gen);
    if (a >= 5000)
    {
        cout << a << " is more then 5000";
    }
    else if (a >= 1000)
    {
        cout << a << " is more then 1000";
    }
    else
    {
        cout << "idk";
    }
    cout << "\na = " << a;
}

int rand_n (int min, int max){ //input: 2 integers, output: 1 random integer, bigger than the first and smaller then the second
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main(){
int a;
}