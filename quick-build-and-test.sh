#!/bin/bash
# bash script to run different compile / linking steps easily

shopt -s nocasematch; # ignore letter case
mkdir -p build; cd build # make build dir; if not exist, move to it


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

#other vars 
timestamp=$(date '+%F_%H-%M-%S')


# prompt on what to build
echo -n "What to build? ('engine', 'project'): "; read input

case $input in
  engine | e)
    echo -e "Building engine...\n"
    
    executable_name="engine-$timestamp.exe"
    
    g++ -o $executable_name \
    $inc_root $inc_engine \
    $src_root $src_engine \
    -pthread
    
    echo -e "\n...finished!"
    ;;
    
  project | p)
    echo -e "Building project...\n"
    
    executable_name="project-$timestamp.exe"
    
    g++ -o $executable_name \
    $inc_root $inc_engine $inc_project \
    $src_root $src_engine $src_project \
    -pthread
    
    echo -e "\n...finished!"
    ;;
    
  *)
    echo "Invalid input, skipped."
    ;;
esac


# prompt to if to run the built exe or not
echo -n "Run $executable_name? (yes, no): "; read input

case $input in
  yes | y)
    echo -n "Running $executable_name ..."; echo -e "\n"

    ./$executable_name
    
    echo -e "\n...program exited."
    ;;
    
  no | n)
    echo "Skipped."
    ;;
    
  *)
    echo "Invalid input, skipped."
    ;;
esac


cd .. #go back to root dir