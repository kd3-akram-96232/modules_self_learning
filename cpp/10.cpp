#include<iostream>
#include <vector>
using namespace std;

class Matrix{
    int size;
    vector<vector<int>> matrix;

    public:
        Matrix(int size){
            this->size = size;
            matrix.resize(size, vector<int>(size));
        }

        void accept(){
            for (int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    int temp;
                    cout << "Enter: " << i << "," << j << ": ";
                    cin >> temp;
                    matrix[i][j] = temp;
                }
            }
        }
        
        Matrix operator+(const Matrix &other){    
            Matrix third(size);
            for(int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    int first = this->matrix[i][j];
                    int second = other.matrix[i][j];
                    third.matrix[i][j] = first + second;
                }
            }

            return third;
        }

        Matrix operator-(const Matrix &other){    
             Matrix third(size);
            for(int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    int first = this->matrix[i][j];
                    int second = other.matrix[i][j];
                    third.matrix[i][j] = first - second;
                }
            }

            return third;
        }


        Matrix operator*(const Matrix &other){    
             Matrix third(size);
            for(int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    third.matrix[i][j] = 0;
                    for(int k = 0; k < size; k++){
                        third.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
                    }
                }
            }

            return third;
        }

        void printMatrix(){

            for(int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

        }


};  


int main(){

    int matrixSize = 2;
    cout << "Enter size: ";
    cin >> matrixSize;
    
    Matrix mt1(matrixSize);
    // int mtx1rows[matrixSize] = { 5, 10 };
    // int mtx1cols[matrixSize] = { 20, 30 };
    // mt1.setRows( mtx1rows );
    // mt1.setCols( mtx1cols );

    mt1.accept();

    mt1.printMatrix();

    // mt1.printMatrix();
    
    Matrix mt2(matrixSize);
    mt2.accept();
    mt2.printMatrix();
    // int mtx2rows[matrixSize] = { 50, 100 }; 
    // int mtx2cols[matrixSize] = { 200, 300 }; 
    // mt2.setRows( mtx2rows );
    // mt2.setCols( mtx2cols );

    cout << "result" <<  endl;

    Matrix mt3 = mt1 * mt2;
    mt3.printMatrix();
    // Matrix mt4 = mt1 - mt2;
    // mt3.printMatrix();

    return 0;
}