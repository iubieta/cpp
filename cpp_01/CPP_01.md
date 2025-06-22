# Cpp 01

## Ex00:
- Files: Makefile, main.cpp, Zombie.h, Zombie.cpp newZombie.cpp, randomChump.cpp
- Goal: Implement a `Zombie` class with the following:
    - String private attributte `name`
    - Function `void announce(void)`: zombie announces themselves: `name: BraiiiiiiinnnzzzZ...`
- Then implement following functions:
    - `Zombie *newZombie(std::string name)`: Creates a zombie, names it, and returns it.
    - `void randomChump(std::string name)`: Creates a zombie, names it and the zombie announces itself.
- Main point: determine when to allocate zombies on the stack or heap.
- Zombies must been destroyed when not needed anymore. Print a message with the zombie name for debugging.
