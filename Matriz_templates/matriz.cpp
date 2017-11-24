#include<iostream>
using namespace std;
template <typename t>
class matriz{//es el objeto matriz
	public:
	t ** M;
	int f,c;
	matriz(int a=3,int b=3){
		f=a;c=b;
		M=new t* [f];
		for(int i=0;i<f;i++)
			*(M+i)=new t [c];
	}
	~matriz(){
		for(int i=0;i<f;i++)
			delete [] *(M+i);
	       	delete [] M;
	}
};
matriz<int>operator+(matriz<int>& a,matriz<int>& b){//suma de matrices de numeros
	matriz <int>tmp(a.f,b.c);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			tmp.M[i][j]=a.M[i][j]+b.M[i][j];
	return tmp;
}
matriz<char>operator+(matriz<char> &a,matriz<int>& b){//suma de una matriz de caracteres y una de numeros
	matriz <char>tmp(a.f,b.f);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			tmp.M[i][j]=a.M[i][j]+b.M[i][j];
	return tmp;
}
matriz<int>operator<(matriz<int>& a,matriz<int>& b){//compracion menor entre matrices de caracteres
	matriz <int>tmp(a.f,b.c);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			if(a.M[i][j]<b.M[i][j]){
				tmp.M[i][j]=a.M[i][j];
			}
			else{
				tmp.M[i][j]=b.M[i][j];
			}
	return tmp;
}
matriz<int>operator>(matriz<int>& a,matriz<int>& b){//comparacion mayor entre matrices de caracteres
	matriz <int>tmp(a.f,b.c);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			if(a.M[i][j]>b.M[i][j]){
				tmp.M[i][j]=a.M[i][j];
			}
			else{
				tmp.M[i][j]=b.M[i][j];
			}
	return tmp;
}
matriz<char>operator<(matriz<char>& a,matriz<char>& b){//comparacion menor entre matrices de caracteres
	matriz <char>tmp(a.f,b.c);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			if(a.M[i][j]<b.M[i][j]){
				tmp.M[i][j]=a.M[i][j];
			}
			else{
				tmp.M[i][j]=b.M[i][j];
			}
	return tmp;
}
matriz<char>operator>(matriz<char>& a,matriz<char>& b){//comparacion mayor entre matrices de caracteres
	matriz <char>tmp(a.f,b.c);
	for(int i=0;i<a.f;i++)
		for(int j=0;j<a.c;j++)
			if(a.M[i][j]>b.M[i][j]){
				tmp.M[i][j]=a.M[i][j];
			}
			else{
				tmp.M[i][j]=b.M[i][j];
			}
	return tmp;
}

ostream& operator<<(ostream &o,matriz<int> &a){//impresion de matriz de numeros
	for(int i=0;i<a.f;i++){
		for(int j=0;j<a.c;j++){
			o<<a.M[i][j];
			if(j==a.c-1)o<<'\n';
			else o<<' ';
		}
	}
	o<<'\n';
	return o;
}
ostream& operator<<(ostream &o,matriz<char> &a){//impresion de matriz de caracteres
	for(int i=0;i<a.f;i++){
		for(int j=0;j<a.c;j++){
			o<<a.M[i][j];
			if(j==a.c-1)o<<'\n';
			else o<<' ';
		}
	}
	o<<'\n';
	return o;
}
int main(){
	int a,b;
	cout<<"Ingrese las dimensiones de las matrices"<<endl;
	cin>>a>>b;
	matriz <int>num1(a,b);
	matriz <int>num2(a,b);
	cout<<"Ingrese las matrices de numeros"<<endl;
	for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>num1.M[i][j];
	for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>num2.M[i][j];
	matriz <char>car1(a,b);
	matriz <char>car2(a,b);
	cout<<"Ingrese las matrices de caracteres"<<endl;
	for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>car1.M[i][j];
	for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>car2.M[i][j];
	cout<<endl;;
	matriz<int> r1=num1<num2;
	cout<<"La matriz de la comparacion de matrices en menor en numeros es\n"<<r1<<endl;
	matriz<int> r2=num1>num2;
	cout<<"La matriz de la comparacion de matrices en mayor en numeros es\n"<<r2<<endl;
	matriz<char> r3=car1<car2;
	cout<<"La matriz de la comparacion de matrices en menor en caracteres es\n"<<r3<<endl;
	matriz<char> r4=car1>car2;
	cout<<"La matriz de la comparacion de matrices en mayor en caracteres es\n"<<r4<<endl;
	matriz<int> r5=num1+num2;
	cout<<"La matriz de la suma de las matrices de numeros es \n"<<r5;
	matriz<char> r6=car1+num1;
	cout<<"La suma de la primeras matrices de numeros y caracteres es\n"<<r6;
	matriz<char> r7=car2+num2;
	cout<<"La suma de las segundas matrices de numeros y caracteres es\n"<<r7;
	return 0;
}
