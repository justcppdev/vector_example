#include <catch.hpp>
#include <sstream>


#include "vector.hpp"

TEST_CASE("creating tree") {
  tree_t<int> tree1;
  REQUIRE(tree1.root() == nullptr);
}

TEST_CASE("insert") {
  tree_t<int> tree1;
  tree1.insert(5);
  tree1.insert(4);
  tree1.insert(6);
  tree1.insert(7);
  std::string out{
      "------7\n"
      "---6\n"
      "5\n"
      "---4\n"};

  std::ostringstream stream;
  tree1.print(stream, 0, tree1.root());

  REQUIRE(stream.str() == out);
}

TEST_CASE("find") {
  tree_t<int> tree1;
  tree1.insert(5);
  tree1.insert(4);
  tree1.insert(6);
  tree1.insert(7);
  REQUIRE(tree1.find(5) == true);
  REQUIRE(tree1.find(8) == false);
}
TEST_CASE("operations") {
  tree_t<int> tree1;
  tree1.act('+', 5);
  tree1.act('+', 4);
  tree1.act('+', 6);
  std::string out{
      "---6\n"
      "5\n"
      "---4\n"};
  std::ostringstream stream;
std::ostringstream stream1;
	std::ostringstream stream2;
  tree1.operation(stream1, '?', 5);
  REQUIRE(stream1.str() == "true");

  tree1.operation(stream2, '?',3);
  REQUIRE(stream2.str() == "false");

  tree1.operation(stream, '=',0);
  REQUIRE(stream.str() == out);
}

TEST_CASE(" tree1 == tree2"){
 tree_t<int> tree1 {8, 3, 11, 12, 1, 5, 6, 7, 9, 10, 14, 13, 15};
 tree_t<int> tree2 {8, 3, 11, 12, 1, 5, 6, 7, 9, 10, 14, 13};
 tree1.remove(15);
 REQUIRE( tree1 == tree2);
} 

TEST_CASE(" initializer_list ")
{
	
	tree_t<int> tree1 { 5, 4, 6 };
	std::ostringstream stream;
	tree1.print(stream, 0, tree1.root());
	 std::string out{
      "---6\n"
      "5\n"
      "---4\n"};
	REQUIRE(out == stream.str());
}
TEST_CASE(" tree1 != tree2")
{	
	tree_t<int> tree1 {3,4,5};
	tree_t<int> tree2 {3,4,6};
	REQUIRE(!(tree1 == tree2));
}
TEST_CASE("BST delete non inserted element", "[delete]")
{	
	
	tree_t<int> tree1 {8};
	 REQUIRE(!(tree1.remove(4)));
	REQUIRE(!(tree1.isEmpty()));
}

TEST_CASE("BST delete root without children", "[delete]")
{	
	
	tree_t<int> tree1 {8};
	REQUIRE(tree1.remove(8));
	REQUIRE(tree1.isEmpty());
}


TEST_CASE("BST delete root with one child", "[delete]")
{	
	tree_t<int> tree1 {8,4,3};
	tree_t<int> tree2 {4,3};
	
  	REQUIRE(tree1.remove(8));
    	REQUIRE(tree1 ==  tree2);	
}

TEST_CASE("BST delete root with children", "[delete]")
{

	tree_t<int> tree1 {8, 4, 3, 10, 9, 13, 11, 12};
	tree_t<int> tree2 {9, 4, 3, 10, 13, 11, 12};
    	REQUIRE( tree1.remove(8));
    	REQUIRE( tree1 == tree2 );
}

TEST_CASE("BST delete non root without children", "[delete]")
{
	
	tree_t<int> tree1 {8, 4, 3, 10, 9, 13, 11, 12};
	tree_t<int> tree2 {8, 4, 10, 9, 13, 11, 12};
    	REQUIRE( tree1.remove(3));
    	REQUIRE( tree1 == tree2 );
}

TEST_CASE("BST delete non root with one child", "[delete]")
{
	tree_t<int> tree1 {8, 4, 3, 10, 9, 13, 11, 12};
	tree_t<int> tree2 {8, 4, 3, 10, 9, 13, 12};
    	REQUIRE( tree1.remove(11));
    	REQUIRE( tree1 == tree2 );
}

TEST_CASE("BST delete non root with children", "[delete]")
{
	tree_t<int> tree1 {8, 4, 3, 10, 9, 13, 11, 12};
	tree_t<int> tree2 {8, 4, 3, 11, 9, 13, 12};
    	REQUIRE( tree1.remove(10));
    	REQUIRE( tree1 == tree2 );
}
