#include <list>

#include "test.h"

TEST(ListConstructor, DefaultConstructor) {
  std::cout << "\n ============== TEST: S21_List ============== \n"
            << std::endl;

  s21::list<int> lst;
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(ListConstructor, SizeConstructor) {
  s21::list<int> lst(5);
  EXPECT_EQ(lst.size(), 5);
  EXPECT_FALSE(lst.empty());
  for (const auto &item : lst) {
    EXPECT_EQ(item, 0);
  }
}

TEST(ListConstructor, SizeConstructorZero) {
  s21::list<int> lst(0);
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(ListConstructor, InitializerListConstructor) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  EXPECT_EQ(lst.size(), 5);
  EXPECT_FALSE(lst.empty());

  auto it = lst.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
}

TEST(ListConstructor, InitializerListConstructorEmpty) {
  s21::list<int> lst{};
  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(ListConstructor, InitializerListConstructorOneElement) {
  s21::list<int> lst{42};
  EXPECT_EQ(lst.size(), 1);
  EXPECT_FALSE(lst.empty());
  EXPECT_EQ(*lst.begin(), 42);
}

TEST(ListConstructor, ConstructorCopy) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};
  s21::list<int> s21Copy(s21List);
  std::list<int> stdCopy(stdList);
  EXPECT_EQ(s21Copy.front(), stdCopy.front());
  EXPECT_EQ(s21Copy.back(), stdCopy.back());
}

TEST(ListConstructor, OperatorCopy) {
  s21::list<int> s21List = {8, 9, 10};
  std::list<int> stdList = {8, 9, 10};
  s21::list<int> s21Copy(s21List);
  std::list<int> stdCopy;
  stdCopy = stdList;
  EXPECT_EQ(s21Copy.front(), stdCopy.front());
  EXPECT_EQ(s21Copy.back(), stdCopy.back());
}

TEST(ListConstructor, CopyConstructor) {
  s21::list<int> original{1, 2, 3, 4, 5};
  s21::list<int> copy(original);

  EXPECT_EQ(copy.size(), original.size());
  EXPECT_FALSE(copy.empty());

  auto it_original = original.begin();
  auto it_copy = copy.begin();
  while (it_original != original.end() && it_copy != copy.end()) {
    EXPECT_EQ(*it_original, *it_copy);
    ++it_original;
    ++it_copy;
  }
}

TEST(ListConstructor, CopyConstructorEmpty) {
  s21::list<int> original;
  s21::list<int> copy(original);

  EXPECT_EQ(copy.size(), 0);
  EXPECT_TRUE(copy.empty());
}

TEST(ListConstructor, CopyConstructorOneElement) {
  s21::list<int> original{42};
  s21::list<int> copy(original);

  EXPECT_EQ(copy.size(), 1);
  EXPECT_FALSE(copy.empty());
  EXPECT_EQ(*copy.begin(), 42);
}

TEST(ListConstructor, ConstructorMove) {
  s21::list<int> s21List = {5, 6, 7};
  std::list<int> stdList = {5, 6, 7};
  s21::list<int> s21Copy(std::move(s21List));
  std::list<int> stdCopy(std::move(stdList));
  EXPECT_EQ(s21Copy.front(), stdCopy.front());
  EXPECT_EQ(s21Copy.back(), stdCopy.back());
  EXPECT_EQ(s21List.empty(), stdList.empty());
}

TEST(ListConstructor, OperatorMove) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};
  s21::list<int> s21Copy;
  s21Copy = std::move(s21List);
  std::list<int> stdCopy;
  stdCopy = std::move(stdList);
  EXPECT_EQ(s21Copy.front(), stdCopy.front());
  EXPECT_EQ(s21Copy.back(), stdCopy.back());
  EXPECT_EQ(s21List.empty(), stdList.empty());
}

TEST(ListIterator, Front) {
  s21::list<int> s21List = {8, 9, 10};
  std::list<int> stdList = {8, 9, 10};
  EXPECT_EQ(s21List.front(), stdList.front());
}

