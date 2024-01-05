#include <iostream>
#include <stdio.h>
// #include <conio.h>

using namespace std;
void Kali2 (int& X) {
X = X * 2;
cout<<"Nilai di dalam fungsi :"<<X<<endl;
}

int main() {
int Bilangan;
cout<<"Masukkan bilangan bulat :";
cin>>Bilangan;
cout<<endl;
cout<<"Nilai awal : "<<Bilangan<<endl;
Kali2(Bilangan);
cout<<""<<Bilangan<<endl;
return 0;
}