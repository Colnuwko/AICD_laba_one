#include <conio.h>
#include <string>
#include "Header1.h"
void menu()
{ 
	system("cls");
	cout << "������� ��������� ������"<<endl;
	cout << "������� ������ � �����������"<<endl;
	cout << "������� ��� ���������� �������"<<endl;
	

}
void menu_2()
{
	system("cls");
	cout << "1. ������� �������"<<endl;
	cout << "2. ������� �������" << endl;
	cout << "3. ����� ��������� ������������" << endl;
	cout << "4. ��������� ������ �� �����" << endl;
	cout << "5. �������� ������ �� �����" << endl;
	cout << "6. ��������� ������� ������������" << endl;
	cout << "7. �������� �������" << endl;
	cout << "esc -  �����" << endl;
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
	int key=0;
	while (key != 27)
	{
		menu();
		key = get_key();
		switch (key)
		{
		case 49:
		{
			Vector b;
			B = b;
			cout << "���� ��������� �������" <<endl <<"������ �: " << A << endl <<"������ �: " << B << endl;
			
			//goto random;
			_getch();
			break;
		}
		case 50:
		{
			cout << "������� ��������� ���� �������" << endl << "������� ����������� ��������" << endl;
			int size;
			double epsilon;
			cin >> size;
			cout << "������������, � ������ ������� ����� ���������"<< endl;
			cin >> epsilon;
			cout << "����� ����� ��������� �������" << endl;
			Vector a(size, epsilon);
			cout << endl << "������� ��������� ������" << endl;
			Vector b(size, epsilon);
			A = a;
			B = b;
			cout << "������, �� ���������� � ����" << endl<<"�� ������ ��������� ����� ��� �������� :)" << endl << "������ �: " << A << endl << "������ �: " << B << endl;
			
			//goto Par;
			_getch();
			break;
		}
		case 51:
		{
			cout << "1. ������� ��� ���� ����������� �������" << endl << "2. ������� ��� ���������� � ��������� �������" << endl;
			key = get_key();
			switch (key)
			{
			case 49:
			{
				cout << "������� ��������� ���� �������" << endl << "������� ����������� ��������" << endl;
				cin >> size;
				cout << "������������, � ������ ������� ����� ���������" << endl;
				cin >> epsilon;
				cout << "����� ����� ��������� �������" << endl;
				Vector a(size, epsilon);
				A = a;
				B = a;
				cout << "������, �� ���������� � ����" << endl << "�� ������ ��������� ����� ��� �������� :)" << endl << "������ �: " << A << endl << "������ �: " << B << endl;
				
				//goto My_copy;
				_getch();
				break;
			}
			case 50:
			{
				 B = A;
				cout << "���� ��������� �������" << endl << "������ �: " << A << endl << "������ �: " << B << endl;
				
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
			cout << "������ �: " << A << endl << "������ �: " << B << endl;
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
				while (key != 0){
				cout<<"�� ��������?"<<endl << "1. A - B" << endl << "2. B - A" << endl;
				
				
					key = get_key();
					if (key == 49) { res = A - B; cout << "A - B = " << res << endl; key = 0; }

					else {
						if (key == 50) { res = B - A; cout << "B - A = " << res << endl;  key = 0; }
						else { cout << "��� ������ ��� ������! :)"<< endl; }
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
				cout << "������� ��������"<< endl;
				cin >> x;
				while (key != 0){
				cout << "��� �����?" << endl << "1. A / x" << endl << "2. B / x" << endl;
				
				
					key = get_key();
					if (key == 49) { res = A / x; cout << "A / x = " << res << endl; key = 0;
					}

					else {
						if (key == 50) { res = B / x; cout << "B / x = " << res << endl; key = 0;
						}
						else { cout << "��� ������ ��� ������! :)" << endl;  }
					}
				}
				_getch();
				break;
			}
			case 53:
			{	
				double x;
				cout << "������� ���������" << endl;
				cin >> x;
				while (key != 0){
				cout << "��� �� ��� ��������?" << endl << "1. A * x" << endl << "2. x * B" << endl;
				
				
					key = get_key();
					if (key == 49) { res = A * x; cout << "A * x = " << res << endl; key = 0;
					}

					else {
						if (key == 50) { res = x * B; cout << "x * B = " << res << endl; key = 0;
						}
						else { cout << "��� ������ ��� ������! :)" << endl; }
					}
				}
				_getch();
				break;
			}
			case 54:
			{
				double x;
				x = Vector::square(A, B);
				cout << "������� = " << x << endl;
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
			case 27:
			{
				system("cls");
				break;
			}
			}
		}
		cout << "�� ������������� ������ �����?"<<endl <<"����� ���������� ������ � ������ ��������� �������� ����� �������"<<endl<<"esc -  �����"<<endl;
		key = get_key();
	}

}



 