TEST(ListIterator, Back) {
  s21::list<int> s21List = {8, 9, 10};
  std::list<int> stdList = {8, 9, 10};
  EXPECT_EQ(s21List.back(), stdList.back());
}

TEST(ListIterator, Front_Empty) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_TRUE(s21List.empty());
  EXPECT_TRUE(stdList.empty());
}

TEST(ListIterator, Back_Empty) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_TRUE(s21List.empty());
  EXPECT_TRUE(stdList.empty());
}

TEST(ListIterator, Front_SingleElement) {
  s21::list<int> s21List = {42};
  std::list<int> stdList = {42};
  EXPECT_EQ(s21List.front(), stdList.front());
}

TEST(ListIterator, Back_SingleElement) {
  s21::list<int> s21List = {42};
  std::list<int> stdList = {42};
  EXPECT_EQ(s21List.back(), stdList.back());
}

TEST(ListEmpty, EmptyList) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_EQ(s21List.empty(), stdList.empty());
}

TEST(ListEmpty, NonEmptyList) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};
  EXPECT_EQ(s21List.empty(), stdList.empty());
}

TEST(ListEmpty, AfterRemovingAllElements) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};
  s21List.clear();
  stdList.clear();
  EXPECT_EQ(s21List.empty(), stdList.empty());
}

TEST(ListSize, SizeOfEmptyList) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_EQ(s21List.size(), stdList.size());
}

TEST(ListSize, SizeAfterAddingElements) {
  s21::list<int> s21List;
  std::list<int> stdList;
  s21List.push_back(1);
  stdList.push_back(1);
  s21List.push_back(2);
  stdList.push_back(2);
  EXPECT_EQ(s21List.size(), stdList.size());
}

TEST(ListSize, SizeAfterRemovingElements) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};
  s21List.pop_back();
  stdList.pop_back();
  EXPECT_EQ(s21List.size(), stdList.size());
}

TEST(ListMaxSize, MaxSizeIsGreaterThanZero) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_GT(s21List.max_size(), 0);
  EXPECT_GT(stdList.max_size(), 0);
}

TEST(ListMaxSize, MaxSizeConsistency) {
  s21::list<int> s21List;
  std::list<int> stdList;
  EXPECT_EQ(s21List.max_size(), stdList.max_size());
}

TEST(ListMaxSize, MaxSizeGreaterThanZeroAndConsistent) {
  s21::list<int> s21List;
  size_t first_call = s21List.max_size();
  EXPECT_GT(first_call, 0);
  EXPECT_EQ(s21List.max_size(), first_call);
}

TEST(ListInsert, InsertAtBeginning) {
  s21::list<int> s21List = {2, 3, 4};
  std::list<int> stdList = {2, 3, 4};

  auto s21It = s21List.begin();
  auto stdIt = stdList.begin();

  s21List.insert(s21It, 1);
  stdList.insert(stdIt, 1);

  EXPECT_EQ(s21List.size(), stdList.size());
  EXPECT_EQ(s21List.front(), stdList.front());
}

TEST(ListInsert, InsertInMiddle) {
  s21::list<int> s21List = {1, 2, 4};
  std::list<int> stdList = {1, 2, 4};

  auto s21It = ++s21List.begin();
  auto stdIt = ++stdList.begin();

  s21List.insert(s21It, 3);
  stdList.insert(stdIt, 3);

  EXPECT_EQ(s21List.size(), stdList.size());
  EXPECT_EQ(s21List.front(), stdList.front());
  EXPECT_EQ(*s21List.begin(), *stdList.begin());
  EXPECT_EQ(*++s21List.begin(), *++stdList.begin());
}

