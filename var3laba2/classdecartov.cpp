#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

#include "lab2var3.h"

//декартов лист  x^3+y^3=nxy
//n = 3a
//класс, определ€ющий пр€мую декартов лист

//функци€ получает число
int CDecartovList::getNum(int* a, char* info)
{
	int data;
	std::cout<<info;
	std::cin>>data;
	if (!std::cin.good())
	{
		std::cout<<"error"<<std::endl;
		std::cin.clear();
		return -1;
	}
	*a = data;
	return 0;
}

//фунци€ получает phi преобразовывает в радианы
int GetPhi(double* phi, char* info)
{
	int data;
	std::cout<<info;
	std::cin>>data;
	*phi = ((data%360)*3.14)/360.0;
	if (!std::cin.good())
	{
		std::cout<<"error"<<std::endl;
		std::cin.clear();
		return -1;
	}
	return 0;	
}

//функци€ ищет большую хорду(сторону квадрата)
double CDecartovList::FindChord()
{
	return n/((2)^(1/2));
}

//функци€ возвращает рассто€ние до центра в пол€рной системе координат в зависимости от угла
double CDecartovList::FindDistance ()
{
	double phi;	// угол дл€ пол€рной системы координат
	GetPhi(&phi,"write phi: ");
	return ((n/3.0) * cos(phi)*sin(phi)) / ( pow(cos(phi),3) + pow (sin(phi),3));
}

//функци€ возвращает радиус кривизны в вершиине узла
double CDecartovList::FindRa()
{
	return n/(8*((2)^(1/2)));
}

//функци€ возвращает радиус кривизны в узловой точке
double CDecartovList::FindRo()
{
	return n/2.0;
}

//функци€ возвращает площадь петли листа
double CDecartovList::FindS()
{
	return  (n^2)/6;
}

//функци€ возвращает длину наибольшего поперечника
double CDecartovList::FindAcross()
{
	return n * ((3^(1/2)) - (3/2))^(1/2);
}

//функци€ возвращает рассто€ние от узла до наибольшего поперечника
double CDecartovList::FindDO()
{
	return n/(6^(1/2));
}

void print_menu ()
{
	cout<<"Command list:"<<std::endl;
	cout<<"1 - default figure (n=1)"<<std::endl;
	cout<<"2 - set values"<<std::endl;
	cout<<"3 - FindChord"<<std::endl;
	cout<<"4 - FindDistance"<<std::endl;
	cout<<"5 - FindRa"<<std::endl;
	cout<<"6 - FindRo"<<std::endl;
	cout<<"7 - FindS"<<std::endl;
	cout<<"8 - FindAcross"<<std::endl;
	cout<<"9 - FindDO"<<std::endl;
	cout<<"0 - quit"<<std::endl;

}

int main()
{
    CDecartovList Dlist; // объ€вление объекта
	print_menu ();
	while (1)
	{
		// получаем и выполн€ем команду
		int res = 0;
		int menu = 0;
		res = Dlist.getNum(&menu,"");
		if (res < 0)
			print_menu ();
		else if (menu == 0)
			break;
		else if (menu == 1)			
			Dlist = CDecartovList::CDecartovList();
		else if (menu == 2)
		{ 
			int n = 0;
			Dlist.getNum(&n,"write n: ");
			Dlist = CDecartovList::CDecartovList(n);
		}
		else if (menu == 3)
			cout<<"Chord:"<<Dlist.FindChord()<<endl;
		else if (menu == 4)
			cout<<"Distance:"<<Dlist.FindDistance()<<endl;
		else if (menu == 5)
			cout<<"Ra:"<<Dlist.FindRa()<<endl;
		else if (menu == 6)
			cout<<"Ro:"<<Dlist.FindRo()<<endl;
		else if (menu == 7)
			cout<<"S:"<<Dlist.FindS()<<endl;
		else if (menu == 8)
			cout<<"Across:"<<Dlist.FindAcross()<<endl;
		else if (menu == 9)
			cout<<Dlist.FindDO()<<endl;
		else
			print_menu ();
		if (res < 0)
			break;
	}
    system("pause");
    return 0;
}