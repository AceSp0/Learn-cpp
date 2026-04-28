#include <iostream>

//Всë, что ниже - это глобальное пространство имëн


void foo(){
	std::cout << "function foo() " << std::endl;
}


int global_a = 5; //Глобальная переменная


struct point{
	double x, y;
};






// Создадим свое пространство имен: namespace имя_пространства{ ...... }

namespace firstSpace {
void foo(){ //Да, обычно пишут без отступа
	std::cout << "function foo() from firstSpace" <<std::endl;
}
}


//Давайте добавим нашу структуру point в пространство имен firstSpace. Для этого еще раз пропишем наше пространство имен, но уже с другим элементом. На программном уровне это будет единое пространство имен.

namespace firstSpace {
struct point {
	double x, y;
};
}

//P.s это можно было сделать и единым целым, не прописывая так второй раз, а просто добавив к тому, где мы изначально задали пространство firstSpace







//И создадим еще одно пространство имен

namespace secondSpace {
void foo(){
	std::cout << "function foo() from secondSpace " << std::endl;
}
}






//Вложенные пространства имен (то есть пространство в пространстве)

namespace firstSpace {

namespace params {
int digit = 15; 
}
}






int main(){
	
//Символ четвероточия :: - символ раскрытия области видимости. Если слева от него не прописано никакое имя, то, значит, это из глобальной области видимости.
//А если слева что-то прописано, по типу так: std::cout - слева прописано std, значит, это уже не глобальное пространство имен, а пространство имен std

	::point pt {}; //Прописали тип структуры point и создали еë объект
	::foo(); //ВЫзвали функцию из глобального пространства имен
	
	std::cout << ::global_a << std::endl;

	int global_a = 255;

	std::cout << "Глобальная переменная: " << ::global_a << std::endl;
	std::cout << "Локальная переменная: " << global_a << std::endl;

	
	//Выходит, что, прописывая std::cout, мы имеем в виду, что мы обращаемся к объекту cout класса ostream, который лежит в пространстве имен std
	
	
	firstSpace::foo();
	secondSpace::foo();

	firstSpace::point pt1 {}; //Обратились к структуре point, но которая уже не из глобального пространства имен, а из firstSpace
	


	//Хотим обратитьтся к переменной digit, которая лежит в firstSpace в params
	
	std::cout << "Число из вложенного пространства: " << firstSpace::params::digit << std::endl;
	
	//Если мы перед ключевым словом namespace пространства имен params пропишем inline, то сможем обращатиться к переменной digit просто вот так: firstSpace::digit
	return 0;
}





