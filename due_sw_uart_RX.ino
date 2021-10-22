void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void roda_sinal(int sinal){
  digitalWrite(10, sinal); 
  espera_T();
}

void espera_T() {
  for(int i = 0; i < 1093 * 2; i++)
    asm("NOP");
}

void loop() {

  // start bit
  roda_sinal(0); 

  // R
  roda_sinal(0); 
  roda_sinal(1); 
  roda_sinal(0); 
  roda_sinal(0); 
  roda_sinal(1); 
  roda_sinal(0); 
  roda_sinal(1); 
  roda_sinal(0); 

  // parity bit
  roda_sinal(1); 

  // stop bit
  roda_sinal(1); 

  delay(1000);
}
