// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#define	  stop {bool tmp{}; tmp = tmp;};

#include "myString.h"

int main()
{
//////////////////////////////////////////////////////////////////////



	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

	{
		MyString s1("AAA"), s2;
		s2=s1;
		s1="CCC";
		s2= MyString("tmp");
		s1=s1;
		stop


	}


/*
	//2.Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//2b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора

	Point pt1(1,1);
	Point pt2(2,2);
//	pt2+=pt1;
//  pt2+=1;
	Point pt3(3,3);
//  pt2+=pt1+=pt3;
	stop
*/
/*
	//Задание 2c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	Point pt1(1,1);
	Point pt2(2,2);
	Point pt3;

//	pt3 = pt1 + 5;
//	pt3 = 2 + pt1;
//	pt3 = pt1 + pt2;

//	pt3 = pt1 - 5;
//	pt3 = pt1 - pt2;
	stop

	//Задание 1d. Перегрузите унарный оператор +/- 
//	pt3 = -pt1;
//	pt3 = +pt1;

*/

/*
	//Задание 2d. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	cout<<s<<endl;


	stop
*/
/*//Задание 2e*. Перегрузите операторы + и += для класса MyString таким образом,
  //чтобы происходила конкатенация строк
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	s4 += s1; 
	stop

*/
	//Задание 3. Разработать "базу данных" о сотрудниках посредством ассоциативного
	//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
	//в базе быть не может), а данными: пол, возраст, должность, зарплата...
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках
	//Например:
/*
		BD bd;	//создание пустой базы
		bd["Ivanov"] = Data(30,MALE,<остальные данные>);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		std::cout<<bd;	//вывод информации обо всех сотрудниках

*/
	
	return 0;
}//endmain