TEST(ListInsert, InsertAtEnd) {
  s21::list<int> s21List = {1, 2, 3};
  std::list<int> stdList = {1, 2, 3};

  auto s21It = s21List.end();
  auto stdIt = stdList.end();

  s21List.insert(s21It, 4);
  stdList.insert(stdIt, 4);

  EXPECT_EQ(s21List.size(), stdList.size());
  EXPECT_EQ(s21List.back(), stdList.back());
}

TEST(ListErase, EraseMiddleElement) {
  s21::list<int> s21List = {1, 2, 3, 4, 5};
  std::list<int> stdList = {1, 2, 3, 4, 5};

  auto s21It = ++s21List.begin();
  auto stdIt = ++stdList.begin();

  s21List.erase(s21It);
  stdList.erase(stdIt);

  EXPECT_EQ(s21List.size(), stdList.size());

  auto s21ItCheck = s21List.begin();
  auto stdItCheck = stdList.begin();
  while (s21ItCheck != s21List.end() && stdItCheck != stdList.end()) {
    EXPECT_EQ(*s21ItCheck, *stdItCheck);
    ++s21ItCheck;
    ++stdItCheck;
  }
}

TEST(ListErase, EraseFirstElement) {
  s21::list<int> s21List = {1, 2, 3, 4, 5};
  std::list<int> stdList = {1, 2, 3, 4, 5};

  s21List.erase(s21List.begin());
  stdList.erase(stdList.begin());

  EXPECT_EQ(s21List.size(), stdList.size());
  EXPECT_EQ(s21List.front(), stdList.front());
}

TEST(ListErase, EraseLastElement) {
  s21::list<int> s21List = {1, 2, 3, 4, 5};
  std::list<int> stdList = {1, 2, 3, 4, 5};

  auto s21It = --s21List.end();
  auto stdIt = --stdList.end();

  s21List.erase(s21It);
  stdList.erase(stdIt);

  EXPECT_EQ(s21List.size(), stdList.size());
  EXPECT_EQ(s21List.back(), stdList.back());
}

TEST(ListErase, EraseOnlyElement) {
  s21::list<int> s21List = {42};
  std::list<int> stdList = {42};

  s21List.erase(s21List.begin());
  stdList.erase(stdList.begin());

  EXPECT_TRUE(s21List.empty());
  EXPECT_TRUE(stdList.empty());
}

TEST(ListErase, EraseAllElements) {
  s21::list<int> s21List = {1, 2, 3, 4, 5};
  std::list<int> stdList = {1, 2, 3, 4, 5};

  while (!s21List.empty()) {
    s21List.erase(s21List.begin());
  }
  while (!stdList.empty()) {
    stdList.erase(stdList.begin());
  }

  EXPECT_TRUE(s21List.empty());
  EXPECT_TRUE(stdList.empty());
}

TEST(PushBack, PushBackEmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.push_back(1);
  std_list.push_back(1);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(PushBack, PushBackMultipleElements) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  for (int i = 0; i < 5; ++i) {
    s21_list.push_back(i);
    std_list.push_back(i);
  }

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(PopBack, PopBackSingleElement) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.push_back(1);
  std_list.push_back(1);

  s21_list.pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_TRUE(s21_list.empty());
}

TEST(PopBack, PopBackMultipleElements) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  for (int i = 0; i < 5; ++i) {
    s21_list.push_back(i);
    std_list.push_back(i);
  }

  s21_list.pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(PushFront, PushFrontEmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.push_front(1);
  std_list.push_front(1);

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(PushFront, PushFrontMultipleElements) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  for (int i = 0; i < 5; ++i) {
    s21_list.push_front(i);
    std_list.push_front(i);
  }

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(PopFront, PopFrontSingleElement) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.push_front(1);
  std_list.push_front(1);

  s21_list.pop_front();
  std_list.pop_front();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_TRUE(s21_list.empty());
}

