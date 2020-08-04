#include <iostream>
#include <cmath>
using namespace std;

//Definimos la funcion que vamos a utilizar
double func(double x)
{
    double f1 = exp(-x * x);
    double f2 = x;
    return f1 - f2;
}

//Definimos la derivada de la función
double dfunc(double x)
{
    return -2 * x * exp(-x * x) - 1;
}

// Definimos el método de dicotomia o biseccion
double dicotomia(double a, double b, int k, double tol)
{
    // a,b = Cota inferior y superior, respectivamente, del intervalo de estudio
    // k = Numero de iteraciones
    // tol = Tolerancia permitida

    double fa = func(a);
    double fb = func(b);

    if (fa * fb > 0)
    {
        cout << "ERROR! La funcion tiene que cambiar de signo en el intervalo" << endl;
    }

    int i = 0; //Definimos e inicializamos el contador para el bucle
    double c, fc;

    while (i < k)
    {
        c = (a + b) / 2; //Punto medio del intervalo
        fc = func(c);    //Valor de la funcion en el punto medio

        if (abs(b - a < tol))
        {
            return c;
        }
        if (fa * fc <= 0)
        {
            b = c;
            fb = fc;
        }
        if (fc * fb < 0)
        {
            a = c;
            fa = fc;
        }
        i += 1;
    }
    return c;
}

double newton(double x0, int k, double tol)
{
    // x0 = aproximacion inicial
    // k = Numero de iteraciones
    // tol = Tolerancia permitida

    int i = 0;
    double xf;

    while (i < k)
    {
        xf = x0 - func(x0) / dfunc(x0); //Formula de Newton-Raphson

        if (abs(xf - x0 < tol))
        {
            return xf;
        }
        else
        {
            x0 = xf;
        }
        i += 1;
    }
    return xf;
}

int main()
{

    //Definimos variables
    double a, b, x0, tol;
    int k;

    //Pedimos datos por teclado
    cout << "Ingrese cota inferior de intervalo (para método dicotomia) " << endl;
    cin >> a;
    cout << "Ingrese cota superior del intervalo (para método dicotomia) " << endl;
    cin >> b;
    cout << "Ingrese numero de iteraciones " << endl;
    cin >> k;
    cout << "Ingrese tolerancia " << endl;
    cin >> tol;
    cout << "Ingrese aproximación inicial (para metodo newton) " << endl;
    cin >> x0;

    //Mostramos los resultados por pantalla
    cout << "El resultado obtenido con dicotomia es: " << dicotomia(a, b, k, tol) << endl; // Llamamos a la funcion dicotomia
    cout << "El resultado obtenido con Newton es: " << newton(x0, k, tol) << endl;         // Llamamos a la funcion newton

    //El resultado tiene que ser 0.6529186404192
}