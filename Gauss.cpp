#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int n;
    float a=0, b=0, c=0, d=0, e=0,g=0;

    // если рандомный размер
    //n = 1 + (rand() % 10); // генерация размера количества столбцов от 1 до 10

    // если размер вводится пользователем
    cout << "enter the size of the matrix ";
    cin >> n;

    float ** arr = new float* [n]; // создание динамического двумерного массива на n строк
    float *column = new float[n]; // создание динамического одномерного массива длины n
    float x[n];

    for (int i = 0; i < n; i++) // создание каждого одномерного массива в динамическом двумерном массиве, или иначе - создание столбцов размерность n
        arr[i] = new float[n];
    
    int data[] = {3,-9,3,2,-4,4,1,8,-18};
    int index = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j] = data[index++];
        }
    }

    int data1[] = {-18,-10,35};
    for (int i=0; i < n; i++){
        column[i] = data1[i];
    }


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // // заполнение единичной матрицы
    // for (int i=0; i < n; i++){
    //     for (int j=0; j < n; j++){
    //         if (i==j)
    //         arr[i][j] = 1;
    //         else
    //         arr[i][j] = 0;
    //     }
    // }


    // // заполнение столбца
    // for (int k=0; k < n; k++){
    //     column[k] = 1;
    // }
    //!!!!!!!!!!!!!!!!!!!!!!!!!


    //вывод чисел
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\t";
        cout << ("%d", column[i]);
        cout << endl;
    }
    cout << endl;

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // while(d==0){
    // cout << "row number of the matrix ";
    // cin >> a;
    // cout << "coloumn number of the matrix ";
    // cin >> b;
    // cout << "coefficient ";
    // cin >> c;
    // cout << "row number of the column ";
    // cin >> e;
    // cout << "coefficient ";
    // cin >> g;

    // arr[static_cast<int>(a)][static_cast<int>(b)] = c;
    // column[static_cast<int>(e)] = g;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\t";
    //     cout << ("%d", column[i]);
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "press 1 if that's all, othetwise - 0 \n";
    // cin >> d;

    // if (d!=0){
    //         break;
    //     }
    // }

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    cout << "---------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
    }
    cout << "\t";
    cout << ("%d", column[i]);
    cout << endl;
    }
    cout << endl;

    // цикл делит строку матрицы на элементы гравной диагонали
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (arr[i][j]!=0 && i==j){
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

                break;
            }
        }
    }

    // печать измененной матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\t";
        cout << ("%d", column[i]);
        cout << endl;
    }
    cout << endl;

    cout << "---------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\t";
        cout << ("%d", column[i]);
        cout << endl;
    }
    cout << endl;

    for (int i=0; i < n; i++) // освобождение памяти каждого одномерного массива в двумерном массиве - удаление столбцов
    delete [] arr[i];
    delete [] arr; // освобождение памяти двумерного массива


// Обратный ход метода Гаусса
    for (int i = n-1; i >= 0; i--){
        x[i] = arr[i][n]; // берем свободный член
        for (int j = i+1; j < n; j++){
            x[i] = x[i] - x[j] * arr[i][j]; // вычитаем уже найденные значения x 
        }
        x[i] = x[i] / arr[i][i]; // делим на коэффициент при x[i]
    }

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

    for (int i = 0; i < n; i++) {
        cout << "x" << i << " = " << x[i] << endl; //выводим решения
    }
    cout << endl;

    return 0;
}