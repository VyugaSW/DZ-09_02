

#include <iostream>
#include <Windows.h>

using namespace std;

// Задание 1
void task1();
void sortNum(int arr[], int s) {
	int temp;
	for (int i = 0; i < s; i++) {
		for (int j = s - 1; j > i; j--) {
			if (arr[j - 1] < arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}

		}
	}
	for (int i = 0; i < s; i++) {
		cout <<  arr[i] << endl;
	}
}
void users(string arr[], int arr1[], int arr2[], int s) {
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " |Мобильный номер - " << arr1[i] << " |Домашний номер - " << arr2[i] << endl;
	}
}
void task1() {
	int const s = 8;
	int massNumtel[s] = { 747389011,796483825,701234972,751820397,780991680,798155751,784552323,765201252 };
	int massHometel[s] = { 75425,75265,75865,98575,54684,18746,17854,18453 };
	string name[s] = { "Nikola","Dali","Rassel","Robert","Napoleon","Petr","Ivan","Markz" }; // Насчёт пользовательских данных мне смутно было,
	char chose;                                                                              // Поэтому каждому номеру был дан несомненный властелин.
	cout << "Здравствуйте,\n";
	cout << "*Сортировка по номерам мобильных телефонов - s\n";
	cout << "*Сортировка по домашним номерам телефонов - h\n";
	cout << "*Вывод пользовательских данных - u\n";
	cout << "*Выход - f\n";
	cin >> chose;

	switch (chose) {
	case('s'):
		cout << "Отсортированно в порядке убывания:\n";
		sortNum(massNumtel, s);
		break;
	case('h'):
		cout << "Отсортированно в порядке убывания:\n";
		sortNum(massHometel, s);
		break;
	case('u'):
		users(name, massNumtel, massHometel, s);
		break;
	case('f'):
		cout << "До свидания, досточтимый\n";
		break;
	default:
		cout << "ОШИБКА\n" << "Проверьте команду\n\n";
		task1();
		break;
	}

}
//--

//Задание 2
void task2() {
	int mass[10] = { 1,2,3,45,5,6,7,8,10,9 };
	int temp;
	int counter;
	for (int i = 0; i < 10; i++) {
		counter = 0;
		for (int j = 9; j > i; j--) {
			if (mass[j - 1] > mass[j]) {
				counter++;
				temp = mass[j - 1];
				mass[j - 1] = mass[j];
				mass[j] = temp;
			}
		}
		if (counter == 0) break;
	}
	for (int i = 0; i < 10; i++) {
		cout << mass[i] << endl;
	}
}
//--

//Задание 3
void task3() {
	int oladi[8] = { 5,10,7,8,9,3,2,4 };
	int temp, temp1;
	for (int i = 0; i < 8; i++) {
		temp = i;
		temp1 = oladi[i];
		for (int j = i + 1; j < 8; j++) {
			if (oladi[j] > temp1) {
				temp = j;
				temp1 = oladi[j];
			}
		}
		if (temp != i) {
			oladi[temp] = oladi[i];
			oladi[i] = temp1;
		}
	}
	for (int i = 0; i < 8; i++) {
		cout << oladi[i] << endl;
	}

}
//--

//Задание 4
int bubleCount = 0, ChoseCount = 0; //для хранения
void BubleSortTask2(int mass[], int s) {
	int temp;
	int counter;
	for (int i = 0; i < s; i++) {
		counter = 0;
		for (int j = s-1; j > i; j--) {
			if (mass[j - 1] > mass[j]) {
				counter++;
				bubleCount++;
				temp = mass[j - 1];
				mass[j - 1] = mass[j];
				mass[j] = temp;
			}
		}
		if (counter == 0) break;
	}
}
void ChosenSort(int a[], int s) {
    int temp, a1;
    for (int i = 0; i < s; i++) {
        temp = i;
        a1 = a[i];
        for (int j = i + 1; j < s; j++) {
            if (a[j] < a1) {
                temp = j;
                a1 = a[j];
            }
        }
        if (temp != i) {
			ChoseCount++;
            a[temp] = a[i];
            a[i] = a1;
        }
    }
}
void randomMassiveBUBLE() {
	int const s = 1000;
	int mass[s];
	srand(time(NULL));
	for (int i = 0; i < s; i++) {
		mass[i] = rand() % 10;
	}
	BubleSortTask2(mass, s);
}
void randomMassiveCHOSEN() {
	int const s = 1000;
	int mass[s];
	srand(time(NULL));
	for (int i = 0; i < s; i++) {
		mass[i] = rand() % 10;
	}
	ChosenSort(mass, s);
}
void task4() {
	for (int i = 0; i < 10; i++) {
		randomMassiveBUBLE();
		randomMassiveCHOSEN();
	}
	cout << "Среднее число перестановок в пузырьковом методе - " << bubleCount / 10 << endl;
	cout << "Среднее число перестановок в выборочном методе - " << ChoseCount / 10 << endl;
}
//--


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//Написать программу «справочник». Создать два одномерных
	//массива.Один массив хранит номера мобильных телефонов,
	//	второй — домашние телефонные номера.
	//	Реализовать меню для пользователя :
	//■■ Отсортировать по номерам мобильных
	//■■ Отсортировать по домашним номерам телефонов;
	//■■ Вывести пользовательский данные;
	//■■ Выход.

	//task1();


	//Написать программу, реализующую сортировку массива с
	//помощью усовершенствованной сортировки пузырьковым ме-
	//тодом. Усовершенствование состоит в том, чтобы анализировать
	//количество перестановок на каждом шагу, если это количество
	//равно нулю, то продолжать сортировку нет смысла — массив
	//отсортирован.

	//task2();


	//Есть стопка оладий различного радиуса. Единственная
	//операция, проводимая с ними — между любыми двумя суем
	//лопатку и меняем порядок оладий над лопаткой на обратный.
	//Необходимо за минимальное количество операций таких
	//отсортировать снизу вверх по убыванию радиуса.
	
	//task3();


	//Написать программу, которая сравнивает число переста-
	//новок элементов при использовании сортировки «пузырь -
	//ком»(усовершенствованная версия задани я 2) и методом
	//выбора.Выполнить ее тестирование на разных 10 массивах,
	//содержащих 1000 случайных элементов, вычислить среднее
	//число перестановок для каждого метода после тестирования.

	//task4();
}

