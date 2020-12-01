//Variable donde almacenaremos el valor del potenciometro
float valor=0;
float sensorvalorgrados=0;

float valor2=0;
float sensorvalorgrados2=0;

void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
}
 
void loop() {
  // leemos del pin A0 valor
  valor = analogRead(A7);
  valor = valor*100/1023;

  valor2 = analogRead(A6);
  valor2 = valor2*100/1023;

  sensorvalorgrados = map(valor, 0, 100, 0, 290); 
  sensorvalorgrados2 = map(valor2, 0, 100, 0, 290); 
 
  //Imprimimos por el monitor serie
  Serial.print(" Grados = ");
  Serial.print(sensorvalorgrados);
  Serial.print("\t");
  Serial.print(" Grados = ");
  Serial.println(sensorvalorgrados2);
  delay(100);
 
}
