# C-Project repository

This project is a template for implementing "perlin" noise in the terminal. It is not really the 
perlin noise algorithm, but will create some cool results nonetheless. 

It is intended to create stuff in a pretty standard order, you want to: 

1. Make sure you can get a random value between 0-255 from a function call.
2. Assign a character with more or less density based on the random value
3. Be able to print a grid of these characters, updating at regular intervalls
4. Smooth out transition by looking at a "pixels" previous value, and their neighbours
5. Implement a new degree of randomness to make sure the grid does not turn stale

## Example of a "finished" product

https://github.com/user-attachments/assets/530bf134-00ed-485d-b5c1-c2e878c05471

## Compile

g++ perlin.c out.c -o perl

## Run

./perl


