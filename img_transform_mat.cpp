// Problem Statement

// Priya is building a system to automate image transformations using matrix operations. To do this,
// she needs to multiply two matrices representing pixel data and transformation rules.

// Help Priya perform matrix multiplication and print the resulting matrix if the operation is valid.
// Input format:

// The first line of input consists of two int values, representing the number of rows R1 and columns C1 of the first matrix.
// The next R1 × C1 integers represent the elements of the first matrix.
// The next line consists of two int values, representing the number of rows R2 and columns C2 of the second matrix.
// The next R2 × C2 integers represent the elements of the second matrix.
// Output format:

// If matrix multiplication is possible, print R1 lines, each containing C2 space-separated int values 
// representing the resulting matrix.
// Otherwise, print "Matrix multiplication not possible".




#include <iostream>
#include <vector>

using namespace std;

int main(){
    int R1 , C1 ;
    cin>> R1 >>C1 ;

    cout<<"mat1 init.."<<endl ;
    vector<vector<int>> mat1(R1 , vector<int>(C1)) ;
    for(int i = 0 ; i<R1 ; i++){
        for(int j = 0 ; j<C1 ; j++){
            cin>>mat1[i][j] ;
        }
    }
    cout<<"mat1 done"<<endl ;

    int R2 , C2 ;
    cin>> R2 >>C2 ;

    cout<<"mat2 init.."<<endl ;
    vector<vector<int>> mat2(R2 , vector<int>(C2)) ;
    for(int i = 0 ; i<R2 ; i++){
        for(int j = 0 ; j<C2 ; j++){
            cin>>mat2[i][j] ;
        }
    }
    cout<<"mat2 done"<<endl ;

    if(C1 != R2) {
        cout<< "Matrix multiplication not possible"<<endl ;
        return 0 ;
    }

    //init the reslutlant matrix
    vector<vector<int>> res(R1 , vector<int>(C2)) ; //[R1 X C2]

    for(int i = 0 ; i<R1 ; i++){
        for(int j = 0 ; j<C2 ; j++){
            for (int k = 0; k < C1; k++) { // Slide across Row i and Column j
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for(int i = 0 ; i < R1 ; i++){
        for(int j = 0 ; j < C2 ; j++) {
            cout<<res[i][j] ;
            if( j < C2 - 1){
                cout << " " ;
            }
        }
        cout<<"\n" ;
    }



    return 0 ;
}