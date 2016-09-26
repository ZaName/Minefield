/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isGetOutOfBounds)
{
	Field minefield(50);

	bool failed = false;
	try {
		minefield.get(50,0);
	} catch (std::exception ex) {
		failed = true;
	}
	
	ASSERT_TRUE(failed);
}

TEST(FieldTest, isSafeOutOfBounds)
{
	Field minefield(50);

	bool failed = false;
	try {
		minefield.isSafe(50,0);
	} catch (std::exception ex) {
		failed = true;
	}
	
	ASSERT_TRUE(failed);
}

TEST(FieldTest, isRevealAdj)
{
	Field minefield(50);

	minefield.placeMine(0,0);
	minefield.revealAdjacent(0, 1);
	
	ASSERT_EQ( MINE_SHOWN, minefield.get(0,0) );
}
