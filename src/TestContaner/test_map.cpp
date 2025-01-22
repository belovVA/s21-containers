#include <map>

#include "test.h"

TEST(MapDefaultConstructorTest, DefaultConstructor) {
  std::cout << "\n ============== TEST: S21_Map ============== \n" << std::endl;
  s21::map<int, int> myMap;

  ASSERT_TRUE(myMap.empty());
  ASSERT_EQ(myMap.size(), 0);
}

TEST(MapInitializerListConstructorTest, InitializerListConstructor) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_FALSE(myMap.empty());
  ASSERT_EQ(myMap.size(), 3);
  ASSERT_EQ(myMap.at(1), 10);
  ASSERT_EQ(myMap.at(2), 20);
  ASSERT_EQ(myMap.at(3), 30);
}

TEST(MapCopyConstructorTest, CopyConstructor) {
  s21::map<int, int> sourceMap = {{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> copiedMap(sourceMap);

  ASSERT_EQ(sourceMap.size(), copiedMap.size());
  ASSERT_EQ(copiedMap.at(2), 20);
}

TEST(MapMoveConstructorTest, MoveConstructor) {
  s21::map<int, int> sourceMap = {{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> movedMap(std::move(sourceMap));

  ASSERT_TRUE(sourceMap.empty());
  ASSERT_EQ(movedMap.size(), 3);
  ASSERT_EQ(movedMap.at(1), 10);
}

TEST(MapAtTest, AtExistingKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(myMap.at(1), 10);
  ASSERT_EQ(myMap.at(2), 20);
  ASSERT_EQ(myMap.at(3), 30);
}

TEST(MapAtTest, AtNonExistentKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_THROW(myMap.at(4), const char*);
  ASSERT_THROW(myMap.at(0), const char*);
}

TEST(MapOperatorBracketTest, OperatorBracketExistingKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(myMap[1], 10);
  ASSERT_EQ(myMap[2], 20);
  ASSERT_EQ(myMap[3], 30);
}

TEST(MapOperatorBracketTest, OperatorBracketNonExistentKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_NO_THROW(myMap[4]);
  ASSERT_EQ(myMap[4], 0);
  myMap[5] = 50;
  ASSERT_EQ(myMap[5], 50);
}

TEST(MapIteratorTest, BeginAndEndWithEmptyMap) {
  s21::map<int, int> myMap;
  s21::map<int, int>::iterator it = myMap.begin();
  s21::map<int, int>::iterator endIt = myMap.end();

  ASSERT_EQ(it, endIt);
}

TEST(MapIteratorTest, BeginAndEndWithNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  s21::map<int, int>::iterator it = myMap.begin();
  s21::map<int, int>::iterator endIt = myMap.end();

  ASSERT_NE(it, endIt);
  ASSERT_EQ((*it).first, 1);
  ASSERT_EQ((*(--endIt)).first, 3);
}

TEST(MapIteratorTest, IterateThroughMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  std::vector<std::pair<int, int>> elements;

  for (s21::map<int, int>::iterator it = myMap.begin(); it != myMap.end();
       ++it) {
    elements.push_back(*it);
  }

  std::vector<std::pair<int, int>> expected = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(elements, expected);
}

TEST(MapEmptyTest, EmptyMap) {
  s21::map<int, int> myMap;

  ASSERT_TRUE(myMap.empty());
  ASSERT_EQ(myMap.size(), 0);
}

TEST(MapEmptyTest, NonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_FALSE(myMap.empty());
  ASSERT_EQ(myMap.size(), 3);
}

TEST(MapSizeTest, SizeOfEmptyMap) {
  s21::map<int, int> myMap;

  ASSERT_EQ(myMap.size(), 0);
}

TEST(MapSizeTest, SizeOfNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_EQ(myMap.size(), 3);
}

TEST(MapMaxSizeTest, MaxSize) {
  s21::map<int, int> myMap;

  ASSERT_LE(myMap.max_size(), std::numeric_limits<size_t>::max());
}

TEST(MapClearTest, ClearNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  myMap.clear();

  ASSERT_TRUE(myMap.empty());
  ASSERT_EQ(myMap.size(), 0);
}

TEST(MapInsertValueTest, InsertNewElement) {
  s21::map<int, int> myMap;
  auto result = myMap.insert(std::make_pair(1, 10));

  ASSERT_TRUE(result.second);
  ASSERT_EQ((*(result.first)).first, 1);
  ASSERT_EQ((*(result.first)).second, 10);
  ASSERT_EQ(myMap.size(), 1);
}

TEST(MapInsertManyTest, InsertManyUniqueElements) {
  s21::map<int, std::string> myMap;
  std::map<int, std::string> stdMap;

  std::vector<std::pair<int, std::string>> items = {
      {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};

  myMap.insert_many(items);
  stdMap.insert(items.begin(), items.end());

  EXPECT_EQ(myMap.size(), stdMap.size());
  for (const auto& item : items) {
    EXPECT_EQ(myMap[item.first], stdMap[item.first]);
  }
}

TEST(MapInsertManyTest, InsertManyWithDuplicates) {
  s21::map<int, std::string> myMap;
  std::map<int, std::string> stdMap;

  std::vector<std::pair<int, std::string>> items = {
      {1, "one"},   {2, "two"},  {2, "duplicate"},
      {3, "three"}, {4, "four"}, {4, "duplicate"}};

  myMap.insert_many(items);
  for (const auto& item : items) {
    stdMap.insert(item);
  }

  EXPECT_EQ(myMap.size(), stdMap.size());
  for (const auto& item : stdMap) {
    EXPECT_EQ(myMap[item.first], stdMap[item.first]);
  }
}

TEST(MapInsertManyTest, InsertManyEmpty) {
  s21::map<int, std::string> myMap;
  std::map<int, std::string> stdMap;

  std::vector<std::pair<int, std::string>> items;
  myMap.insert_many(items);
  stdMap.insert(items.begin(), items.end());
  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapInsertManyTest, InsertManyMixedElements) {
  s21::map<int, std::string> myMap;
  std::map<int, std::string> stdMap;

  std::vector<std::pair<int, std::string>> items = {
      {5, "five"}, {3, "three"}, {1, "one"},
      {4, "four"}, {2, "two"},   {5, "duplicate"}};

  myMap.insert_many(items);
  for (const auto& item : items) {
    stdMap.insert(item);
  }

  EXPECT_EQ(myMap.size(), stdMap.size());
  for (const auto& item : stdMap) {
    EXPECT_EQ(myMap[item.first], stdMap[item.first]);
  }
}

TEST(MapInsertValueTest, InsertExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  auto result = myMap.insert(std::make_pair(1, 20));
  ASSERT_FALSE(result.second);
  ASSERT_EQ((*(result.first)).second, 10);
  ASSERT_EQ(myMap.size(), 1);
}

TEST(MapInsertKeyObjTest, InsertNewElement) {
  s21::map<int, int> myMap;
  std::pair<s21::map<int, int>::iterator, bool> result = myMap.insert(1, 10);

  ASSERT_TRUE(result.second);
  ASSERT_EQ((*(result.first)).first, 1);
  ASSERT_EQ(myMap.size(), 1);
}

TEST(MapInsertKeyObjTest, InsertExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  std::pair<s21::map<int, int>::iterator, bool> result = myMap.insert(1, 20);
  ASSERT_FALSE(result.second);
  ASSERT_EQ((*(result.first)).second, 10);
  ASSERT_EQ(myMap.size(), 1);
}

TEST(MapInsertOrAssignTest, InsertOrAssignNewElement) {
  s21::map<int, int> myMap;
  auto result = myMap.insert_or_assign(1, 10);

  ASSERT_EQ((*(result.first)).first, 1);
  ASSERT_EQ(myMap.size(), 1);
}

TEST(MapInsertOrAssignTest, InsertOrAssignExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  auto result = myMap.insert_or_assign(1, 20);
  ASSERT_EQ((*(result.first)).first, 1);
  ASSERT_EQ((*(result.first)).second, 20);
  ASSERT_EQ(myMap.size(), 1);
}