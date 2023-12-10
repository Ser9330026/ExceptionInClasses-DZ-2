#include "Exception.h"
#include <iostream>
#include <string>
#include <exception>

class Triangle
{
private:
	double side1, side2, side3;
	double angle1, angle2, angle3;
public:
	Triangle() : side1(), side2(), side3(), angle1(), angle2(), angle3() {};
	Triangle(double side1, double side2, double side3,
		double angle1, double angle2, double angle3)
	{
		if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
			throw MyException("ОШИБКА!!! Не достает сторон");
		}
		if (angle1 + angle2 + angle3 != 180) {
			throw MyException("ОШИБКА!!! Сумма углов не равна 180 градусов");
		}
		this->side1 = side1;
		this->side2 = side2;
		this->side3 = side3;
		this->angle1 = angle1;
		this->angle2 = angle2;
		this->angle3 = angle3;
	}
	
	void printTriangle() {
		std::cout << "Введите стороны треугольника: ";
		std::cin >> side1 >> side2 >> side3;
		std::cout << "Введите величины углов треугольника: ";
		std::cin >> angle1 >> angle2 >> angle3;
	}	
};

int main() {
	setlocale(LC_ALL, "rus");
	
	try
	{
		Triangle tr1;
		tr1.printTriangle();
	}
	catch(const MyException& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}