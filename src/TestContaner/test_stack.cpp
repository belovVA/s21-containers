#include "test.h"

class S21StackTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21StackTest, Constructor0) {
  s21::stack<int> stck;
  EXPECT_TRUE(stck.empty());
}

TEST_F(S21StackTest, Constructor1) {
  s21::stack<int> stck{1, 2, 3, 4};
  EXPECT_FALSE(stck.empty());
  EXPECT_EQ(stck.size(), 4);
}

TEST_F(S21StackTest, Constructor2) {
  s21::stack<double> stck{1, 2, 3, 4.4};
  EXPECT_FALSE(stck.empty());
  EXPECT_EQ(stck.size(), 4);
}

TEST_F(S21StackTest, Constructor3) {
  s21::stack<int> stck{1, 2, 3, 4};
  s21::stack<int> stck2(stck);
  EXPECT_FALSE(stck2.empty());
  EXPECT_EQ(stck2.size(), 4);
}

TEST_F(S21StackTest, Constructor4) {
  s21::stack<int> stck{1, 2, 3, 4};
  s21::stack<int> stck2(std::move(stck));
  EXPECT_FALSE(stck2.empty());
  EXPECT_EQ(stck2.size(), 4);
}

TEST_F(S21StackTest, top1) {
  s21::stack<int> stck{1, 2, 3, 4};
  EXPECT_EQ(stck.top(), 4);
}

TEST_F(S21StackTest, top2) {
  s21::stack<double> stck{1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(stck.top(), 3.3);
}

TEST_F(S21StackTest, top3) {
  s21::stack<std::string> stck{"1", "2"};
  EXPECT_EQ(stck.top(), "2");
}

TEST_F(S21StackTest, push1) {
  s21::stack<int> stck;
  stck.push(1);
  EXPECT_EQ(stck.top(), 1);
}

TEST_F(S21StackTest, push2) {
  s21::stack<int> stck{1};
  stck.push(2);
  EXPECT_EQ(stck.top(), 2);
}

TEST_F(S21StackTest, push3) {
  s21::stack<std::string> stck{"abc"};
  stck.push("qet");
  EXPECT_EQ(stck.top(), "qet");
}

TEST_F(S21StackTest, pop1) {
  s21::stack<int> stck;
  EXPECT_ANY_THROW(stck.pop());
}

TEST_F(S21StackTest, pop2) {
  s21::stack<int> stck{1, 2, 3, 4};
  stck.pop();
  EXPECT_EQ(stck.top(), 3);
}

TEST_F(S21StackTest, pop3) {
  s21::stack<std::string> stck{"abc"};
  stck.pop();
  EXPECT_TRUE(stck.empty());
}

TEST_F(S21StackTest, operator1) {
  s21::stack<int> stck1{1, 2, 3};
  s21::stack<int> stck2;
  stck2 = stck1;
  EXPECT_EQ(stck2.top(), 3);
  EXPECT_FALSE(stck1.empty());
}

TEST_F(S21StackTest, operator2) {
  s21::stack<int> stck1{1, 2, 3};
  s21::stack<int> stck2;
  stck2 = std::move(stck1);
  EXPECT_EQ(stck2.top(), 3);
  EXPECT_TRUE(stck1.empty());
}

TEST_F(S21StackTest, insert_many1) {
  s21::stack<int> stck{4, 5, 6};
  stck.insert_many_back(7, 8, 9);

  EXPECT_EQ(stck.size(), 6);
  EXPECT_EQ(stck.top(), 9);
}

TEST_F(S21StackTest, insert_many2) {
  s21::stack<int> stck;
  stck.insert_many_back(1, 2);

  EXPECT_EQ(stck.size(), 2);
  EXPECT_EQ(stck.top(), 2);
}

TEST_F(S21StackTest, insert_many3) {
  s21::stack<int> stck;
  stck.insert_many_back();
  EXPECT_EQ(stck.size(), 0);
}