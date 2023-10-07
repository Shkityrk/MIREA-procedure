//
// Created by konstantin on 26.09.2023.
//
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;

int D(int a, int b){// используем функцию, чтобы вычесть одно число из другого
    while (a!=b){// Проверка на равность чисел и вычитание до того момента, когда числа будут равны. т.е разложение по множителям числа
        if (a>b) a-=b;
        else b-=a;

    }
    return a;

}
void Task5Prog1(){
    double a,b;//ввод двух чисел в формате с плавающей точкой
    cout<<"Введите 1 число"<<endl;
    cin>>a;
    cout<<"Введите 2 число"<<endl;
    cin>>b;
    if ((a!=0) and (b!=0)){// проверка условия, что числа ненулевые
        cout<<D(a,b)<<endl;// используем функцию
    }
}

int Task5Prog2(){
    int n;

    cout<<"Введите натуральное число"<<endl;
    cin>> n;
    if (n>=1000000){
        return 0;
    }
    vector<int> a(n);// задаем массив чисел

    for (int i = 0; i <= n; i++)
        a[i] = i;// заполняем массив числами, причем номер элемента в массиве равен значению этого элемента

    for (int i=2; i*i<=n;i++ ) {// проход циклом до целого числа, приближенного к корню заданного числа, то есть эффективный перебор делителей
        if (a[i]) {//элемент ненулевой
            for (int j = i * i; j <= n; j += i) {// внутренний проход циклом, на этот раз до числа, приближенного к корню
                a[j] = 0;// зануляем элемент, если его значение имеет хотя бы один делитель, кроме 1 и самого числа
            };
        }
    }


    // далее проходим по всем элементам массива и выводим только те элементы, значение которых не равно 0, т.е это число подпадает под необходимые условия - у числа n нет делителей, находящихся в промежутке (1;sqrt(n)]. такое возможно, так как любое произведение чисел содержит два числа(k*l=n), а значит, проверяя одно число(напр. K, меньшее корня из n) мы явно убираем и число l= n/k также подпадает под наше условие
    for (int i=0; i <= a.size() - 2; i++){
        if (a[i]!=0){
        cout << a[i] << " ";}
    }

}

int Task5Prog3_pt26(){
    string inputFileName = "input1.txt"; // Имя входного файла
    string outputFileName = "output1.txt"; // Имя выходного файла

    ifstream inputFile(inputFileName);
    if (!inputFile) {//обработка ошибки отрытия файла
        std::cerr << "Не удается открыть входной файл." << std::endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Не удается открыть выходной файл." << std::endl;
        return 1;
    }
    // чтение файла и посимвольная замена
    char ch;
    while (inputFile.get(ch)) {
        if (std::isalpha(ch)) {
            if (ch == 'z') {
                ch = 'a'; // Обработка перехода с 'z' к 'a'
            } else if (ch == 'Z') {
                ch = 'A'; // Обработка перехода с 'Z' к 'A'
            } else {
                ch++; // Увеличение символа на следующий в алфавите
            }
        }
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Замена завершена." << std::endl;

    return 0;
}

int GenFile(){// генератор файла, содержащего случайное количество и порядок открытых и закрытых скобок
    cout<<"Запуск генератора файла со скобками"<<endl;
    int totalBrackets = 20; // Общее количество скобок
    int openBrackets = 0;  // Количество открытых скобок
    int closeBrackets = 0; // Количество закрытых скобок

    std::ofstream outputFile("input2.txt");

    if (!outputFile) {// обработка ошибки открытия файла
        std::cerr << "Не удается создать файл." << std::endl;
        return 1;
    }

    random_device rd;// использование функций генерации числа
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < totalBrackets; ++i) {// параллельно с генерацией и записью в текстовый файл выводим полученный символ для проверки
        if (openBrackets < totalBrackets / 2 && dist(gen) == 0) {
            outputFile << '(';
            cout<<'(';
        } else {
            outputFile << ')';
            cout<<')';
        }
    }

    outputFile.close();
    cout << "" << endl;

    return 0;
}

bool isBalanced(const std::string &text) {// функция, проверяющая - соблюдается ли баланс скобок - каждой открытой скобке должна соответвовать закрывающаяся
    stack<char> bracketStack;

    for (char c : text) {// прогон по символам
        if (c == '(') {
            bracketStack.push(c);
        } else if (c == ')') {
            if (bracketStack.empty()) {
                return false; // Несбалансированные скобки
            }
            bracketStack.pop();
        }
    }

    return bracketStack.empty(); // сбалансированные скобки, если стек пуст
}

