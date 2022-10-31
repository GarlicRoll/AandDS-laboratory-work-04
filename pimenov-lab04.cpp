#include <stdlib.h>

using namespace std;

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
        // Деструктор
        ~Tree();
};

Tree :: Tree(int * arr)
{
    this->arr = arr;
}

Tree :: ~Tree()
{
    delete arr;
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
// O(n*log(n))
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

        // Вызываем процедуру heapify на уменьшенной куче
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
    // Максимальное кол-во элементов
    int maxN = 16;

    // Возможность ввода с клавиатуры / случайного ввода
    char randomInput = false;
    cout << "Do you want random input? Y/N\n";
    cin >> randomInput;

    // Кол-во элментов
    unsigned int n;
    if (randomInput == 'Y')
    {
        n = rand() % 11 + 5; 
    }
    else
    {
        cout << "Enter number of element:\n";
        cin >> n;
    }
    // Защита от ввода слишком большого массива с клавиатуры
    if (n > maxN) n = maxN;
    // Массив элментов
    int * arr = new int[n];
    if (randomInput != 'Y') cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {   
        if (randomInput == 'Y')
        {
            arr[i] = rand() % 200 - 100;
        }
        else 
        {
           cin >> arr[i];
        }
    }

    Tree tree(arr);

    cout << "Array is \n";
    tree.printArray(n);

    tree.heapSort(n);

    cout << "Sorted array is \n";
    tree.printArray(n);

    delete &tree;

    return 0;
}