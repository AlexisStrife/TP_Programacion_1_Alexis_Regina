float sumar (float numeroUno, float numeroDos)
{
    float resultado = numeroUno + numeroDos;
    return resultado;
}

float restar (float numeroUno, float numeroDos)
{
    float resultado = numeroUno - numeroDos;
    return resultado;
}


float dividir (float numeroUno, float numeroDos)
{
    float resultado = numeroUno / numeroDos;
    return resultado;
}

float multiplicar (float numeroUno, float numeroDos)
{
    float resultado = numeroUno * numeroDos;
    return resultado;
}


int validaEntero (float numero)
{
    int entero = (int) numero;
    if (numero - entero > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int factorial (int numero)
{
    int factorizacion = numero;
    int i;

    for(i=1; i < numero; i++)
        {
            factorizacion = factorizacion * i;
        }

return factorizacion;

}




