#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("Receptor: setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(2);    //Pin 2 como entrada del RF
    vw_rx_start();       // Se inicia como receptor
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    int dato1=0;
    int dato2=0;
    //verificamos si hay un dato valido en el RF
    if (vw_get_message((uint8_t *)buf,&buflen))
    {
  int i;
  String  DatoCadena="";
        if((char)buf[0]=='i') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            dato1=DatoCadena.toInt();
            Serial.print("Tiempo: ");
            Serial.print(dato1);
            
        }
        else if((char)buf[0]=='f') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            dato2=DatoCadena.toInt();
            Serial.print("   \t");
            Serial.print("Aceleracion: ");
            Serial.println(dato2);
        }
    }
}
