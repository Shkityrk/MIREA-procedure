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
    if (S<=0 or n==0){// проверка условий на выполнимость(сумма не может быть отрицательной, так же как и временной период)
        cout<<"Ошибка!"<<endl;
    }
    else if(p==0){//процент равено 0
        m = S / (12 * n);
    }
    else{
        r = p / 100;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
    }
    if (12 * (pow(1 + r, n) - 1) < 0) {// знаменатель не может быть меньше нуля, в таком случае дробь будет отрицательной, а значит и месячная выплата(противоречие). Числитель же быть отрицательным не может, т.к там нет отрицательных чисел при правильно введеных числах
        cout << "Ошибка!"<<endl;
    }
    if(m!=0){//если есть ответ
        cout << "m = " << m << endl;}

}

void Task3Prog2(){
    double S, n, mTest,m,r;
    double rTemperature = 0.0001;

    cout << "Введите S";// начальная ссуда S рублей
    cin >> S;
    cout << "Введите n";// кол-во лет
    cin >> n;
    cout << "Введите m";// месячная выплата
    cin >> mTest;

    if (n == 0 or S <= 0) { // на 0 делить нельзя!
        cout << "Ошибка"<<endl;
    }
    while (m < mTest) {// процент, если выплаты больше заданной, т.е ссуда выплачена
        r = rTemperature;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));// подсчёт m с процентами
        rTemperature = rTemperature + 0.0001;
    }
    cout << "p = " << r * 100 << "%" << endl;
}

int Task3Prog3(){
    ofstream outputFile("output.txt");// попытка открытия файла
    if (!outputFile) {// проверка при открытии файла
        cerr << "Ошибка!" << endl;
        return 1;
    }
    string list;
    cin>>list;//ввод строчки, которую нужно записать в файл
    outputFile << list << endl;// запись в файл
    outputFile.close();// закрытие файла

    ifstream inputFile("output.txt");// попытка открытия и чтения файла
    if (!inputFile) {//проверка на наличие фалйа
        cerr << "Ошибка!" << endl;
        return 1;
    }
    string line;
    cout << "Содержимое файла:" << endl;
    while (getline(inputFile, line)) {//запись в строку line всех элементов из файла
        cout << line << endl; // вывод строки
    }
    inputFile.close();// закрытие файла
}

int Task3Prog4(){
    ifstream inputFile("output.txt");// попытка открытия и чтения файла
    if (!inputFile) {//обработка ошибки открытия
        cerr << "Не удалось открыть файл для чтения." << endl;
        return 1; //
    }
    char character;//символ
    string number;
    cout << "Числа из файла:" << endl;
    while (inputFile.get(character)) {// посимвольное чтение файла
        if (isdigit(character)) {// является ли символ цифрой?
            number += character; // если да, заносим этот символ в строку
        } else if (!number.empty()) {//выводим символы, определенные как цифры, тем самым получая строчку из цифр в файле
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
    cin>>inputString;// ввод строки
    sort(inputString.begin(), inputString.end());//посимвольная сортировка строки, в прямом порядке, стандартной функцией C++
    cout << "Отсортированная строка: " << inputString << endl;// вывод строки
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