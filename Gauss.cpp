#include <iostream>
#include <cstdlib>
#include <ctime>
#include "math.h"
using namespace std;

// функция печати матрицы
void printarr(double **arr, int n, double *column){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
    }
    cout << " ";
    cout << "|" << column[i];
    cout << endl;
    }
    cout << endl;
}

// функция перестановки строчек
void perest(double **arr, int i, int n){
    for(int h=i+1; h<n; h++){ // смотрим строчки ниже 
        if(arr[h][i] != 0){ // если нашелся ненулевой элемент
            for (int s=0; s<n; s++){ // цикл по столбцам (проверка их на 0)
                int temp = arr[i][s]; // кладем в temp элементы строки, где на главной диагонали обнаружили 0
                arr[i][s] = arr[h][s]; // всем элементам i-й (где 0) строки присваиваем значения h-й строки
                arr[h][s] = temp; // поэлементно присваиваем элементам h-й строки элементы i-й
            }
            break;
        }
    }
}

//функция делния строчки на элемент главной диагонали
void delen(double **arr, double *column, int i, int j, int n){
    double head_elem = arr[i][j]; // это главный элемент
    for (int k = j; k < n; k++){
        arr[i][k] = arr[i][k] / head_elem; // идем по строке с главным элементом и делим ее на него
    }

    column[i] = column[i] / head_elem; // деление столбца b

    for (int t = i+1 /*строки*/; t < n; t++){
        double minus = arr[t][i]; // переменная отвечающая за коэффициент умножения - это элементы под главным элементом
        for (int c = i /*столбцы*/; c < n; c++){
            arr[t][c] = arr[t][c] - minus * arr[i][c]; //4-4*1
        }

        column[t] = column[t] - minus * column[i]; // вычитание элементов столбца b
    }
}

double opred(double **arr, int n, double op){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (n==2){
                op = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
            }
            if (n==3){
                op = arr[0][0]*arr[1][1]*arr[2][2] + arr[0][1]*arr[1][2]*arr[2][0] + arr[0][2]*arr[1][0]*arr[2][1] - arr[0][2]*arr[1][1]*arr[2][0] - arr[0][0]*arr[1][2]*arr[2][1] - arr[0][1]*arr[1][0]*arr[2][2];
            }
        }
    }
    return op;
}

int main() {
    srand((time(NULL)));

    int n, m;
    double op;
    double a=0, b=0, c=0, d=0, e=0,g=0;

    double ** arr = new double* [n]; // создание динамического двумерного массива на n строк
    double *column = new double[n]; // создание динамического одномерного массива длины n
    double *x = new double[n];
    
    cout << "1 = random, 0 = sam" << endl;
    cin >> m;

    if (m == 1){ // если рандом
        n = 2 + (rand() % 2); // генерация размера количества столбцов от 2 до 3

        for (int i = 0; i < n; i++){
            arr[i] = new double[n]; // выделение памяти для каждой строки двумерного массива / создание одномерных массивов для каждой строки массива arr
            for (int j = 0; j < n; j++){
                arr[i][j] =(static_cast<double>(rand()) / static_cast<double>(RAND_MAX / 100)); // заполнение массива случайными числами от 0 до 100
            }
        }

        for (int i = 0; i < n; i++){
            column[i] = (static_cast<double>(rand()) / static_cast<double>(RAND_MAX / 100));
        }
    }

    if (m == 0){ // если сам
        cout << "enter the size of the matrix ";
        cin >> n;

        for (int i = 0; i < n; i++) // создание каждого одномерного массива в динамическом двумерном массиве, или иначе - создание столбцов размерность n
            arr[i] = new double[n];
        
        // заполнение единичной матрицы
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
            if (i==j)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
            }
        }

        // заполнение столбца
        for (int k=0; k < n; k++){
            column[k] = 1;
        }

        //вывод чисел
        printarr(arr, n, column);

        while(d==0){
            cout << "row number of the matrix ";
            cin >> a;
            cout << "coloumn number of the matrix ";
            cin >> b;
            cout << "coefficient ";
            cin >> c;
            cout << "row number of the column ";
            cin >> e;
            cout << "coefficient ";
            cin >> g;

            arr[static_cast<int>(a)][static_cast<int>(b)] = c;
            column[static_cast<int>(e)] = g;

            printarr(arr, n, column);

            cout << "press 1 if that's all, othetwise - 0 \n";
            cin >> d;

            if (d!=0){
                break;
            }
        }
    }

    if (m!=0 && m!=1){
        cout << "error" << endl;
        return 0;
    }

    // вывод чисел
    cout << "---------------------------------" << endl;
    printarr(arr, n, column);

    opred(arr, n, op);
    cout << "the determinant is equal to  " << opred(arr, n, op) << endl;
    
    double opr = opred(arr, n, op);
    if (opr == 0){
        cout << "it is impossible to apply the Gaussian method" << endl;
        return 0;
    }

    double ** raa = new double* [n]; // массив для запоминания исходной матрицы

    for (int i = 0; i < n; i++)
        raa[i] = new double[n];
    
    for (int i = 0; i < n; i++){
        for (int j=0; j < n; j++){
            raa[i][j] = arr[i][j]; // присвоение элементов
        }
    }

    double *column1 = new double[n]; // массив для запоминания исходного столбца

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
        cout << "x" << i << " = " << x[i] << endl; //выводим решения !!!
    }
    cout << endl;

    double *rarr = new double [n]; // для матрицы погрешностей

    for (int i = 0; i < n; i++)
        rarr[i] = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            rarr[i] += raa[i][j] * x[j]; //!!!
        }
        rarr[i] = column1[i] - rarr[i];
    }

    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    cout << "Pogreshnost" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i << " -> " << fabs(rarr[i]) << endl; //!!!
    }
    cout << endl;

    for (int i=0; i < n; i++) // освобождение памяти каждого одномерного массива в двумерном массиве - удаление столбцов
        delete [] arr[i];
    delete [] arr; // освобождение памяти двумерного массива
    delete [] column;
    delete [] x;

    return 0;
}