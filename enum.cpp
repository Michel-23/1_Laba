#include <iostream>

// пересисление 
enum BluetoothState {Connected, Disconnect, Connecting};

int main(){

    BluetoothState currentBluetoothState = BluetoothState::Connecting;
    switch (currentBluetoothState)
    {
        case BluetoothState::Connected:
            std::cout << "Device connected" << std::endl;
            break;
        case BluetoothState::Disconnect:
            std::cout << "Device disconnected" << std::endl;
        default: // любое другое состояние
            std::cout << "Undefined" << std::endl;
            break;
    }

    // bool isFlag = true // новый тип данных
}