TEST(PopFront, PopFrontMultipleElements) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  for (int i = 0; i < 5; ++i) {
    s21_list.push_back(i);
    std_list.push_back(i);
  }

  s21_list.pop_front();
  std_list.pop_front();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(ListSwap, SwapNonEmptyLists) {
  s21::list<int> s21_list1 = {1, 2, 3};
  s21::list<int> s21_list2 = {4, 5, 6, 7};
  std::list<int> std_list1 = {1, 2, 3};
  std::list<int> std_list2 = {4, 5, 6, 7};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());

  auto it1 = s21_list1.begin();
  auto it2 = std_list1.begin();
  while (it1 != s21_list1.end() && it2 != std_list1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }

  it1 = s21_list2.begin();
  it2 = std_list2.begin();
  while (it1 != s21_list2.end() && it2 != std_list2.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(ListSwap, SwapEmptyAndNonEmptyLists) {
  s21::list<int> s21_list1;
  s21::list<int> s21_list2 = {1, 2, 3};
  std::list<int> std_list1;
  std::list<int> std_list2 = {1, 2, 3};

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_EQ(s21_list2.size(), std_list2.size());

  EXPECT_FALSE(s21_list1.empty());
  EXPECT_TRUE(s21_list2.empty());

  auto it1 = s21_list1.begin();
  auto it2 = std_list1.begin();
  while (it1 != s21_list1.end() && it2 != std_list1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(ListSwap, SwapEmptyLists) {
  s21::list<int> s21_list1;
  s21::list<int> s21_list2;
  std::list<int> std_list1;
  std::list<int> std_list2;

  s21_list1.swap(s21_list2);
  std_list1.swap(std_list2);

  EXPECT_TRUE(s21_list1.empty());
  EXPECT_TRUE(s21_list2.empty());
}

TEST(ListMerge, MergeSortedLists) {
  s21::list<int> s21_list1 = {1, 3, 5};
  s21::list<int> s21_list2 = {2, 4, 6};
  std::list<int> std_list1 = {1, 3, 5};
  std::list<int> std_list2 = {2, 4, 6};

  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list2.empty());

  auto s21_it = s21_list1.begin();
  auto std_it = std_list1.begin();
  while (s21_it != s21_list1.end() && std_it != std_list1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMerge, MergeEmptyLists) {
  s21::list<int> s21_list1;
  s21::list<int> s21_list2;
  std::list<int> std_list1;
  std::list<int> std_list2;

  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);

  EXPECT_TRUE(s21_list1.empty());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list1.empty());
  EXPECT_TRUE(std_list2.empty());
}

TEST(ListMerge, MergeEmptyWithNonEmpty) {
  s21::list<int> s21_list1;
  s21::list<int> s21_list2 = {1, 2, 3};
  std::list<int> std_list1;
  std::list<int> std_list2 = {1, 2, 3};

  s21_list1.merge(s21_list2);
  std_list1.merge(std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list2.empty());

  auto s21_it = s21_list1.begin();
  auto std_it = std_list1.begin();
  while (s21_it != s21_list1.end() && std_it != std_list1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSplice, SpliceEntireList) {
  s21::list<int> s21_list1 = {1, 2, 3};
  s21::list<int> s21_list2 = {4, 5, 6};
  std::list<int> std_list1 = {1, 2, 3};
  std::list<int> std_list2 = {4, 5, 6};

  s21_list1.splice(s21_list1.begin(), s21_list2);
  std_list1.splice(std_list1.begin(), std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list2.empty());

  auto s21_it = s21_list1.begin();
  auto std_it = std_list1.begin();
  while (s21_it != s21_list1.end() && std_it != std_list1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSplice, SpliceIntoMiddle) {
  s21::list<int> s21_list1 = {1, 2, 5, 6};
  s21::list<int> s21_list2 = {3, 4};
  std::list<int> std_list1 = {1, 2, 5, 6};
  std::list<int> std_list2 = {3, 4};

  auto s21_it = s21_list1.cbegin();
  auto std_it = std_list1.cbegin();
  ++s21_it;
  ++s21_it;
  ++std_it;
  ++std_it;

  s21_list1.splice(s21_it, s21_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list2.empty());

  s21_it = s21_list1.begin();
  std_it = std_list1.begin();
  while (s21_it != s21_list1.end() && std_it != std_list1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSplice, SpliceEmptyList) {
  s21::list<int> s21_list1 = {1, 2, 3};
  s21::list<int> s21_list2;
  std::list<int> std_list1 = {1, 2, 3};
  std::list<int> std_list2;

  s21_list1.splice(s21_list1.begin(), s21_list2);
  std_list1.splice(std_list1.begin(), std_list2);

  EXPECT_EQ(s21_list1.size(), std_list1.size());
  EXPECT_TRUE(s21_list2.empty());
  EXPECT_TRUE(std_list2.empty());

  auto s21_it = s21_list1.begin();
  auto std_it = std_list1.begin();
  while (s21_it != s21_list1.end() && std_it != std_list1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListReverse, ReverseEmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.reverse();
  std_list.reverse();

  EXPECT_TRUE(s21_list.empty());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListReverse, ReverseSingleElementList) {
  s21::list<int> s21_list = {42};
  std::list<int> std_list = {42};

  s21_list.reverse();
  std_list.reverse();

  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListReverse, ReverseMultipleElementsList) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};

  s21_list.reverse();
  std_list.reverse();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();

  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListReverse, ReverseEvenNumberOfElements) {
  s21::list<int> s21_list = {1, 2, 3, 4};
  std::list<int> std_list = {1, 2, 3, 4};

  s21_list.reverse();
  std_list.reverse();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();

  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListReverse, ReverseOddNumberOfElements) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};

  s21_list.reverse();
  std_list.reverse();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();

  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListUnique, UniqueEmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.unique();
  std_list.unique();

  EXPECT_TRUE(s21_list.empty());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListUnique, UniqueSingleElementList) {
  s21::list<int> s21_list = {42};
  std::list<int> std_list = {42};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(ListUnique, UniqueNoDuplicates) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListUnique, UniqueWithDuplicates) {
  s21::list<int> s21_list = {1, 2, 2, 3, 3, 3, 4, 5, 5};
  std::list<int> std_list = {1, 2, 2, 3, 3, 3, 4, 5, 5};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListUnique, UniqueAllDuplicates) {
  s21::list<int> s21_list = {1, 1, 1, 1, 1};
  std::list<int> std_list = {1, 1, 1, 1, 1};

  s21_list.unique();
  std_list.unique();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.size(), 1);
  EXPECT_EQ(s21_list.front(), 1);
}

