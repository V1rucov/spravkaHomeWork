#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    // объявляем переменные...
    int roomCount;
    string input;
    // пользователь вводит данные...
    cin >> roomCount;
    cin.ignore();
    getline(cin,input);
    // парсим строку с кабинетами в целочисленный массив...
    int arr[roomCount];
    int j = 0;
    stringstream ssin(input);
    while (ssin.good() && j <= roomCount){
        string temp;
        ssin >> temp;
        arr[j] = stoi(temp);
        ++j;
    }
    // поехали по алгоритму...
    int current = 1;
    int sequence[roomCount];
    sequence[0] = 1;
    int index = 1;
    while(true){
        current = arr[current-1];
        if(current != 0) {
            sequence[index] = current;
            ++index;
        }
        else {
            sequence[index] = -1;
            break;
        }
    }
    // вывод
    int i = 0;
    for(i = 0; i < sizeof(sequence)/sizeof(sequence[0]);++i){
        if(sequence[i] != -1) cout << sequence[i] << " ";
        else break;
    }
    --i;
    --i;
    if(sequence[1] != -1){
        for(; i >= 0; --i){
            if(sequence[i] != -1) cout << sequence[i] << " ";
        }
    }

    return 0;
}
