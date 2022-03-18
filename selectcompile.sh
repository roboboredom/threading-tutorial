#!/bin/bash
#bash script to run different compiles easily

mkdir -p build; cd build; #navigate to build dir, if not exist make it

shopt -s nocasematch
echo -n "What to compile? (\'all\'): "
read module
case $module in
all)
  echo "Recompiling all...";
  
  g++ -c test -I ../include -I ../include/engine -I ../include/project -I ../include/project/clients ../src/*.cpp ../src/engine/*.cpp; #../src/project/*.cpp ../src/project/clients/*.cpp;
  
  echo "...finished!"
  ;;

*)
  echo "Invalid argument!"
  ;;
esac

./test; #run program
cd ..; #move back to root dir to avoid issues

#reference:
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
#   "-I ../include "
#   "-I ../include/engine "
#   "-I ../include/project "
#   "-I ../include/project/clients "
#
# set source paths (.cpp):
#   "../src/*.cpp "
#   "../src/engine/*.cpp "
#   "../src/project/*.cpp "
#   "../src/project/clients/*.cpp "
#
# link libraries:
#   "-pthread; "
# 
# run built program:
#  "./project"