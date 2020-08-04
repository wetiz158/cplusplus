#include <iostream> //  "iostream" permite sacar texto y números por el terminal
#include <cmath>
using namespace std; // Esto es para no tener que poner "std" todo el rato.

float input_x()
{
    float x;
    cout << "Ingrese primer término" << endl;
    cin >> x;
    return x;
}

float input_y()
{
        float y;
        cout << "Ingrese segundo término" << endl;
        cin >> y;
        return y;
}

void final(int error, float resultado)
{
    if (error)
    {
        cout << "El resultado es " << resultado << endl
             << endl;
    }
}

int main()
{
    float resultado; // serán los números que el usuario debe introducir en la calculadora
    char op;         // para las diferentes operaciones
    int error ;      // servirá para detectar errores
    do
    {
        cout << "Ingrese operacion (1-5): " << endl; // a continuación se imprimen las opciones

        cout << "1. Suma " << endl;
        cout << "2. Resta " << endl;
        cout << "3. Multiplicación " << endl;
        cout << "4. Division " << endl;
        cout << "5. Salir " << endl;

        cin >> op;
        resultado = 0;
        error = 1;
        switch (op)
        {
            float x, y;
        case '1':
            x = input_x();
            y = input_y();
            resultado = x + y;
            final(error, resultado);
            break;
        case '2':
             x = input_x();
             y = input_y();
            resultado = x - y;
            final(error, resultado);
            break;
        case '3':
             x = input_x();
             y = input_y();
            resultado = x * y;
            final(error, resultado);
            break;
        case '4':
            x = input_x();
            y = input_y();
            if (abs(y) < pow(10, -20))
            { // Fijamos 10^(-20) como el "0" de la maquina
                cout << "ERROR! No se puede dividir por 0" << endl;
            }
            else
            {
                resultado = x / y;
                final(error, resultado);
            }
            break;
        case '5':
            cout << "Programa finalizado" << endl;
            break;
        default:
            error = 0; // cambiara de valor si no se ha realizado ninguna operacion
            cout << "ERROR! Operación inválida" << endl;
        }
    } while (op != '5');
    return 0;
}