// Librerias I2C para controlar el mpu6050
// la libreria MPU6050.h necesita I2Cdev.h, I2Cdev.h necesita Wire.h
#include <VirtualWire.h> 
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Wire.h>"

// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo 
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;

// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int ax, ay, az;
int gx, gy, gz;

void setup() {
  Serial.begin(9600);    //Iniciando puerto serial
  Wire.begin();           //Iniciando I2C  
  sensor.initialize();    //Iniciando el sensor

    // Se inicializa el RF
  vw_setup(2000); // velocidad: Bits per segundo
  vw_set_tx_pin(2); //Pin 2 como salida para el RF 

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);
  
    char buf[VW_MAX_MESSAGE_LEN]; // Cadena para enviar
    int tiempo=millis()/1000; //variable con el tiempo en segundos
    float ax;   //segundo dato para enviar
    String str="";  
    
    str="i"+String(tiempo); //convertimos el entero a String y agramos un inicio de trama
    str.toCharArray(buf,sizeof(buf)); //convertimos el String en un array
    vw_send((uint8_t *)buf, strlen(buf)); //Enviamos el array
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie

    str="f"+String(ay); //convertimos el float a String y agramos un inicio de trama
    str.toCharArray(buf,sizeof(buf)); //convertimos el String en un array
    vw_send((uint8_t *)buf, strlen(buf)); ////Enviamos el array
    vw_wait_tx(); //Esperamos hasta que el mensaje se envie
    
  Serial.print(tiempo);
  Serial.print("\t");
  Serial.println(ay);

  delay(100);
}
