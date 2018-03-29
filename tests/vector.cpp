#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating tree")
{
	tree_t tree1;
	REQUIRE( tree1.root() == nullptr );
}

TEST_CASE("insert")
{
  tree_t tree1;
    tree1.insert(5);
    tree1.insert(4);
    tree1.insert(6); 
    tree1.insert(7);
	std::string out {
	        "------7\n"
		"---6\n"
		"5\n"
		"---4\n"
	};
	
	std::ostringstream stream;
	tree.print (stream, tree.set_pointer());
	
	REQUIRE(stream.str() == out);
	
}

TEST_CASE("find")
{
  tree_t tree1;
  tree1.insert(5);
  tree1.insert(4);
  tree1.insert(6); 
  tree1.insert(7);
  REQUIRE(tree.find(5) == true);
  REQUIRE(tree.find(8) == false);
	
}
TEST_CASE("operations")
{
 tree.operation('+', 5);
 tree.operation('+', 4);
 tree.operation('+', 6);	
	std::string out {
		"--------6\n"
		"----5\n"
		"--------4\n"
	};
	std::ostringstream stream;
	tree.operation ('=', stream);
	
	REQUIRE(stream.str() == out);
}
