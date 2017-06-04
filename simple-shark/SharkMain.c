#include "SharkWrapper.h"
#include "stdio.h"

int main(int argc, char* argv) {
  struct Shark* shark = newShark();
  Shark_set_id(shark, 71);
  printf("Shark id is %i\n", Shark_get_id(shark));
  deleteShark(shark);
}
