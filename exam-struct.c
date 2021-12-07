#include<stdio.h>
#include<string.h>
#include<conio.h>

#define m 40
#define q 30

typedef struct
{
    int clave[m];
    char nombre[q][m];
    float estatura[m];
    float sueldo[m];
}Usuario;

int NumeroUsuarios();
void Captura(Usuario *p, int num);
int EmpleadoAlto(Usuario *p, int num);
void OrdenacionInsercion(Usuario *p, int num);
void ImprimeTabla(Usuario *p, int num);

int main()
{
Usuario usua;
int numero, MasAlto;

  numero = NumeroUsuarios();
  Captura(&usua, numero);
  MasAlto = EmpleadoAlto(&usua, numero);
  printf("El empleado mas alto es %s y mide %f\n", usua.nombre[MasAlto], usua.estatura[MasAlto]);
  OrdenacionInsercion(&usua, numero);
  ImprimeTabla(&usua, numero);
}

int NumeroUsuarios()
{
    int n;
    printf("¿Cuantos empleados son?: " );
    scanf("%d", &n);
    return(n);
}

// 1. Función para capturar la información del arreglo (va junto con la función "NumeroUsuarios")
void Captura(Usuario *p, int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("Clave: ");
        scanf("%i", &p->clave[i]);
        printf("Nombre: ");
        scanf("%s", &p->nombre[i]);
        //getch();
        printf("Estatura: ");
        scanf("%f", &p->estatura[i]);
        printf("Sueldo: ");
        scanf("%f", &p->sueldo[i]);
    }
}

// 2. Función que busca y regresa la posición del empleado más alto
int EmpleadoAlto(Usuario *p, int num)
{
    int i, alto;
    for(i=0; i<num-1; i++)
    {
        if(p->estatura[i] < p->estatura[i+1])
            alto = i+1;
    }
    return(alto);
}

// 3. Función que ordena a los empleados por sueldo (del mayor sueldo al menor)
void OrdenacionInsercion(Usuario *p, int num)
{
  int i, j, aux;
  for (i=1; i<num; i++)
  {
    aux = p->sueldo[i];
    j = i-1;
    while (j >= 0 && p->sueldo[j] < aux)
    {
      p->sueldo[j + 1] = p->sueldo[j];
      p->clave[j + 1] = p->clave[j];
      p->nombre[j + 1][m] = p->nombre[j][m];
      p->estatura[j + 1] = p->estatura[j];
      j--;
    }
      p->sueldo[j+1] = aux;
  }
}

//4. Función que imprima los datos en columnas
void ImprimeTabla(Usuario *p, int num)
{
    int i;
    printf("CLAVE\t");
    printf("NOMBRE\t");
    printf("ESTATURA\t");
    printf("SUELDO\n");

    for(i=0; i<num; i++)
    {
        printf("%d\t", p->clave[i]);
        printf("%s\t", p->nombre[i]);
        printf("%f\t", p->estatura[i]);
        printf("%f\n", p->sueldo[i]);
    }
}

