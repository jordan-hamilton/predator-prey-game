#include "Critter.hpp"

void Critter::incrementAge() {
  age += 1;
}

void Critter::setAge(int a) {
  age = a;
}

void setHasMoved(int i) {
  if (i == 0) {
    hasMoved = false;
  }
  else (i == 1) {
    hasMoved = true;
  }
