@echo off
cmake -S . -B build -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cmake --build build
