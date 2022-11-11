# SmallEncryptor
SmallEncryptor is a tiny encryptor, written in C++. There are no dependencies.

## DISCLAIMER
It requires any version of C++ that is C++17 or greater. I am not responsible for anything you do with this code.


# Usage
I know it's bad practice to store code in `.h` files, but it's a small project so it doesn't really matter.
```c++
#include <iostream>
#include "SmallEncryptor.h"

int main(int argc, char** argv){
  if(argc != 2) return 1;
  Encryptor e;
  std::string file_path = argv[1];

  std::string _f = e.ReadFile(file_path); // Read the file
  e.Encrypt(e.ReadFile(_f), file_path));  // Encrypt the file
  
  // Now if you check the file, it should be encrypted
  return 0;
}
```
