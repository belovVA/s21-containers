#include <vector>

#include "test.h"

TEST(vectorConstructorTest, InitialState) {
  std::cout << "\n ============== TEST: S21_vector ============== \n"
            << std::endl;
  s21::vector<int> test;
  std::vector<int> test_v;

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test.data(), test_v.data());
}

TEST(vectorConstructorTest, InitialState2) {
  s21::vector<float> test;
  std::vector<float> test_v;

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test.data(), test_v.data());
}

TEST(vectorConstructorTest, InitialStateWithSize) {
  s21::vector<double> test1(10);
  std::vector<double> test_v1(10);

  ASSERT_EQ(test1.size(), test_v1.size());
  ASSERT_EQ(test1.capacity(), test_v1.capacity());
}

TEST(vectorConstructorTest, InitialStateWithSize2) {
  s21::vector<float> test1(10);
  std::vector<float> test_v1(10);

  ASSERT_EQ(test1.size(), test_v1.size());
  ASSERT_EQ(test1.capacity(), test_v1.capacity());
}

TEST(vectorConstructorTest, InitialStateWithList) {
  s21::vector<int> test = {1, 3, 5, 7, 9};
  std::vector<int> test_v = {1, 3, 5, 7, 9};

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test[0], test_v[0]);
  ASSERT_EQ(test[1], test_v[1]);
  ASSERT_EQ(test[2], test_v[2]);
  ASSERT_EQ(test[3], test_v[3]);
  ASSERT_EQ(test[4], test_v[4]);
}

TEST(vectorConstructorTest, InitialStateWithList2) {
  s21::vector<float> test = {1.1, 3.3, 5.5, 7.7, 9.9};
  std::vector<float> test_v = {1.1, 3.3, 5.5, 7.7, 9.9};

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test[0], test_v[0]);
  ASSERT_EQ(test[1], test_v[1]);
  ASSERT_EQ(test[2], test_v[2]);
  ASSERT_EQ(test[3], test_v[3]);
  ASSERT_EQ(test[4], test_v[4]);
}

TEST(vectorConstructorTest, CopyConstructorCopiesData) {
  s21::vector<int> test(5);
  std::vector<int> test_v(5);
  for (int i = 0; i < 5; ++i) {
    test[i] = i + 1;
    test_v[i] = i + 1;
  }

  s21::vector<int> copyTest(test);
  std::vector<int> copyTest_v(test_v);

  ASSERT_EQ(copyTest.size(), copyTest_v.size());
  ASSERT_EQ(copyTest.capacity(), copyTest_v.capacity());
  for (size_t i = 0; i < copyTest.size(); ++i) {
    ASSERT_EQ(copyTest[i], copyTest_v[i]);
  }
}

TEST(vectorConstructorTest, CopyConstructorFromEmptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  s21::vector<int> copyTest(test);
  std::vector<int> copyTest_v(test_v);

  ASSERT_EQ(copyTest.size(), copyTest_v.size());
  ASSERT_EQ(copyTest.capacity(), copyTest_v.capacity());
}

TEST(vectorConstructorTest, MoveConstructorTransfersData) {
  s21::vector<int> test(5);
  std::vector<int> test_v(5);
  for (int i = 0; i < 5; ++i) {
    test[i] = i + 1;
    test_v[i] = i + 1;
  }

  s21::vector<int> moved(std::move(test));
  std::vector<int> moved_v(std::move(test_v));

  ASSERT_EQ(moved.size(), moved_v.size());
  ASSERT_EQ(moved.capacity(), moved_v.capacity());
  for (size_t i = 0; i < moved.size(); ++i) {
    ASSERT_EQ(moved[i], moved_v[i]);
  }
  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorConstructorTest, MoveConstructorFromEmptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  s21::vector<int> moved(std::move(test));
  std::vector<int> moved_v(std::move(test_v));

  ASSERT_EQ(moved.size(), moved_v.size());
  ASSERT_EQ(moved.capacity(), moved_v.capacity());
}

