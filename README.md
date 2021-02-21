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

        Return the addition of p with this, without modifying values of x and y

* Point & addEqual(const Point & p);

        Return the addition of p with this, modifying the values of x and y of this

* Point sub (const Point & p) const;

        Return the subtration of p with this without modifying values of x and y

* int getX() const;

        Return the value of x

* int getY() const;

        Return the value of y

* void setX(int xT);

        Sets the value of x with xT

* void setY(int yT);

        Sets the value of y with yT

* bool isEqual(const Point & p) const;

        Return true if p has the same coordinates as this

* Point & rotateRight();

        Modifies this with rotation of 90º to the right

### Random
Makes a namespace Random with some methods that generates pseudo-random Numbers and Points.
It uses srand() and random() from <cstdlib> as well <ctime>

#### Constructor
*void init (unsigned s);
        Initializes random number generator with a seed. This is useful for debugging. 
*void init ();
        Initializes random number generator with a seed generated from current time

#### Methods
* unsigned get (unsigned max);
        Get a random number between zero and max 
* unsigned get (unsigned min, unsigned max);
        Get a random number between min and max
* Point get(Point min, Point max);
        Get a random Point within min and max
* Point random();
        Get a random Point in the current display space

### Display
Emulates a screen with dimension 80*24. It uses curses library.
It's a singletone class, that creates the object dsp globally.

As soon as you include <Display.h> it will start curses mode.

#### Moving cursor
* void dsp.setCursor(int x, int y);
        Move the cursor to the position (x,y)

#### Methods for writing
* void dsp.putc(int chr);
        Writes chr on the screen at the current position
* void dsp.putc(int x, int y, int chr, int col = WHITE);
        Writes chr on the screen at coordinates (x,y) in col colour
        You can use the following colors: Display::BLACK, Display::RED, Display::GREEN, Display::YELLOW, Display::BLUE, Display::MAGENTA, Display::CYAN, Display::WHITE, Display::BBLACK, Display::BRED, Display::BGREEN, Display::BYELLOW, Display::BBLUE, Display::BMAGENTA, Display::BCYAN, Display::BWHITE
* void dsp.puts(const char * str);
        Writes at the current location the string str

#### Methods to manipulate terminal
* void dsp.setForeground(int color);
        Changes the letter colour to one of the following: Display::BLACK, Display::RED, Display::GREEN, Display::YELLOW, Display::BLUE, Display::MAGENTA, Display::CYAN, Display::WHITE, Display::BBLACK, Display::BRED, Display::BGREEN, Display::BYELLOW, Display::BBLUE, Display::BMAGENTA, Display::BCYAN, Display::BWHITE
* void dsp.setBackground(int color);
        Changes background of the text to one of the following: Display::BLACK, Display::RED, Display::GREEN, Display::YELLOW, Display::BLUE, Display::MAGENTA, Display::CYAN, Display::WHITE
* void dsp.cursorOff();
        Hides cursor
* void dsp.cursorOn();
        Shows cursor
* void dsp.windowClear();
        Cleans the window
* void dsp.getWindow();
        returns the window pointer. It's useful if is needed to use some function of curses