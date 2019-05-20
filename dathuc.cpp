#include "dathuc.h"
dathuc::dathuc()
{
	this->n=0;
	this->hesos=NULL;
}
dathuc::dathuc(int n)
{
	this->n=n+1;
	this->hesos=new double[n+1]();
}
dathuc::dathuc(int n,double hesos[])
{
	this->n=n+1;
	this->hesos=hesos;
}
//setters
void dathuc::setN(int n)
{
	this->n=n+1;
	delete[] this->hesos;
	this->hesos=new double [n+1]();
}
void dathuc::sethesos(double a[])
{
	this->hesos=a;
}
bool dathuc::setheso(int i,double value)
{

	this->hesos[i]=value;
	return true;
}
//getters
int dathuc::getN()const
{
	return this->n;
}
double dathuc::getsohang(int i)const
{
	return this->hesos[i];
}
double* dathuc::getdathuc()const
{
	return this->hesos;
}
//operators
dathuc dathuc::operator +(const dathuc &b)
{
	int maxsize=this->n > b.getN() ? this->n: b.getN();
	double *kq=new double [maxsize]();
	for(int i=0;i<maxsize;i++)
	{
		if(i<this->n && i<b.getN())
		{
			kq[i]=this->hesos[i]+b[i];
		}
		else if(i>this->n)
		{
			kq[i]=b[i];
		}
		else
		{
			kq[i]=this->hesos[i];
		}
	}
	return dathuc(maxsize-1,kq);
}
dathuc dathuc::operator -(const dathuc &b)
{
	int maxsize=this->n >b.getN() ? this->n : b.getN();
	double *kq=new double [maxsize]();
	for(int i=0;i<maxsize;i++)
	{
		if(i<this->n && i<b.getN())
		{
			kq[i]=this->hesos[i]-b[i];
		}
		else if(i>this->n)
		{
			kq[i]=b[i];
		}
		else
		{
			kq[i]=this->hesos[i];
		}
	}
	return dathuc(maxsize-1,kq);
}
dathuc dathuc::operator *(const dathuc &b)
{
	int maxsize=this->n > b.getN() ? this->n : b.getN();
	double *kq=new double[maxsize]();
	for(int i=0;i<maxsize;i++)
	{
		if(i<this->n && i<b.getN())
		{
			kq[i]=this->hesos[i]*b[i];
		}
		else if(i>this->n)
		{
			kq[i]=b[i];
		}
		else
		{
			kq[i]=this->hesos[i];
		}
	}
	return dathuc(maxsize-1,kq);
}
dathuc dathuc::operator /(const dathuc &b)
{
	int maxsize=this->n > b.getN() ? this->n : b.getN();
	double *kq=new double[maxsize]();
	for(int i=0;i<maxsize;i++)
	{
		if(i<this-> n && i<b.getN())
		{
			kq[i]=this->hesos[i]/b[i];
		}
		else if(i<this->n)
		{
			kq[i]=b[i];
		}
		else
		{
			kq[i]=this->hesos[i];
		}
	}
	return dathuc(maxsize-1,kq);
}
double dathuc::operator [](int i)const
{
	return this->hesos[i];
}
//methos
void dathuc::display()const
{
	for(int i=n-1;i>=0;i--)
	{
		if(this->hesos[i]!=0)
		{
			cout<<this->hesos[i]<<".x"<<i;
			if(i==0)
				break;
			else
				cout<<"+";
		}
	}
	cout<<endl;
}
dathuc::~dathuc()
{}
int main()
{
	dathuc a(5);
	a.setheso(0,1);
	a.setheso(1,4);
	a.setheso(2,3);
	a.setheso(5,2);
	a.display();
	dathuc b(3);
	cout <<"+"<< endl;
	b.setheso(0, 3);
	b.setheso(1, 3);
	b.setheso(3, 3);
	b.display();
	cout << "kq:=";
	dathuc kq = a + b;
	dathuc kq2 = a - b;
	kq.display();
	kq2.display();
	return 0;
}