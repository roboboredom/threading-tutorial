#!/bin/bash
# bash script to run different compile / linking steps easily


# include paths (.h):
inc_root="-I ../include"
inc_engine="-I ../include/engine"
inc_project="-I ../include/project \
             -I ../include/project/clients"

# source paths (.cpp):
src_root="../src/*.cpp"
src_engine="../src/engine/*.cpp"
src_project="../src/project/*.cpp \
             ../src/project/clients/*.cpp"


# make build dir; if not exist, move to it
mkdir -p build; cd build;

# get input
echo -n "What to build? ('engine', 'project'): "
shopt -s nocasematch; read input

# act on input
case $input in

  engine)
    echo "Building engine..."
    g++ -o engine \
    $inc_root $inc_engine \
    $src_root $src_engine \
    -pthread
    echo "...finished!"
    ;;

  project)
    echo "Building project..."
    g++ -o project \
    $inc_root $inc_engine $inc_project \
    $src_root $src_engine $inc_ \
    -pthread
    echo "...finished!"
    ;;

  *)
    echo "Invalid argument!"
    ;;
esac