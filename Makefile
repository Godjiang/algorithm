sort_debug :
	g++ -o out/sort_debug sort.cpp -std=c++11 -DDEBUG

sort :
	g++ -o out/sort sort.cpp -std=c++11

clean :
	rm out/*