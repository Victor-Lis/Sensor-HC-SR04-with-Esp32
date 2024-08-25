# Sensor HC-SR04 with Esp32
Esse é um projeto simples onde estou utilizando o sensor HC-SR04 para detectar distâncias junto ao Esp32

Criei esse projeto acima de tudo para testar também a porta do arduino VIN.

## Usando o HC-SR04
1- Declarando pinos, variáveis e monitor serial
```c++
#define pinoTrig 12 // Pino de comunicaçao ligado ao Trigger
#define pinoEcho 13  // Pino de comunicaçao ligado ao Echo

float distancia;

void leitura();

void setup() {
  Serial.begin(115200);

  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
}
```

2- Declarando função de leitura
```c++
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
```

3- Chamando função 'leitura()' dentro da função 'loop()'
```c++
void loop() {
  leitura();
  delay(100);
}
```

## Declarando Leds
1- Declarando portas
```c++
#define verde 4
#define amarelo 19
#define vermelho 23

void setup() {
  Serial.begin(115200);

  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
    
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
}
```

2- Criando função para desligar leds
```c++
void turnOff(){
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);  
}
```

3- Criando função para ligar leds
```c++
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
```

4- Chamando dentro do 'loop()'
```c++
void loop() {
  leitura();
  ligarLed();
  delay(100);
}
```

## Autores
- [@Victor-Lis](https://github.com/Victor-Lis)
