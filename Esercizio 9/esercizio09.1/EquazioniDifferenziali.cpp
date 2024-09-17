#include "EquazioniDifferenziali.h"
#include <cassert>
#include <cmath>

using namespace std;

bool is_close(double a, double b, double epsilon = 1e-8) {
  return fabs(a - b) < epsilon;
}

void test_euler() {
  Eulero eulero ;
  OscillatoreArmonico oa{1.0};
  const double lastt{70.0};
  const double h{0.1};
  vector<double> pos{0.0, 1.0};

  for (double t{}; t <= lastt; t += h) {
    pos = eulero.Passo(t, pos, h, &oa);
  }

  assert(is_close(pos[0], 19.773746013860173));
  assert(is_close(pos[1], 25.848774751522960));
}

