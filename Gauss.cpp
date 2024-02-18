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

    for (int i = 0; i < n; i++) // создание каждого одномерного массива в динамическом двумерном массиве, или иначе - создание столбцов размерность n
        arr[i] = new float[n];

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << "\t";
        cout << ("%d", column[i]);
        cout << endl;
    }
    cout << endl;

    
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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << "  ";
            }
        cout << "\t";
        cout << ("%d", column[i]);
        cout << endl;
        }
        cout << endl;

        cout << "press 1 if that's all, othetwise - 0 \n";
        cin >> d;

        if (d!=0){
            break;
        }
    }
 // ????? не продолжает работать
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (j==i){
                if (arr[i][j]!=0){
                    for (int k = 0; k < n; k++){
                        arr[i][k] /= arr[i][j];
                    }
                }
            }
        }
    }    

    for (int i=0; i < n; i++) // освобождение памяти каждого одномерного массива в двумерном массиве - удаление столбцов
        delete [] arr[i];
    delete [] arr; // освобождение памяти двумерного массива

    return 0;
}