TEST(ListSort, SortEmptyList) {
  s21::list<int> s21_list;
  std::list<int> std_list;

  s21_list.sort();
  std_list.sort();

  EXPECT_TRUE(s21_list.empty());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListSort, SortSingleElementList) {
  s21::list<int> s21_list = {42};
  std::list<int> std_list = {42};

  s21_list.sort();
  std_list.sort();

  EXPECT_EQ(s21_list.size(), std_list.size());
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(ListSort, SortAlreadySortedList) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};

  s21_list.sort();
  std_list.sort();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSort, SortReverseOrderList) {
  s21::list<int> s21_list = {5, 4, 3, 2, 1};
  std::list<int> std_list = {5, 4, 3, 2, 1};

  s21_list.sort();
  std_list.sort();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSort, SortRandomOrderList) {
  s21::list<int> s21_list = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  std::list<int> std_list = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

  s21_list.sort();
  std_list.sort();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListSort, SortListWithDuplicates) {
  s21::list<int> s21_list = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  std::list<int> std_list = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

  s21_list.sort();
  std_list.sort();

  EXPECT_EQ(s21_list.size(), std_list.size());

  auto s21_it = s21_list.begin();
  auto std_it = std_list.begin();
  while (s21_it != s21_list.end() && std_it != std_list.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListInsertMany, InsertManyAtBeginning) {
  s21::list<int> myList = {3, 4, 5};
  std::list<int> stdList = {3, 4, 5};
  auto it1 = myList.cbegin();
  myList.insert_many(it1, 1, 2);
  auto it2 = stdList.cbegin();
  stdList.insert(it2, {1, 2});

  ASSERT_EQ(myList.size(), stdList.size());

  auto myIt = myList.begin();
  auto stdIt = stdList.begin();

  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertMany, InsertManyInMiddle) {
  s21::list<int> myList = {1, 2, 5, 6};
  std::list<int> stdList = {1, 2, 5, 6};
  auto it1 = myList.cbegin();
  it1++;
  it1++;
  myList.insert_many(it1, 3, 4);
  auto it2 = stdList.cbegin();
  it2++;
  it2++;
  stdList.insert(it2, {3, 4});

  ASSERT_EQ(myList.size(), stdList.size());

  auto myIt = myList.begin();
  auto stdIt = stdList.begin();

  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertMany, InsertManyAtEnd) {
  s21::list<int> myList = {1, 2, 3, 4};
  std::list<int> stdList = {1, 2, 3, 4};
  auto it1 = myList.end();
  myList.insert_many(it1, 5, 6);
  auto it2 = stdList.end();
  stdList.insert(it2, {5, 6});

  ASSERT_EQ(myList.size(), stdList.size());

  auto myIt = myList.begin();
  auto stdIt = stdList.begin();

  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertMany, InsertManyEmpty) {
  s21::list<int> myList;
  std::list<int> stdList;
  auto it1 = myList.cbegin();
  myList.insert_many(it1, 1, 2, 3);
  auto it2 = stdList.cbegin();
  stdList.insert(it2, {1, 2, 3});

  ASSERT_EQ(myList.size(), stdList.size());

  auto myIt = myList.begin();
  auto stdIt = stdList.begin();

  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertManyBack, InsertManyBackEmptyList) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.insert_many_back(1, 2, 3, 4, 5);
  stdList.insert(stdList.end(), {1, 2, 3, 4, 5});
  EXPECT_EQ(myList.size(), stdList.size());
  auto myIt = myList.begin();
  auto stdIt = stdList.begin();
  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertManyBack, InsertManyBackNonEmptyList) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.push_back(0);
  stdList.push_back(0);
  myList.insert_many_back(1, 2, 3);
  stdList.insert(stdList.end(), {1, 2, 3});
  EXPECT_EQ(myList.size(), stdList.size());
  auto myIt = myList.begin();
  auto stdIt = stdList.begin();
  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertManyBack, InsertManyBackZeroElements) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.insert_many_back();
  stdList.insert(stdList.end(), {});
  EXPECT_EQ(myList.size(), stdList.size());
}

TEST(ListInsertManyFront, InsertManyFrontEmptyList) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.insert_many_front(1, 2, 3, 4, 5);
  stdList.insert(stdList.begin(), {1, 2, 3, 4, 5});
  EXPECT_EQ(myList.size(), stdList.size());
  auto myIt = myList.begin();
  auto stdIt = stdList.begin();
  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertManyFront, InsertManyFrontNonEmptyList) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.push_back(0);
  stdList.push_back(0);
  myList.insert_many_front(1, 2, 3);
  stdList.insert(stdList.begin(), {1, 2, 3});
  EXPECT_EQ(myList.size(), stdList.size());
  auto myIt = myList.begin();
  auto stdIt = stdList.begin();
  while (myIt != myList.end() && stdIt != stdList.end()) {
    EXPECT_EQ(*myIt, *stdIt);
    ++myIt;
    ++stdIt;
  }
}

TEST(ListInsertManyFront, InsertManyFrontZeroElements) {
  s21::list<int> myList;
  std::list<int> stdList;

  myList.insert_many_front();
  stdList.insert(stdList.begin(), {});

  EXPECT_EQ(myList.size(), stdList.size());
}