# Cryptopp example

## 1. Build static library
```
cd cryptopp
make static
```

## 2. Build example (with clang)
```
clang++ -I./cryptopp -L./cryptopp -lcryptopp -o main main.cpp
```

## 3. Run
```
$ ./main
Message: 05080C0E010E06000101010101010101060406010704060100000000
Digest: 0EA5E034142BDECC5D3AEC9DE727EE836BF95E1D
```

## 参考サイト
[HMAC - Crypto++ Wiki](https://www.cryptopp.com/wiki/HMAC)
