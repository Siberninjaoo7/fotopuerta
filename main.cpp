#include "TextLCD.h"
#include "iostream"
#include "mbed.h"
#include <chrono>
#include <cstdlib>
#include <ostream>
using namespace std ::chrono;
DigitalOut arregloCol[3] = {D6, D7, D8};
DigitalIn arregloFil[4] = {D2, D3, D4, D5};
int teclado[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 0, 0}};
UnbufferedSerial Serial(USBTX, USBRX, 9600);
AnalogIn entrada(A0), entrada2(A2);
float volt1 = 0, volt2 = 0;
// puertos para el lcd
TextLCD display(D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);

int main() {
  int xFuncion = -1, yFuncion = -1;
  Timer t;
  float tiempo;
  bool puerta1 = false;
  bool puerta2 = false;
  while (true) {
    display.locate(0, 1);
    volt1 = entrada.read();
    volt2 = entrada2.read();
    int valor1 = 0;
    int valor2 = 0;

    if (volt1 < 0.23 && !puerta1 && !puerta2) {
      cout << "Nigger" << endl;
      t.start();
      puerta1 = true;
      puerta2 = true;
    }

    if (volt2 < 0.05 && puerta2 && puerta1) {
      cout << "Juan" << endl;
      t.stop();
      tiempo = t.elapsed_time().count()/1000000.0;
      puerta2 = true;
      cout << "Tiempo: " << tiempo << endl;
      // display.printf("Tiempo: ");
      // string temp = (string)tiempo;
      // display.printf(temp);
      float velocidad = 0.1 / tiempo;
      cout << "Velocidad: " << velocidad<<endl;
      // string vel = (string)velocidad;
      // display.printf(vel);
      cout << "Aceleracion: " << (0.1*2) / (tiempo*tiempo) << endl;
      // string ac = (string)(velocidad / tiempo);
      // display.printf(ac);
      tiempo = 0;
      puerta1 = false;
      puerta2 = false;
      t.reset();
    }
  }
  xFuncion = -1;
  yFuncion = -1;
}