TEST(vectorMoveAssignmentTest, MoveFromNonEmptyToEmpty) {
  s21::vector<int> test;
  std::vector<int> test_v;
  for (int i = 0; i < 5; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  s21::vector<int> test2;
  std::vector<int> test_v2;
  test2 = std::move(test);
  test_v2 = std::move(test_v);

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test.data(), test_v.data());

  ASSERT_EQ(test2.size(), test_v2.size());
  ASSERT_EQ(test2.capacity(), test_v2.capacity());
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(test2[i], test_v2[i]);
  }
}

TEST(vectorMoveAssignmentTest, MoveFromNonEmptyToNonEmpty) {
  s21::vector<int> test(5);
  std::vector<int> test_v(5);

  for (int i = 0; i < 5; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  s21::vector<int> test2(3);
  std::vector<int> test_v2(3);
  for (int i = 0; i < 3; ++i) {
    test2.push_back(i + 10);
    test_v2.push_back(i + 10);
  }

  test2 = std::move(test);
  test_v2 = std::move(test_v);

  ASSERT_EQ(test.size(), test_v.size());
  ASSERT_EQ(test.capacity(), test_v.capacity());
  ASSERT_EQ(test.data(), test_v.data());

  ASSERT_EQ(test2.size(), test_v2.size());
  ASSERT_EQ(test2.capacity(), test_v2.capacity());
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(test2[i], test_v2[i]);
  }
}

TEST(vectorAtTest, ValidIndex) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  ASSERT_EQ(test.at(0), test_v.at(0));
  ASSERT_EQ(test.at(1), test_v.at(1));
  ASSERT_EQ(test.at(2), test_v.at(2));
}

TEST(vectorAtTest, OutOfRangeException) {
  s21::vector<int> test = {1, 2, 3};

  EXPECT_THROW(test.at(3), std::out_of_range);
  EXPECT_THROW(test.at(50), std::out_of_range);
}

TEST(vectorAtTest, EmptyvectorException) {
  s21::vector<int> test;

  EXPECT_THROW(test.at(0), std::out_of_range);
  EXPECT_THROW(test.at(10), std::out_of_range);
}

TEST(vectorAtTest, AccessLastElement) {
  s21::vector<int> test(5);
  std::vector<int> test_v(5);
  for (int i = 0; i < 5; ++i) {
    test.push_back(i * 10);
    test_v.push_back(i * 10);
  }

  ASSERT_EQ(test.at(4), test_v.at(4));
}

TEST(vectorOperatorTest, ValidAccess) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(test[0], test_v[0]);
  EXPECT_EQ(test[1], test_v[1]);
  EXPECT_EQ(test[2], test_v[2]);
}

TEST(vectorOperatorTest, FirstAndLastElementAccess) {
  s21::vector<int> test = {10, 20, 30};
  std::vector<int> test_v = {10, 20, 30};

  EXPECT_EQ(test[0], test_v[0]);
  EXPECT_EQ(test[2], test_v[2]);
}

TEST(vectorFrontTest, ValidAccess) {
  s21::vector<int> test = {10, 20, 30};
  std::vector<int> test_v = {10, 20, 30};

  EXPECT_EQ(test.front(), test_v.front());
}

TEST(vectorFrontTest, SingleElementAccess) {
  s21::vector<int> test = {5};
  std::vector<int> test_v = {5};

  EXPECT_EQ(test.front(), test_v.front());
}

TEST(vectorFrontTest, AccessAfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 1; i <= 5; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  EXPECT_EQ(test.back(), test_v.back());
}

TEST(vectorBackTest, ValidAccess) {
  s21::vector<int> test = {10, 20, 30};
  std::vector<int> test_v = {10, 20, 30};

  EXPECT_EQ(test.back(), test_v.back());
}

TEST(vectorBackTest, SingleElementAccess) {
  s21::vector<int> test = {5};
  std::vector<int> test_v = {5};

  EXPECT_EQ(test.back(), test_v.back());
}

TEST(vectorBackTest, AccessAfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 1; i <= 5; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  EXPECT_EQ(test.back(), test_v.back());
}

TEST(vectorDataTest, ValidPointer) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(*test.data(), *test_v.data());
  EXPECT_EQ(test.data()[1], test_v.data()[1]);
  EXPECT_EQ(test.data()[2], test_v.data()[2]);
}

TEST(vectorDataTest, EmptyvectorPointer) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.data(), test_v.data());
}

