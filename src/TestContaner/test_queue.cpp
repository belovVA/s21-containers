#include "test.h"

class S21QueueTest : public ::testing::Test {
 protected:
  void SetUp() override { srand(static_cast<unsigned>(time(0))); }
};

TEST_F(S21QueueTest, Constructor0) {
  s21::queue<int> que;
  EXPECT_TRUE(que.empty());
}

TEST_F(S21QueueTest, Constructor1) {
  s21::queue<int> que{1, 2, 3, 4};
  EXPECT_FALSE(que.empty());
  EXPECT_EQ(que.size(), 4);
}

TEST_F(S21QueueTest, Constructor2) {
  s21::queue<double> que{1, 2, 3, 4.4};
  EXPECT_FALSE(que.empty());
  EXPECT_EQ(que.size(), 4);
}

TEST_F(S21QueueTest, Constructor3) {
  s21::queue<int> que{1, 2, 3, 4};
  s21::queue<int> que2(que);
  EXPECT_FALSE(que2.empty());
  EXPECT_EQ(que2.size(), 4);
}

TEST_F(S21QueueTest, Constructor4) {
  s21::queue<int> que{1, 2, 3, 4};
  s21::queue<int> que2(std::move(que));
  EXPECT_FALSE(que2.empty());
  EXPECT_EQ(que2.size(), 4);
}

TEST_F(S21QueueTest, front1) {
  s21::queue<int> que{1, 2, 3, 4};
  std::queue<int> que2;
  que2.push(1);
  que2.push(2);
  que2.push(3);
  que2.push(4);
  EXPECT_EQ(que.front(), que2.front());
}

TEST_F(S21QueueTest, front2) {
  s21::queue<double> que{1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(que.front(), 1.1);
}

TEST_F(S21QueueTest, front3) {
  s21::queue<std::string> que{"1", "2"};
  EXPECT_EQ(que.front(), "1");
}

TEST_F(S21QueueTest, back1) {
  s21::queue<int> que{1, 2, 3, 4};
  EXPECT_EQ(que.back(), 4);
}

TEST_F(S21QueueTest, back2) {
  s21::queue<double> que{1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(que.back(), 3.3);
}

TEST_F(S21QueueTest, back3) {
  s21::queue<std::string> que{"1", "2"};
  EXPECT_EQ(que.back(), "2");
}

TEST_F(S21QueueTest, push1) {
  s21::queue<int> que;
  que.push(1);
  EXPECT_EQ(que.front(), 1);
}

TEST_F(S21QueueTest, push2) {
  s21::queue<int> que{1};
  que.push(2);
  EXPECT_EQ(que.front(), 1);
  EXPECT_EQ(que.back(), 2);
}

TEST_F(S21QueueTest, push3) {
  s21::queue<std::string> que{"abc"};
  que.push("qet");
  EXPECT_EQ(que.front(), "abc");
  EXPECT_EQ(que.back(), "qet");
}

TEST_F(S21QueueTest, pop1) {
  s21::queue<int> que;
  EXPECT_ANY_THROW(que.pop());
}

TEST_F(S21QueueTest, pop2) {
  s21::queue<int> que{1, 2, 3, 4};
  que.pop();
  EXPECT_EQ(que.front(), 2);
}

TEST_F(S21QueueTest, pop3) {
  s21::queue<std::string> que{"abc"};
  que.pop();
  EXPECT_TRUE(que.empty());
}

TEST_F(S21QueueTest, operator1) {
  s21::queue<int> que1{1, 2, 3};
  s21::queue<int> que2;
  que2 = que1;
  EXPECT_EQ(que2.front(), 1);
  EXPECT_EQ(que2.back(), 3);
  EXPECT_FALSE(que1.empty());
}

TEST_F(S21QueueTest, operator2) {
  s21::queue<int> que1{1, 2, 3};
  s21::queue<int> que2;
  que2 = std::move(que1);
  EXPECT_EQ(que2.front(), 1);
  EXPECT_EQ(que2.back(), 3);
  EXPECT_TRUE(que1.empty());
}

TEST_F(S21QueueTest, insert_many1) {
  s21::queue<int> int_q = {4, 5, 6};
  int_q.insert_many_back(7, 8, 9);

  EXPECT_EQ(int_q.size(), 6);
  EXPECT_EQ(int_q.back(), 9);
}

TEST_F(S21QueueTest, insert_many2) {
  s21::queue<int> int_q;
  int_q.insert_many_back(1, 2);

  EXPECT_EQ(int_q.size(), 2);
  EXPECT_EQ(int_q.back(), 2);
}

TEST_F(S21QueueTest, insert_many3) {
  s21::queue<int> int_q;
  int_q.insert_many_back();

  EXPECT_EQ(int_q.size(), 0);
}