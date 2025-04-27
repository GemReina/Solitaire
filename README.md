# Solitaire
This repository contains the final project for the course Methodology and Technology of Programming II at the University of Girona.
The project consists of implementing a command-line version of the classic Solitaire card game, following the specifications provided by the professors.

The code is commented in Catalan.

## Project Description
Solitaire is a well-known single-player card game that aims to organize cards into four ordered piles, one for each suit, from Ace to King.
This version has been developed using C++, respecting the structure and behavior outlined in the project statement.

## Key Features
- Full implementation of Solitaire's game mechanics.
- Command-line interface (CLI) with a menu-driven system.
- Ability to move cards between the tableau, foundation piles, and discard piles according to the rules.
- Additional options like spying the board (revealing all hidden cards) and restarting the draw pile.
- Well-structured object-oriented code with classes like Card, Deck, Board, Pile, and Game.
- Random shuffling of the deck using the Fisher-Yates algorithm.

## How to Compile and Run
You need a C++ compiler (like g++).

***bash***
```
g++ -o solitaire main.cpp
./solitaire
```

## File Structure
- main.cpp: Main program (user interaction and game loop).
- Carta.h/cpp: Card representation.
- Baralla.h/cpp: Deck management and shuffling.
- PilaCartes.h/cpp: Management of card piles.
- Tauler.h/cpp: Management of the tableau.
- Joc.h/cpp: Game logic management.

## Authors
Gemma Reina

## License
This project is intended for educational purposes only.
