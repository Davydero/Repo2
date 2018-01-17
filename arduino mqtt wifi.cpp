#include<ESP8266WiFi.h>
#include<PubSubClient.h>

const char* ssid="HUAWEI_P9_4069";
const char* password="";
const char* mqtt_server="iot.eclipse.org";
char hum[5];
int humedad=10;

WiFiClient espClient;
PubSubClient client (espClient);
char msg[50];

void setup(){
	
	pinMode(BUILTIN_LED,OUTPURT);
	Serial.begin(115200);
	setup_wifi();
	client.sertServer(mqtt_server,1883);
	client.setCallback(callback);

}

void setup_wifi(){
	delay(10);
	Serial.println("conectandose a: ");
	Serial.println(ssid);
	WiFi.begin(ssid,password);
	while(WiFi.status()!=WL_CONNECTED)
	{
	delay(500);
	Serial.print(".");
	}	

	Serial.println("");
	Serial.println("WiFi conectado");
	Serial.println("Direccion IP");
	Serial.println(WiFi.localIP);
}

void callback(char* topic,byte* payload, unsigned int length)
{
	Serial.print("mensaje ");
	Serial.print(topic);
	for(int i=0;i<length;i++)
	{
		Serial.print((char)payload[i]);
	}
	Serial.println();
}

void reconnect(){
	while(!client.connected())
	{
		Serial.print("intentando reconexion");
		if(client.connect("ESP8266Client"))
		{
			Serial.println("connect");
			client.publish("ucbtja_s5","hola");
			client.subscribe("ucbtja");
		}
		else{
			Serial.print("failed, rc-");
			Serial.print(client.state());
			Serial.println("intentando luego de 5s");
			delay(5000);
		}
	}
}

void loop(){
	if(!client.connected())
	{
		reconnect();
	}
	client.loop();
	sprintf(hum,"%d",humedad);
	Serial.print("mensaje publicado: ");
	Serial.println(hum);
	client.publish("ucbtja_s5",strcat(hum,"_h"));
	humedad++;
	




}