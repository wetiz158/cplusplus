#include <iostream> //  "iostream" permite sacar texto y números por el terminal
#include <fstream> // para trabajar con ficheros

using namespace std; // Esto es para no tener que poner "std" todo el rato.

/*
 ifstream u_entr flujo entrada
 ofstream u_sal flujo salida
 u_entr.open() para abrirlo
 u_entr.close() para cerrarlo


int p_escalar ( int i , int u[ ] , int v[ ] )
{
     int  w = 0 ;
       w += u[i] * v[i] ;
   return w ;
}
*/

int main()
{
    ifstream leer;

    //  string nombre_archivo;
    // cout << "Introduzca el nombre del archivo que desea abrir : " << endl;
    // cin >> nombre_archivo;
    //  leer.open(nombre_archivo.c_str()); // abre el archivo

    leer.open("vector.txt"); // Apertura del fichero

    int n, w; // n sera la dimension y w el producto escalar

    if (leer.bad())
    {
        cout << "Incapaz de crear o abrir el fichero" << endl;
    }
    else
    {
       // while (!leer.eof())
       // {
            leer >> n; // lee la dimensión
            cout << "n = " << n << endl;

        // int u[n],
        // int v[n];

            double * u;
            double * v;
            u = new double[n];
            v = new double[n];

            for (int i = 0; i < n; i++) // lee u, despues v y manda ambos a la funcion del producto escalar
            {
                //   leer >> u[i]; // lee el primer vector y lo almacena en u
                leer >> u[i];
                  cout << "u[" << i << "] = " << u[i]<< endl;
            }
            for (int i = 0; i < n; i++) // lee u, despues v y manda ambos a la funcion del producto escalar
            {
             //   leer >> v[i]; // lee el segundo vector y lo almacena en v
             leer >> v[i];
             
              cout << "v[" << i << "] = " << v[i]<< endl;
            }

            for (int i = 0; i < n; i++) // lee u, despues v y manda ambos a la funcion del producto escalar
            {
                w += u[i] * v[i]; // ten que sair -7
            }
            cout << "Producto escalar = " << w << endl;
            delete [] u;
            delete [] v;
leer.close();
 // }  
    }
}
