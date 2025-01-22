#include "test.h"

class S21ArrayTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21ArrayTest, ConstructorDefault0) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
  EXPECT_EQ(arr.size(), 0);
}

TEST_F(S21ArrayTest, ConstructorDefault1) {
  s21::array<int, 5> arr;
  EXPECT_FALSE(arr.empty());
  EXPECT_EQ(arr.size(), 5);
}

TEST_F(S21ArrayTest, ConstructorItems0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  std::array<int, 5> arr_std{1, 2, 3, 4, 5};
  EXPECT_FALSE(arr.empty());
  for (int i = 0; i < (int)arr.size(); i++) {
    EXPECT_EQ(arr[i], arr_std[i]);
  }
}

TEST_F(S21ArrayTest, ConstructorItems1) {
  s21::array<std::string, 5> arr{"a", "bb", "ccc", "dd", "f"};
  std::array<std::string, 5> arr_std{"a", "bb", "ccc", "dd", "f"};
  EXPECT_FALSE(arr.empty());
  for (int i = 0; i < (int)arr.size(); i++) {
    EXPECT_EQ(arr[i], arr_std[i]);
  }
}

TEST_F(S21ArrayTest, ConstructorItems2) {
  s21::array<std::string, 6> arr{"a", "bb", "ccc", "dd", "f"};
  std::array<std::string, 6> arr_std{"a", "bb", "ccc", "dd", "f"};
  EXPECT_FALSE(arr.empty());
  for (int i = 0; i < (int)arr.size(); i++) {
    EXPECT_EQ(arr[i], arr_std[i]);
  }
}

TEST_F(S21ArrayTest, ConstructorCpy0) {
  s21::array<int, 5> arr1{1, 2, 3, 4, 5};
  s21::array<int, 5> arr2(arr1);
  EXPECT_EQ(arr1.size(), arr2.size());
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(arr1[i], arr2[i]);
  }
}

TEST_F(S21ArrayTest, ConstructorMove0) {
  s21::array<int, 5> arr1{1, 2, 3, 4, 5};
  s21::array<int, 5> arr2(std::move(arr1));
  EXPECT_EQ(arr2.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(arr2[i], i + 1);
  }
}

TEST_F(S21ArrayTest, Begin0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  auto elem = arr.begin();
  EXPECT_EQ(*elem, 1);
}

TEST_F(S21ArrayTest, Begin1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  auto elem = arr.begin();
  EXPECT_DOUBLE_EQ(*elem, 1.1);
}
TEST_F(S21ArrayTest, Begin2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  auto elem = arr.begin();
  EXPECT_EQ(*elem, "1");
}

TEST_F(S21ArrayTest, End0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  auto elem = arr.end();
  --elem;
  EXPECT_EQ(*elem, 5);
}

TEST_F(S21ArrayTest, End1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  auto *elem = arr.end();
  --elem;
  EXPECT_DOUBLE_EQ(*elem, 5.5);
}
TEST_F(S21ArrayTest, End2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  auto *elem = arr.end();
  --elem;
  EXPECT_EQ(*elem, "5");
}

TEST_F(S21ArrayTest, at0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  int x;
  EXPECT_NO_THROW(x = arr.at(3));
  EXPECT_EQ(x, 4);
  EXPECT_ANY_THROW(arr.at(8));
}

TEST_F(S21ArrayTest, at1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  double x;
  EXPECT_NO_THROW(x = arr.at(2));
  EXPECT_EQ(x, 3.3);
  EXPECT_ANY_THROW(arr.at(8));
}

TEST_F(S21ArrayTest, at2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  std::string x;
  EXPECT_NO_THROW(x = arr.at(1));
  EXPECT_EQ(x, "2");
  EXPECT_ANY_THROW(arr.at(8));
}

TEST_F(S21ArrayTest, operator0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  int x;
  EXPECT_NO_THROW(x = arr[3]);
  EXPECT_EQ(x, 4);
}

TEST_F(S21ArrayTest, operator1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  double x;
  EXPECT_NO_THROW(x = arr[2]);
  EXPECT_EQ(x, 3.3);
}

