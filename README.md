# Runescape decanting calculator

## Description
A calculator to evaluate Runescape potion decantments

For example

3 1/4th potions == 3/4ths of a potion

900 3/th potions = 675 4/4th potions  

## Requirements

### Linux
make

### Windows
cc/gcc via mingw or equivalent

## Setup
Use prexisting binaries in ```bin ```
### Linux
make steps
### Windows (w/o make)
```
git clone https://github.com/Wamadahama/Runescape-Decanting-Calculator.git
cd Runescape-Decanting-Calculator/
cc -std=c99 src\Decanter.c -o bin\decanter  
```
