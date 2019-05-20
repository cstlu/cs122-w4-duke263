#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
using namespace std;
class dathuc
{
private:
	int n;
	double *hesos;
public:
	dathuc();
	dathuc(int);
	dathuc(int,double[]);
	//setters
	void setN(int);
	void sethesos(double[]);
	bool setheso(int,double);
	//getters
	int getN()const;
	double getsohang(int)const;
	double* getdathuc()const;
	//operators
	dathuc operator +(const dathuc &);
	dathuc operator -(const dathuc &);
	dathuc operator *(const dathuc &);
	dathuc operator /(const dathuc &);
	double operator [](int)const;
	//methos
	void display()const;
	~dathuc();
};
#endif