TEST(vectorDataTest, ModifyDataThroughPointer) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  *test.data() = 10;
  *test_v.data() = 10;

  EXPECT_EQ(test[0], test_v[0]);
  EXPECT_EQ(test[1], test_v[1]);
  EXPECT_EQ(test[2], test_v[2]);
}

TEST(vectorDataTest, DataAfterResize) {
  s21::vector<int> test = {1, 2, 3, 4};
  std::vector<int> test_v = {1, 2, 3, 4};

  test.push_back(5);
  test_v.push_back(5);

  EXPECT_EQ(test.data()[4], test_v.data()[4]);
  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorBeginTest, CompareWithStdvector) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(*test.begin(), *test_v.begin());
}

TEST(vectorBeginTest, Emptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.begin(), test.end());
  EXPECT_EQ(test_v.begin(), test_v.end());
}

TEST(vectorBeginTest, ModifyElement) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  *test.begin() = 10;
  *test_v.begin() = 10;

  EXPECT_EQ(*test.begin(), *test_v.begin());
}

TEST(vectorEndTest, CompareWithStdvector) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_NE(test.end(), test.begin());
  EXPECT_NE(test_v.end(), test_v.begin());
}

TEST(vectorEndTest, Emptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.end(), test.begin());
  EXPECT_EQ(test_v.end(), test_v.begin());
}

TEST(vectorEndTest, Iteration) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  auto s21_iter = test.begin();
  auto std_iter = test_v.begin();

  while (s21_iter != test.end() && std_iter != test_v.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    ++s21_iter;
    ++std_iter;
  }

  EXPECT_EQ(s21_iter, test.end());
  EXPECT_EQ(std_iter, test_v.end());
}

TEST(vectorEmptyTest, Emptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.empty(), test_v.empty());
}

TEST(vectorEmptyTest, NonEmptyvector) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(test.empty(), test_v.empty());
}

TEST(vectorEmptyTest, AfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.empty(), test_v.empty());

  test.push_back(1);
  test_v.push_back(1);

  EXPECT_EQ(test.empty(), test_v.empty());
}

TEST(vectorEmptyTest, AfterClearing) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(test.empty(), test_v.empty());

  test.clear();
  test_v.clear();

  EXPECT_EQ(test.empty(), test_v.empty());
}

TEST(vectorSizeTest, Emptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.size(), test_v.size());
}

TEST(vectorSizeTest, NonEmptyvector) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  EXPECT_EQ(test.size(), test_v.size());
}

TEST(vectorSizeTest, AfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.push_back(1);
  test_v.push_back(1);

  EXPECT_EQ(test.size(), test_v.size());
}

TEST(vectorSizeTest, AfterClearing) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.clear();
  test_v.clear();

  EXPECT_EQ(test.size(), test_v.size());
}

TEST(vectorMaxSizeTest, MaxSizeInt) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.max_size(), test_v.max_size());
}

TEST(vectorMaxSizeTest, MaxSizeDouble) {
  s21::vector<double> test;
  std::vector<double> test_v;

  EXPECT_EQ(test.max_size(), test_v.max_size());
}

TEST(vectorMaxSizeTest, MaxSizeEmptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.max_size(), test_v.max_size());
}

TEST(vectorMaxSizeTest, MaxSizeAfterReserve) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.reserve(100);
  test_v.reserve(100);

  EXPECT_EQ(test.max_size(), test_v.max_size());
}

