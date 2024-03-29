#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printarr(float **arr, int n, float *column){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
    }
    cout << "\t";
    cout << column[i];
    cout << endl;
    }
    cout << endl;
}

void perest(float **arr, int i, int n){
    for(int h=i+1; h<n; h++){ // смотрим строчки ниже 
        if(arr[h][i] != 0){ // если нашелся ненулевой элемент
            for (int s=0; s<n; s++){ // цикл по столбцам (проверка их на 0)
            int temp = arr[i][s]; // тот самый столбцовый элемент
            arr[i][s] = arr[h][s]; // всем элементам i-й строки присваиваем значения h-й строки
            arr[h][s] = temp;
            }
            break;
        }
    }
}

void delen(float **arr, float *column, int i, int j, int n){
    float head_elem = arr[i][j];
    for (int k = j; k < n; k++){
        arr[i][k] = arr[i][k] / head_elem;
    }

    column[i] = column[i] / head_elem; // деление столбца b

    for (int t = i+1 /*вертикали треугольника = строки*/; t < n; t++){
        float minus = arr[t][i]; // переменная отвечающая за коэффициент умножения
        for (int c = i /*горизонтали треугольника = столбцы*/; c < n; c++){ // строка
            arr[t][c] = arr[t][c] - minus * arr[i][c];
        }

        column[t] = column[t] - minus * column[i]; // вычитание элементов столбца b
    }
}

int main() {

    int n=3; //***

    float ** arr = new float* [n]; // создание динамического двумерного массива на n строк
    float *column = new float[n]; // создание динамического одномерного массива длины n
    float *x = new float[n];

    for (int i = 0; i < n; i++) // создание каждого одномерного массива в динамическом двумерном массиве, или иначе - создание столбцов размерность n
        arr[i] = new float[n];
    
    int data[] = {0,0,1,1,0,0,0,1,0};
    int index = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j] = data[index++];
        }
    }

    int data1[] = {1,1,1};
    for (int i=0; i < n; i++){
        column[i] = data1[i];
    }

    //вывод чисел
    cout << "---------------------------------" << endl;
    printarr(arr, n, column);

    float ** raa = new float* [n]; // массив для запоминания исходной матрицы

    for (int i = 0; i < n; i++)
        raa[i] = new float[n];
    
    for (int i = 0; i < n; i++){
        for (int j=0; j < n; j++){
            raa[i][j] = arr[i][j];
        }
    }

    float *column1 = new float[n]; // массив для запоминания исходного столбца

    for (int i = 0; i < n; i++){
        column1[i] = column[i];
    }

    // цикл делит строку матрицы на элементы гравной диагонали
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (arr[i][i] == 0){
                perest(arr, i, n);
            }
            if (arr[i][j]!=0 && i==j){
                delen(arr, column, i, j, n);
                break;
            }
        }
    }

    // печать измененной матрицы
    cout << "---------------------------------" << endl;
    printarr(arr, n, column);

    // Обратный ход метода Гаусса
    for (int i = n-1; i >= 0; i--){
        x[i] = column[i];
        if (i!=n){
            for (int j = i+1; j < n; j++){
                x[i] = x[i] - x[j] * arr[i][j];
            }
        }
    }

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

    for (int i = 0; i < n; i++) {
        cout << "x" << i << " = " << x[i] << endl; //выводим решения
    }
    cout << endl;

    float *rarr = new float [n];

    for (int i = 0; i < n; i++) 
        rarr[i] = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            rarr[i] += raa[i][j] * x[j];
        }
        rarr[i] = column1[i] - rarr[i];
    }

    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    cout << "Pogreshnost" << endl;
    for (int i = 0; i < n; i++) {
        cout << rarr[i] << endl;
    }
    cout << endl;

    for (int i=0; i < n; i++) // освобождение памяти каждого одномерного массива в двумерном массиве - удаление столбцов
        delete [] arr[i];
    delete [] arr; // освобождение памяти двумерного массива
    delete [] column;
    delete [] x;

    return 0;
}