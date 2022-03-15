#!/bin/bash

shopt -s nocasematch
echo -n "What to compile? (\'all\'): "

read module
case $module in
all)
  echo "Recompiling all...";
  
  mkdir -p build; cd build;
  g++ -o project -I ../src -I ../src/engine ../src/*.cpp ../src/engine/*.cpp -pthread;
  
  echo "...finished!"
  ;;

*)
  echo "Invalid argument!"
  ;;
esac

# make build folder if not exist
#   "mkdir -p build; "
#
# start in build folder
#   "cd build; "
#
# call g++ and set output name:
#   "g++ -o project " 
#
# set include paths (.h):
#   "-I ../src "
#   "-I ../src/engine "
#
# set source paths (.cpp):
#   "../src/*.cpp "
#   "../src/engine/*.cpp "
#
# link libraries:
#   "-pthread; "
# 
# run built program:
#  "./project"