TEST(vectorReserveTest, ReserveIncreaseCapacity) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.reserve(10);
  test_v.reserve(10);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorReserveTest, ReserveNoDecrease) {
  s21::vector<int> test(15);
  std::vector<int> test_v(15);

  test.reserve(10);
  test_v.reserve(10);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorReserveTest, ReserveExact) {
  s21::vector<int> test(5);
  std::vector<int> test_v(5);

  test.reserve(5);
  test_v.reserve(5);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorReserveTest, ReserveEmptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.reserve(20);
  test_v.reserve(20);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorCapacityTest, Emptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorCapacityTest, CapacityAfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 0; i < 10; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorCapacityTest, CapacityAfterReserve) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.reserve(15);
  test_v.reserve(15);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorCapacityTest, CapacityShrinkToFit) {
  s21::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> test_v = {1, 2, 3, 4, 5};

  test.reserve(20);
  test_v.reserve(20);

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorShrinkToFitTest, ShrinkToFitAfterPushBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 0; i < 10; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  test.reserve(20);
  test_v.reserve(20);

  test.shrink_to_fit();
  test_v.shrink_to_fit();

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorShrinkToFitTest, ShrinkToFitAfterPopBack) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 0; i < 10; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  for (int i = 0; i < 5; ++i) {
    test.pop_back();
    test_v.pop_back();
  }

  test.shrink_to_fit();
  test_v.shrink_to_fit();

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorShrinkToFitTest, ShrinkToFitAfterReserve) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 0; i < 10; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  test.reserve(50);
  test_v.reserve(50);

  test.shrink_to_fit();
  test_v.shrink_to_fit();

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(vectorShrinkToFitTest, ShrinkToFitEmptyvector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.shrink_to_fit();
  test_v.shrink_to_fit();

  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(VectorClearTest, ClearEmptyVector) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.clear();
  test_v.clear();

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(VectorClearTest, ClearNonEmptyVector) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.clear();
  test_v.clear();

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
}

TEST(VectorClearTest, ClearAndPushBack) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.clear();
  test_v.clear();

  test.push_back(4);
  test_v.push_back(4);

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
  EXPECT_EQ(test[0], test_v[0]);
}

TEST(VectorInsertTest, InsertAtBeginning) {
  s21::vector<int> test = {2, 3};
  std::vector<int> test_v = {2, 3};

  test.insert(test.begin(), 1);
  test_v.insert(test_v.begin(), 1);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorInsertTest, InsertAtMiddle) {
  s21::vector<int> test = {1, 3};
  std::vector<int> test_v = {1, 3};

  test.insert(test.begin() + 1, 2);
  test_v.insert(test_v.begin() + 1, 2);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorInsertTest, InsertAtEnd) {
  s21::vector<int> test = {1, 2};
  std::vector<int> test_v = {1, 2};

  test.insert(test.end(), 3);
  test_v.insert(test_v.end(), 3);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorEraseTest, EraseFromBeginning) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.erase(test.begin());
  test_v.erase(test_v.begin());

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorEraseTest, EraseFromMiddle) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.erase(test.begin() + 1);
  test_v.erase(test_v.begin() + 1);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorEraseTest, EraseFromEnd) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.erase(test.end() - 1);
  test_v.erase(test_v.end() - 1);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorPushBackTest, PushBackToEmpty) {
  s21::vector<int> test;
  std::vector<int> test_v;

  test.push_back(1);
  test_v.push_back(1);

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test[0], test_v[0]);
}

TEST(VectorPushBackTest, PushBackToNonEmpty) {
  s21::vector<int> test = {1, 2};
  std::vector<int> test_v = {1, 2};

  test.push_back(3);
  test_v.push_back(3);

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorPushBackTest, PushBackCapacity) {
  s21::vector<int> test;
  std::vector<int> test_v;

  for (int i = 0; i < 10; ++i) {
    test.push_back(i);
    test_v.push_back(i);
  }

  EXPECT_EQ(test.size(), test_v.size());
  EXPECT_EQ(test.capacity(), test_v.capacity());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorPopBackTest, PopBackNonEmpty) {
  s21::vector<int> test = {1, 2, 3};
  std::vector<int> test_v = {1, 2, 3};

  test.pop_back();
  test_v.pop_back();

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorPopBackTest, PopBackToEmpty) {
  s21::vector<int> test = {1};
  std::vector<int> test_v = {1};

  test.pop_back();
  test_v.pop_back();

  EXPECT_EQ(test.size(), test_v.size());
}

TEST(VectorPopBackTest, MultiplePopBacks) {
  s21::vector<int> test = {1, 2, 3, 4};
  std::vector<int> test_v = {1, 2, 3, 4};

  for (int i = 0; i < 3; ++i) {
    test.pop_back();
    test_v.pop_back();
  }

  EXPECT_EQ(test.size(), test_v.size());
  for (size_t i = 0; i < test.size(); ++i) {
    EXPECT_EQ(test[i], test_v[i]);
  }
}

