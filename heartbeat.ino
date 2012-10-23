/*
Heartbeat 

Blink a led as a Heartbeat

Connect a led and resistor to pin 9, or any PWM capable pin and configure below

Public Domain - http://eduardofv.com

Heartbeat
Brief explanation
On [1] Stevens and Lakin describe a detailed mathematical analysis of the signal of the cardiac pulse. 
 
I've taken one of their equations that closesly reesembles a basic cardiac pulse and generated a lookup table
for the luminosity value.
  f(x)=(sin(x)^13) * cos(x-PI/10)
  check the function graphed on Google: 
  https://www.google.com/search?q=f(x)%3Dx%5E2&aq=0&oq=f(x)%3Dx%5E2&sugexp=chrome,mod=0&sourceid=chrome&ie=UTF-8#hl=en&sugexp=eesh&gs_nf=3&tok=XNR9_ssPDiWlznMIqzFhTA&pq=f(x)%3Dx%5E2&cp=32&gs_id=gp&xhr=t&q=f(x)%3D(sin(x)%5E13)*cos(x-3.1416/10)&pf=p&sclient=psy-ab&oq=f(x)%3D(sin(x)%5E13)*cos(x-3.1416/10)&fp=3059d924d1e1a0d7

_heartbeat_period defines the period of the function in milliseconds.
An adult in rest has a pulse of 70 pulsations per minute aproximately, so the period is 857ms (60000/70)

[1] Stevens, Scott; Lakin, William. A Differentiable, Periodic Function for Pulsatile Cardiac 
    Output Based on Heart Rate and Stroke Volume
    http://math.bd.psu.edu/faculty/stevens/Publications/paper3.pdf
*/

const unsigned char _heartbeat_values[]  = {21,21,21,21,21,21,21,21,21,21,21,21,21,22,23,25,
  28,34,42,54,71,92,117,145,175,203,228,246,255,254,242,220,191,157,121,87,
  58,34,17,6,1,0,2,5,9,13,16,18,19,20,21,21,21,21,21,21,21,21,21,21,21,21,21,21};
const unsigned char _HEARTBEAT_INDEXES = 64;

byte ledPin = 9; //Must be PWM capable pin
//int heartbeat_period = 500; //[ms] 60000/120 (120 beats x min, baby) 
int heartbeat_period = 857; //[ms] 60000/70 (70 beats x min, adult in rest) 
//int heartbeat_period = 1000; // slower, feels like soothing


void heartbeat(){
  int index = (millis()%heartbeat_period) * _HEARTBEAT_INDEXES / heartbeat_period;
  analogWrite(ledPin, _heartbeat_values[index]);
}

void setup(){
  pinMode(ledPin,OUTPUT);  
}

void loop(){
  heartbeat();
  delay(10);  
}
