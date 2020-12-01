int pin_lectura = A0;  
float voltaje_entrada;
float voltaje_final;
float voltaje_entrada2;
float corriente;
float corriente_mA;
float resistencia1 = 51000; //Resistencia de 51K
float resistencia2 = 51000; //Resistencia de 51k
//float resistencia3 = 100; //Resistencia de 51k
//int R_3;
//String mensaje = " Ingresa el valor de la resistencia: ";

void setup() {
  Serial.begin(9600);
  pinMode(pin_lectura, INPUT);
}

void loop() {

  voltaje_entrada = (analogRead(A0) * 4.5) / 1024;  //Lee el voltaje de entrada
  voltaje_final = voltaje_entrada / (resistencia2 / (resistencia1 + resistencia2));  //Fórmula del divisor resistivo para el voltaje final
//  corriente = voltaje_final/ resistencia3;
  //corriente_mA = corriente*1000;

  Serial.print ("Voltaje DC:");
  Serial.print ("\t");
  Serial.println(voltaje_final);  //Muestra el voltaje final
//  Serial.print ("\t");
//  Serial.print ("Corriente Dc - mA:");
//  Serial.print ("\t");
//  Serial.println(corriente_mA);  //Muestra el voltaje final
  delay(500);
  

}
