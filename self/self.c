#include <stdio.h>

bool isProperSubset(const IntegerSet& a, const IntegerSet& b);

bool operator < (const IntegerSet& a, const IntegerSet& b) {

  if(isProperSubset(a, b)) return true;

  if(isProperSubset(b, a)) return false;

  return false;
}

bool operator > (const IntegerSet& a, const IntegerSet& b) {

  if(isProperSubset(a, b)) return true;

  if(isProperSubset(b, a)) return false;

  if(a,size() != b.size()) return a.size() < b.size();

  return lexicoraphic_compare(a.begin(), a.end(), b.begin(), b.end());
}

bool isPrime(int n) {
  if(n % 2 == 0) return false;
  for(int i = 2; i < n; ++i)
    if(n % i == 0)
      return false;
  return true;
}

bool isPrime(int n) {
  if(n == 2) return true;
  if(n % 2 == 0) return false;
  for(int i = 2; i < n; ++i)
    if(n % i == 0)
      return false;
  return true;  
}

int main(void) {
  

  return 0;
}