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

  tree1.act( 5, '?');
  REQUIRE("true" == "true");

  tree1.act( 3, '?');
  REQUIRE("false" == "false");

  tree1.operation(stream2, 0, '=');
  REQUIRE(stream2.str() == out);
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
TEST_CASE(" tree1 = tree2")
{	
	tree_t<int> tree1 {3,4,5};
	tree_t<int> tree2 {3,4,6};
	REQUIRE(!(tree1 == tree2));
}
