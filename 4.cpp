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
    ofstream outputFile("example2.txt");//создание или открытие файла
    if (!outputFile) {//обработка ошибки
        cerr << "Ошибка!" << endl;
        return 1;
    }
    for (int i = 1; i <= 10; i++) {//ввод 10 чисел последовательно с клавиатуры
        double num;
        cin>>num;
        outputFile << num << endl;
    }
    outputFile.close();

    ifstream inputFile("example2.txt");//снова открываем файл
    if (!inputFile) {
        cerr << "Ошибка!" << endl;
        return 1;
    }

    double number;
    double sum = 0;
    while (inputFile >> number) {// Вычисляем сумму чисел из файла
        sum += number;
    }
    inputFile.close();
    cout << "Сумма чисел из файла: " << sum << endl;

}

int Task4Prog2_subprogram(int x){//обработка задания с учетом области допустимых значений
    if(x>0) return 1;
    else if (x==0) return 0;
    else return -1;
}

void Task4Prog2(){
    int number;
    cout<<"Введите число:";
    cin>>number;
    cout<<"sign x="<<Task4Prog2_subprogram(number)<<endl;//вывод ответа

}

double CalculateRectangleArea(double width, double height) {//вычисление площади прямоугольника
    return width * height;
}

double CalculateTriangleArea(double base, double height) {//вычисление площади треоугольника
    return 0.5 * base * height;
}

static double CalculateCircleArea(double radius) {//вычисление площади окружности
    return M_PI * pow(radius, 2);
}

