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

void mySort(vector<int>& arr);

string toString(const vector<int>& array);

int main(void) {
  
  while(true) {
    int n = rand() % 100 + 1;
    vector<int> input(n);
    for(int i = 0; i < n; ++i)
      input[i] = rand();
    
    vector<int> mySorted = input;
    mySort(mySorted);
    vector<int> reference = input;
    sort(reference.begin(), reference.end());

    if(mySorted != reference) {
      cout << "Mismatch found!" << endl;
      cout << "Input: " << toString(input) << endl;
      cout << "My Sort: " << toString(mySorted) << endl;
      cout << "Reference: " << toString(reference) << endl;
      break;
    }
  }

  return 0;
}