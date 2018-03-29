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
	tree1.print (stream,0,tree1.root());
	
	REQUIRE(stream.str() == out);
	
}

TEST_CASE("find")
{
  tree_t tree1;
  tree1.insert(5);
  tree1.insert(4);
  tree1.insert(6); 
  tree1.insert(7);
  REQUIRE(tree1.find(5) == true);
  REQUIRE(tree1.find(8) == false);
	
}
TEST_CASE("operations")
{
tree_t tree1;
 tree1.act('+', 5);
 tree1.act('+', 4);
 tree1.act('+', 6);	
	std::string out {
		"---6\n"
		"5\n"
		"---4\n"
	};
	std::ostringstream stream;
	std::ostringstream stream1;
	std::ostringstream stream2;
	
	tree1.act('?', 5, stream);
	REQUIRE(stream.str() == "true");
	
	tree1.act('?', 3, stream);
	REQUIRE(stream1.str() == "false");
	
	tree1.act1 ('=', 0 , stream);
	REQUIRE(stream2.str() == out);
}
