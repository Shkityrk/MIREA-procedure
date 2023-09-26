//
// Created by konstantin on 26.09.2023.
//
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int Task4Prog1(){
    ofstream outputFile("example2.txt");
    if (!outputFile) {
        cerr << "Ошибка!" << endl;
        return 1;
    }
    for (int i = 1; i <= 10; i++) {
        double num;
        cin>>num;
        outputFile << num << endl;
    }
    outputFile.close();

    ifstream inputFile("example2.txt");
    if (!inputFile) {
        cerr << "Ошибка!" << endl;
        return 1;
    }
    // Вычисляем сумму чисел из файла
    double number;
    double sum = 0;
    while (inputFile >> number) {
        sum += number;
    }
    inputFile.close();
    cout << "Сумма чисел из файла: " << sum << endl;

}

int Task4Prog2_subprogram(int x){
    if(x>0) return 1;
    else if (x==0) return 0;
    else return -1;
}

void Task4Prog2(){
    int number;
    cout<<"Введите число:";
    cin>>number;
    cout<<"sign x="<<Task4Prog2_subprogram(number)<<endl;

}

double CalculateRectangleArea(double width, double height) {
    return width * height;
}

double CalculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

static double CalculateCircleArea(double radius) {
    return M_PI * pow(radius, 2);
}

void Task4Prog3(){
    int choice;

    cout << "Выберите фигуру:" << endl;
    cout << "1. Прямоугольник" << endl;
    cout << "2. Треугольник" << endl;
    cout << "3. Круг" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            double width, height;
            cout << "Введите длины сторон прямоугольника>";
            cin >> width >> height;
            double area = CalculateRectangleArea(width, height);
            cout << "Площадь прямоугольника>" << area << endl;
            break;
        }
        case 2: {
            double base, height;
            cout << "Введите основание треугольника>";
            cin >> base;
            cout << "Введите высоту треугольника>";
            cin>> height;
            double area = CalculateTriangleArea(base, height);
            cout << "Площадь треугольника=" << area << endl;
            break;
        }
        case 3: {
            double radius;
            cout << "Введите радиус круга>";
            cin >> radius;
            double area = CalculateCircleArea(radius);
            cout << "Площадь круга=" << area << endl;
            break;
        }
        default:
            cout << "Ошибка!" << endl;
            break;
    }
}

void Task4Prog4(){
    for (int i=0; i<=4;i++){//4 строки со звездами и полосками
        for (int j=0;j<=12; j++){//рисуем звездочки
            cout<<"*";

        }
        for (int k=0; k<=10+30;k++){// дорисуем линию
            cout<<"_";
        }
        cout<<"_"<<endl;}
    for (int i=0; i<=9; i++){
        for (int j=0; j<=23+30;j++){
            cout<<"_";
        }
        cout<<"_"<<endl;
    }
}

void Task4Prog5(){
    int size = 100; // ширина графика
    int height = 21; // высота

    vector<string> sinGraph(height, string(size, ' ')); // пустое поле
    sinGraph[height/2] = string(size, '-'); // ось

    for(int i = 0; i < size; i++) { // точки графика
        sinGraph[(round(10 * sin(i / 4.5) + 10))][i] = '*';
    }

    for(auto s: sinGraph) { // напечатать
        cout << s << '\n';
    }
}


void Task4Prog6(){
    int temp = 0, max_temp = 0, res = 0, plus_c = 0, count = 0;
    std::string s;
    std::cout << "Введите число"<<endl;

    std::cin >> s;

    std::map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;


    for (char c : s) {
        if (m.find(c) == m.end()) {
            std::cout << "Ошибка!"<<endl;
            return;
        }
        int n = m.at(c);
        if (n < temp || temp == 0) {
            plus_c = 1;
            res += temp;
            temp = n;
            count++;
            max_temp = std::max(temp, max_temp);
        }
        else if (n == temp && plus_c < 3)
        {
            count++;
            plus_c++;
            res += temp;
        }
        else if (n > temp && (n <= max_temp || count == 1))
        {
            plus_c = 0;
            if (temp == 0)
            {
                temp = n;
                max_temp = std::max(temp, max_temp);
                count++;
            }
            else
            {
                if (std::to_string(n).length() - std::to_string(temp).length() > 1)
                {
                    std::cout << "Ошибка!"<<endl;
                    return;
                }
                else
                {
                    res += n - temp;
                    temp = 0;
                    count++;
                }
            }
        }

        else {
            std::cout << "Ошибка!"<<endl;
            return;
        }
    }
    std::cout << res + temp << endl;

    /*
    string line;
    cout<<"Введите число >";
    cin>>line;
    int i, lenX;
    int j = 0;
    int result = 0;
    lenX = line.length() - 1;

    for(i = lenX; i >= 0; i--) {
        if (Symbol(line[i]) >= j)
            result += Symbol(line[i]);
        else
            result -= Symbol(line[i]);
        j = Symbol(line[i]);
    }
    cout<<result;*/
}
int func_6(int i, int m, int c, int cnt, int am, int Sold){
    int Snext =((m*Sold+i)%c);

    if (am==cnt){
        return Snext;
    }
    am++;
    return func_6(i,m,c,cnt,am, Snext);
}

