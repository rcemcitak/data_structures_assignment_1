// ********************************************************************************************
// Author: Ramazan Cem Citak
// Topic: EE441 Programming Assignment 1 - PART 1
// Submission Date: November 6, 2022, Sunday

#include <iostream>
#include <math.h>

using namespace std;

// Adding the template given in the assignment
// The Matrix class
template <int N>
class Matrix
{
private:
    double data[N][N];
public:
    Matrix(void);
    int const SIZE = N;
    void Display(void) const;
    double Getter(int i, int j) const; // Getter function which takes the index values
    void Setter(double value, int i, int j); // Setter function which takes the value that is set and index values

};

// Constructor for the class Matrix
// Initially, a matrix is an identity matrix
template<int N>
Matrix<N>::Matrix(void){
    int i,j;
    for (i=0; i<N; ++i){
        for (j=0; j<N; ++j){
            if (i==j){
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
}

// Display function for a matrix
template<int N>
void Matrix<N>::Display(void) const{
    int i,j;
    for (i=0; i<N; ++i){
        for (j=0; j<N; ++j){
            cout << data[i][j] << "\t";
            }
        cout<<"\n";
    }
    cout<<"\n";
}

// Getter function
template<int N>
double Matrix<N>::Getter(int i, int j) const{
    if ((i >= 0 && i<N)&&(j >= 0 && j<N))
        return data[i][j];
    else
        cout << "The indices entered are not valid." << endl;
}

// Setter function
template<int N>
void Matrix<N>::Setter(double value, int i, int j){
    if ((i >= 0 && i<N)&&(j >= 0 && j<N))
        data[i][j] = value;
    else
        cout << "The indices entered are not valid." << endl;

}

// Matrix addition operation function
template<int N>
Matrix<N> Addition(Matrix<N> A, Matrix<N> B){ // Using pass by value
    Matrix<N> resultMatrix;
    int i,j;
    double a,b,result;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            a = A.Getter(i,j);
            b = B.Getter(i,j);
            result = a + b;
            resultMatrix.Setter(result,i,j);
        }
    }
    return resultMatrix;
}

// Matrix subtraction operation function
template<int N>
Matrix<N> Subtraction(Matrix<N> A, Matrix<N> B){ // Using pass by value
    Matrix<N> resultMatrix;
    int i,j;
    double a,b,result;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            a = A.Getter(i,j);
            b = B.Getter(i,j);
            result = a - b;
            resultMatrix.Setter(result,i,j);
        }
    }
    return resultMatrix;
}

// Matrix multiplication operation function
template<int N>
Matrix<N> Multiplication(Matrix<N> A, Matrix<N> B){
    Matrix<N> resultMatrix;
    int i,j,k;
    double value,aik,bkj;

    for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j){
                value = 0;
                for(k = 0; k < N; ++k)
                {
                    aik = A.Getter(i,k);
                    bkj = B.Getter(k,j);
                    value+=aik*bkj;
                }
                resultMatrix.Setter(value,i,j);
            }
    }
    return resultMatrix;
}

// Determinant function
// I could not implement a determinant function
template<int N>
double Determinant(Matrix<N> A){

}

int main(){

    // Defining 4 different matrices
    Matrix<2> myMatrix1;
    Matrix<2> myMatrix2;
    Matrix<2> myMatrix3;
    Matrix<3> myMatrix4;

    // Setting 9 values of a 3x3 matrix
    myMatrix4.Setter(5,0,0);
    myMatrix4.Setter(7,0,1);
    myMatrix4.Setter(3,0,2);
    myMatrix4.Setter(12,1,0);
    myMatrix4.Setter(1.5,1,1);
    myMatrix4.Setter(0,1,2);
    myMatrix4.Setter(4,2,0);
    myMatrix4.Setter(8,2,1);
    myMatrix4.Setter(6,2,2);

    // Setting 4 values of a 2*2 matrix
    myMatrix1.Setter(5,0,0);
    myMatrix1.Setter(7,0,1);
    myMatrix1.Setter(12,1,0);
    myMatrix1.Setter(1.5,1,1);

    // Setting 4 values of a 2x2 matrix
    myMatrix2.Setter(2,0,0);
    myMatrix2.Setter(2.5,0,1);
    myMatrix2.Setter(4,1,0);
    myMatrix2.Setter(8,1,1);

    // Displaying 4 different matrices
    cout << "Matrix 1" << endl;
    myMatrix1.Display();
    cout << "Matrix 2" << endl;
    myMatrix2.Display();
    cout << "Matrix 3" << endl; // To see a 3x3 matrix
    myMatrix3.Display();
    cout << "Matrix 4" << endl;
    myMatrix4.Display();

    // Addition of Matrix 1 and Matrix 2
    cout << "Addition of Matrix 1 and 2" << endl;
    (Addition(myMatrix1,myMatrix2)).Display();

    // Subtraction of Matrix 1 and Matrix 2
    cout << "Subtraction of Matrix 1 and 2" << endl;
    (Subtraction(myMatrix1,myMatrix2)).Display();


    // Multiplication of Matrix 1 and Matrix 2
    cout << "Multiplication of Matrix 1 and 2" << endl;
    (Multiplication(myMatrix1,myMatrix2)).Display();

    return 0;
}
// End of the code
// ********************************************************************************************
