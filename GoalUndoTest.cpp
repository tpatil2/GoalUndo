/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include <string>
#include "GoalUndo.h"

std::string job1="draw square";
std::string job2="draw triangle";
std::string opr1="rotate 90";
std::string opr2="rotate 60";
std::string opr3="draw vertical line";


class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};


TEST(GoalUndoTest, TEST_GET_GOAL)
{
  GoalUndo obj;
  obj.addOperation(job1,opr1);
	ASSERT_EQ("draw square",obj.getGoal());
}


TEST(GoalUndoTest, TEST_UNDOGOAL)
{
  GoalUndo obj;
  obj.addOperation(job2,opr2);
  obj.addOperation(job1,opr1);
  obj.undoGoal();
	ASSERT_EQ("draw triangle",obj.getGoal());
}

TEST(GoalUndoTest, TEST_EMPTY_UNDOGOAL)
{
  GoalUndo obj;
  obj.undoGoal();
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_EMPTY_UNDOOPERATION)
{
  GoalUndo obj;
  obj.undoOperation();
  obj.undoOperation(opr3);
	ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_UNDO_OPERATION)
{
  GoalUndo obj;
  obj.addOperation(job1,opr2);
  obj.addOperation(opr3);
  obj.addOperation(job2,opr1);
	obj.addOperation(opr3);
  obj.undoOperation();
  ASSERT_EQ("draw triangle",obj.getGoal());
}

TEST(GoalUndoTest, TEST_UNDO_SPECIFIC_OPERATION)
{
  GoalUndo obj;
  obj.addOperation(job1,opr1);
  obj.addOperation(opr2);
  obj.addOperation(opr3);
  obj.undoOperation(opr2);
  ASSERT_EQ("rotate 90 draw vertical line",obj.getOperations());
}

TEST(GoalUndoTest, TEST_UNDO_LAST_OPERATION)
{
  GoalUndo obj;
  obj.addOperation(job1,opr1);
  obj.undoOperation();
  ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_ADD_EMPTY_OPERATION)
{
  GoalUndo obj;
  obj.addOperation("");
  obj.addOperation("","");
  ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_UNDO_EMPTY_OPERATION)
{
  GoalUndo obj;
  obj.undoOperation("");
  ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_UNDO_LAST_SPECIFIC_OPERATION)
{
  GoalUndo obj;
  obj.addOperation(job1,opr1);
  obj.undoOperation(opr1);
  ASSERT_EQ("",obj.getGoal());
}

TEST(GoalUndoTest, TEST_GET_OPERATIONS)
{
  GoalUndo obj;
  obj.addOperation(job1,opr2);
  obj.addOperation(opr3);
	ASSERT_EQ("rotate 60 draw vertical line",obj.getOperations());
}

TEST(GoalUndoTest, TEST_ADD_NEW_GOAL)
{
  GoalUndo obj;
  obj.addOperation(job1,opr2);
  obj.addOperation(job2,opr1);
	ASSERT_EQ("draw triangle",obj.getGoal());
}

TEST(GoalUndoTest, TEST_ADD_OPERATION)
{
  GoalUndo obj;
  obj.addOperation(job2);
  obj.addOperation(opr1);
  obj.addOperation(opr2);
  obj.addOperation(opr3);
	ASSERT_EQ("draw triangle rotate 90 rotate 60 draw vertical line",obj.getOperations());
}

TEST(GoalUndoTest, TEST_GET_EMPTY_OPR)
{
  GoalUndo obj;
	ASSERT_EQ("",obj.getOperations());
}
