#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <stdexcept>
#include <string>
using std::stoul;

#include "project_euler/Factory.h"
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
  catch (std::out_of_range e) {
    usage = true;
    cerr << "Out of Range Exception: " << e.what() << "\n";
  }
  catch (std::invalid_argument e) {
    usage = true;
    cerr << "Invalid Argument Exception: " << e.what() << "\n";
  }
  catch (std::logic_error e) {
    usage = true;
    cerr << "Logic Error: " << e.what() << "\n";
  }
  catch (std::runtime_error e) {
    usage = true;
    cerr << "Runtime Error: " << e.what() << "\n";
  }
  catch (std::exception e) {
    usage = true;
    cerr << "Exception: " << e.what() << "\n";
  }

  if (usage) {
    cerr << "Invalid usage. Pass either a number or nothing to run all" << endl;
    return 1;
  }

  return 0;
}

void all_problems() {
  auto list = project_euler::Factory::list();

  Timer total, individual;

  total.start();
  for (const auto n : list) {
    auto p = project_euler::Factory::create(n);
    individual.start();
    p->solve();
    individual.stop();
    cout << p->description() << "\n" << p->answer() << "\n"
         << "Time elapsed: " << individual << "\n";
  }
  total.stop();

  cout << "Total time elapsed: " << total << endl;
}

void one_problem(const unsigned long problem) {
  auto p = project_euler::Factory::create(problem);

  Timer t;

  t.start();
  p->solve();
  t.stop();

  cout << p->description() << "\n" << p->answer() << "\n"
       << "Time elapsed: " << t << endl;
}