TEST(VectorSwapTest, SwapEqualSize) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int> test2 = {4, 5, 6};
  std::vector<int> test_v1 = {1, 2, 3};
  std::vector<int> test_v2 = {4, 5, 6};

  test1.swap(test2);
  test_v1.swap(test_v2);

  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
    EXPECT_EQ(test2[i], test_v2[i]);
  }
}

TEST(VectorSwapTest, SwapDifferentSize) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int> test2 = {4, 5};
  std::vector<int> test_v1 = {1, 2, 3};
  std::vector<int> test_v2 = {4, 5};

  test1.swap(test2);
  test_v1.swap(test_v2);

  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
  }
  for (size_t i = 0; i < test2.size(); ++i) {
    EXPECT_EQ(test2[i], test_v2[i]);
  }
}

TEST(VectorSwapTest, SwapWithEmptyVector) {
  s21::vector<int> test1 = {1, 2, 3};
  s21::vector<int> test2;
  std::vector<int> test_v1 = {1, 2, 3};
  std::vector<int> test_v2;

  test1.swap(test2);
  test_v1.swap(test_v2);

  EXPECT_EQ(test1.size(), test_v1.size());
  EXPECT_EQ(test2.size(), test_v2.size());
}

TEST(VectorInsertManyTest, InsertMultipleAtMiddle) {
  s21::vector<int> test1 = {1, 2, 3, 4};
  std::vector<int> test_v1 = {1, 2, 3, 4};

  test1.insert_many(test1.begin() + 2, 5, 6, 7);
  test_v1.insert(test_v1.begin() + 2, {5, 6, 7});

  EXPECT_EQ(test1.size(), test_v1.size());
  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
  }
}

TEST(VectorInsertManyTest, InsertMultipleAtBeginning) {
  s21::vector<int> test1 = {4, 5, 6};
  std::vector<int> test_v1 = {4, 5, 6};

  test1.insert_many(test1.begin(), 1, 2, 3);
  test_v1.insert(test_v1.begin(), {1, 2, 3});

  EXPECT_EQ(test1.size(), test_v1.size());
  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
  }
}

TEST(VectorInsertManyTest, InsertMultipleAtEnd) {
  s21::vector<int> test1 = {1, 2, 3};
  std::vector<int> test_v1 = {1, 2, 3};

  test1.insert_many(test1.end(), 4, 5, 6);
  test_v1.insert(test_v1.end(), {4, 5, 6});

  EXPECT_EQ(test1.size(), test_v1.size());
  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
  }
}

TEST(VectorInsertManyTest, InsertEmpty) {
  s21::vector<int> test1 = {1, 2, 3};
  std::vector<int> test_v1 = {1, 2, 3};

  test1.insert_many(test1.end());
  test_v1.insert(test_v1.end(), {});

  EXPECT_EQ(test1.size(), test_v1.size());
  for (size_t i = 0; i < test1.size(); ++i) {
    EXPECT_EQ(test1[i], test_v1[i]);
  }
}

TEST(VectorInsertManyBack, InsertManyBackEmptyVector) {
  s21::vector<int> myVector;
  std::vector<int> stdVector;

  myVector.insert_many_back(1, 2, 3, 4, 5);
  stdVector.insert(stdVector.end(), {1, 2, 3, 4, 5});
  EXPECT_EQ(myVector.size(), stdVector.size());
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], stdVector[i]);
  }
}

TEST(VectorInsertManyBack, InsertManyBackNonEmptyVector) {
  s21::vector<int> myVector;
  std::vector<int> stdVector;

  myVector.push_back(0);
  stdVector.push_back(0);
  myVector.insert_many_back(1, 2, 3);
  stdVector.insert(stdVector.end(), {1, 2, 3});
  EXPECT_EQ(myVector.size(), stdVector.size());
  for (size_t i = 0; i < myVector.size(); ++i) {
    EXPECT_EQ(myVector[i], stdVector[i]);
  }
}

TEST(VectorInsertManyBack, InsertManyBackZeroElements) {
  s21::vector<int> myVector;
  std::vector<int> stdVector;

  myVector.insert_many_back();
  stdVector.insert(stdVector.end(), {});
  EXPECT_EQ(myVector.size(), stdVector.size());
}