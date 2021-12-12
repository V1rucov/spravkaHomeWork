#include <iostream>
#include <sstream>
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
    int sequence[roomCount*2];
    sequence[0] = 1;
    int index = 1;
    while(true){
        current = arr[current-1];
        if(current != 0) {
            sequence[index] = current;
            ++index;
        }
        else {
            sequence[index] = current;
            break;
        }
    }
    // зеркалим (если надо)...
    /*if(sizeof(sequence)>1){
        for(int i = sizeof(sequence)-1; i >=0; i--){
            //
        }
    }*/
    // вывод
    for(int i = 0; i < sizeof(sequence);++i){
        if(sequence[i] != 0) cout << sequence[i] << "\t";
    }

    return 0;
}
