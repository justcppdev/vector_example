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
  tree1.act1('+', 5);
  tree1.act1('+', 4);
  tree1.act1('+', 6);
  std::string out{
      "---6\n"
      "5\n"
      "---4\n"};
  std::ostringstream stream;
  std::ostringstream stream1;
  std::ostringstream stream2;

  tree1.act('?', 5, stream);
  REQUIRE(stream.str() == "true");

  tree1.act('?', 3, stream1);
  REQUIRE(stream1.str() == "false");

  tree1.act('=', 0, stream2);
  REQUIRE(stream2.str() == out);
}

TEST_CASE(" delete el"){
 tree_t<int> tree1 {8, 3, 12, 1, 5, 6, 7, 9, 10, 14, 13, 15};
 tree_t<int> tree2 {8, 3, 11, 12, 1, 5, 6, 7, 9, 10, 14, 13, 15};
 tree1.remove(11);
 REQUIRE( tree1 == tree2);
} 

TEST_CASE(" initializer_list ")
{
	
	tree_t<int> tree1 { 5, 4, 6 };
	std::ostringstream stream;
	tree.print1(stream, 0, tree1.root());
	 std::string out{
      "---6\n"
      "5\n"
      "---4\n"};
	REQUIRE(out == stream.str());
}
