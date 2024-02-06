// ********************************************************************************************
// Author: Ramazan Cem Citak
// Topic: EE441 Programming Assignment 1 - PART 2
// Submission Date: November 6, 2022, Sunday
// Question 1,2 and 3 codes with benchmark code are in this main.cpp file.

#include <iostream>
#include <chrono>
#include <cstring>
using namespace std;

// ********************************************************************************************
// Question 1: Tower of Hanoi
// Disc class for the different diameters of the discs
template <int N>
class Disc{
private:
    int diameter[N]; // Integer array for the varying diameters
public:
    Disc(int n); // The constructor definition with number of discs
};

// Question 1 - b)
// Class Hanoi for the game with three rods
class Hanoi{
private:
    int rod_0[20];
    int rod_1[20];
    int rod_2[20];
public:
    Hanoi(int n);  // Constructor definition
    void move(int from, int to); // Function for moving a disc from one rod to another
};

// Question 1 - a)
// Constructor for Hanoi class
template <int N>
Disc<N>::Disc(int n){

    int j=1; // The smallest diameter 1
    if (n == 0){
        diameter[0] = 0;
    }
    else {
        for (int i=0; i<n; i++){
            diameter[i] = j; // Diameters are 1,2,3 ... according to the number of discs
            j++;
        }
    }
}

// Question 1 - c)
// Constructor for class Hanoi
Hanoi::Hanoi(int const n){

    for (int i=0; i<n; i++){ // Loop for adjusting the initial diameters of the discs in rod 1

    }
}

// Question 1 - d)
//Function for moving a disc from one rod to another
void Hanoi::move(int from, int to){
    int n;
    if (from == 0 || from == 1 ||from == 2 || to == 0 || to == 1 ||to == 2){

        if (n == 0) {
        return;
            }

        cout << "Disc " << n << " is moved from " << from << " to rod " << to << endl;

        cout << "Move disk " << n << " is moved from " << from << " to rod " << to << endl;
    }
    else {
        cout << "Entered indices are not valid." << '\n';
    }
}

// Question 1 - e)
// I could not complete the recursive function
void solve_hanoi(Hanoi& game){
    int n;
    // solve_hanoi(n - 1,n);
    // solve_hanoi(n, n-1);
}

// ********************************************************************************************
// Question 2:
// Helper function for question 2
void print_backwards_helper(const char * string, int length)
{
    if(length <= 0) // If the NULL character is reached, end the recursive operation.
        return;

    cout << string[length - 1]; // Recursively print the characters in a reverse order
    print_backwards_helper(string, length - 1);
}

void print_backwards(char const * string){
    size_t length = strlen(string);// Finding the size of the string except the NULL character
    int len = length;

    print_backwards_helper(string,len); // Call the recursive helper function
}

// ********************************************************************************************
// Question 3:
// I could not find the algorithm for finding the nth prime number
int nth_prime(int n){
    int i;

}

// ********************************************************************************************
// Given Benchmark Code:
void benchmark(void (*func)(int))
{
    int const AMOUNT = 20;
    int const REPEAT = 10;
    double results[AMOUNT];
    for (int i = 0 ; i < AMOUNT ; ++i) {
        auto start = std::chrono::steady_clock::now();
        for (int j = 0 ; j < REPEAT ; ++j) {
            func(i+1);
        }
        auto finish = std::chrono::steady_clock::now();
        results[i] = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count() / REPEAT;
    }

    std::cout << std::endl << std::endl;
    std::cout << "n\ttime (ns)\n";
    for (int i = 0 ; i < AMOUNT ; ++i) {
        std::cout << i+1 << '\t' << results[i] << '\n';
    }
    std::cout << std::endl;
}

void wrapper_solve_hanoi(int n)
{
    auto game = Hanoi(n);
    solve_hanoi(game);
}

void wrapper_print_backwards(int n)
{
    char * str = new char[n+1];
    for (int i = 0 ; i < n ; ++i) {
        str[i] = 'a' + i;
    }
    str[n] = '\0';

    print_backwards(str);

    delete[] str;
}

void wrapper_nth_prime(int n)
{
    volatile int temp = nth_prime(n);
}

// This main file is used for benchmarking the question 1, 2 and 3
// of the PART 2 in EE441 Programming Assignment
int main()
{
    //benchmark(wrapper_solve_hanoi);
    benchmark(wrapper_print_backwards);
    //benchmark(wrapper_nth_prime);
    return 0;
}


