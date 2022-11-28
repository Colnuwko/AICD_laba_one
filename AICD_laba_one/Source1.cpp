#include <conio.h>
#include <string>
#include "Header1.h"
void menu()
{ 
	system("cls");
	cout << "Создать рандомный вектор"<<endl;
	cout << "Создать вектор с параметрами"<<endl;
	cout << "Создать два одинаковых вектора"<<endl;
	

}
void menu_2()
{
	system("cls");
	cout << "1. Сложить векторы"<<endl;
	cout << "2. Вычесть векторы" << endl;
	cout << "3. Найти скалярное произведение" << endl;
	cout << "4. Разделить вектор на число" << endl;
	cout << "5. Умножить вектор на число" << endl;
	cout << "6. вычислить площадь треугольника" << endl;
	cout << "7. Сравнить вектора" << endl;
	cout << "8. Изменить элемент вектора" << endl;
	cout << "9. Просмотреть отдельный элемент вектора" << endl;
	cout << "esc -  выход" << endl;
}
int get_key()
{	
	int key;
	key = _getch();
	system("cls");
	return key;
}
Vector Random()
{
	Vector X;
	return X ;
}
Vector Param(int a, int size, double epsilon)
{
	if (a == 1)
	{
		Vector X(size, epsilon);
		return X;
	}
	else
	{
		Vector Y(size, epsilon);
		return Y;
	}
}
Vector A;
Vector B;
int main()
{
	int size;
	double epsilon;
	setlocale(LC_ALL, "Rus");
	int key = 0;
	
		while (key != 27)
		{
			try
			{
				menu();
				key = get_key();
				switch (key)
				{
				case 49:
				{
					Vector b;
					B = b;
					cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

					//goto random;
					_getch();
					break;
				}
				case 50:
				{
					system("cls");
					cout << "Давайте заполгним наши векторы" << endl << "Введите размерность первого вектора" << endl;
					int size_one;
					int size_two;
					int epsilon;
					cin >> size_one;
					cout << "А теперь введем размерность 2 вектора" << endl;
					cin >> size_two;
					cout << "Замечательно, а теперь введите точность сравнения" << endl;
					cin >> epsilon;
					cout << "Самое время заполнить вектора" << endl;
					Vector a(size_one, epsilon);
					cout << endl << "Остался последний вектор" << endl;
					Vector b(size_two, epsilon);
					A = a;
					B = b;
					cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

					//goto Par;
					_getch();
					break;
				}
				case 51:
				{
					cout << "1. Создать два моих собственных вектора" << endl << "2. Создать два одинаковых и рандомных вектора" << endl;
					key = get_key();
					switch (key)
					{
					case 49:
					{
						cout << "Давайте заполгним наши векторы" << endl << "Введите размерность векторов" << endl;
						cin >> size;
						cout << "Замечательно, а теперь введите число сравнения" << endl;
						cin >> epsilon;
						cout << "Самое время заполнить вектора" << endl;
						Vector a(size, epsilon);
						A = a;
						B = a;
						cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

						//goto My_copy;
						_getch();
						break;
					}
					case 50:
					{
						B = A;
						cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

						//goto random_copy;
						_getch();
						break;
					}
					}
					getchar();
					break;
				}
				}
				while (key != 27)
				{
					menu_2();
					cout << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
					key = get_key();
					Vector res;
					switch (key)
					{
					case 49:
					{
						res = A + B;
						cout << "A + B = " << res << endl;
						_getch();
						break;
					}
					case 50:
					{
						while (key != 0) {
							cout << "Шо вычитаем?" << endl << "1. A - B" << endl << "2. B - A" << endl;


							key = get_key();
							if (key == 49) { res = A - B; cout << "A - B = " << res << endl; key = 0; }

							else {
								if (key == 50) { res = B - A; cout << "B - A = " << res << endl;  key = 0; }
								else { cout << "тут только два выбора! :)" << endl; }
							}
						}
						_getch();
						break;
					}
					case 51:
					{
						double x = A * B;
						cout << "A * B = " << x << endl;
						_getch();
						break;
					}
					case 52:
					{
						double x;
						cout << "Введите делитель" << endl;
						cin >> x;
						while (key != 0) {
							cout << "Что делим?" << endl << "1. A / x" << endl << "2. B / x" << endl;


							key = get_key();
							if (key == 49) {
								res = A / x; cout << "A / x = " << res << endl; key = 0;
							}

							else {
								if (key == 50) {
									res = B / x; cout << "B / x = " << res << endl; key = 0;
								}
								else { cout << "тут только два выбора! :)" << endl; }
							}
						}
						_getch();
						break;
					}
					case 53:
					{
						double x;
						cout << "Введите множитель" << endl;
						cin >> x;
						while (key != 0) {
							cout << "Что на что умножаем?" << endl << "1. A * x" << endl << "2. x * B" << endl;


							key = get_key();
							if (key == 49) {
								res = A * x; cout << "A * x = " << res << endl; key = 0;
							}

							else {
								if (key == 50) {
									res = x * B; cout << "x * B = " << res << endl; key = 0;
								}
								else { cout << "тут только два выбора! :)" << endl; }
							}
						}
						_getch();
						break;
					}
					case 54:
					{
						double x;
						x = Vector::square(A, B);
						cout << "Площадь = " << x << endl;
						_getch();
						break;
					}
					case 55:
					{
						if (A == B) cout << A << "==" << B << endl;
						else cout << A << "!=" << B << endl;
						_getch();
						break;
					}
					case 56:
					{
					repeat:
						cout << "1. Изменить значения вектора 1" << endl << "2. Изменить значения вектора 2" << endl;
						int x;
						cin >> x;
						if (x == 1)
						{

							cout << "Выберите элемент" << A << endl;
							cin >> x;;
							if (x < A.Get_size())
							{
								double temp = A[x];
								cout << "Введите новое значение" << endl;
								cin >> A[x];
								cout << "предыдущее значение: " << temp << "изменено на " << A[x] << endl;

							}
							else
							{
								cout << "Введеный индекс выходит за рамки вектора" << endl;
								_getch();
								goto repeat;
							}
						}
						else
						{
							if (x == 2)
							{
								cout << "Выберите элемент" << B << endl;
								cin >> x;
								if (x < B.Get_size() + 1)
								{
									double temp = B[x];
									cout << "Введите новое значение" << endl;
									cin >> B[x];
									cout << "предыдущее значение: " << temp << "изменено на " << B[x] << endl;

								}
							}
							else
							{
								cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
								_getch();
								goto repeat;
							}
						}

						_getch();
						break;
					}
					case 57:
					{
						repeat_two:
						cout << "1. Просмотреть значения вектора 1" << endl << "2. Просмотреть значения вектора 2" << endl;
						int x;
						cin >> x;
						if (x == 1)
						{
							cout <<A <<endl << "какое число вы хотите лицезреть??" << endl;
							cin >> x;
							cout << A[x];
							_getch();

						}
						else
						{
							if (x == 2)
							{
								cout << B << endl << "какое число вы хотите лицезреть??" << endl;
								cin >> x;
								cout << B[x];
								_getch();

							}
							else {
								cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
								_getch();
								goto repeat_two;
							}
						}
					}
					case 27:
					{
						system("cls");
						break;
					}
					}
				}
				cout << "Вы действительно хотите выйти?" << endl << "Чтобы продолжить работу с новыми векторами жмякните любую клавишу" << endl << "esc -  выход" << endl;
				key = get_key();

			}
			catch (invalid_argument err)
			{
				cout << "invalid argument: " << err.what() << std::endl;
				_getch();
			}
			catch (out_of_range err)
			{
				cout << "Our of range " << err.what() << std::endl;
				_getch();
			}
			catch (logic_error err)
			{
				cout << "Logic error: " << err.what() << std::endl;
				_getch();
			}
	}
}



 