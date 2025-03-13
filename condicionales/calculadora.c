#include <stdio.h>

int main(int argc, char const *argv{}) 
{
    float num1, num2, resultado;
    char operador;
do{
    printf("Ingrese un numero, luego el operador y luego el segundo numero");
    printf("Operaciones disponibles:\n+\n-\n*\n/\n");
    printf("Ingrese ? para salir\n");
    setbuf(stdin, NULL);
    scanf("%f%c%f", &num1, &operador, &num2)

    switch (operador)
    {
    case '+':
        resultado = num1 + num2;
        break;
    
    case '-':
        resultado = num1 - num2;
        break;

    case '*':
        resultado = num1 * num2;
        break;
    
    case '/':
        resultado = num1 + num2;
        break;
