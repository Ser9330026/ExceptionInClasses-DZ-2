#include <exception>
#include <string>
#include <cstring>

class MyException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Ошибка создания геометрической фигуры";
	}
};