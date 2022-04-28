#!/bin/bash
# Bash script to easily execute multiple compile / run jobs.

# SETUP ========================================
echo -e '\0033\0143'     # clear terminal
shopt -s nocasematch     # set interpreter to ignore letter case
mkdir -p build; cd build # make build dir; if not exist, move to it

timestamp=$(date '+%F_%H-%M-%S') # timestamp var for files / logs
# ----- ========================================


# PATHS ========================================
  # INCLUDE PATHS (.h):
    inc_root="-I ../inc"
    inc_engine="-I ../inc/engine"
    #inc_project="-I ../inc/project \
    #             -I ../inc/project/clients"

  # SOURCE PATHS (.cpp):
    src_root="../src/*.cpp"
    src_engine="../src/engine/*.cpp"
    #src_project="../src/project/*.cpp \
    #             ../src/project/clients/*.cpp"
# ----- ========================================


# SCRIPT =======================================
echo -n "What to compile? ('root', 'engine'): "; read input
case $input in
  root | r)
    echo -e "Starting compile job 'root'...\n"

    executable_name="main.exe" # "main-$timestamp.exe"
    
    g++ -std=c++17 \
    -o $executable_name \
    $inc_root \
    $src_root 
    
    echo -e "\n...compile job ended."
    ;;

  engine | e)
    echo -e "Starting compile job 'engine'...\n"

    executable_name="main.exe"
    
    g++ -std=c++17 \
    -o $executable_name \
    $inc_root $inc_engine \
    $src_root $inc_root 
    
    echo -e "\n...compile job ended."
    ;;

  *)
    echo "Invalid command."
    ;;
esac

# prompt to if to run the built exe or not
echo -n "Run $executable_name? ('y', 'n'): "; read input
case $input in
  y)
    echo -n "Running $executable_name ..."; echo -e "\n"

    ./$executable_name; 

    echo -e "\n...program exited with code: $?" # '$?' = return val of last run prog
    ;;
    
  n)
    echo "Skipped."
    ;;
    
  *)
    echo "Invalid command."
    ;;
esac

cd .. #go back to root dir
# ------ =======================================