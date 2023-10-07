//
// Created by shkit on 02.10.2023.
//
#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int main(){
    //setlocale(LC_ALL, "Rus");// для Visual Studio
    //SetConsoleOutputCP(CP_UTF8); // в иных случаях

    int osn, cost_lop, max_sum, max_n;
    cout<<"Введите основание ";
    cin>> osn;
    cout<<"Введите стоимость лопасти ";
    cin>> cost_lop;
    cout<<"Введите максимальную сумму ";
    cin>> max_sum;

    for (int n=1; n<2*pow(10,7); n++){// проходим по циклу, изменяя количество лопастей. Считаем, больше ли это значение, чем максимальная сумма
        if (osn+ n*cost_lop<=max_sum){//если условие выполняется - находим максимум из выданного числа и максимального. но т.к. n  увеличивается, достаточно не проверять максимум - предыдущее всегда будет меньше, чем данное число
            max_n=n;
        }
    }
    cout<<"Максимальное количество лопастей ="<<max_n<<endl;
    return 0;


}