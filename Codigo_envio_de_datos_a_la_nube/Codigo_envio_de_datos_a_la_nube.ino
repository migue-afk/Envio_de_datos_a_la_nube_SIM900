
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);

#define APN "internet.movistar.com.ec"
#define Authorization "*****************="
#define RESET_SIM900 9

float dato=0.5;
String serial="Nombre_dispositivo";
String bateria="90";
String memoria="85";

void setup(){
SIM900.begin(19200);  
Serial.begin(19200);
delay(1000);
pinMode(RESET_SIM900, OUTPUT);
digitalWrite(RESET_SIM900, LOW);

EcendidoMedianteSoftware();
}

void loop(){
  Serial.println("HTTP GET :");
  Serial.print("AT\\r\\n");
  SIM900.println("AT"); 
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("ATE0");
  delay(1000);
  ShowSerialData(); 
  delay(1000);
  
  SIM900.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+SAPBR=3,1,\"APN\",\"" + String(APN) + "\"");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+SAPBR=1,1");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+SAPBR=2,1");
  delay(5000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPINIT");
  delay(1000);
  ShowSerialData(); 
  delay(1000);
  
  SIM900.println("AT+HTTPPARA=\"CID\",1");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPPARA=\"URL\",\"DIRECCION URL"+serial+"&dato="+dato+"&bateria="+bateria+"&memoria="+memoria+"\"");
  delay(1000);
  ShowSerialData(); 
  delay(1000);
  
  SIM900.println("AT+HTTPPARA=\"REDIR\",1");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPPARA=\"USERDATA\",\"Authorization: " + String(Authorization) + "\"");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
  delay(1000);
  ShowSerialData(); 
  delay(1000);
  
  SIM900.println("AT+HTTPPARA?");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPSSL=1");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+HTTPSSL?");
  delay(1000);
  ShowSerialData();  
  delay(1000);

  SIM900.println("AT+HTTPACTION=0");  
  delay(15000);
  ShowSerialData(); 
  delay(2000);
  
  SIM900.println("AT+HTTPREAD");
  delay(8000);
  ShowSerialData(); 
  delay(2000);
  
  SIM900.println("AT+HTTPTERM");
  delay(1000);
  ShowSerialData();  
  delay(1000);
  
  SIM900.println("AT+SAPBR=0,1");
  delay(1000);
  ShowSerialData(); 
  delay(1000);
}

void ShowSerialData()
{
  while(SIM900.available()!=0)  
  Serial.write(char (SIM900.read())); 
}



//*********************************************Encendido del módulo por sofware
void EcendidoMedianteSoftware()
{
  
Serial.println("Espera_conexion_SIM900_Encendido_por_software");

digitalWrite(9, HIGH);
delay(1000);
digitalWrite(9, LOW);
delay(20000);//Tiempo prudencial para encuentro de una red de tu operadora

//Comprobacion de conexion (Si la respuesta al comnado AT es OK, estamos listos para el envio de los siguentes comandos AT)

SIM900.println("AT"); 
delay(1000);
}
