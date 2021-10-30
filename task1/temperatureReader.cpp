#include <cctype>   // char-behandling
#include <cstring>  // strengbehandling
#include <iostream> // innlesing/utskrift
#include <cstdlib>
#include <fstream>

using namespace std; // bruker standard navnerom

void read_temperatures(double temperatures[], int length);

int main() {                // ikke void her!
  const int length = 5;

  double temperatures[length];
  double temperature;
  
  //Read temperatures from file
  read_temperatures(temperatures, length);


  //Read in temperatures from console
  /*for (int i = 0; i < length; i++) {
      cout << "Temperatur " << i+1 << ":";
      cin >> temperature;
      temperatures[i] = temperature;
  }*/

  int under10 = 0;
  int under21 = 0;
  int over20 = 0;

  for (int i = 0; i < length; i++) {
      if (temperatures[i] < 10)
      {
          under10++;
      } else if (temperatures[i] < 21)
      {
         under21++;
      } else {
          over20++;
      }
  }

  cout << "Antall under 10 er: " << under10 << endl;
  cout << "Antall mellom 10 og 20 er: " << under21 << endl;
  cout << "Antall over 20 er: " << over20 << endl;
  
  return 0;
}

void read_temperatures(double temperatures[], int length) {
     const char filename[] = "temperaturer.txt";

     ifstream file;
  file.open(filename);
  if (!file)
  {
      cout << "finner ikke filen." << endl;
  }

  double number;
  for (size_t i = 0; i < length; i++)
  {
      double number;
      file >> number;
      temperatures[i] = number;
  }
}