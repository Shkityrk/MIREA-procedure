#include <iostream>
#include <cmath>


void Task1Prog1() {
    std::cout << "Константин" << std::endl;
}
void Task1Prog2() {
    int a, b;
    std::cout << "Введите значение а> ";
    std::cin >> a;
    std::cout << "Введите значение b> ";
    std::cin >> b;

    std::cout << "Сумма: " << a + b << std::endl;
    std::cout << "Разность: " << a - b << std::endl;
    std::cout << "Произведение: " << a * b << std::endl;

    if (b != 0) {
        double del = static_cast<double>(a) / b;
        std::cout << "Частное: " << del << std::endl;

    }
    else {
        std::cout << "Деление невозможно!" << std::endl;
    }
}

void Task1Prog3() {
    double b, c;
    std::cout << "Введите значение b> ";
    std::cin >> b;
    std::cout << "Введите значение c> ";
    std::cin >> c;
    if (b == 0) {
        std::cout << "Нет корней!" << std::endl;
    }
    else {
        std::cout << -c / b << std::endl;
    }
}

void Task1Prog4() {
    int a, b, c;
    std::cout << "Введите значение a> ";
    std::cin >> a;
    std::cout << "Введите значение b> ";
    std::cin >> b;
    std::cout << "Введите значение c> ";
    std::cin >> c;
    if ((b * b - 4 * a * c) > 0) {
        std::cout << (-b + sqrt(b * b - 4 * a * c)) / 2 * a << std::endl;
        std::cout << (-b - sqrt(b * b - 4 * a * c)) / 2 * a << std::endl;
    }
    else if ((b * b - 4 * a * c) == 0) {
        std::cout << (-b / 2 * a) << std::endl;
    }
    else { std::cout << "Корней нет" << std::endl; }
}

void Task1Prog5() {
    bool a, b, c;

    std::cout << "На улице светло(1) или темно(0)? ";
    std::cin >> a;
    std::cout << "Шторы развешены(1) или нет(0)? ";
    std::cin >> b;
    std::cout << "Лампа включена(1) или нет(0)? ";
    std::cin >> c;

    if ((a && b) || c) {
        std::cout << "В комнате светло";
    }
    else { std::cout << "В комнате темно"; }
}

int main() {
    //setlocale(LC_ALL, "Rus"); // для Visual Studio
    //SetConsoleOutputCP(CP_UTF8); //в иных случаях

    Task1Prog1();
    Task1Prog2();
    Task1Prog3();
    Task1Prog4();
    Task1Prog5();
}