void Task4Prog7(){
    cout<<"1--------------------"<<endl;
    int cnt=1;
    for (int x= cnt; x<cnt+50; x++){
        cout<< func_6(37, 3,64, x,0,0)<<endl;
    }
    cout<<"2--------------------"<<endl;

    for (int x= cnt; x<cnt+50; x++){
        cout<< func_6(25173,13849,65537, x,0,0)<<endl;
    }
}

void Task4Prog8(){
    double matrix_a[3][4] = { // 3x4
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}};

    double matrix_b[4][2] = { // 4x2
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}};

    double matrix_c[3][2];



    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 2; y++) {
            for (int i = 0; i < 4; i++) {
                matrix_c[x][y] += matrix_a[x][i] * matrix_b[i][y];
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 2; y++) {
            cout << matrix_c[x][y] << " ";
        }
        cout << endl;
    }


    int maxSeller = 0;
    int minSeller = 0;
    double maxMoney = 0;
    double minMoney = 10000000;
    for (int x = 0; x < 3; x++) {
        if (matrix_c[x][0] > maxMoney) {
            maxSeller = x + 1;
            maxMoney = matrix_c[x][0];
        }
        if (matrix_c[x][0] < minMoney) {
            minSeller = x + 1;
            minMoney = matrix_c[x][0];
        }
    }
    cout << "Продавец № " << maxSeller << " Максимум " << maxMoney << endl;
    cout << "Продавец № " << minSeller << " Минимум: " << minMoney << endl;

    maxSeller = 0;
    minSeller = 0;
    double maxComss = 0;
    double minComss = 10000000;
    for (int x = 0; x < 3; x++) {
        if (matrix_c[x][1] > maxComss) {
            maxSeller = x + 1;
            maxComss = matrix_c[x][1];
        }
        if (matrix_c[x][1] < minComss) {
            minSeller = x + 1;
            minComss = matrix_c[x][1];
        }
    }
    cout << "Продавец № " << maxSeller << " Максимум " << maxComss << endl;
    cout << "Продавец № " << minSeller << " Минимум " << minComss << endl;

    double sumMoney = 0;
    for (int x = 0; x < 3; x++) {
        sumMoney += matrix_c[x][0];
    }
    cout << "Общая сумма = " << sumMoney << endl;


    double sumComss = 0;
    for (int x = 0; x < 3; x++) {
        sumComss += matrix_c[x][1];
    }
    cout << "Комиссионные = " << sumComss << endl;


    double SumMoneyResult = 0;
    for (int x = 0; x < 3; x++) {
        SumMoneyResult += matrix_c[x][0] + matrix_c[x][1];
    }
    cout << "Всего = " << SumMoneyResult << endl;
}

int nToTen(int base, string input){
    int decimal = 0;
    int exponent = input.length() - 1;
    for (char digit : input) {
        int value;
        if (isdigit(digit)) {
            value = digit - '0';
        } else {

            value = 10 + (digit - 'A');
        }

        decimal += value * pow(base, exponent);
        exponent--;
    }

    return decimal;
}
string DecimalToBase(int decimalNumber, int base) {
    if (base < 2 || base > 16) {
        return "Ошибка!";
    }

    string result = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        char digit;

        if (remainder < 10) {
            digit = '0' + remainder; // Цифры 0-9
        } else {
            digit = 'A' + (remainder - 10); // Буквы A-F для шестнадцатеричной системы и так далее
        }

        result = digit + result;
        decimalNumber /= base;
    }

    return result;
}

int Task4Prog9(){
    string str;
    int osnNumber, osnNeed, number;
    cout<<"Введите число >";
    cin>>str;
    number=0;
    cout<<"Введите основание числа >";
    cin>>osnNumber;
    cout<<"Введите необходимое основание >";
    cin>>osnNeed;

    int ten= nToTen(osnNumber, str);
    string result = DecimalToBase(ten, osnNeed);
    cout<<result;
}

int main(){
    //setlocale(LC_ALL, "Rus"); // для Visual Studio
    //SetConsoleOutputCP(CP_UTF8); //в иных случаях

    Task4Prog1();
    Task4Prog2();
    Task4Prog3();
    Task4Prog4();
    Task4Prog5();
    Task4Prog6();
    Task4Prog7();
    Task4Prog8();
    Task4Prog9();
}


