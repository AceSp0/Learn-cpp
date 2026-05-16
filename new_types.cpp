#include <iostream>

//bool - true/false (1 байт)
//wchar_t - расширенный char (Windows - 2 байта, Linux - 4 байта)
//char8_t - char для символов кодировки UTF-8 (1 байт)
//char16_t - char для символов кодировки UTF-16 (2 байта)
//char32_t - char для символов кодировки UTF-32 (4 байта)


//P.s в языке C++ символы (т.е. char a = 'c' - c-это символ) представляются именно в виде симовлов, а не в виде int, как в языке C

using std::cout;
using std::endl;
int main(){
	bool fl_print = false;
	fl_print = true;

	wchar_t wch;

	wch = L'Я'; //(буквы русского языка - 2 байта в  UTF-8 (но зависит от кодировки текущего файла, т.е может быть и не UTF-8), английском - 1 байт)
	cout << wch << endl;

	if (fl_print){
		cout <<" HI! " << endl;
	}
	cout << fl_print << endl;
	
	
	char str[] = "Привет, Мир!";
	cout << str << endl;
	cout << "Размер str: " << sizeof(str) << endl; //Вес больше количества символов, так как символы русского алфавита занимают 2 байта
	
	char ch = 'd';
	ch = str[0];
	cout << ch << endl; //Выведет неизвестный символ, так как русская буква 'П' занимает 2 байта, char рассчитан под 1 байт
	
	wchar_t str2[] = L"Привет, Мир!";
	wchar_t test = str[0];
	cout << test << endl;


	return 0;
}
