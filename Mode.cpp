

int mode(const int dataset[], const int size, int modes[])
{
  if(size < 0){
    return -1;
  }
  if(size < 1){
    return 0;
  }
  //int sortedSet[size] = dataset; 
  int temp; 
  int changes = 1;
  int counter = 0;
  int mode = 0;
  int amount = 0;
  int largest = 0;
  while(counter < size){
    for(int i = counter; i < size; i++){
      if(dataset[counter] == dataset[i + 1]){
        amount += 1;
      }
    }
    if(amount > largest){
      largest = amount;
    } 
    amount = 0;
    counter++;
  }
  counter = 0;
  while(counter < size){
    for(int q = counter; q < size; q++){
      if(dataset[counter] == dataset[q + 1]){
        amount += 1;
      }
    }
    if(amount == largest){
      modes[mode] = dataset[counter];
      mode++;
    } 
    amount = 0;
    counter++;
  }
  while(changes > 0){
    changes = 0;
    for(int j = 1; j < mode; j++){
      if(modes[j -1] - modes[j] > 0){
        temp = modes[j - 1];
        modes[j - 1] = modes [j];
        modes[j] = temp;
        changes += 1;
      }
    }
  }
  return mode;
}


#ifndef MARMOSET_TESTING

/*
 * Marmoset doesn't see anything in here
 *
 * Use this space to test your code
 */

#include <cstdlib>  // atoi
#include <iostream> // cout, endl

using namespace std;

#define MIN_ARGS 0

int main(const int argc, const char* const argv[])
{
  if (argc < MIN_ARGS)              // not enough inputs
    return -1;

  int sz = argc - 1;                // 1 for name
  int input[sz];                    // to hold inputs

  for (int i = 0; i < sz; ++i)      // loop over all inputs, store in array
    input[i] = atoi(argv[i + 1]);   // atoi = string to integer

  int modes[sz];                    // there will be at most as many modes
                                    // as there are numbers

  int ret = mode(input, sz, modes); // call the function

  cout << "Function returned: " << ret << " modes" << endl;

  cout << "Modes were:";
  for (int i = 0; i < ret; ++i)     // loop over and print all modes
    cout << ' ' << modes[i];
  cout << endl;

  return 0;
}

#endif
