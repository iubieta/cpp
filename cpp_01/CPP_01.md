# Cpp 01

## Ex00:
- Files: Makefile, main.cpp, Zombie.h, Zombie.cpp, newZombie.cpp, randomChump.cpp
- Goal: Implement a `Zombie` class with the following:
    - String private attributte `name`
    - Function `void announce(void)`: zombie announces themselves: `name: BraiiiiiiinnnzzzZ...`
- Then implement following functions:
    - `Zombie *newZombie(std::string name)`: Creates a zombie, names it, and returns it.
    - `void randomChump(std::string name)`: Creates a zombie, names it and the zombie announces itself.
- Main point: determine when to allocate zombies on the stack or heap.
- Zombies must been destroyed when not needed anymore. Print a message with the zombie name for debugging.

## Ex01:
- Files: Makefile, main.cpp, Zombie.h, Zombie.cpp, zombieHorde.cpp
- Goal: implement `Zombie *zombieHorde(int n, std::string name)` function:
    - It must allocate `n` Zombie objects in a single allocation.
    - Then initialize them with the given name.
    - Function returns a pointer to first zombie.
- Announce and delete all the zombies.
