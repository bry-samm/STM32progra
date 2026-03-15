/*
 * NombreProgra.c
 * 
 * Created:
 * Author:
 * Description:
 */
//************************************************************************************
// Encabezado (librerías)
#define F_CPU 16000000#include <avr/io.h>#include <avr/interrupt.h>
#include "initUART/initUART.h"
//************************************************************************************
// Function prototypes
void setup();
void writeChar(char caracter);
void cadena_texto(char* texto);

uint8_t arriba = 0;
//************************************************************************************
// Main Function
int main(void)
{
	setup();
	/* Replace with your application code */
	while (1)
	{
	}
}
//************************************************************************************
// NON-INterrupt subroutines
void setup()
{
	cli();
/*
	CLKPR = (1 << CLKPCE); // Habilitar la configuración del oscilador CPU
	CLKPR = (1 << CLKPS2) | (1 << CLKPS1); // 64 PRESCALER -> 1MHz
*/
	// Configuración de botones en PORTB
	DDRB &= ~((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3) | (1 << PORTB4) | (1 << PORTB5)); // Los configuro como entradas
	PORTB |= (1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3) | (1 << PORTB4) | (1 << PORTB5); // Activo los pull up

	// Habilitar interrupción en PB0, PB1, PB2
	PCICR |= (1 << PCIE0); // Habilita interrupciones por cambio en el puerto B
	//PCMSK0 |= (1 << PCINT0) | (1 << PCINT1) | (1 << PCINT2);
	PCMSK0 |= 0b00111111;   // Activo mascara de interrupción de PCINT0–PCINT5 (PORTB0 al PORTB5)

	initUART();
	
	sei();
}

//Función para poder enviar caracteres
void writeChar(char caracter){
	while ((UCSR0A & (1 << UDRE0)) == 0); //Indica si aun sigue ocupado la transmisión de datos
	UDR0 = caracter;	//Escribe la información en este registro
}

//Empleamos un puntero para ir mandando cada caracter del string
void cadena_texto(char* texto) {
	while (*texto != '\0') {
		writeChar(*texto);
		texto++;
	}
}

//************************************************************************************
// Interrupt subroutines
ISR(PCINT0_vect)
{
	//Se emplea static para que al momento de entrar y salir de la interrupción aun se mantenga el valor
	//se usa FF por que como está configurado con pull-up el estádo "apagado" es 1
	static uint8_t estado_anterior = 0xFF;
	uint8_t estado_actual = PINB; //Se lee lo que está en el puerto
	uint8_t cambio = estado_anterior ^ estado_actual; //Se emplea un XOR para indicar que cambió el estado indicando el botón que se presionó

	// Botón en PB0
	if ((cambio & (1 << PINB0)) && !(estado_actual & (1 << PINB0)))//!(estado_actual & (1 << PINB0) ==> indica si está encendido o apagado el botón, tiene el NOT debido al pull-up
	{
		arriba = 1;
		//cadena_texto("arriba\r\n");
		writeChar('1');
	}

	// Botón en PB1
	if ((cambio & (1 << PINB1)) && !(estado_actual & (1 << PINB1)))//Misma lógica que en PB0
	{
		//cadena_texto("abajo\r\n");
		writeChar('2');
	}

	// Botón en PB2
	if ((cambio & (1 << PINB2)) && !(estado_actual & (1 << PINB2)))
	{
		//cadena_texto("derecha\r\n");
		writeChar('3');
	}
	// Botón en PB3
	if ((cambio & (1 << PINB3)) && !(estado_actual & (1 << PINB3)))
	{
		//cadena_texto("izquierda\r\n");
		writeChar('4');
	}
	// Botón en PB4
	if ((cambio & (1 << PINB4)) && !(estado_actual & (1 << PINB4)))
	{
		//cadena_texto("A\r\n");
		writeChar('5');
	}
	// Botón en PB5
	if ((cambio & (1 << PINB5)) && !(estado_actual & (1 << PINB5)))
	{
		//cadena_texto("B\r\n");
		writeChar('6');
	}
	
	//Se coloca esta lógica para conocer el estado en el que se encuentran los botones
	//sin esta lógica el XOR no tendría sentido ya que se está comparando con los mismos valores viejos
	estado_anterior = estado_actual;
}

