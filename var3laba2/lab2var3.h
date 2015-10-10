#include <stdio.h>
#include <iostream>
#include <cmath>

int getNum(int* n, char* info);

class CDecartovList 
{
private:
	int n;		//декартов лист  x^3+y^3=nxy
public:
	CDecartovList(): n(1) {};
	CDecartovList(int _n) {n = _n; };
	//int GetPhi(double* phi, char* info);
	int getNum(int *n ,char* info);
	double FindChord();
	double FindDistance();
	double FindRa();
	double FindRo();
	double FindS();
	double FindAcross();
	double FindDO();

	~CDecartovList () {};	//деструктор
};
