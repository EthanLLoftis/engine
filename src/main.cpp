#include "engine.h"

#include <iostream>

int main(void) {
   std::cout << "GAME ENGINE" << "\n";

   Engine e;


   e.loop(e.init());
}
