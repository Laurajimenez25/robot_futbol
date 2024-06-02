// Conexiones puente h
// motor 1_izquierdo
int IN1 = 10; // enmascaro al pin 10 con el nombre de IN1
int IN2 = 9;  // enmascaro al pin 9 con el nombre de IN2

// motor 2_derecho
int IN3 = 8; // enmascaro al pin 8 con el nombre de IN3
int IN4 = 7; // enmascaro al pin 7 con el nombre de IN4

char command = 'S'; // creo la variable de lectura del bluetooth y la inicializo en 'S'

// Definimos el tipo de puntero a función
typedef void (*MotorCallback)();

// Declaración de funciones para cada comando
void forward();
void backward();
void right();
void left();
void stop();
void rightOneWheel();
void leftOneWheel();

// Mapa de comandos a funciones
struct Command {
  char command;
  MotorCallback callback;
};

Command commandMap[] = {
  {'F', forward},
  {'B', backward},
  {'R', right},
  {'L', left},
  {'S', stop},
  {'I', rightOneWheel},
  {'G', leftOneWheel}
};

void setup() {
  Serial.begin(9600); // inicio el puerto serial para la comunicación con el bluetooth
  pinMode(IN1, OUTPUT); // configuro el pin donde conecte IN1 como salida
  pinMode(IN2, OUTPUT); // configuro el pin donde conecte IN2 como salida
  pinMode(IN3, OUTPUT); // configuro el pin donde conecte IN3 como salida
  pinMode(IN4, OUTPUT); // configuro el pin donde conecte IN4 como salida
}

void loop() {
  if (Serial.available() > 0) { // leo el puerto serial
    command = Serial.read(); // si hay un dato lo cargo en la variable commanddato
    for (int i = 0; i < sizeof(commandMap) / sizeof(Command); i++) {
      if (commandMap[i].command == command) {
        commandMap[i].callback();
        break;
      }
    }
  }
}

void forward() {
  // giro motor 1 sentido anti horario
  digitalWrite(IN1, LOW); // envío 0V al pin donde conecte IN1
  digitalWrite(IN2, HIGH); // envío 5V al pin donde conecte IN2
  // giro motor 2 sentido horario
  digitalWrite(IN3, HIGH); // envío 5V al pin donde conecte IN3
  digitalWrite(IN4, LOW); // envío 0V al pin donde conecte IN4
}

void backward() {
  // giro motor 1 sentido horario
  digitalWrite(IN1, HIGH); // envío 5V al pin donde conecte IN1
  digitalWrite(IN2, LOW); // envío 0V al pin donde conecte IN2
  // giro motor 2 sentido anti horario
  digitalWrite(IN3, LOW); // envío 0V al pin donde conecte IN3
  digitalWrite(IN4, HIGH); // envío 5V al pin donde conecte IN4
}

void right() {
  // giro motor 1 sentido anti horario
  digitalWrite(IN1, LOW); // envío 0V al pin donde conecte IN1
  digitalWrite(IN2, HIGH); // envío 5V al pin donde conecte IN2
  // giro motor 2 sentido anti horario
  digitalWrite(IN3, LOW); // envío 0V al pin donde conecte IN3
  digitalWrite(IN4, HIGH); // envío 5V al pin donde conecte IN4
}

void left() {
  // giro motor 1 sentido horario
  digitalWrite(IN1, HIGH); // envío 5V al pin donde conecte IN1
  digitalWrite(IN2, LOW); // envío 0V al pin donde conecte IN2
  // giro motor 2 sentido horario
  digitalWrite(IN3, HIGH); // envío 5V al pin donde conecte IN3
  digitalWrite(IN4, LOW); // envío 0V al pin donde conecte IN4
}

void stop() {
  // motor 1 DETENIDO
  digitalWrite(IN1, LOW); // envío 0V al pin donde conecte IN1
  digitalWrite(IN2, LOW); // envío 0V al pin donde conecte IN2
  // motor 2 DETENIDO
  digitalWrite(IN3, LOW); // envío 0V al pin donde conecte IN3
  digitalWrite(IN4, LOW); // envío 0V al pin donde conecte IN4
}

void rightOneWheel() {
  // giro motor 1 sentido anti horario
  digitalWrite(IN1, LOW); // envío 0V al pin donde conecte IN1
  digitalWrite(IN2, HIGH); // envío 5V al pin donde conecte IN2
}

void leftOneWheel() {
  // giro motor 2 sentido horario
  digitalWrite(IN3, HIGH); // envío 5V al pin donde conecte IN3
  digitalWrite(IN4, LOW); // envío 0V al pin donde conecte IN4
  delay(100); // demora de 100 milisegundos
}
