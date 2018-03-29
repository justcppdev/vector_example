#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating tree")
{
	tree_t tree1;
	REQUIRE( tree1.root() == nullptr );
}
