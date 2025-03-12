#include <iostream>

using namespace std;

int main()
{
	float a,c;
	
	cout<<"Enter a: ";
		cin>>a;
	
	cout<<"Enter c: ";
		cin>>c;
	
	float *p;
	
		p=&a;
	
		*p*=3;
	
		*p+=c;
	
		p=&c;
	
	cout<<"a adress: "<<&a<<endl;
	cout<<"c adress: "<<&c<<endl;
	cout<<"p adress: "<<&p<<endl;
	
	cout<<"a value: "<<a<<endl;
	cout<<"c value: "<<c<<endl;
	cout<<"pointer value: "<<*p;
	
		return 0;
	
}
