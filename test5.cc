#include <iostream>
#include <cstdio>

using namespace std;

extern int i;
extern float f(float);

float b;
float f(float a) {
  return a + 1.0;
}

int i;
int h(int x) {
  return x + 1;
}

int main() {
  b = 1.0;
  i = 2;
  cout << f(b) << endl;
  cout << h(i) << endl;
}
