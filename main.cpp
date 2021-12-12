#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
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
    vector<int> arr;
    int j = 0;
    stringstream ssin(input);
    while (ssin.good() && j <= roomCount){
        string temp;
        ssin >> temp;
        arr.push_back(stoi(temp));
        ++j;
    }
    // поехали по алгоритму...
    int current = 1;
    vector<int> sequence;
    sequence.push_back(1);
    while(true){
        current = arr[current-1];
        if(current != 0) {
            sequence.push_back(current);
        }
        else {
            sequence.push_back(-1);
            break;
        }
    }
    // вывод
    int i = 0;
    for(i = 0; i < sequence.size();++i){
        if(sequence[i] != -1) cout << sequence[i] << " ";
        else break;
    }
    i = i-2;
    if(sequence[1] != -1){
        for(; i >= 0; --i){
            if(sequence[i] != -1) cout << sequence[i] << " ";
        }
    }

    return 0;
}
