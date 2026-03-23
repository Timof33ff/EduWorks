#pragma once
#include <random>

int getRandomInt(int l, int r) {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(l, r);
  return gen(rd);
}
