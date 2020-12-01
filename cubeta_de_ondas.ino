//Declaramos las variables necesarias
int numero=0;
int auxnumero=0;
int sensorPinLDR = A0;
int valorLDR = 0;

int numero1=0;
int auxnumero1=0;
int sensorPinLDR1 = A1;
int valorLDR1 = 0;

void setup() {
  
 Serial.begin(9600);
   
}

void loop() {
  
  valorLDR = analogRead(sensorPinLDR);// Leemos el valor de la LDR y lo guardamos en valorLDR
  valorLDR1 = analogRead(sensorPinLDR1);// Leemos el valor de la LDR y lo guardamos en valorLDR

  auxnumero=0;//hacemos la variable auxnumero 0. Esta variable nos ayuda a contar solo 1 cada vez que entremos en el bucle de más abajo
  auxnumero1=0;//hacemos la variable auxnumero 0. Esta variable nos ayuda a contar solo 1 cada vez que entremos en el bucle de más abajo


    Serial.print("Oscilaciones ariba");
    Serial.print("\t");
    Serial.print(numero);
    Serial.print("\t");
    Serial.print("Oscilaciones abajo");
    Serial.print("\t");
    Serial.println(numero1);
  
  while(valorLDR<900 && valorLDR1<900){//Entramos en el bucle si valorLDR es menor de 600. Esto ocurre cuando no da el laser sobre la LDR.
    valorLDR = analogRead(sensorPinLDR);// Leemos el valor de la LDR y lo guardamos en valorLDR
    valorLDR1 = analogRead(sensorPinLDR1);// Leemos el valor de la LDR y lo guardamos en valorLDR
    if(auxnumero==0 && auxnumero1==0 ){// Entramos en el if si auxnumero es 0. Esto solo ocurre la primera vez que recorremos el while.
    numero++;//Sumamos 1 a la variable numero
    numero1++;//Sumamos 1 a la variable numero
    auxnumero=1;//hacemos auxnumero 1, para que solo sume una vez 1 a la variable numero cuando estamos dando vueltas dentro del bucle.
    auxnumero1=1;//hacemos auxnumero 1, para que solo sume una vez 1 a la variable numero cuando estamos dando vueltas dentro del bucle.
      }
    }  

}
