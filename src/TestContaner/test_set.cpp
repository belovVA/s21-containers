#include <set>

#include "test.h"

class SetTest : public testing::Test {
 protected:
  void SetUp() {
    for (int i = 0; i < 20; ++i) {
      my_set.insert(i);
      origin_set.insert(i);
    }
  }
  s21::set<int> my_set;
  std::set<int> origin_set;
};

TEST(SetConstructorTest, DefaultConstructor) {
  std::cout << "\n ============== TEST: S21_Set ============== \n" << std::endl;
  s21::set<int> mySet;
  ASSERT_TRUE(mySet.empty());
  ASSERT_EQ(mySet.size(), 0);
}

TEST(SetConstructorTest, InitializerListConstructor) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  ASSERT_EQ(mySet.size(), 5);
  ASSERT_TRUE(mySet.find(3) != mySet.end());
}

TEST(SetConstructorTest, CopyConstructor) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), copiedSet.size());
  ASSERT_TRUE(copiedSet.find(2) != copiedSet.end());
  ASSERT_EQ(*sourceSet.find(3), *copiedSet.find(3));
}

TEST(SetConstructorTest, MoveConstructor) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> movedSet(std::move(sourceSet));

  ASSERT_EQ(sourceSet.size(), 0);
  ASSERT_EQ(movedSet.size(), 3);
  ASSERT_TRUE(movedSet.find(1) != movedSet.end());
}

TEST(SetConstructorTest, EmptyInitializerList) {
  s21::set<int> emptySet = {};
  ASSERT_TRUE(emptySet.empty());
  ASSERT_EQ(emptySet.size(), 0);
}

TEST(SetConstructorTest, CopyConstructorEmptySet) {
  s21::set<int> sourceSet;
  s21::set<int> copiedSet(sourceSet);
  ASSERT_TRUE(copiedSet.empty());
}

TEST(SetConstructorTest, CopyConstructorSingleElementSet) {
  s21::set<int> sourceSet = {42};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), copiedSet.size());
  ASSERT_EQ(*sourceSet.find(42), *copiedSet.find(42));
}

TEST(SetConstructorTest, CopyConstructorWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), 3);
  ASSERT_EQ(copiedSet.size(), 3);
  ASSERT_TRUE(copiedSet.find(2) != copiedSet.end());
}

TEST(SetConstructorTest, MoveConstructorWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> movedSet(std::move(sourceSet));

  ASSERT_EQ(sourceSet.size(), 0);
  ASSERT_EQ(movedSet.size(), 3);
  ASSERT_TRUE(movedSet.find(2) != movedSet.end());
}

TEST(SetMoveOperatorTest, MoveAssignment) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> movedSet;
  movedSet = std::move(sourceSet);

  ASSERT_EQ(sourceSet.size(), 0);
  ASSERT_EQ(movedSet.size(), 3);
  ASSERT_TRUE(movedSet.find(1) != movedSet.end());
}

TEST(SetMoveOperatorTest, MoveAssignmentFromEmptySet) {
  s21::set<int> sourceSet;
  s21::set<int> movedSet = {1, 2, 3};
  movedSet = std::move(sourceSet);
  ASSERT_TRUE(sourceSet.empty());
  ASSERT_EQ(movedSet.size(), 0);
}

TEST(SetMoveOperatorTest, MoveAssignmentWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> movedSet = {10, 20, 30};
  movedSet = std::move(sourceSet);

  ASSERT_EQ(sourceSet.size(), 0);
  ASSERT_EQ(movedSet.size(), 3);
  ASSERT_TRUE(movedSet.find(2) != movedSet.end());
}

TEST(SetSizeAndEmptyTest, EmptyAndSizeWithEmptySet) {
  s21::set<int> mySet;
  ASSERT_TRUE(mySet.empty());
  ASSERT_EQ(mySet.size(), 0);
}

TEST(SetSizeAndEmptyTest, EmptyAndSizeWithNonEmptySet) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  ASSERT_FALSE(mySet.empty());
  ASSERT_EQ(mySet.size(), 5);
}

TEST(SetMaxSizeTest, MaxSize) {
  s21::set<int> mySet;
  size_t max_size = mySet.max_size();

  ASSERT_TRUE(max_size > 0);
}

TEST(SetBeginEndTest, BeginAndEndWithEmptySet) {
  s21::set<int> mySet;
  ASSERT_EQ(mySet.begin(), mySet.end());
}

TEST(SetBeginEndTest, BeginAndEndWithNonEmptySet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.begin();
  s21::set<int>::iterator endIt = mySet.end();

  ASSERT_EQ(*it, 1);
  ASSERT_EQ(*(--endIt), 5);
}

TEST(SetBeginEndTest, IterateThroughSet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  std::vector<int> elements;

  for (s21::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    elements.push_back(*it);
  }

  std::vector<int> expected = {1, 2, 3, 4, 5};
  ASSERT_EQ(elements, expected);
}

TEST(SetFindTest, FindElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.find(3);
  ASSERT_NE(it, mySet.end());
  ASSERT_EQ(*it, 3);
}

TEST(SetFindTest, FindNonExistentElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.find(6);
  ASSERT_EQ(it, mySet.end());
}

