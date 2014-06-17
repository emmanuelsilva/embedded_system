cd executable
for f in ../*.cpp; do g++ -c $f  ; done
g++ *.o
