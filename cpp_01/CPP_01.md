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

## Ex02:
- Files: Makefile, main.cpp
- Goal: a program that contains:
    - String initialized to "HI THIS IS BRAIN"
    - stringPTR
    - stringREF
- Program must print the memory address and value of each variable

## Ex03:
- Files: Makefile, main.cpp, Weapon.h , Weapon.cpp, HumanA.h, HumanA.cpp, HumanB.h, HumanB.cpp
- Goals:
    - Implement Weapon class with:
        - Private `type` string attribute
        - `getType()` function that returns a const reference to `type`
        - `setType()` function that sets `type` using a string passed as a parameter
    - Create two classes, `HumanA` and `HumanB`, with:
        - `name`
        - `Weapon`
        - `attack()` function that displays: "<name> attacks with their <weapon type>" 
    - `HumanA` takes the Weapon in its constructor, `HumanB` doesnt.
    - `HumanB` may not always hace a Weapon, whereas `HumanA` yes.

- Testing code:
    ```c++
        int main()
        {
            {
                Weapon club = Weapon("crude spiked club");
                HumanA bob("Bob", club);
                bob.attack();
                club.setType("some other type of club");
                bob.attack();
            }
            {
                Weapon club = Weapon("crude spiked club");
                HumanB jim("Jim");
                jim.setWeapon(club);
                jim.attack();
                club.setType("some other type of club");
                jim.attack();
            }
            return 0;
        }
    ```
- Expected result:
    ```
    Bob attacks with their crude spiked club
    Bob attacks with their some other type of club
    
    Jim attacks with their crude spiked club
    Jim attacks with their some other type of club
    ```
## Ex04:
- Files: Makefile, main.cpp, *.cpp, *.h 
- Forbidden: `std::string::replace`
- Goal: Create a program that takes three parametres `filename`, `s1` y `s2`.
Opens the file and copies it into `filename.replace` replacing every occurrence of `s1 ` with `s2`.
- Every function of string class except `replace` are allowed.
