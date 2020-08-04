#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n = 0; // dimension de los vectores
    cout << "Introduzca la dimensión del vector" << endl; // la primera línea del archivo es la dimension
    cin >> n;

    int u[n];
    cout << "los términos serán u[i] = i + 2" << endl;

    for (int i = 0; i < n; i++) // en la segunda linea se escribe el vector u con los términos separados por un espacio
    {
        u[i] = i + 2;
        cout << "u["<< i << "] = " << u[i] << endl;
    }

    int v[n];
    cout << "los términos serán v[i] = i - 2" << endl;

    for (int i = 0; i < n; i++) // en la tercera linea se escribe el vector v con los términos separados por un espacio
    {
        v[i] = i - 2;
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    ofstream escribir;
    escribir.open("vector.txt"); //Apertura del fichero
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
            escribir << u[i] << " ";
        }
        escribir << endl;
        for (int i = 0; i < n; i++)
        {
        escribir << v[i] << " ";
        }
         escribir.close(); //Cerramos fichero el fichero
    }
}