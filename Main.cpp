#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int Div(int a, int b)
{
    int n, max;
    if (a < b)
        n = a;
    else
        n = b;
    for (int i = 1; i <= n; i++)
        if (a % i == 0 && b % i == 0)
            max = i;
    return max;
}

template <typename T>
void print_arr(T arr[], const int length) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b }\n";
}

int mirror_num(int n){
        int n1 = 0;
        int n2;
        while (n > 0)
        {
            n2 = n % 10;
            n1 = n1 * 10 + n2;
            n = n / 10;
        }
        return n1;
    }


template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {
    for (int i = begin; i < length; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


void arr_4(int A, int B, int arr[], const int length){
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % (B + 1 - A) + A;
        std::cout << arr[i] << ", ";
    }
}




int main() {
    setlocale(LC_ALL, "russian");
    //Задача 1.
    int n, m;
    std::cout << "Задача 1.\nВведите два числа -> ";
    std::cin >> n;
    std::cin >> m;
    Div(n, m);
    std::cout << "Наибольший делитель -> " << Div(n, m) << std::endl;

    //Задача 2.
    int mirror;
    std::cout << "Задача 2.\n Введите число -> ";
    std::cin >> mirror;
    std::cout << "Зеркальное число вашего числа -> " << mirror_num(mirror) << std::endl;


    //Задача 3.
    const int size1 = 10;
    int mass[size1]{2, 3, 10, 30, 9, 0, 42, 7, 5, 93};
    int N;
    std::cout << "Задача 3.\nИзначальный массив: \n";
    for (int i = 0; i < size1; i++)
        std::cout << mass[i] << ", ";
    std::cout << "Выберете число из массива-> ";
    std::cin >> N;
    std::cout << "Индекс искомого числа = " << search_index(mass, size1, N);
    std::cout << "\nОтсортированный массив начиная с элемента N: ";
    std::sort(mass, mass + (size1 - N));
    std::cout << std::endl;
    print_arr(mass, size1);


    //Задача 4.
    int A, B;
    int const size = 10;
    int arr[size];
    std::cout << "Задача 4.\n Введите начало диапазона -> ";
    std::cin >> A;
    std::cout << "Введите конец диапазона -> ";
    std::cin >> B;
    std::cout << "Массив: "; 
    arr_4(A, B, arr, size);
    return 0;
}