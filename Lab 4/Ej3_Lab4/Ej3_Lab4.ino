// Variable global de velocidad
volatile int velocidad = 20;
// Constantes de velocidad máxima, mínima y cuanto aumenta
const int maxima = 1000;
const int minima = 20;
const int aumenta = 20;
 
// Array con los números de los pines donde están conectados
// los LEDs de las luces del coche fantástico
int leds[5] = {8, 9, 10, 11, 12};
 
void setup() {
  // Inicializamos los pines de los LEDs como salida y a estado bajo
  for (int i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
 
  // Asignamos la velocidad mínima
  velocidad = minima;
 
  // Configuramos los pines de interrupciones para que
  // detecten un cambio de bajo a alto
  attachInterrupt(digitalPinToInterrupt(2), velocidadMenos, RISING);
  attachInterrupt(digitalPinToInterrupt(3), velocidadMas, RISING);
 
}
 
void loop() {
  // Este primer bucle recorre el array de izquierda a derecha
  for (int i = 0; i < 5; i++)
  {
    // Solo para el segundo pin y consecutivos apagamos el pin anterior
    // En el caso de 0 no hace falta ya que por defecto está apagado
    // Cuidado que nos salimos del rango del array 0-1=-1 no existe este elemento
    if (i > 0)
    {
      // Apagamos el LED a la izquierda
      digitalWrite(leds[i - 1], LOW);
    }
 
    // Encendemos en el LED en el que estamos
    digitalWrite(leds[i], HIGH);
 
    // Esperamos el tiempo marcado por velocidad
    delay(velocidad);
  }
 

  digitalWrite(leds[4], LOW);

  for (int i = 4; i >= 0; i--)
  {

    if (i < 4)
    {

      digitalWrite(leds[i + 1], LOW);
    }

    digitalWrite(leds[i], HIGH);

    delay(velocidad);
  }
  digitalWrite(leds[0], LOW);
 
}

void velocidadMenos()
{
  velocidad = velocidad - aumenta;

  if (velocidad < minima)
  {
    velocidad = minima;
  }
}
void velocidadMas()
{
  velocidad = velocidad + aumenta;
  if (velocidad > maxima)
  {
    velocidad = maxima;
  }
}
