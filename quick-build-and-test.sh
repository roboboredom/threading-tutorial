#!/bin/bash
# bash script to run different compile / linking steps easily

shopt -s nocasematch; # ignore letter case
mkdir -p build; cd build # make build dir; if not exist, move to it


# include paths (.h):
inc_root="-I ../include"
#inc_engine="-I ../include/engine"
#inc_project="-I ../include/project \
#             -I ../include/project/clients"

# source paths (.cpp):
src_root="../src/*.cpp"
#src_engine="../src/engine/*.cpp"
#src_project="../src/project/*.cpp \
#             ../src/project/clients/*.cpp"

#other vars 
#timestamp=$(date '+%F_%H-%M-%S')


# prompt on what to build
echo -n "What to build? ('root'): "; read input

case $input in
  main | m)
    echo -e "Building root...\n"

    #executable_name="main-$timestamp.exe"
    executable_name="main.exe"
    
    g++ -std=c++17 \
    -o $executable_name \
    $inc_root \
    $src_root \
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