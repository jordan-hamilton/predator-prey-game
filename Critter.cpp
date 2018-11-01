#include "Critter.hpp"

void Critter::incrementAge() {
  age += 1;
}

void Critter::setAge(int a) {
  age = a;
}

void Critter::setHasMoved(int i) {
  if (i == 0) {
    hasMoved = false;
  } else if (i == 1) {
    hasMoved = true;
  }
}
