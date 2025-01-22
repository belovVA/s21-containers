#include <set>

#include "test.h"

template <typename T>
bool MultisetEqual(const s21::multiset<T>& s21_ms,
                   const std::multiset<T>& std_ms) {
  if (s21_ms.size() != std_ms.size()) return false;
  auto s21_it = s21_ms.begin();
  auto std_it = std_ms.begin();
  while (s21_it != s21_ms.end() && std_it != std_ms.end()) {
    if (*s21_it != *std_it) return false;
    ++s21_it;
    ++std_it;
  }
  return true;
}

TEST(MultiSetTest, DefaultConstructor) {
  std::cout << "\n ============== TEST: S21_Multiset ============== \n"
            << std::endl;
  s21::multiset<int> s21_ms;
  std::multiset<int> std_ms;

  EXPECT_TRUE(MultisetEqual(s21_ms, std_ms));
}

TEST(MultiSetTest, InitializerListConstructor) {
  s21::multiset<int> s21_ms{1, 2, 2, 3};
  std::multiset<int> std_ms{1, 2, 2, 3};

  EXPECT_EQ(s21_ms.size(), std_ms.size());
  auto s21_it = s21_ms.begin();
  auto std_it = std_ms.begin();
  while (s21_it != s21_ms.end() && std_it != std_ms.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(MultiSetTest, CopyConstructor) {
  s21::multiset<int> s21_ms1{1, 2, 3};
  std::multiset<int> std_ms1{1, 2, 3};

  s21::multiset<int> s21_ms2(s21_ms1);
  std::multiset<int> std_ms2(std_ms1);

  EXPECT_TRUE(MultisetEqual(s21_ms2, std_ms2));
}

TEST(MultiSetTest, CopyAssignment) {
  s21::multiset<int> s21_ms1{1, 2, 3};
  std::multiset<int> std_ms1{1, 2, 3};

  s21::multiset<int> s21_ms2;
  std::multiset<int> std_ms2;

  s21_ms2 = s21_ms1;
  std_ms2 = std_ms1;

  EXPECT_TRUE(MultisetEqual(s21_ms2, std_ms2));
}

TEST(MultiSetTest, MoveConstructor) {
  s21::multiset<int> s21_ms1{1, 2, 2, 3};
  std::multiset<int> std_ms1{1, 2, 2, 3};

  s21::multiset<int> s21_ms2(std::move(s21_ms1));
  std::multiset<int> std_ms2(std::move(std_ms1));

  EXPECT_TRUE(MultisetEqual(s21_ms2, std_ms2));
  EXPECT_EQ(s21_ms1.size(), std_ms1.size());
}

TEST(MultiSetTest, InsertElement) {
  s21::multiset<int> s21_ms;
  std::multiset<int> std_ms;

  s21_ms.insert(1);
  std_ms.insert(1);
  s21_ms.insert(1);
  std_ms.insert(1);
  s21_ms.insert(2);
  std_ms.insert(2);

  EXPECT_TRUE(MultisetEqual(s21_ms, std_ms));
}

TEST(MultiSetTest, InsertManyInitializerList) {
  s21::multiset<int> s21_ms;
  std::multiset<int> std_ms;

  s21_ms.insert_many({1, 1, 2, 3});
  std_ms.insert({1, 1, 2, 3});

  EXPECT_TRUE(MultisetEqual(s21_ms, std_ms));
}

TEST(MultiSetTest, FindElement) {
  s21::multiset<int> s21_ms{1, 2, 2, 3};
  std::multiset<int> std_ms{1, 2, 2, 3};

  auto s21_it = s21_ms.find(2);
  auto std_it = std_ms.find(2);

  ASSERT_NE(s21_it, s21_ms.end());
  ASSERT_NE(std_it, std_ms.end());
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(MultiSetTest, Clear) {
  s21::multiset<int> s21_ms{1, 2, 2, 3};
  std::multiset<int> std_ms{1, 2, 2, 3};

  s21_ms.clear();
  std_ms.clear();

  EXPECT_TRUE(MultisetEqual(s21_ms, std_ms));
}

TEST(MultiSetInsertManyTest, InsertManyUniqueElements) {
  s21::multiset<int> mySet;
  std::multiset<int> stdSet;

  std::vector<int> items = {1, 2, 3, 4, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());

  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : items) {
    EXPECT_TRUE(mySet.contains(item));
    EXPECT_TRUE(stdSet.count(item) > 0);
  }
}

TEST(MultiSetInsertManyTest, InsertManyWithDuplicates) {
  s21::multiset<int> mySet;
  std::multiset<int> stdSet;

  std::vector<int> items = {1, 2, 2, 3, 4, 4, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());

  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : stdSet) {
    EXPECT_TRUE(mySet.contains(item));
  }
}

TEST(MultiSetInsertManyTest, InsertManyEmpty) {
  s21::multiset<int> mySet;
  std::multiset<int> stdSet;

  std::vector<int> items;
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());
  EXPECT_EQ(mySet.size(), stdSet.size());
}

