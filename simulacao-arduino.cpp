/*
 * Global Solution - Computer Science
 * FIAP - Professor Mauricio Neto
 * * Sistema de Alarme Climático com Lógica Digital
 * Este código implementa a lógica do sistema de alarme em um Arduino.
 * Ele lê 4 entradas de sensores e ativa um alarme (LED) com base nas regras de risco.
*/

// Mapeamento dos Pinos de Entrada para os Sensores 
const int pinoA = 2; // Sensor de Chuva Intensa
const int pinoB = 3; // Sensor de Vento Forte
const int pinoC = 4; // Sensor de Umidade do Solo
const int pinoD = 5; // Sensor de Temperatura Elevada

// Mapeamento do Pino de Saída para o Alarme
const int pinoAlarmeX = 13; // LED no pino 13, representa a saída X

/**
 * Verifica a lógica do alarme combinando as regras de risco.
 * Retorna 'true' se o alarme deve ser ativado (X=1).
 */
bool verificarCondicaoDeAlarme() {
  // Lê o estado atual (0 ou 1) de cada sensor
  bool a = digitalRead(pinoA);
  bool b = digitalRead(pinoB);
  bool c = digitalRead(pinoC);
  bool d = digitalRead(pinoD);

  // Expressão Lógica Booleana do Alarme: X = (A·C) + (A·B) + (B·D)
  
  // Condição 1: Risco de Enchente (Chuva E Umidade) 
  bool riscoEnchente = a && c;

  // Condição 2: Risco de Desabamento (Chuva E Vento) 
  bool riscoDesabamento = a && b;

  // Condição 3: Risco de Incêndio (Vento E Temperatura) 
  bool riscoIncendio = b && d;

  // O alarme é ativado se QUALQUER um dos riscos for verdadeiro
  return riscoEnchente || riscoDesabamento || riscoIncendio;
}

// Função de configuração inicial, executada uma vez ao ligar o Arduino
void setup() {
  // Configura os pinos dos sensores como entrada (INPUT)
  pinMode(pinoA, INPUT);
  pinMode(pinoB, INPUT);
  pinMode(pinoC, INPUT);
  pinMode(pinoD, INPUT);
  
  // Configura o pino do alarme como saída (OUTPUT)
  pinMode(pinoAlarmeX, OUTPUT);
}

// Função principal, executada repetidamente em loop
void loop() {
  // 1. Verifica se a condição de alarme foi atendida chamando a função
  bool ativarAlarme = verificarCondicaoDeAlarme();
  
  // 2. Envia o resultado para o pino do alarme (liga ou desliga o LED)
  digitalWrite(pinoAlarmeX, ativarAlarme);
  
  // 3. Pequena pausa para estabilidade do circuito
  delay(100);
}