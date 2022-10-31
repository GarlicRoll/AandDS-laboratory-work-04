#include <stdlib.h>

using namespace std;

/*
int main()
{   
    int array[10] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int arrayLen = 10;
    int buffer;
    int i = 1;

    while (arrayLen != 1)
    {   
        buffer = array[0];
        array[0] = array[arrayLen - i];
        array[arrayLen - i] = buffer;
        i++;
    }

    return 0;
}
*/

// Реализация пирамидальной сортировки на C++
#include <iostream>

using namespace std;


class Tree
{   
    private:
        int * arr;

    public:
        // Вывод дерева как строка
        void printArray(int); 
        // Преобразование в двоичную кучу
        void heapify(int, int);
        // Пирамидальная сортировка
        void heapSort(int);
        // Конструктор
        Tree(int *);
};

Tree :: Tree(int * arr)
{
    this->arr = arr;
}


// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи
void Tree :: heapify(int n, int i)
{
    int largest = i;   
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && this->arr[l] > this->arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && this->arr[r] > this->arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(this->arr[i], this->arr[largest]);

    // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }
}


// Основная функция, выполняющая пирамидальную сортировку
void Tree :: heapSort(int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(i, 0);
    }
}

// Вспомогательная функция для вывода на экран массива размера n
void Tree :: printArray(int n)
{
    for (int i = 0; i < n; ++i)
        cout << this->arr[i] << " ";
    cout << "\n";
}

// Управляющая программа
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    Tree tree(arr);

    cout << "Array is \n";
    tree.printArray(n);

    tree.heapSort(n);

    cout << "Sorted array is \n";
    tree.printArray(n);
    return 0;
}