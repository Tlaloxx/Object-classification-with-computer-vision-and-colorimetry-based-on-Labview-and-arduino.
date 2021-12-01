#include <Servo.h>

Servo servo_uno; 
Servo servo_dos; 
Servo servo_tre; 

int led_a = 5;
int led_b = 6;
int led_c = 7; 

int pin_uno = 8;  
int pin_dos = 9;
int pin_tre = 10;

int pulso_min = 500;
int pulso_max = 2000; 
char dato = 0;


void setup()
{
 
  servo_uno.attach(pin_uno, pulso_min, pulso_max);
  servo_dos.attach(pin_dos, pulso_min, pulso_max);
  servo_tre.attach(pin_tre, pulso_min, pulso_max);
  
  pinMode(led_a,OUTPUT);
  pinMode(led_b,OUTPUT);
  pinMode(led_c,OUTPUT);
 
  
  Serial.begin(9600);
}


void loop() 
{
  
  if(Serial.available()) // Verificar si el puerto esta disponible 
    {
       dato = Serial.read();
       
        
          if (dato == 49) //49 = VERDE
                { 
                  servo_uno.write(0);
                  servo_dos.write(0);
                  servo_tre.write(0);
                  /*COLOCAR SERVOS EN CERO*/
                  digitalWrite(led_a,HIGH);
                  /*ENCENDER EL LED VERDE*/
                  delay(500);
                  /*ESPERAR UN SEGUNDO*/
                  servo_uno.write(180);
                  delay(2000); 
                  servo_dos.write(0);
                  servo_tre.write(0); 
                  /*COLOCAR SERVOS EN POSICION*/ 
                  digitalWrite(led_a,LOW); 
                   /*APAGAR EL LED VERDE*/
                  delay(1000); 
                }
                
      
            if (dato == 50) //50 = AZUL
                {
                  servo_uno.write(0);
                  servo_dos.write(0);
                  servo_tre.write(0);
                  /*COLOCAR SERVOS EN CERO*/
                  digitalWrite(led_b,HIGH);
                  /*ENCENDER EL LED VERDE*/
                  delay(500);
                  /*ESPERAR UN SEGUNDO*/
                  servo_uno.write(180);
                  servo_dos.write(60);
                  servo_tre.write(0); 
                  delay(2000); 
                  servo_dos.write(0);
                  /*COLOCAR SERVOS EN POSICION*/ 
                  digitalWrite(led_b,LOW); 
                   /*APAGAR EL LED VERDE*/
                  delay(1000); 
                }
                
                
            if (dato == 52) // 52 = ROJO
                {
                  servo_uno.write(0);
                  servo_dos.write(0);
                  servo_tre.write(0);
                  /*COLOCAR SERVOS EN CERO*/
                  digitalWrite(led_c,HIGH);
                  /*ENCENDER EL LED VERDE*/
                  delay(500);
                  /*ESPERAR UN SEGUNDO*/
                  servo_uno.write(180);
                  servo_dos.write(75);
                  servo_tre.write(75); 
                  delay(2000); 
                  servo_dos.write(0);
                  servo_tre.write(0); 
                  /*COLOCAR SERVOS EN POSICION*/ 
                  digitalWrite(led_c,LOW); 
                   /*APAGAR EL LED VERDE*/
                  delay(1000); 
                }
             
             else
                {
                 // delay(500);  
                }
                Serial.print("@");
            
    }
}
