#define pinoTrig 12 // Pino de comunicaçao ligado ao Trigger
#define pinoEcho 13  // Pino de comunicaçao ligado ao Echo

#define verde 4
#define amarelo 19
#define vermelho 23

float distancia;

void leitura();

void setup() {
  Serial.begin(115200);

  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
    
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
}

void loop() {
  leitura();
  ligarLed();
  delay(100);
}

void ligarLed(){
  turnOff();
  if(distancia >= 20){
    digitalWrite(verde, HIGH);
  }else if(distancia < 20 && distancia >= 10){
    digitalWrite(amarelo, HIGH);
  }else{
    digitalWrite(vermelho, HIGH);  
  }
}

void turnOff(){
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);  
}

void leitura(){
  digitalWrite(pinoTrig, HIGH); // Manda um sinal de nível alto por 10 microssegundos
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  distancia = pulseIn(pinoEcho, HIGH); // Le o comprimento de onda em alta
  
  distancia = distancia/2; // Divide por 2 pois esse e o tempo da onda ir e voltar
  distancia = distancia*0.034029; // Multiplicamos por 0,034 por causa da velocidade do som (d=v*t)

  Serial.print("Distancia em cm: ");
  Serial.println(distancia);
}
