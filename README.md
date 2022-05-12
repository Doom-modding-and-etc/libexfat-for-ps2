About
-----
This port aims to provide a full-featured [exFAT](https://en.wikipedia.org/wiki/ExFAT) file system implementation for Sony Playstation 2. It only consists a library that provides mounting and unmounting exFat drivers.

Supported operating systems:
* GNU/Linux
* Mac OS X 10.5 or later
* FreeBSD
* Playstation 2

Compiling
---------

To build this library on GNU/Linux you need to install the following packages:

* [git](https://www.git-scm.com/)
* [autoconf](https://www.gnu.org/software/autoconf/)
* [automake](https://www.gnu.org/software/automake/)
* [pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config/)
* fuse-devel (or libfuse-dev)
* [gcc](https://gcc.gnu.org/)
* [make](https://www.gnu.org/software/make/)

On Mac OS X:

* autoconf
* automake
* pkg-config
* [OSXFUSE](https://osxfuse.github.io/)
* [Xcode](https://en.wikipedia.org/wiki/Xcode) (legacy versions include autotools but their versions are too old)

On OpenBSD:

* git
* autoconf (set AUTOCONF_VERSION environment variable)
* automake (set AUTOMAKE_VERSION environment variable)

Get the source code, change directory and compile:
 git clone https://github.com/Doom-modding-and-etc/libexfat-for-ps2.git
 cd libexfat-for-ps2 
 make install

Feedback
--------

If you have any questions, issues, suggestions, bug reports, etc. please create an [issue][https://github.com/Doom-modding-and-etc/libexfat-for-ps2/issues]. Pull requests are also very welcome!

# Todo-list:
- Support bdm and hdd
- Fix some compiler warnings
- Fix the library itself