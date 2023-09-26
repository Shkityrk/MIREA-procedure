//
// Created by konstantin on 26.09.2023.
//
#include <iostream>
#include <windows.h>
#include <cmath>
#include <algorithm>
#include <fstream>


using namespace std;
void Task3Prog1(){
    double S, n,p,m,r;
    cout<<"Введите p>";
    cin>>p;
    cout<<"Введите n>";
    cin>>n;
    cout<<"Введите S>";
    cin>>S;
    if (S<=0 or n==0){
        cout<<"Ошибка!"<<endl;
    }
    else if(p==0){
        m = S / (12 * n);
    }
    else{
        r = p / 100;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
    }
    if (12 * (pow(1 + r, n) - 1) < 0) {
        cout << "Ошибка!"<<endl;
    }
    if(m!=0){
        cout << "m = " << m << endl;}

}

void Task3Prog2(){
    double S, n, mTest,m,r;
    double rTemperature = 0.0001;

    cout << "Введите S";
    cin >> S;
    cout << "Введите n";
    cin >> n;
    cout << "Введите m";
    cin >> mTest;

    if (n == 0 or S <= 0) { // на 0 делить нельзя!
        cout << "Ошибка"<<endl;
    }
    while (m < mTest) {
        r = rTemperature;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
        rTemperature = rTemperature + 0.0001;
    }
    cout << "p = " << r * 100 << "%" << endl;
}

int Task3Prog3(){
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Ошибка!" << endl;
        return 1;
    }
    string list;
    cin>>list;
    outputFile << list << endl;
    outputFile.close();

    ifstream inputFile("output.txt");
    if (!inputFile) {
        cerr << "Ошибка!" << endl;
        return 1;
    }
    string line;
    cout << "Содержимое файла:" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();
}

int Task3Prog4(){
    ifstream inputFile("output.txt");
    if (!inputFile) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return 1; //
    }
    char character;
    string number;
    cout << "Числа из файла:" << endl;
    while (inputFile.get(character)) {
        if (isdigit(character)) {
            number += character;
        } else if (!number.empty()) {
            cout << number << endl;
            number = "";
        }
    }

    if (!number.empty()) {
        cout << number << endl;
    }
    inputFile.close();
}

int Task3Prog5(){
    string inputString;
    cin>>inputString;
    sort(inputString.begin(), inputString.end());
    cout << "Отсортированная строка: " << inputString << endl;
}

int main(){
    //setlocale(LC_ALL, "Rus"); // для Visual Studio
    //SetConsoleOutputCP(CP_UTF8); //в иных случаях

    Task3Prog1();
    Task3Prog2();
    Task3Prog3();
    Task3Prog4();
    Task3Prog5();
}