/* 
@autor:
 * Cesar Villalobos
 * Estudiante: Ing.Sistemas UDI

Programa que mediante registros en C realiza operaciones entre números racionales positivos, entre las
operaciones están suma,resta,multiplicación y división; además el resultado de cada 
operación se imprime como fracción irreductible.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct fracc{
	int numerador;
	int denominador;
}fra; //Se define una estructura con dos campos enteros y se apoda "fra"

fra armarnumero(){ //Se crea una función de tipo fra
	fra num; //Se inicializa una variable 
	printf("Ingrese el numerador: ");
	scanf("%d",&num.numerador);
	printf("Ingrese el denominador: ");
	scanf("%d",&num.denominador); //Se llenan los valores de la estructura
	return num;	//Se retorna 
}

fra sumarnumeros(fra a, fra b){ //Funcion que recibe dos estructuras y establece una operación 
	fra suma;
	suma.numerador=(a.numerador*b.denominador)+(a.denominador*b.numerador); // a/b + c/d=(a*d+b*c) / b*d
	suma.denominador=a.denominador*b.denominador;
	return suma;
}
fra restarnumeros(fra a, fra b){ //Funcion que recibe dos estructuras y establece una operación 
	fra resta;
	resta.numerador=(a.numerador*b.denominador)-(a.denominador*b.numerador);
	resta.denominador=a.denominador*b.denominador;
	return resta;
}
fra multnumeros(fra a,fra b){ //Funcion que recibe dos estructuras y establece una operación 
	fra multi;
	multi.numerador=a.numerador*b.numerador;
	multi.denominador=a.denominador*b.denominador;
	return multi;
}

fra dividirnumeros(fra a,fra b){ //Funcion que recibe dos estructuras y establece una operación 
	fra divi;
	divi.numerador=a.numerador*b.denominador;
	divi.denominador=a.denominador*b.numerador;
	return divi;
}

void imprimir(fra a,fra b,fra c,fra d){ //Funcion encargada de imprimir los numeros
	printf("En la suma el numerador es: %d y el denominador es: %d\n",a.numerador,a.denominador);
	printf("En la resta numerador es: %d y el denominador es: %d\n",b.numerador,b.denominador);	
	printf("En la multiplicacion el numerador es: %d y el denominador es: %d\n",c.numerador,c.denominador);
	printf("En la division el numerador es: %d y el denominador es: %d\n",d.numerador,d.denominador);
}

fra reducirnum(fra a){ //Funcion encargada de volver una fraccion irreductible
	int i,c;
	if(a.numerador<0){
		a.numerador=fabs(a.numerador); //Soluciona el error de comparación entre numerador y denominador cuando uno de ellos es negativo
	}
	if(a.numerador>=a.denominador){ //Determina el mayor de los dos
		for (i=a.numerador;i>=1;i--){ //Recorrerá desde 2 hasta la mitad del numero mayor
			if(a.numerador%i==0 && a.denominador%i==0){ //Se busca un numero de division entera de ambos numeros a la vez 
				a.numerador/=i; 
				a.denominador/=i; //De encontrar el numero dividira ambos terminos en él
			}
		}
	}else{
		for (i=a.denominador;i>=1;i--){
			if(a.numerador%i==0 && a.denominador%i==0){
				a.numerador/=i;
				a.denominador/=i; //Se procede igual 
			}
		}
	}
	return a;
}
int main(){
	fra a = armarnumero(); //Funcion encargada de arma una estructura
	fra b = armarnumero();
	fra resul=sumarnumeros(a,b); //Llama a la funcion sumarnumeros y le entrega las dos estructuras, su valor de return se asignará a resul
	fra resultt=restarnumeros(a,b); //Llama a la funcion restarnumeros y le entrega las dos estructuras, su valor de return se asignará a resultt
	fra resulttt=multnumeros(a,b); //Llama a la funcion multnumeros y le entrega las dos estructuras, su valor de return se asignará a resulttt
	fra resultttt=dividirnumeros(a,b);
	fra reducid=reducirnum(resul); //Llama a la funcion reducirnum y le entrega la estructura resul para que su return sea asignado a reducid
	fra reducidd=reducirnum(resultt);
	fra reduciddd=reducirnum(resulttt);
	fra reducidddd=reducirnum(resultttt);
	imprimir(reducid,reducidd,reduciddd,reducidddd); //Llama la funcion imprimir para operar las 4 estructuras y mostrarlas por pantalla	
}
