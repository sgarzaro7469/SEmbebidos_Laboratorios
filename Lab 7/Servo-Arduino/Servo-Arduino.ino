//Laboratorio 7 - Ejercicio 1
//Servo-Arduino


#include <Servo.h>

Servo servoMotor;


void setup() {
  Serial.begin(115200);
  //Pin del que recibe el dato el servo
  servoMotor.attach(9);
  //Angulo de inicio, en 0
  servoMotor.write(0);
}


void loop() {
   // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo
  // Para el sentido positivo
  for (int i = 0; i <= 180; i++)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }
 
  // Para el sentido negativo
  for (int i = 179; i > 0; i--)
  {
    // Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    // Hacemos una pausa de 25ms
    delay(25);
  }

}
