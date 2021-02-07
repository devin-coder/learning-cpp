g++ -c api.cpp -I./ 
ar -rcs libapi.a api.o
g++ -c use_api.cpp -I./
ar -rcs libuse_api.a use_api.o
# lib depend order 
# g++ -o main main.cpp -L./ -lapi -luse_api -I./ 
g++ -o main main.cpp -L./ -luse_api -lapi -I./ 
./main 

