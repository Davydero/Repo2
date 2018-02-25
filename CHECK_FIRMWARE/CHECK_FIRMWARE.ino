//Serial Relay - Arduino will patch a 
//serial link between the computer and the GPRS Shield
//at 19200 bps 8-N-1
//Computer is connected to Hardware UART
//GPRS Shield is connected to the Software UART 

//#include <SoftwareSerial.h>

//SoftwareSerial GSMSerial(7, 8);
char palabra;
int a=0;
int contador=0;
int contador2=50;
void setup()
{
//GSMSerial.begin(19200);               // the GPRS/GSM baud rate   
Serial.begin(115200); 
Serial1.begin(115200);              // the GPRS/GSM baud rate   
delay(2000);
Serial1.println();
}

void loop()
{
if(a==0)
{//Serial1.println("AT+BTPOWER=1");//SIEMPRE HAY QUE PRENDER
//Serial1.println("AT+BTSTATUS?");
//Serial1.println("AT+BTSCAN=1,20");//escanea dispositivos 
//Serial1.println("AT+BTPAIR=0,1");
//Serial1.println("AT+BTPAIR=1,1");//para confirmar la contrasena de emparejamiento
//Serial1.println("AT+BTGETPROF=1");//checkea q perfiles admite el smartphone
//Serial1.println("AT+BTPAIRCFG?");
Serial1.println("AT+BTCONNECT=1,4");//conecta al dispositivo emparejado como serial
delay(50);
  
//Serial1.println("AT");//Serial.println("Serial enviado");
//delay(50);

if(Serial1.available())

{palabra=(char)Serial1.read();delay(5); Serial.print(palabra);}
delay(50);

a=1;
}
if(Serial1.available())

{palabra=(char)Serial1.read();delay(10); Serial.print(palabra);}


//Envio de datos Bluetooth
/*String ang="Angulo :";
String angulo=ang+contador2;
String dist="Distancia :";
String distancia=dist+contador;
Serial1.println("AT+BTSPPSEND=30");delay(50);
Serial1.print(distancia+angulo);Serial1.println('#');delay(50);*/




contador++;
if(contador>=100){contador=0;}
contador2--;
if(contador2<=1){contador2=50;}




}
