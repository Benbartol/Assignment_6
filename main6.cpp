//Ben Bartol
//ID: 2315721
//CPSC 350 Rene German

#include <iostream>
#include <stdio.h>
#include "assignment6.h"
using namespace std;

int main(int argc, char *argv[]){
  Sorting s;


  if(argc < 2){
    cout << "Error... Enter Valid File Input" << endl;
  }else if(argc >= 2){
    string file = argv[1];
    s.setFile(file);
  }
  return 0;
}
