# detect

### OverView
Detect enumerates all the files contained in the specified path, specifying a character with the -s option enumerates all files and directories containing that character.
For example, if you want to detect a file with extension cpp,use as follows.

```
shichimi:~/detect: $ ./detect /Users/shichimi/detect/ -s cpp
/Users/shichimi/detect/main.cpp
/Users/shichimi/detect/CMakeFiles/3.7.1/CompilerIdCXX/CMakeCXXCompilerId.cpp
/Users/shichimi/detect/CMakeFiles/detect.dir/main.cpp.o
/Users/shichimi/detect/CMakeFiles/detect.dir/src/detect.cpp.o
/Users/shichimi/detect/CMakeFiles/detect.dir/src/option.cpp.o
/Users/shichimi/detect/src/detect.cpp
/Users/shichimi/detect/src/option.cpp
...
..
.
any...
any..
any.

```

[![](https://img.shields.io/badge/Language-C%2B%2B-ff69b4.svg)](https://isocpp.org/)
[![](https://img.shields.io/apm/l/vim-mode.svg)](https://github.com/keisukeYamagishi/SHIDirection/blob/master/LICENCE.txt)
[![](https://img.shields.io/badge/Twitter-O--Linker__Error-blue.svg)](https://twitter.com/O_Linker_Error)


### Build status of each OS

|OS|build|result|
|:------|:------|:------|
|***mac OS X***|[![Build Status](https://travis-ci.org/keisukeYamagishi/detect.svg?branch=master)](https://travis-ci.org/keisukeYamagishi/detect)|passing|
|***Ubunts***|[![Build Status](https://travis-ci.org/keisukeYamagishi/detect.svg?branch=master)](https://travis-ci.org/keisukeYamagishi/detect)|passing|

## git clone

***Via SSH***: For those who plan on regularly making direct commits, cloning over SSH may provide a better experience (which requires uploading SSH keys to GitHub):

```
mkdir gitrepo

cd gitrepo

git clone git@github.com:keisukeYamagishi/detect.git

```

***Via https***: For those checking out sources as read-only, HTTPS works best:

```
mkdir gitrepo

cd gitrepo

git clone https://github.com/keisukeYamagishi/detect.git

```

### Build 

#### Get CMake(mac OS only)


Please install the .dmg file of Mac OSX 10.6 or later list. Please run it if you want to install the following command.

***homebrew***

```
brew install cmake
```

Check whether cmake has been installed or not by the following command.

```
cmake --version
```
If cmake's version is displayed installation is complete, detect's Cmake version will be 2.7. If it is more than that, you can build it.

### mac OS X(mac OS X only)

MakeFile is output if you move to the immediate clone source directory and execute the cmake command, please execute the make command, if executed, the detect binary will be output.

```
cd /source_directory/gitrepo

cmake .

make 

```

## Use it 

```
shichimi:~/detect: $ ./detect
usage: detect [--version] [<path>] [-s search=value]

These are common detect commands used in various situations:

detect version: 1.0.0

option: 

-s set search value 
-v output detedt version number

Regars !
```
#### Specify the path you want to search first, and specify the character string you want to search in option -s.
```
shichimi:~/detect: $ ./detect /Users/shichimi/detect/ -s cpp
/Users/shichimi/detect//main.cpp
/Users/shichimi/detect//CMakeFiles/3.7.1/CompilerIdCXX/CMakeCXXCompilerId.cpp
/Users/shichimi/detect//CMakeFiles/detect.dir/main.cpp.o
/Users/shichimi/detect//CMakeFiles/detect.dir/src/detect.cpp.o
/Users/shichimi/detect//CMakeFiles/detect.dir/src/option.cpp.o
/Users/shichimi/detect//src/detect.cpp
/Users/shichimi/detect//src/option.cpp

```
#### If you do not specify any string in the option -s, it enumerates all the files in the specified path.

```
shichimi:~/detect: $ ./detect /Users/shichimi/detect/
/Users/shichimi/detect/.git
/Users/shichimi/detect/.gitignore
/Users/shichimi/detect/cmake_install.cmake
/Users/shichimi/detect/CMakeCache.txt
/Users/shichimi/detect/CMakeFiles
/Users/shichimi/detect/CMakelists.txt
/Users/shichimi/detect/detect
/Users/shichimi/detect/LICENSE
/Users/shichimi/detect/main.cpp
/Users/shichimi/detect/Makefile
any...file
any
any

```

