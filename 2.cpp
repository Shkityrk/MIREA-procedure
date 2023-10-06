//
// Created by konstantin on 26.09.2023.
//
#include <iostream>
#include <windows.h>
#include <cmath>
#include <algorithm>


using namespace std;

const double PI = 3.1415926535;
void Task2Prog1() {
    SetConsoleOutputCP(CP_UTF8);
    double h, R, r, l, V, S;
    cout << "Введите h ";
    cin >> h;
    cout << "Введите R ";
    cin >> R;
    cout << "Введите r ";
    cin >> r;


    if (h > 0 && R > 0 && r > 0 && l > 0 && l <= h) {
        l = sqrt(pow(R - r, 2) + pow(h, 2));
        V = (1.0/3.0) * M_PI * h * (pow(R, 2) + R * r + pow(r, 2));
        S = PI * (pow(R, 2) + (R + r) * l + pow(r, 2));

        // Вывод результатов
        cout << "V=" << V << endl;
        cout << "S=" << S << endl;
    } else {
        cout << "Усеченный конус с заданными параметрами не существует." << endl;
    }
}

void Task2Prog2() {
    double x,a,w;

    cout << "Input x:" ;
    cin >> x;

    cout << "Input a:";
    cin >> a;

    if (x == 0) {
        cout << "Ошибка! 1" << endl;
        return;
    }
    else if (abs(x) < 1)
    {
        w = a * log(abs(x));
        cout << w << endl;
        return;
    }
    else if (a - pow(x, 2) < 0) {
        cout << "Ошибка! 2" << endl;
        return;
    }

    w = sqrt(a - pow(x, 2));
    cout << w << endl;
}

double calculate_z(double x, double y, double b) {//вычисление результата
    if (x < 0 || b < 0) {// проверка области допустимых значений
        cout << "Ошибка!" << endl;
        return -1;
    }
    double result = log(b - y) * sqrt(b - x);
    return result;
}

void Task2Prog3() {
    double x, y, b;
    cout << "Введите значение x>";
    cin >> x;
    cout << "Введите значение y>";
    cin >> y;
    cout << "Введите значение b>";
    cin >> b;

    double z = calculate_z(x, y, b);
    if (z != -1) {
        cout << "z=" << z << endl;
    }
}

void Task2Prog4() {
    double n;
    cout << "Введите число:";
    cin >> n;
    if (n<1){
        cout<<"Ошибка!"<<endl;
    }
    else {
        n=ceil(n);
        for (int i = n; i <= n + 9; i++) {
            cout << i << endl;
        }
    }
}

double equation(double x) {//запись выражения

    return ((pow(x, 2) - 2 * x + 2) / (x - 1));

}

void Task2Prog5() {
    double r;
    for (double x = -4; x <= 4; x = x + 0.5) {
        if ((x - 1) != 0) {
            cout << x<<" "<<equation(x) << endl;
        }
        else {
            cout << x<<" "<<"Ошибка" << endl;
        }
    }

}


int main(){
    //setlocale(LC_ALL, "Rus"); // для Visual Studio
    //SetConsoleOutputCP(CP_UTF8); //в иных случаях

    Task2Prog1();
    Task2Prog2();
    Task2Prog3();
    Task2Prog4();
    Task2Prog5();
}