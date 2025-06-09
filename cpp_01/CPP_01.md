C++ - Mo dule 01
Memory allo cation, p ointers to memb ers,
references, switch statement
Summary:
This document contains the exercises of Module 01 from C++ modules.
Version: 10


Contents
I Intro duction
 2
I I General rules
 3
I I I Exercise 00: BraiiiiiiinnnzzzZ
 5
IV Exercise 01: Moar brainz!
 6
V Exercise 02: HI THIS IS BRAIN
 7
VI Exercise 03: Unnecessary violence
 8
VI I Exercise 04: Sed is for losers
 10
VI I I Exercise 05: Harl 2.0
 11
IX Exercise 06: Harl ˝lter
 13
X Submission and p eer-evaluation
 14
1


Chapter I
Intro duction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an ex-
tension of the C programming language, or "C with Classes" (source:
 Wikipedia
).
The goal of these mo dules is to intro duce you to
Ob ject-Oriented Programming
.
This will b e the starting p oint of your C++ journey. Many languages are recommended
to learn OOP. We decided to cho ose C++ since it's derived from your old friend C.
Because this is a complex language, and in order to keep things simple, your co de will
comply with the C++98 standard.
We are aware mo dern C++ is way di˙erent in a lot of asp ects. So if you want to
b ecome a pro˝cient C++ develop er, it's up to you to go further after the 42 Common
Core!
2


Chapter I I
General rules
Compiling

Compile your co de with
c++
and the ˛ags
-Wall -Wextra -Werror

Your co de should still compile if you add the ˛ag
-std=c++98
Formatting and naming conventions

The exercise directories will b e named this way:
ex00, ex01, ... , exn

Name your ˝les, classes, functions, memb er functions and attributes as required in
the guidelines.

Write class names in
Upp erCamelCase
format. Files containing clas s co de will
always b e named according to the class name. For instance:
ClassName.hpp
/
ClassName.h
,
ClassName.cpp
, or
ClassName.tpp
. Then, if you
have a header ˝le containing the de˝nition of a class "BrickWall" standing for a
brick wall, its name will b e
BrickWall.hpp
.

Unless sp eci˝ed otherwise, every output messages must b e ended by a new-line
character and displayed to the standard output.

Goodbye Norminette!
No co ding style is enforced in the C++ mo dules. You can
follow your favorite one. But keep in mind that a co de your p eer-evaluators can't
understand is a co de they can't grade. Do your b est to write a clean and readable
co de.
Allowe d/Forbidden
You are not co ding in C anymore. Time to C++! Therefore:

You are allowed to use almost everything from the standard library. Thus, instead
of sticking to what you already know, it would b e smart to use as much as p ossible
the C++-ish versions of the C functions you are used to.

However, you can't use any other external library. It means C++11 (and derived
forms) and
Boost
libraries are forbidden. The following functions are forbidden
to o:
*printf()
,
*alloc()
and
free()
. If you use them, your grade will b e 0 and
that's it.
3


C++ - Mo dule 01
Memory allo cation, p ointers to memb ers,
references, switch statement

Note that unless explicitly stated otherwise, the
using namespace <ns_name>
and
friend
keywords are forbidden. Otherwise, your grade will b e -42.

You are allowed to use the STL in the Mo dule 08 and 09 only.
That means:
no
Containers
(vector/list/map/and so forth) and no
Algorithms
(anything that
requires to include the
<algorithm>
header) until then. Otherwise, your grade will
b e -42.
A few design requirements

Memory leakage o ccurs in C++ to o. When you allo cate memory (by using the
new
keyword), you must avoid
memory leaks
.

From Mo dule 02 to Mo dule 09, your classes must b e designed in the
Ortho dox
Canonical Form, except when explicitely stated othe rwise
.

Any function implementation put in a header ˝le (except for function templates)
means 0 to the exercise.

You should b e able to use each of your headers indep endently from others. Thus,
they must include all the dep endencies they need. However, you must avoid the
problem of double inclusion by adding
include guards
. Otherwise, your grade will
b e 0.
Read me