void Task4Prog3(){
    int choice;

    cout << "Выберите фигуру:" << endl;
    cout << "1. Прямоугольник" << endl;
    cout << "2. Треугольник" << endl;
    cout << "3. Круг" << endl;
    cin >> choice;

    switch (choice) {// выбор подпрограммы и подсчет ответа в соответствующей выбору подпрограмме
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
        default:// обработка иных ответов
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
    for (int i=0; i<=9; i++){// выводим остальные линии
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
        sinGraph[(round(10 * sin(i / 4.5) + 10))][i] = '*';//если точка соответсвует синусу - рисуем звезлочку
    }

    for(auto s: sinGraph) { // построчно выводим
        cout << s << '\n';
    }
}



string int_to_roman(int number) // обратный перевод из числа в roman
{
    const int arr_numbers{ 13 }; // список из чисел
    const int arr_romans{ 13 }; // список из коомбинаций этих чисел в римской
    int numbers[arr_numbers]{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string romans[arr_romans]{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    string res = ""; // результат
    for (int i = 0; i < 13; i++)
    {
        int count = number / numbers[i]; // ищу сколько раз встречается нужная цифра
        for (int k = 0; k < count; k++)
        {
            res = res + romans[i]; // добавляю нужную цифру нужное кол-во раз
        }
        number = number - (numbers[i] * count); // вычитаю из числа уже обработанную часть числа и обрабатываю дальше
    }
    return res; // возвращаю переведенное
}

int Task4Prog6() // ОСНОВНАЯ ФУНКЦИЯ
{
    int temp = 0, max_temp = 0, res = 0, plus_c = 0, count = 0;
    string s;
    /* temp - предыдущий символ (по числовому зн-ю), max_temp - макс. предыдущий символ (по числовому зн-ю), res - результат,
    * plus_c - количество одинаковых прибавляемых символов подряд, count - количество всех ОБРАБОТАННЫХ на данный момент символов
    */

    cout << "Введите число в римской системе"<<endl;

    cin >> s; // s - введенная строка

    map<char, int> m; // словарик с символами (roman to 10)
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;


    for (char c: s) { // двигаюсь по символам "с" введенной строки
        if (m.find(c) == m.end()) {
            cout
                    << "Incorrect num\n"; // если символа из строки нет в словарике, то скипаем число - во введенном числе есть неверный символ
            return 0;
        }
        int n = m.at(c); // n - значение по ключу символа в словарике (по факту - обрабатываемая цифра в данный момент)
        if (n < temp ||
            temp == 0) { // если n < предыдущей цифры или temp == 0 (т.е. обрабатываемая цифра первое в числе)
            plus_c = 1; // перезагружаю счетчик подряд идущих одинаковых цифр
            res += temp; // прибавляем в результат предыдущую цифру
            temp = n; // в temp заносим n, т.е. для следующей итерации цикла for это будет уже предыдущим значением
            count++; // увеличиваем общее количество обработанных цифр на 1
            max_temp = max(temp, max_temp); // максимальная предыдущая цифра
        } else if (n == temp && plus_c < 3) // если цифра равна предыдущей И количество подряд идущих до n меньше 3
        {
            count++; // увеличиваем общее кол-во цифр
            plus_c++; // увеличиваем кол-во подряд идущих одинаковых цифр
            res += temp; // в результат добавляем предыдущую цифру
        } else if (n > temp && (n <= max_temp || count ==
                                                 1)) // если данная цифра n > предыдущей И (n <= максимальной предыдущей или это вторая цифра в числе)
        {
            if (to_string(n).length() - to_string(temp).length() >
                1) // разница в длине чисел (n - temp) в десятичной должна быть равна единице
            {
                cout << "Incorrect num\n";
                return 0;
            } else {
                res += n - temp; // в результат добавляется разница нынешнего числа - предыдущее
                temp = 0;  // в temp присваивается 0, т.к. на следующем шаге нас не волнует
                max_temp = max(n, max_temp); // max_temp присваиваем максимальное число из предыдущих
                count++; // увеличиваем общее кол-во обработанных
            }
        } else {
            cout << "Ошибка"<<endl; // не выполняются условия выше
            return 0;
        }
    }

    if (int_to_roman(res + temp) == s) // доп. проверка
    {
        cout << res + temp << endl;
    }

}

int func_6(int i, int m, int c, int cnt, int am, int Sold){//генерируем числа рекусивным способом - вводим значения, учитываем число рекурсивных повторений, количество уже совершенных повторений и предыдущее значение
    int Snext =((m*Sold+i)%c);// рассчитываем значение на текцщем шаге

    if (am==cnt){//проверка - нужно ли делать еще повторений?
        return Snext;
    }
    am++;// увеличиваем счетчик повторений на единицу
    return func_6(i,m,c,cnt,am, Snext);//вызываем еще одну функцию
}

void Task4Prog7(){
    //1 часть
    cout<<"1 часть"<<endl;
    int cnt=1;
    for (int x= cnt; x<cnt+50; x++){
        cout<< func_6(37, 3,64, x,0,0)<<endl;//вызываем функцию от нужных данных; число совершенных повторений и предыдущее значение зануляем
    }
    cout<<"2 часть"<<endl;
//2 часть
    for (int x= cnt; x<cnt+50; x++){
        cout<< func_6(25173,13849,65537, x,0,0)<<endl;
    }
}

void Task4Prog8(){
    double matrix_a[3][4] = { // матрица 3x4
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}};

    double matrix_b[4][2] = { // матрица 4x2
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}};

    double matrix_c[3][2];// задаем пустую матрицу размером, с перемноженную


    // выполняем перемножение матриц и выводим ее
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

    // считаем необходимые данные
    int maxSeller = 0;//продавец с наибольшей прибылью
    int minSeller = 0;// продавец с наименьшей прибылью
    double maxMoney = 0; //минимальные комиссионные
    double minMoney = 10000000;//максимальные комиссионные
    for (int x = 0; x < 3; x++) {
        if (matrix_c[x][0] > maxMoney) {//ищем максимальную прибыль продавца
            maxSeller = x + 1;
            maxMoney = matrix_c[x][0];
        }
        if (matrix_c[x][0] < minMoney) {//ищем минимальную прибыль продавца
            minSeller = x + 1;
            minMoney = matrix_c[x][0];
        }
    }
    cout << "Продавец № " << maxSeller << " Максимум " << maxMoney << endl;// выводим ответ
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
    for (int x = 0; x < 3; x++) {// считаем общую сумму денег
        sumMoney += matrix_c[x][0];
    }
    cout << "Общая сумма = " << sumMoney << endl;


    double sumComss = 0;
    for (int x = 0; x < 3; x++) {// считаем общие комиссионные
        sumComss += matrix_c[x][1];
    }
    cout << "Комиссионные = " << sumComss << endl;


    double SumMoneyResult = 0;
    for (int x = 0; x < 3; x++) {// всего денег прошло через руки продавцов
        SumMoneyResult += matrix_c[x][0] + matrix_c[x][1];
    }
    cout << "Всего = " << SumMoneyResult << endl;
}

int nToTen(int base, string input){//перевод числа из СС base в 10-тичную
    int decimal = 0;
    int exponent = input.length() - 1;// длина числа
    for (char digit : input) {// определяем, что дает цифра в соответствии с весом числа и разрядом
        int value;
        if (isdigit(digit)) {//если символ - цифра
            value = digit - '0';
        } else {// для СС, больших 10, где есть буквенные обозначения цифры

            value = 10 + (digit - 'A');
        }

        decimal += value * pow(base, exponent);// считаем число в десятичной СС
        exponent--;
    }

    return decimal;
}
string DecimalToBase(int decimalNumber, int base) {// перевод числа из 10-чной в число с основанием base
    if (base < 2 || base > 16) {//основание должно иметь определенные границы
        return "Ошибка!";
    }

    string result = "";
    // раскладываем число на цифры. Для этого делим число на основание и запоминаем остатки от деления
    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;//цифра при делении на основание
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

    int ten= nToTen(osnNumber, str);//переводим число из baze в 10-чную СС
    string result = DecimalToBase(ten, osnNeed);//из 10-чной в необходимую
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


