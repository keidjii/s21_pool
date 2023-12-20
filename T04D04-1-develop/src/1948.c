#include <math.h>
#include <stdio.h>

int ispros(int a); //являтся ли число простым,  если да возвращает один
int del(int a, int b); //проверяет делимость a на b, если да вернет 1
int maxpr(int a); //ищет простой делитель

int main() {
  int a;
  char c;
  if (scanf("%d%c", &a, &c) == 2 && c == '\n')
    printf("%d", maxpr(a));
  else
    printf("ekfsda");
  return 0;
}

int del(int a, int b) {
  // int i;
  while (a > 0)
    a = a - b;

  if (a == 0)
    return 1;
  else
    return 0;
}

int ispros(int a) {
  for (int i = a - 1; i > 1; i--) {
    if (del(a, i))
      return 0;
    else
      continue;
  }
  return 1;
}

int maxpr(int a) {
  if (a < 0)
    a = fabs(a);
  for (int i = a; i > 0; i--)
    if (del(a, i) && ispros(i))
      return i;
  return 0;
}




