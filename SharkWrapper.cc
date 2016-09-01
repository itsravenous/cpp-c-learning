#include "Shark.h"
#include "SharkWrapper.h"

extern "C" {
  Shark* newShark() {
    return new Shark();
  }

  void Shark_set_id(Shark* shark, int i) {
    shark->set_id(i);
  }

  int Shark_get_id(Shark* shark) {
    return shark->get_id();
  }

  void deleteShark(Shark* shark) {
    delete shark;
  }
}

