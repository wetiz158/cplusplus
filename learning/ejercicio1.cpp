#include <iostream> // Cargo librerías: "iostream" permite sacar texto y números por el terminal

using namespace std; // Esto es para no tener que poner "std" todo el rato.

int factorial(int n,int fact) // para definir el factorial de k. 
{
     
  //  if(n < 0)
   //     fact = 0;
        if (n == 0)
        fact = 1;
        else{
          //  for (i = 1; i <= n; i++){
           //     fact = fact * i;
          cout << "factorial " << fact << endl;
          fact = fact * n;
          // }
          cout << "fact  de " << n << " = " << fact << endl;
        }
        return fact;
}

int potencia(int exponente) //para definir la potencia de 3^y
{
    int resultado = 1;
    for (int i = 0; i < exponente; ++i)
    {
        resultado *= 3;
    }
    return resultado;
}

int main()
{
// Un bucle para el cálculo de los términos de la serie y otro anidado para devolver el factorial
double Sn = 0; // suma de los términos de la serie
double an = 0; // términos de la serie
int n = 0;     // limite de terminos del sumatorio desde 0
cout << "Ingrese el número (entero!) de términos (> 0): " << endl;
cin >> n;
if (n > 0)
{
    int fact = 1;
    for (int i = 0; i <= n - 1; i++) // bucle para el cálculo de los an
    {
        fact = factorial(i, fact);
        double bn = potencia(i);
        double cn = 3 + fact;
        an = bn / cn;
    // cout << endl
    //  << "El término " << i << " es " << an << endl;
        Sn = Sn + an; // Sumatorio de los términos k primeros términos de la serie
    }
 cout << endl
        << "La suma de los " << n << " primeros términos de la sucesión es " << Sn << endl;
}
else {
cout << "Número de términos no valido" << endl;
}
}
