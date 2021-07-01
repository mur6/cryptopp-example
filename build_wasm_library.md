# Cryptopp for wasm
## 静的ライブラリのビルド
wasm向けに、静的ライブラリをビルドする方法。
```sh
cd cryptopp
emmake make CXXFLAGS="-mno-bulk-memory" static
```
safari対応のために、`-mno-bulk-memory`オプションをつけてビルドする。


## サンプルプログラムのビルド
```sh
em++ -I./cryptopp -L./cryptopp -lcryptopp -mno-bulk-memory -o main.js main.cpp
```