TEST(MultiSetInsertManyTest, InsertManyMixedElements) {
  s21::multiset<int> mySet;
  std::multiset<int> stdSet;

  std::vector<int> items = {5, 3, 1, 4, 2, 5};
  mySet.insert_many(items);
  stdSet.insert(items.begin(), items.end());
  EXPECT_EQ(mySet.size(), stdSet.size());
  for (const auto& item : stdSet) {
    EXPECT_TRUE(mySet.contains(item));
  }
}

TEST(MultiSetTest, MoveAssignment) {
  s21::multiset<int> s21_ms1{1, 2, 3};
  std::multiset<int> std_ms1{1, 2, 3};

  s21::multiset<int> s21_ms2;
  std::multiset<int> std_ms2;

  s21_ms2 = std::move(s21_ms1);
  std_ms2 = std::move(std_ms1);

  EXPECT_TRUE(MultisetEqual(s21_ms2, std_ms2));

  EXPECT_EQ(s21_ms1.size(), 0);
  EXPECT_EQ(std_ms1.size(), 0);
}

TEST(MultiSetTest, MoveAssignmentWithElements) {
  s21::multiset<int> s21_ms1{1, 2, 2, 3, 4};
  std::multiset<int> std_ms1{1, 2, 2, 3, 4};

  s21::multiset<int> s21_ms2;
  std::multiset<int> std_ms2;

  s21_ms2 = std::move(s21_ms1);
  std_ms2 = std::move(std_ms1);

  EXPECT_TRUE(MultisetEqual(s21_ms2, std_ms2));

  EXPECT_EQ(s21_ms1.size(), 0);
  EXPECT_EQ(std_ms1.size(), 0);
}

TEST(MultiSetTest, MoveAssignmentSelfAssignment) {
  s21::multiset<int> s21_ms{1, 2, 3};
  std::multiset<int> std_ms{1, 2, 3};

  s21_ms = s21_ms;
  std_ms = std_ms;

  EXPECT_TRUE(MultisetEqual(s21_ms, std_ms));
}

TEST(MultiSetTest, LowerBound) {
  s21::multiset<int> s21_ms{1, 2, 3, 4};
  std::multiset<int> std_ms{1, 2, 3, 4};

  auto s21_it = s21_ms.lower_bound(3);
  auto std_it = std_ms.lower_bound(3);

  EXPECT_NE(s21_it, s21_ms.end());
  EXPECT_NE(std_it, std_ms.end());
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(MultiSetTest, UpperBound) {
  s21::multiset<int> s21_ms{1, 2, 2, 3, 4};
  std::multiset<int> std_ms{1, 2, 2, 3, 4};

  auto s21_it = s21_ms.upper_bound(2);
  auto std_it = std_ms.upper_bound(2);

  EXPECT_NE(s21_it, s21_ms.end());
  EXPECT_NE(std_it, std_ms.end());
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(MultiSetTest, CountElements) {
  s21::multiset<int> s21_ms{1, 2, 2, 3, 4};
  std::multiset<int> std_ms{1, 2, 2, 3, 4};

  EXPECT_EQ(s21_ms.count(2), std_ms.count(2));
  EXPECT_EQ(s21_ms.count(5), std_ms.count(5));
}

TEST(MultisetTest, EqualRangeTest) {
  s21::multiset<int> ms;
  ms.insert(1);
  ms.insert(2);
  ms.insert(2);
  ms.insert(3);
  ms.insert(4);
  auto range = ms.equal_range(2);
  EXPECT_EQ(*range.first, 2);
  EXPECT_EQ(*range.second, 3);
  range = ms.equal_range(5);
  EXPECT_EQ(range.first, ms.end());
  EXPECT_EQ(range.second, ms.end());
  range = ms.equal_range(0);
  EXPECT_EQ(*range.first, 1);
  EXPECT_EQ(*range.second, 1);
  range = ms.equal_range(1);
  EXPECT_EQ(*range.first, 1);
  EXPECT_EQ(*range.second, 2);
}

TEST(MultiSetEraseTest, EraseExistingElement) {
  s21::multiset<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::multiset<int>::iterator it = mySet.find(2);
  mySet.erase(it);

  ASSERT_EQ(mySet.size(), initialSize - 1);
  ASSERT_FALSE(mySet.contains(2));
}

TEST(MultiSetEraseTest, EraseNonExistentElement) {
  s21::multiset<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::multiset<int>::iterator it = mySet.find(42);
  mySet.erase(it);

  ASSERT_EQ(mySet.size(), initialSize);
}

TEST(MultiSetEraseTest, EraseExistingElementMultipleTimes) {
  s21::multiset<int> mySet = {1, 2, 2, 3, 3, 3};
  size_t initialSize = mySet.size();
  s21::multiset<int>::iterator it = mySet.find(2);
  mySet.erase(it);
  ASSERT_EQ(mySet.size(), initialSize - 1);
  ASSERT_TRUE(mySet.contains(2));
}