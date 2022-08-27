#ifndef PERSONA_H 
#define PERSONA_H
#include <string>
class Persona //Declaramos la unica clase con el nombre Persona
{
private:    
  std::string nombre;
  int edad;
  float estatura;
  float peso;   
  float aumentaEstatura(float metros){return estatura += metros};
  float aumentaPeso(float kilogramos){return peso += kilogramos};
  
public:      /
  Persona(const std::string& nombre,int edad, float peso, float estatura); // Constructor
  void saluda();
  int cumpleAnios();
};
#endif