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

int D(int a, int b){
    while (a!=b){
        if (a>b) a-=b;
        else b-=a;

    }
    return a;

}
void Task5Prog1(){
    double a,b;
    cout<<"Введите 1 число"<<endl;
    cin>>a;
    cout<<"Введите 2 число"<<endl;
    cin>>b;
    if ((a!=0) and (b!=0)){
        cout<<D(a,b)<<endl;
    }
}

int Task5Prog2(){
    int n;

    cout<<"Введите натуральное число"<<endl;
    cin>> n;
    if (n>=1000000){
        return 0;
    }
    vector<int> a(n);

    for (int i = 0; i <= n; i++)
        a[i] = i;

    for (int i=2; i*i<=n;i++ ) {
        if (a[i]) {
            for (int j = i * i; j <= n; j += i) {
                a[j] = 0;
            };
        }
    }



    for (int i=0; i <= a.size() - 2; i++){
        if (a[i]!=0){
        cout << a[i] << " ";}
    }

}

int Task5Prog3_pt26(){
    std::string inputFileName = "input1.txt"; // Имя входного файла
    std::string outputFileName = "output1.txt"; // Имя выходного файла

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Не удается открыть входной файл." << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Не удается открыть выходной файл." << std::endl;
        return 1;
    }

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

int GenFile(){
    cout<<"Запуск генератора файла со скобками"<<endl;
    int totalBrackets = 20; // Общее количество скобок
    int openBrackets = 0;  // Количество открытых скобок
    int closeBrackets = 0; // Количество закрытых скобок

    std::ofstream outputFile("input2.txt");

    if (!outputFile) {
        std::cerr << "Не удается создать файл." << std::endl;
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);

    for (int i = 0; i < totalBrackets; ++i) {
        if (openBrackets < totalBrackets / 2 && dist(gen) == 0) {
            outputFile << '(';
            cout<<'(';
        } else {
            outputFile << ')';
            cout<<')';
        }
    }

    outputFile.close();
    std::cout << "" << std::endl;

    return 0;
}

bool isBalanced(const std::string &text) {
    std::stack<char> bracketStack;

    for (char c : text) {
        if (c == '(') {
            bracketStack.push(c);
        } else if (c == ')') {
            if (bracketStack.empty()) {
                return false; // Несбалансированные скобки
            }
            bracketStack.pop();
        }
    }

    return bracketStack.empty(); // Сбалансированные скобки, если стек пуст
}

int Task5Prog3_pt38(){
    GenFile();
    cout<<"Запуск основной программы"<<endl;
    string fileName = "input2.txt"; // Имя файла для проверки

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Не удается открыть файл." << endl;
        return 1;
    }

    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    if (isBalanced(fileContent)) {
        cout << "Скобки в файле сбалансированы." << std::endl;
    } else {
        cout << "Скобки в файле несбалансированы." << std::endl;
    }

    inputFile.close();

    return 0;
}

int Task5Prog4_pt26(){
    std::string S;
    std::cout << "Введите строку: ";
    std::getline(std::cin, S);

    // Используем потоковый ввод для разделения слов
    std::istringstream iss(S);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() >= 3) {
        std::string thirdWord = words[2];
        std::cout << "Третее слово в обратном порядке: ";
        for (int i = thirdWord.length() - 1; i >= 0; i--) {
            std::cout << thirdWord[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "В строке нет третьего слова." << std::endl;
    }

    return 0;
}

int Task5Prog4_pt38(){
    int m;
    cout<<"Введите число:"<<endl;
    cin>>m;

    for (int num1=1; num1<=9;num1++ ){
        for (int num2=0; num2<=9;num2++ ){
            for (int num3=0; num3<=9;num3++ ){
                if ((num1+num2+num3)==m){
                    cout<<num1*100+num2*10+num3<<endl;
                }
            }
        }
    }

}

struct Student {
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
        return static_cast<double>(sum) / grades.size();
    }
};

bool compareByAverageGrade(const Student &a, const Student &b) {
    return a.averageGrade() > b.averageGrade();
}



int Task5Prog5_pt26(){
    std::vector<Student> students;
    students.push_back({ "12345", "Иванов Иван Иванович", {85, 90, 78, 92, 88} });
    students.push_back({ "54321", "Петров Петр Петрович", {76, 80, 82, 89, 75} });
    students.push_back({ "67890", "Сидоров Алексей Петрович", {94, 92, 88, 91, 89} });

    // Сортировка студентов по среднему баллу
    std::sort(students.begin(), students.end(), compareByAverageGrade);

    // Создание файла и запись данных
    std::ofstream outputFile("student_data.txt");

    if (outputFile.is_open()) {
        for (const Student &student : students) {
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
    int c[n];
    for (int i=0;i<n;i++){
        cin>>c[i];
    }
    int count=0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (c[i]+c[j]==13){
                count++;
            }

        }
    }
    if (count==0){
        cout<<"Пар нет!"<<endl;
        return 0;
    }
    else{
        cout<<count<<endl;
        return 0;
    }


}
int main() {
    //setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(CP_UTF8);

    Task5Prog5_pt38();
}

