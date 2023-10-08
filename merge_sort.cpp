//
// Created by konstantin on 08.10.2023.
//

/*
Сортировка слиянием (Merge Sort) - это алгоритм сортировки, основанный на принципе "разделяй и властвуй".
Этот алгоритм разбивает исходный массив на две половины, рекурсивно сортирует каждую половину, а затем
объединяет их в один упорядоченный массив. Вот подробное описание алгоритма:

1. Разделение (Splitting):
Начнем с исходного массива, который требуется отсортировать.
Разделим его на две равные части: левую и правую.
Рекурсивно применим сортировку слиянием к каждой из половин.

2. Сортировка (Merging):
Когда половины массива уже отсортированы, следующий этап - объединение (слияние) этих двух отсортированных половин
в один упорядоченный массив.
Создадим третий массив (или временную структуру данных), который будет использоваться для слияния.
Начнем сравнивать элементы левой и правой половин и копировать наименьший элемент из них в третий массив.
Повторим этот процесс до тех пор, пока одна из половин не будет полностью перенесена в третий массив.
Затем скопируем оставшиеся элементы из другой половины в третий массив.

3. Объединение (Combining):
Теперь третий массив содержит отсортированные элементы, объединяя левую и правую половины исходного массива.
Третий массив становится отсортированным массивом, и сортировка слиянием завершена.
Преимущества сортировки слиянием:

Сортировка слиянием обеспечивает стабильную сортировку, то есть она не меняет порядок элементов с одинаковыми значениями.
Она эффективна и может сортировать массивы любого размера и типа данных.
Ее время выполнения составляет O(n log n), где "n" - количество элементов в массиве, что делает ее эффективной для больших наборов данных.
Однако сортировка слиянием требует дополнительной памяти для временных структур данных, что может сделать ее неоптимальной для некоторых ограниченных сред.
 */

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

/**
 * Слияние двух отсортированных половин массива.
 *
 * @param arr    Ссылка на вектор, который нужно объединить.
 * @param left   Индекс начала левой половины.
 * @param middle Индекс середины массива.
 * @param right  Индекс конца правой половины.
 */
void merge(vector<int>& arr, int left, int middle, int right) {
    /**
     * @brief размер левой половины
     */
    int n1 = middle - left + 1;

    /**
     * @brief размер левой половины
     */
    int n2 = right - middle;
/**
 * @brief Левая половина массива чисел
 */
    vector<int> leftArr(n1);
    /**
 * @brief Левая половина массива чисел
 */
    vector<int> rightArr(n2);

    // Копируем данные во временные массивы leftArr и rightArr
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    // Слияние временных массивов обратно в основной массив arr
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов leftArr (если они есть)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов rightArr (если они есть)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

//
/**
 * Функция для рекурсивной сортировки слиянием
 * @param arr Ссылка на вектор, который нужно объединить.
 * @param left Индекс начала левой половины.
 * @param right Индекс начала правой половины.
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Находим середину массива
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем левую и правую половины
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Объединяем отсортированные половины
        merge(arr, left, middle, right);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout<<"Введите длину массива >";
    cin>>n;
    vector<int> arr (n);
    cout<<"Введите числа: "<<endl;

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }


    int arrSize = arr.size();// длина массива

    cout << "Исходный массив: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
