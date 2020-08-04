#include <iostream>
#include <fstream>

using namespace std;

int main(){
int n = 0;                                            // dimension de los vectores
cout << "Introduzca la dimensión del vector" << endl; // la primera línea del archivo es la dimension
cin >> n;

int v[n];
cout << "los términos serán v[i] = i - 2" << endl;

for (int i = 0; i < n; i++) // en la segunda linea se escribe el vector con los términos separados por un espacio
{
    v[i] = i - 2;

    

    cout << "v[" << i << "] = " << v[i] << endl;
}

cout << "v = ";
for (int i = 0; i < n; i++)
{
    cout << v[i] << " ";
}
cout << endl;

ofstream escribir;
escribir.open("vector_v.txt"); //Apertura del fichero
if (escribir.bad())
{
    cout << "Incapaz de crear o abrir el fichero" << endl;
}
else
{
    // Escritura en el fichero
    escribir << n << endl;
    for (int i = 0; i < n; i++)
    {
        escribir << v[i] << " ";
    }

    escribir.close(); //Cerramos fichero el fichero
}
}