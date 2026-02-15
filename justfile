set quiet := true

init:
    echo "initializing"
    mkdir build
    touch main.cpp
    echo "finished"

build:
    echo "building"
    g++ -std=c++23 main.cpp -o ./build/main
    echo "finished"

run:
    echo "building"
    g++ -std=c++23 main.cpp -o ./build/main
    echo "finished"
    echo "running\n\n"
    ./build/main

clean:
    rm -rf build
