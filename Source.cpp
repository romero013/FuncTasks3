// FuncTasks3
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template <typename T> void showArr(T arr[], int length);
void typeOfN(int N) {
	cout << "INT\n";
}
void typeOfN(double N) {
	cout << "DOUBLE\n";
}
void typeOfN(float N) {
	cout << "FLOAT\n";
}
int sumAB(int A, int B);
void sortRange(int arr[], int length);
void moveArray(int arr[], int length, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;

	// Задача 1
	cout << "Задача 1.\n";
	cout << "10 - ";
	typeOfN(10); // Вывод в типе данных int
	cout << "5.5 - ";
	typeOfN(5.5); // Вывод в типе данных double
	cout << "5.5 - ";
	typeOfN((float)5.5); // Вывод в типе данных float

	// Задача 2
	cout << "Задача 2.\nВведите два числа: ";
	cin >> n >> m;
	cout << "Сумма чисел от " << n << " до " << m << " = " << sumAB(n, m) << "\n\n";

	// Задача 3
	cout << "Задача 3.\nИзначальный массив:\n";
	int z3[10];
	for (int i = 0; i < 10; i++)
		z3[i] = rand() % (20 + 1 - (-20)) + (-20); // (y - x) + x; где x - начало интервала, y - конец интервала. (x = -20, y = 20); Если в конце добавить (+100), диапазон сместится на 100 (x = 80, y = 120).
	showArr(z3, 10);
	cout << "Итоговый массив:\n";
	sortRange(z3, 10);
	showArr(z3, 10);

	// Задача 4
	cout << "Задача 4.\nИзначальный массив:\n";
	int z4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	showArr(z4, 10);
	cout << "Введите количество сдвигов: ";
	cin >> n;
	moveArray(z4, 10, n);
	cout << "Итоговый массив:\n";
	showArr(z4, 10);

	return 0;
}
// Задача 2
int sumAB(int A, int B) {
	if (A == B)
	return A;
	return B + sumAB(A, B - 1);
}
// Задача 3
void sortRange(int arr[], int length) {
	int firstIndex = - 1, lastIndex = - 1;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			firstIndex = i;
			break;
		}
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			lastIndex = i;
			break;
		}
	if (firstIndex != -1)
		// Пузырьковый метод
		/*for (int i = lastIndex; i > firstIndex; i--)
			for (int j = firstIndex; j < i; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);*/
		// Быстрая сортировка
		sort(arr + firstIndex, arr + lastIndex);
}
// Задача 4
void moveArray(int arr[], int length, int n) {
	if (n >= length)
		n -= (n / length) * length; // Оптимизация кода. Не делает лишних итераций.
	for (int j = 0; j < n; j++) {
		int tmp = arr[length - 1]; // Берём значение последнего элемента массива, а не его порядковый номер, как обычно.
		for (int i = length - 1; i >= 1; i--)
			arr[i] = arr[i - 1];
		arr[0] = tmp;
	}
}
// Вывод массива
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}