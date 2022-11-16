#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

class Vector {
private:
	double* data;
	int _size;
	double epsilon;
public:

	Vector() { //����������� �� ����������
		srand(time(0));
		_size = rand() % 3 + 4;
		epsilon = 0,000001;
		data = new double [_size];

		for (size_t i = 0; i < _size; i++)
		{
			data[i] = rand()%300-100;
		}
	}	
	
	Vector(int size, double eps){ // ����������� � ����������
		if (size < 1) throw "������������ ��������";
		_size = size;
		epsilon = abs(eps);
		data = new double [size];
		cout << "������� ��������:\n";
		double a;
		for (size_t i = 0; i < size; i++)
		{
			cout << "A["<< i<< "] = ";
			cin >> a;
			data[i] = a;
		}
	}
	Vector(const Vector& a) { // ����������� �����������
		data = new double [a._size];
		_size = a._size;
		epsilon = a.epsilon;
		for (size_t i = 0; i < a._size; i++)
		{
			data[i] = a.data[i];
		}
	}
	~Vector() {	delete[] data; 	}
	void Vprint() // ����� ������
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << "A["<< i << "] = "<<data[i] ;
		}
		cout << "/n";
	}
	int Get_size() { return _size;}

/*	double operator()(int i) const {
		if (i<0 or i>_size) throw "Invalid index";
		return data[i];
	}

	double& operator()(int i) {
		if (i<0 or i>_size)  throw "Invalid index";
		return data[i];
	}
	*/
	double operator[](int i) const { //������ � ������
		if (i<0 or i>_size) throw "Invalid index";
		return data[i];
	}

	double& operator[](int i) {
		if (i<0 or i>_size)  throw "Invalid index";
		return data[i];	
	}
	friend ostream& operator<<(ostream& os, const Vector& a) //�����
	{
		for (int i = 0; i < a._size; ++i)
		{
			os << left << a.data[i] << ' ';
		}
		return os;
	}
	bool operator==(const Vector& a) {				//��������� ���������
		if (_size != a._size) {
			return false;
		}
		else {
			for (size_t i = 0; i < _size; i++)
			{
				if (fabs(data[i] - a.data[i]) > epsilon) {
					return false;
				}
			}
		}
		return true;
	}
	bool operator!=(const Vector& a) {
		return !(*this == a);
	} 
	Vector operator=(const Vector& a)
	{
		_size = a._size;
		for (size_t i = 0; i < _size; i++)
		{
			data[i] = a.data[i];
		}
		return *this;
	}
	
	Vector& operator+=(const Vector& a) {		//�������� ��������
		if (_size != a._size) throw "����������� ������� �������";
		for (size_t i = 0; i < _size; i++)	
		{
			data[i] += a.data[i];
		}			
		return *this;
	}
	Vector operator+(const Vector& a) const{ // *this + a 
		Vector temp(*this);
		temp += a;
		//cout << temp << endl;
		Vector tmp(temp);
		return tmp;
	}
	Vector& operator-=(const Vector& a) {
		if (_size != a._size) throw "����������� ������� �������";
		for (size_t i = 0; i < _size; i++)
		{
			data[i] -= a.data[i];
		}
		return *this;
	}
	Vector operator-(const Vector& a) const { //��������� ��������
		Vector temp(*this);
		temp -= a;
		//cout << temp << endl;
		return temp;
	}
	Vector& operator*=(const Vector& a) { //*this ��� ��� ���������� ����, � � ���������������� ��� �������� �
		if (_size != a._size) throw "����������� �������� �������";
		for (size_t i = 0; i < _size; i++)
		{
			data[i] *=a.data[i];
		}
		return *this;
	}
	double operator*(const Vector& a) const { // ��������� ��������� ��������
		Vector temp(*this);
		temp *= a;
		//cout << temp << endl;
		double scalar=0;
		for (size_t i = 0; i < _size; i++)
		{
			scalar+= temp.data[i];
		}
		return scalar;
	} 
	Vector& operator*=(const double a) { // ������ �� �����
		for (size_t i = 0; i < _size; i++)
		{
			data[i] *= a;
		}
		return *this;
	}
	Vector operator*(const double a) const { // 
		Vector temp(*this);
		temp *= a;
		//cout << temp << endl;
		return temp;
	}
	 friend Vector operator*(const double b, const Vector& a)  { // ����� �� ������
		Vector temp(a);
		temp *= b;
		//cout << temp << endl;
		return temp;
	 }
	Vector& operator/=(const double a) { //*this ��� ��� ���������� ����, � � ���������������� ��� �������� �
		if (a==0) throw "����������� ��������� �������";
		for (size_t i = 0; i < _size; i++)
		{
			data[i] /= a;
		}
		return *this;
	}
	Vector operator/(const double a) const { // *this + a 
		Vector temp(*this);
		temp /= a;
		//cout << temp << endl;
		return temp;
	}
	static double square(Vector& a, Vector& b)// ���������� ������� ������������ ����� 2 �������
	{
		return 0.5 * sin(a,b) * length(a,b);
	}
	static double sin(Vector a,Vector b) //���������� ������ ��� �������
	{
		if (a._size != b._size) throw "������� �� �����";
		double chislitel = 0; 
		double temp=0,tmp = 0;
		double znamenatel = 1;
		for (size_t i = 0; i < a._size; i++)
		{
			chislitel += (a.data[i] * b.data[i]);
			
		}
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
		temp = sqrt(temp);
		tmp = sqrt(tmp);
		temp = temp * tmp;
		znamenatel = temp;
		return sqrt(1 - pow((chislitel/znamenatel), 2));
	}
	static double length(Vector a,Vector b) //���������� ������������ ���� ��������
	{ 
		double temp = 0;
		double tmp = 0;
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
			temp = sqrt(temp);
			tmp = sqrt(tmp);
			return temp * tmp;
	}
};