#include<iostream>
#include<string>
using namespace std;

struct persona{
    string nombre[100];
    int DNI;
    int EDAD;
};

int main(){
    int n;
    cout<<"Ingrese la cantidad de personas: "; cin>>n;
    persona person[n];
    for(int i=0;i<n;i++){
        cout<<"Ingrese la persona "<<i+1<<endl;
        cin.getline(person.nombre,'\n');
    }

    return 0;
}