You can add some additional ˝les if you need to (i.e., to split your co de). As these
assignments are not veri˝ed by a program, feel free to do so as long as you turn in
the mandatory ˝les.

Sometimes, the guidelines of an exercise lo ok short but the examples can show
requirements that are not explicitly written in the instructions.

Read each mo dule completely b efore starting! Really, do it.

By Odin, by Thor! Use your brain!!!
You will have to implement a lot of classes. This can seem tedious,
unless you're able to script your favorite text editor.
You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don't be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.
4


Chapter I I I
Exercise 00: BraiiiiiiinnnzzzZ
Exercise : 00
BraiiiiiiinnnzzzZ
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
newZombie.cpp, randomChump.cpp
Forbidden functions :
None
First, implement a
Zombie
class. It has a string private attribute
name
.
Add a memb er function
void announce( void );
to the Zombie class. Zombies
announce themselves as follows:
<name>: BraiiiiiiinnnzzzZ...
Don't print the angle brackets (< and >). For a zombie named Fo o, the message
would b e:
Foo: BraiiiiiiinnnzzzZ...
Then, implement the two following functions:

Zombie* newZombie( std::string name );
It creates a zombie, name it, and return it so you can use it outside of the function
scop e.

void randomChump( std::string name );
It creates a zombie, name it, and the zombie announces itself.
Now, what is the actual p oint of the exercise? You have to determine in what case
it's b etter to allo cate the zombies on the stack or heap.
Zombies must b e destroyed when you don't need them anymore. The destructor must
print a mess age with the name of the zombie for debugging purp oses.
5


Chapter IV
Exercise 01: Moar brainz!
Exercise : 01
Moar brainz!
Turn-in directory :
ex
01
=
Files to turn in :
Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
zombieHorde.cpp
Forbidden functions :
None
Time to create a
horde of Zombies
!
Implement the following function in the appropriate ˝le:
Zombie* zombieHorde( int N, std::string name );
It must allo cate
N
Zombie ob jects in a single allo cation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
p ointer to the ˝rst zombie.
Implement your own tests to ensure your
zombieHorde()
function works as exp ected.
Try to call
announce()
for each one of the zombies.
Don't forget to
delete
all the zombies and check for
memory leaks
.
6


Chapter V
Exercise 02: HI THIS IS BRAIN
Exercise : 02
HI THIS IS BRAIN
Turn-in directory :
ex
02
=
Files to turn in :
Makefile, main.cpp
Forbidden functions :
None
Write a program that contains:

A string variable initialized to "HI THIS IS BRAIN".

stringPTR
: A p ointer to the string.

stringREF
: A reference to the string.
Your program has to print:

The memory address of the string variable.

The memory address held by
stringPTR
.

The memory address held by
stringREF
.
And then:

The value of the string variable.

The value p ointed to by
stringPTR
.

The value p ointed to by
stringREF
.
That's all, no tricks. The goal of this exercise is to demystify references which can
seem completely new. Although there are some little di˙erences , this is another syntax
for something you already do: address manipulation.
7


Chapter VI
Exercise 03: Unnecessary violence
Exercise : 03
Unnecessary violence
Turn-in directory :
ex
03
=
Files to turn in :
Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,
hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp
Forbidden functions :
None
Implement a Weap on class that has:

A private attribute
type
, which is a string.

A
getType()
memb er function that returns a const reference to
type
.

