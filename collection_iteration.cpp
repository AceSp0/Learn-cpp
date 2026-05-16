#include <iostream>

using std::cout;
using std::endl;

int main(){
	//Будем перебирать коллекцию: for (<тип элемента массива> <имя переменной>: <имя перебираемой коллекции>
	
	char msg[] = "I like C++ language";

	for (char x : msg)
		cout << x << " "; //Выведем элемеенты массива через пробелы


	return 0;
}
