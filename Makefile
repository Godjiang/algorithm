sort_debug :
	g++ -o out/sort_debug sort_algorithm/test_sort.cpp -std=c++11 -DDEBUG -g

sort :
	g++ -o out/sort sort_algorithm/test_sort.cpp -std=c++11 -g

bin_tree_debug :
	g++ -o out/bin_tree tree/test_bin_tree.cpp -std=c++11 -DDEBUG -g

bin_tree :
	g++ -o out/bin_tree tree/test_bin_tree.cpp -std=c++11 -g

clean :
	rm out/*