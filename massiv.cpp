#include <iostream>

int main(){
    int* arr = new int[100];
    for (int i=0; i<100; i++){
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    delete [] arr;

    // int s = arr[0];

    // for (int i=0; i<100; i++){
    //     std::cout << arr[i] << " ";
    // }
    // delete [] arr;
}