TEST(SetContainsTest, ContainsElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  ASSERT_TRUE(mySet.contains(1));
}

TEST(SetContainsTest, ContainsNonExistentElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  ASSERT_FALSE(mySet.contains(6));
}

TEST(SetClearTest, ClearEmptySet) {
  s21::set<int> mySet;
  mySet.clear();

  ASSERT_TRUE(mySet.empty());
  ASSERT_EQ(mySet.size(), 0);
}

TEST(SetClearTest, ClearNonEmptySet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  mySet.clear();

  ASSERT_TRUE(mySet.empty());
  ASSERT_EQ(mySet.size(), 0);
}

TEST(SetClearTest, ClearMultipleTimes) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  mySet.clear();
  mySet.clear();
  mySet.clear();

  ASSERT_TRUE(mySet.empty());
  ASSERT_EQ(mySet.size(), 0);
}

TEST(SetInsertTest, InsertNewElement) {
  s21::set<int> mySet;
  auto result = mySet.insert(42);

  ASSERT_TRUE(result.second);
  ASSERT_EQ(*result.first, 42);
  ASSERT_EQ(mySet.size(), 1);
  ASSERT_TRUE(mySet.contains(42));
}

TEST(SetInsertTest, InsertExistingElement) {
  s21::set<int> mySet = {1, 2, 3};
  auto result = mySet.insert(2);
  ASSERT_FALSE(result.second);
  ASSERT_EQ(*result.first, 2);
  ASSERT_EQ(mySet.size(), 3);
}

TEST(SetEraseTest, EraseExistingElement) {
  s21::set<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it = mySet.find(2);
  mySet.erase(it);

  ASSERT_EQ(mySet.size(), initialSize - 1);
  ASSERT_FALSE(mySet.contains(2));
}

TEST(SetEraseTest, EraseNonExistentElement) {
  s21::set<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it = mySet.find(42);
  mySet.erase(it);

  ASSERT_EQ(mySet.size(), initialSize);
}

TEST(SetEraseTest, EraseExistingElementMultipleTimes) {
  s21::set<int> mySet = {1, 2, 2, 3, 3, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it = mySet.find(2);
  mySet.erase(it);
  ASSERT_EQ(mySet.size(), initialSize - 1);
  ASSERT_FALSE(mySet.contains(2));
}

TEST(SetSwapTest, SwapTwoNonEmptySets) {
  s21::set<int> set1 = {1, 2, 3};
  s21::set<int> set2 = {4, 5, 6};

  set1.swap(set2);

  ASSERT_EQ(set1.size(), 3);
  ASSERT_EQ(set2.size(), 3);
  ASSERT_TRUE(set1.contains(4));
  ASSERT_TRUE(set2.contains(1));
}

TEST(SetSwapTest, SwapEmptySetWithNonEmptySet) {
  s21::set<int> set1;
  s21::set<int> set2 = {1, 2, 3};

  set1.swap(set2);

  ASSERT_EQ(set1.size(), 3);
  ASSERT_EQ(set2.size(), 0);
  ASSERT_TRUE(set1.contains(1));
  ASSERT_FALSE(set2.contains(1));
}

TEST(SetMergeTest, MergeTwoNonEmptySets) {
  s21::set<int> set1 = {1, 2, 3};
  s21::set<int> set2 = {3, 4, 5};

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 5);
  ASSERT_EQ(set2.size(), 0);
  ASSERT_TRUE(set1.contains(4));
  ASSERT_TRUE(set1.contains(1));
}

TEST(SetMergeTest, MergeEmptySetWithNonEmptySet) {
  s21::set<int> set1;
  s21::set<int> set2 = {1, 2, 3};

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 3);
  ASSERT_EQ(set2.size(), 0);
  ASSERT_TRUE(set1.contains(1));
  ASSERT_FALSE(set2.contains(1));
}

TEST(SetMergeTest, MergeTwoEmptySets) {
  s21::set<int> set1;
  s21::set<int> set2;

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 0);
  ASSERT_EQ(set2.size(), 0);
}

TEST(SetInsertManyTest, InsertManyUniqueElements) {
  s21::set<int> mySet;
  std::set<int> stdSet;

  std::vector<int> items = {1, 2, 3, 4, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());

  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : items) {
    EXPECT_TRUE(mySet.contains(item));
    EXPECT_TRUE(stdSet.count(item) > 0);
  }
}

TEST(SetInsertManyTest, InsertManyWithDuplicates) {
  s21::set<int> mySet;
  std::set<int> stdSet;

  std::vector<int> items = {1, 2, 2, 3, 4, 4, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());
  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : stdSet) {
    EXPECT_TRUE(mySet.contains(item));
  }
}

TEST(SetInsertManyTest, InsertManyEmpty) {
  s21::set<int> mySet;
  std::set<int> stdSet;

  std::vector<int> items;
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());
  EXPECT_EQ(mySet.size(), stdSet.size());
}

TEST(SetInsertManyTest, InsertManyMixedElements) {
  s21::set<int> mySet;
  std::set<int> stdSet;

  std::vector<int> items = {5, 3, 1, 4, 2, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());
  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : stdSet) {
    EXPECT_TRUE(mySet.contains(item));
  }
}
