long distancia;
long tiempo;
int luminosidad;
int valor;
byte potencia_1 = 5, potencia_2 = 10; 
byte trigger = 7;
byte echo = 3;
byte e_1 = 2, e_2 = 4, e_3 = 8, e_4 = 9;

void setup() {
  Serial.begin (9600);
  pinMode (e_1, OUTPUT);
  pinMode (e_2, OUTPUT);
  pinMode (potencia_1, OUTPUT);
  pinMode (trigger, OUTPUT);
  pinMode (e_3, OUTPUT);
  pinMode (e_4, OUTPUT);
  pinMode (potencia_2, OUTPUT);
  pinMode (echo, INPUT); 
  digitalWrite (e_1, LOW);
  digitalWrite (e_2, LOW);
  digitalWrite (e_3, LOW);
  digitalWrite (e_4, LOW);
  analogWrite (potencia_1, 0);
  analogWrite (potencia_2, 0);
}

void loop() {
 valor = analogRead (A4);
 luminosidad = map(valor, 969, 49, 0, 100);
 Serial.print("Lectura: ");
 Serial.print(valor);
 Serial.print ("  Luminosidad: ");
 Serial.print (luminosidad);
 Serial.print ("%");
 Serial.println ();
  if(valor <=968 && valor >= 216){
    digitalWrite (trigger, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger, LOW);
    delayMicroseconds (10);
    tiempo = (pulseIn (echo, HIGH));
    distancia = (tiempo/58);
    Serial.print ( " Distancia: ");
    Serial.print (distancia);
    Serial.print ("cm ");
    delay (100);
    motor();
     
}
  if(luminosidad <=100 && luminosidad >= 98){
    digitalWrite (trigger, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger, LOW);
    delayMicroseconds (10);
    tiempo = (pulseIn (echo, HIGH));
    distancia = (tiempo/58);
    Serial.print ( " Distancia: ");
    Serial.print (distancia);
    Serial.print ("cm ");
    motorReversa();
    delay (100);}
}

void motor(){
 analogWrite (potencia_1, 255);
 analogWrite (potencia_2, 255);
 digitalWrite (e_1, HIGH);
 digitalWrite (e_2, LOW);
 digitalWrite (e_3, HIGH);
 digitalWrite (e_4, LOW);
 if (distancia <= 120 && distancia >= 100){
  digitalWrite (e_1, LOW);
  digitalWrite (e_2, LOW);
  digitalWrite (e_3, LOW);
  digitalWrite (e_4, LOW);}
}

void motorReversa(){
 analogWrite (potencia_1, 255);
 analogWrite (potencia_2, 255);
 digitalWrite (e_1, LOW);
 digitalWrite (e_2, HIGH);
 digitalWrite (e_3, LOW);
 digitalWrite (e_4, HIGH);
 if (distancia <= 10 && distancia >= 0){
  digitalWrite (e_1, LOW);
  digitalWrite (e_2, LOW);
  digitalWrite (e_3, LOW);
  digitalWrite (e_4, LOW);}     
}
