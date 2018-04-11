#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("Сreating tree")
{
	tree_t My_tree;
	REQUIRE( My_tree.root() == nullptr );
}

TEST_CASE("Add elements in tree")
{
	tree_t My_tree;
	My_tree.insert(7);
	My_tree.insert(3);
	My_tree.insert(9);
	My_tree.insert(6);
	std::ostringstream ostream;
	My_tree.print(ostream, 0, My_tree.root());
	std::string output{
		"---9\n"
		"7\n"
		"------6\n"
		"---3\n"};
	REQUIRE(output == ostream.str());
}

TEST_CASE("Check root tree")
{
	tree_t My_tree;
  My_tree.insert(7);
  My_tree.insert(3);
  My_tree.insert(9); 

  REQUIRE(My_tree.find(9) == true);
  REQUIRE(My_tree.find(2) == false);
}

TEST_CASE("Check operator tree '+' and '=' ")
{
	tree_t My_tree;
	std::ostringstream ostream;
	My_tree.check_operator(ostream, '+', 7);
	My_tree.check_operator(ostream, '+', 3);
	My_tree.check_operator(ostream, '+', 9);
	My_tree.check_operator(ostream, '+', 6);
	std::string output {
		"---9\n"
		"7\n"
		"------6\n"
		"---3\n"};
	My_tree.check_operator (ostream, '=', 0);
	
	REQUIRE(output == ostream.str());
}
TEST_CASE("Check operator tree '?' ")
{
	tree_t My_tree;
	My_tree.insert(7);
	My_tree.insert(3);
	My_tree.insert(9); 
	std::ostringstream ostream;
	My_tree.check_operator (ostream, '?', 3);
	REQUIRE(ostream.str() == "true");
}
	
