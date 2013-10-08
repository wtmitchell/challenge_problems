#include <iostream>
using std::cout;
using std::endl;

#include "problems/Factory.h"
#include "util/Timer.h"
using util::Timer;

int main(int argc, char **argv) {

  auto problem = problems::Factory::create(1);

  Timer t;

  t.start();
  problem->solve();
  t.stop();

  cout << problem->answer() << endl;
  cout << "Time elapsed: " << t << endl;

  return 0;
}
