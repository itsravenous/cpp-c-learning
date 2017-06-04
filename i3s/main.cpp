#include "incl/fingerprint.hpp"
#include "incl/compare.hpp"
#include <stdio.h>

int main(int argc, char** argv) {
  double refs[] = { 0.0, 0.0, 100.0, 100.0, 0.0, 100.0 };
  double spots[] = {
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0, 30.0,
    40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0
  };
  double refs2[] = { 0.0, 0.0, 100.0, 100.0, 0.0, 100.0 };
  double spots2[] = {
    15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0, 15.0,
    20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0,
    37.0, 37.0, 37.0, 37.0, 37.0, 37.0, 37.0, 37.0,
    40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0, 40.0
  };
  int count = 4;
  FingerPrint fgp(refs, spots, count);
  FingerPrint fgp2(refs2, spots2, count);
  Pair *pairs = new Pair[100];
 	int paircnt = 0;
 	Compare::compareTwo(fgp2, fgp, pairs, &paircnt);
 	printf("Score: %f\n", fgp.getScore());
}