A
setType()
memb er function that sets
type
using the new one passed as param-
eter.
Now, create two classes:
HumanA
and
HumanB
. They b oth have a
Weapon
and a
name
. They also have a memb er function
attack()
that displays (of course, without the
angle brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost the same except for these two tiny details:

While HumanA takes the Weap on in its constructor, HumanB do esn't.

HumanB may
not always
have a Weap on, whereas HumanA will
always
b e armed.
8


C++ - Mo dule 01
Memory allo cation, p ointers to memb ers,
references, switch statement
If your implementation is correct, executing the following co de will print an attack
with "crude spiked club" then a second attack with "some other typ e of club" for b oth
test cases:
int
main
()
{
{
Weapon
 club
 =
 Weapon
(
"crude spiked club"
);
HumanA
 bob
(
"Bob"
,
 club
);
bob
.
attack
();
club
.
setType
(
"some other type of club"
);
bob
.
attack
();
}
{
Weapon
 club
 =
 Weapon
(
"crude spiked club"
);
HumanB
 jim
(
"Jim"
);
jim
.
setWeapon
(
club
);
jim
.
attack
();
club
.
setType
(
"some other type of club"
);
jim
.
attack
();
}
return
0
;
}
Don't forget to check for
memory leaks
.
In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.
9


Chapter VI I
Exercise 04: Sed is for losers
Exercise : 04
Sed is for losers
Turn-in directory :
ex
04
=
Files to turn in :
Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions :
std::string::replace
Create a program that takes three parameters in the following order: a ˝lename and
two strings,
s1
and
s2
.
It will op en the ˝le
<filename>
and copies its content into a new ˝le
<filename>.replace
, replacing every o ccurrence of
s1
with
s2
.
Using C ˝le manipulation functions is forbidden and will b e considered cheating. All
the memb er functions of the class
std::string
are allowed, except
replace
. Use them
wisely!
Of course, handle unexp ected inputs and errors. You have to create and turn in your
own tests to ensure your program works as exp ected.
10


Chapter VI I I
Exercise 05: Harl 2.0
Exercise : 05
Harl 2.0
Turn-in directory :
ex
05
=
Files to turn in :
Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
Forbidden functions :
None
Do you know Harl? We all do, do we? In case you don't, ˝nd b elow the kind of
comments Harl makes. They are classi˝ed by levels:

"
DEBUG
" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
Example:
"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-
ketchup burger. I real ly do!"

"
INFO
" level: These messages contain extensive information. They are helpful for
tracing program execution in a pro duction environment.
Example:
"I cannot believe adding extra bacon costs more money. You didn't put
enough bacon in my burger! If you did, I wouldn't be asking for more!"

"
WARNING
" level: Warning messages indicate a p otential issue in the system.
However, it can b e handled or ignored.
Example:
"I think I deserve to have some extra bacon for free. I've been coming for
years whereas you started working here since last month."

"
ERROR
" level: These messages indicate an unrecoverable error has o ccurred.
This is usually a critical issue that requires manual intervention.
Example:
"This is unacceptable! I want to speak to the manager now."
11


C++ - Mo dule 01
Memory allo cation, p ointers to memb ers,
references, switch statement
You are going to automate Harl. It won't b e di˚cult since it always says the same
things. You have to create a
Harl
class with the following private memb er functions:

void debug( void );

void info( void );

void warning( void );

void error( void );
Harl
also has a public memb er function that calls the four memb er functions ab ove
dep ending on the level passed as parameter:
void complain( std::string level );
The goal of this exercise is to use
p ointers to memb er functions
. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It do esn't think
twice!
Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed ab ove in the sub ject or cho ose to use comments of your own.
12


Chapter IX
Exercise 06: Harl ˝lter
Exercise : 06
Harl ˝lter
Turn-in directory :
ex
06
=
Files to turn in :
Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
Forbidden functions :
None
Sometimes you don't want to pay attention to everything Harl says. Implement a
system to ˝lter what Harl says dep ending on the log levels you want to listen to.
Create a program that takes as parameter one of the four levels. It will display all
messages from this level and ab ove. For example:
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I
'
ve been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
Although there are several ways to deal with Harl, one of the most e˙ective is to
SWITCH it o˙.
Give the name
harlFilter
to your executable.
You must use, and mayb e discover, the switch statement in this exercise.
You can pass this module without doing exercise 06.
13


Chapter X
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
???????????? XXXXXXXXXX = $3$$4f1b9de5b5e60c03dcb4e8c7c7e4072c
14