int Task5Prog3_pt38(){// основная часть программы.
    //GenFile();// можно использовать для генерации файла со скобками, однако вероятность генерации именно сбалансированных скобок мала. Для запуска программы необходимо создать вручную файл input2.txt в папке с исполняемым файлом, и добавить туда необходимые данные
    cout<<"Запуск основной программы"<<endl;
    string fileName = "input2.txt"; // Имя файла для проверки

    ifstream inputFile(fileName);
    if (!inputFile) {//обработка ошибки открытия файла
        cerr << "Не удается открыть файл." << endl;
        return 1;
    }

    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>()); // читаем строку из файла
    // проверяем через функцию
    if (isBalanced(fileContent)) {
        cout << "Скобки в файле сбалансированы." << endl;
    } else {
        cout << "Скобки в файле несбалансированы." << endl;
    }

    inputFile.close();

    return 0;
}

int Task5Prog4_pt26(){
    string S;
    cout << "Введите строку: ";
    getline(cin, S); // считываем строку

    // используем потоковый ввод для разделения слов
    istringstream iss(S);
    vector<string> words;// создаем массив из слов
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() >= 3) {// если слов больше три, выводим третье
        string thirdWord = words[2];
        cout << "Третее слово в обратном порядке: ";
        for (int i = thirdWord.length() - 1; i >= 0; i--) {
            cout << thirdWord[i];
        }
        cout << std::endl;
    } else {
        cout << "В строке нет третьего слова." << endl;
    }

    return 0;
}

int Task5Prog4_pt38(){
    int m;
    cout<<"Введите число:"<<endl;
    cin>>m;// вводим число

    for (int num1=1; num1<=9;num1++ ){// 1 цифра может быть от 1 до 9; 0 быть не может
        for (int num2=0; num2<=9;num2++ ){ // 2 цифра десятичной СС
            for (int num3=0; num3<=9;num3++ ){//3  цифра десятичной СС
                if ((num1+num2+num3)==m){ // сумма цифр числа равна m
                    cout<<num1*100+num2*10+num3<<endl; // если это правда - выводим число
                }
            }
        }
    }

}

struct Student { // создаем структуру, описывающую все свойства студента
    string regNumber;
    string fullName;
    vector<int> grades;

    // Вычисление среднего балла
    double averageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }

        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();// перевод ответа из числа с плавающей точкой в целочисленный тип данных
    }
};

bool compareByAverageGrade(const Student &a, const Student &b) {
    return a.averageGrade() > b.averageGrade();// сравнение среднего балла каждого студента
}



int Task5Prog5_pt26(){
    std::vector<Student> students;// создаем массив, который заполняем строками с информацией о студенте
    students.push_back({ "12345", "Иванов Иван Иванович", {85, 90, 78, 92, 88} });
    students.push_back({ "54321", "Петров Петр Петрович", {76, 80, 82, 89, 75} });
    students.push_back({ "67890", "Сидоров Алексей Петрович", {94, 92, 88, 91, 89} });

    // Сортировка студентов по среднему баллу
    std::sort(students.begin(), students.end(), compareByAverageGrade);

    // Создание файла и запись данных
    std::ofstream outputFile("student_data.txt");

    if (outputFile.is_open()) {
        for (const Student &student : students) {// выполяняем сортировку, используя функциию структуру
            outputFile << student.regNumber << " | " << student.fullName << " | ";
            for (int grade : student.grades) {
                outputFile << grade << " ";
            }
            outputFile << "| Средний балл: " << std::fixed << std::setprecision(2) << student.averageGrade() << std::endl;
        }
        outputFile.close();
        std::cout << "Данные успешно записаны в файл 'student_data.txt' и отсортированы по среднему баллу." << std::endl;
    } else {
        std::cerr << "Ошибка при открытии файла." << std::endl;
    }

    return 0;
}

int Task5Prog5_pt38(){
    int n=15;
    int c[n];// массив из n элементов
    for (int i=0;i<n;i++){
        cin>>c[i];// ввод n числе и их запись в ячейки массива
    }
    int count=0;// счетчик пар

    for (int i=0;i<n;i++){// делаем перебор, который просматривает все возможные варианты сложения 2 чисел и в случае верного варианта прибавить к счетчику 1 , т.е учесть это число
        for (int j=i+1;j<n;j++){
            if (c[i]+c[j]==13){
                count++;
            }

        }
    }
    if (count==0){// если пар нет => счетчик=0
        cout<<"Пар нет!"<<endl;
        return 0;
    }
    else{//если есть хотя бы одна пара - выводим количество
        cout<<count<<endl;
        return 0;
    }


}
int main() {
    //setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(CP_UTF8);

    Task5Prog5_pt38();
}