TEST_F(S21ArrayTest, operator2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  std::string x;
  EXPECT_NO_THROW(x = arr[1]);
  EXPECT_EQ(x, "2");
}

TEST_F(S21ArrayTest, front0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(arr.front(), 1);
}

TEST_F(S21ArrayTest, front1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_DOUBLE_EQ(arr.front(), 1.1);
}

TEST_F(S21ArrayTest, front2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  EXPECT_EQ(arr.front(), "1");
}

TEST_F(S21ArrayTest, back0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(arr.back(), 5);
}

TEST_F(S21ArrayTest, back1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_DOUBLE_EQ(arr.back(), 5.5);
}

TEST_F(S21ArrayTest, back2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  EXPECT_EQ(arr.back(), "5");
}

TEST_F(S21ArrayTest, data0) {
  s21::array<int, 5> s21_array = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(*(s21_array.data() + i), *(std_array.data() + i));
  }
}

TEST_F(S21ArrayTest, data1) {
  s21::array<double, 3> s21_array = {1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(*(s21_array.data()), 1.1);
}

TEST_F(S21ArrayTest, data2) {
  s21::array<char, 4> s21_array = {'a', 'b', 'c', 'd'};
  EXPECT_EQ(*(s21_array.data()), 'a');
}

TEST_F(S21ArrayTest, data3) {
  s21::array<std::string, 2> s21_array = {"aa", "bb"};
  EXPECT_EQ(*(s21_array.data()), "aa");
}

TEST_F(S21ArrayTest, data4) {
  s21::array<int, 0> s21_array;
  EXPECT_EQ(s21_array.data(), nullptr);
}

TEST_F(S21ArrayTest, operator4) {
  s21::array<int, 5> s21_array1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> s21_array2;
  s21_array2 = s21_array1;
  std::array<int, 5> std_array1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array2;
  std_array2 = std_array1;
  for (int i = 0; i < (int)s21_array2.size(); i++)
    EXPECT_EQ(s21_array2[i], std_array2[i]);
}

TEST_F(S21ArrayTest, operator5) {
  s21::array<int, 5> s21_array1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> s21_array2;
  s21_array2 = std::move(s21_array1);
  std::array<int, 5> std_array1 = {1, 2, 3, 4, 5};
  std::array<int, 5> std_array2;
  std_array2 = std::move(std_array1);
  for (int i = 0; i < (int)s21_array2.size(); i++)
    EXPECT_EQ(s21_array2[i], std_array2[i]);
}

TEST_F(S21ArrayTest, size0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST_F(S21ArrayTest, size1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(arr.size(), 5);
}

TEST_F(S21ArrayTest, size2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  EXPECT_EQ(arr.size(), 5);
}

TEST_F(S21ArrayTest, maxSize0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  EXPECT_EQ(arr.max_size(), 5);
}

TEST_F(S21ArrayTest, maxSize1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(arr.max_size(), 5);
}

TEST_F(S21ArrayTest, maxSize2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  EXPECT_EQ(arr.max_size(), 5);
}

TEST_F(S21ArrayTest, fill0) {
  s21::array<int, 5> arr{1, 2, 3, 4, 5};
  s21::array<int, 5> arr2;
  arr.fill(2);
  arr2.fill(3);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(arr[i], 2);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(arr2[i], 3);
  }
}

TEST_F(S21ArrayTest, fill1) {
  s21::array<double, 5> arr{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::array<double, 5> arr2;
  arr.fill(2.2);
  arr2.fill(3.3);
  for (int i = 0; i < 5; i++) {
    EXPECT_DOUBLE_EQ(arr[i], 2.2);
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_DOUBLE_EQ(arr2[i], 3.3);
  }
}

TEST_F(S21ArrayTest, fill2) {
  s21::array<std::string, 5> arr{"1", "2", "3", "4", "5"};
  s21::array<std::string, 5> arr2;
  arr.fill("2");
  arr2.fill("3");
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(arr[i], "2");
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(arr2[i], "3");
  }
}