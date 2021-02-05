### Primitive types

1. Bit manipulation
  Clears lsb = x & (x-1)
	Get lsb = x & ~(x-1)
	Grey code = x ^ (x>>1)
2. Generate power set using bits
  ```c++
  for(int i=0; i< (1<<S.size()); i++) {
    Int x = i;
    while(x) {
      Int index = log2(x & ~(x-1));
      cout<<S[index];
      if(x &= x-1)
        cout<<”,”
    }
    cout<<endl;
  }
  ```


### Maths

1. GDC
  ```c++
  int gcd(int a, int b)
  {
      if (b == 0)
          return a;
      return gcd(b, a % b);

  }
  ```
