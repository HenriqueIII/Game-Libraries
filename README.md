# Game-Library
This library implements some classes to manipulate I/O from screen, non-blocking **TO/DO**, random numbers generators and handling coordinates.

## Dependencies

The part of the screen I/O uses some functions of <curses.h>, so its a dependency.
> Therefore, if you need to distribute the binary, to ensure compatibility, you must include a copy of ncurses (for Linux/OS X) or pdcurses (for Windows), shared or static.
Please refer to their page to learn how to compile their packages.

* Ubuntu
To accomplish compilation just install the packages bellow 
```
sudo apt install libncurses5-dev libncursesw5-dev
```

## Compiling
* ### Shared Library

```
git clone
cd Game-Library
make
```
Now you should have a shared lib(.so) in the lib folder that you can use.

* ### Static Library

```
git clone
cd Game-Library
make static
```

## Usage

Below you can find how to use this library:

### Point

#### Constructors

* Point(int xT, int yT);
    Make a point with the values x = xT and y = yT

* Point();
    Make a point without values for x and y

#### Methods

* Point add(const Point & p) const;

    Return the addition of **p** to **this** without modifying values of **x** and **y**

* Point & addEqual(const Point & p);

    Return the addition of **p** to **this** modifying the values of **x** and **y** of **this**

* Point sub (const Point & p) const;

    Return the subtration of **p** to **this** without modifying values of **x** and **y**

* int getX() const;

    Return the value of **x**

* int getY() const;

    Return the value of **y**

* bool isEqual(const Point & p) const;

    Return true if **p** has the same coordinates as **this**

* Point & rotateRight();

    Modifies **this** with rotation of 90º to the right