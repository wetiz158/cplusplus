#include <iostream> //  "iostream" permite sacar texto y números por el terminal
#include <cmath>    // "cmath" para realizar operaciones matemáticas como potencia (pow) y raiz cuadrada (sqrt)

using namespace std; // Esto es para no tener que poner "std" todo el rato.

int main() // cálculo de pi por el método de Montecarlo
{
    double N ; // NÚMERO DE PUNTOS ALEATORIOS A LANZAR
    int cond = 0;
do
{
        cout << "Ingrese el número de puntos aleatorios: " << endl;
        cin >> N;
        if (N > 0)
        {
         cond = 1;
        }
        else
        {
            cout << "Debe usarse al menos un punto"<<endl;
            
        }
} while (cond == 0); // el ciclo se repetería hasta obteener un valor valido 

    double r = 1; // RADIO DEL CÍRCULO

    srand((unsigned)time(0)); // semilla necesaria para la generacion de números aleatorios

    double x; // Coordenadas de cada punto aleatorio (no almacenadas)
    double y;

    double c = 0; // Número de puntos dentro del círculo (porción)

    //int m=1e7;

    int cota; // veces que se repetirá el proceso

    do
    {
        cout << "Ingrese el número de repeticiones: " << endl;
        cin >> cota;
        if (cota > 0)
        {
            cond = 1;
        }
        else
        {
            cout << "Debe hacerse al menos una repetición" << endl;
            cond = 0;
        }
    } while (cond == 0);

    double pi_ar[cota]; // Array con los valores de pi para cada repetición

    for (int j = 0; j < cota; j++)
    { // Primer bucle. Repetirá Montecarlo "cota" veces.

        for (int i = 0; i < N; i++)
        { // Segundo bucle. En cada vuelta genera un punto

            x = (double)rand() / (double)RAND_MAX; // generamos dos números aleatorios desde 0 a 1
            y = (double)rand() / (double)RAND_MAX; // x e y son las coordenadas de los puntos aleatorios

            x = x * r; //  Para que vayan de 0 a r
            y = y * r;

            if (x * x + y * y < r * r)
            {        // Comprobar si el punto esta dentro del circulo.
                c++; // aumenta uno si cae dentro
            }
        }

        pi_ar[j] = 4 * c / N; // Cálculo de pi y almacenamiento en un array
        c = 0;                // inicializar c para repetir
        }

        // A partir de aqui es para obtener el error en el cálculo
        // calcularemos la media y la desviacion tipica

        double pi = 0;
        double error = 0;

        for (int j = 0; j < cota; j++)
        {
            pi = pi_ar[j] / cota + pi; // media de todos los pi calculados
        }

        for (int j = 0; j < cota; j++)
        {
            error = error + pow(pi - pi_ar[j], 2) / cota; // Calculo la desviación tipica de los pi calculados
        }

        error = sqrt(error); // raiz cuadrada del error -- desviacion

        cout.precision(15); // numero de digitos que quiero que se expulsen por pantalla.

        cout << endl
             << "Pi es igual a " << pi << endl;
        cout << endl
             << "Pi se encuentra entre " << pi - error << " y " << pi + error << endl;
        return 0;
}
