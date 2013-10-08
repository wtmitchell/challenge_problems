#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <stdexcept>
using std::exception;
using std::out_of_range;
#include <string>
using std::stoul;

#include "problems/Factory.h"
#include "util/Timer.h"
using util::Timer;

void all_problems();
void one_problem(const unsigned long problem);

int main(int argc, char **argv) {
  bool usage = false;

  try {
    if (argc > 2)
      usage = true;
    else if (argc == 2)
      one_problem(stoul(argv[1]));
    else
      all_problems();
  }
  catch (out_of_range oor) {
    usage = true;
    cerr << "Number too large.\n";
  }
  catch (exception ia) {
    usage = true;
  }

  if (usage) {
    cerr << "Invalid usage. Pass either a number or nothing to run all" << endl;
    return 1;
  }

  return 0;
}

void all_problems() {
}

void one_problem(const unsigned long problem) {
  auto p = problems::Factory::create(problem);

  Timer t;

  t.start();
  p->solve();
  t.stop();

  cout << p->answer() << "\n"
       << "Time elapsed: " << t << endl;
}
