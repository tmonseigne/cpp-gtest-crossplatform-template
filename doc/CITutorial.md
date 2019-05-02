# CI Tutorial

## Travis (Linux & Mac OS Build)

To use [travis](https://travis-ci.org/), you need to create a yml file. By connecting to the site and linking it to your github account, you can see all your repositories and activate those that interest you.  
The yml file indicates the configuration of a virtual machine and a set of script to launch, For our example:

~~~{.py}
sudo: false							# don't use sudo command each time
language: cpp						# language initialization

git:
  submodules:
    true							# Initialize submodules

os: linux							# OS choice
dist: xenial						# Distribution choice. By default it's Trusty.

# Package installation
addons:
  apt:
    update: true					# Equivalent to run : sudo apt-get update
    packages:
      - lcov						# Code Coverage
      - valgrind					# Memory Leaks

script:
  # Building phase
  - mkdir -p build && cd build		# Create and go to a folder
  - cmake -DCODE_COVERAGE=ON ..		# Initialize build with code coverage option
  - cmake --build .					# Build project
  # Running phase
  - valgrind --leak-check=full --show-leak-kinds=all ./Hello --gtest_output="xml:../doc/GoogleTestReport.xml"	# Run project with google Tests (with valgrind option)
  - lcov --directory . --capture --output-file coverage.info													# Code Coverage analysis
  - lcov --remove coverage.info 'googletest/*' '/usr/include/*' '/usr/lib/*' -o coverage.info					# Code Coverage cleaner
  - bash <(curl -s https://codecov.io/bash) -f coverage.info || echo "Codecov did not collect coverage reports"	# Send to codecov

notifications:
  email: false						# Don't send email notification
~~~

## Appveyor (Windows Build)

[Appveyor](https://ci.appveyor.com) works on the same principle as travis except that it is possible to configure the system directly on the site (and thus avoid some test commit at the beginning of the implementation of continuous integration).

~~~{.py}
version: 1.0.{build}
image: Visual Studio 2019 Preview
configuration: Release
platform: x64
install:
- ps: git submodule --quiet update --init --recursive	# Initialization of submodules (quiet is necessary to avoïd error on submodules initialization)
build:
  project: hello.sln									# Name of sln
  parallel: true										# Enable parallelisation build
  verbosity: minimal									# Limit verbosity of build 
~~~

## Codecov (Code Coverage)

In this example, I use the travis Ubuntu build and the [lcov package](http://ltp.sourceforge.net/coverage/lcov.php). If you have an acocunt link to your github in the [codecov](https://codecov.io/) website the lines on the `.travis.yml` file are enough.

## Codedocs (Doxygen Documentation Generator)

If you have an acocunt link to your github in the [Codedocs](https://codedocs.xyz/) website, he generate your documentation on each commit. I use the `.codedocs` file to indicate the `Doxyfile` but the different option can be set in this file instead of using Doxyfile (but it's more complicated to set up and test locally.) 