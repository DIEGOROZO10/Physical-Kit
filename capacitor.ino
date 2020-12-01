int linea=0;

void setup() {
Serial.begin(9600);//configura la velocidad
delay(100);
}

void loop()
{
  
int lectura = analogRead(A0); //0 - 1023
float conversion = 5.0*lectura/1023.0;//Modificación para convertir a Voltaje
linea=linea + 1;

Serial.println(conversion);
delay(100); 

}
