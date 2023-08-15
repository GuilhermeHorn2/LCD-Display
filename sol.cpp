#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

void display(int s, int n);
void set_number(int n, std::string &number);
void set_screen(int s, std::vector<std::vector<char>> &screen, int len);
void draw_in_y(int strt, int end, int y, std::vector<std::vector<char>> &screen);
void draw_in_x(int strt, int end, int x, std::vector<std::vector<char>> &screen);
void draw_0(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_1(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_2(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_3(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_4(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_5(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_6(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_7(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_8(int strt, int s, std::vector<std::vector<char>> &screen);
void draw_9(int strt, int s, std::vector<std::vector<char>> &screen);

int main()
{

 /*std::vector<std::vector<char>> v;
 int s = 3;
 set_screen(s, v, 2);
 draw_1(0, s, v);
 draw_0(s + 2 + 1, s, v);
 for (int i = 0; i < v.size(); i++)
 {

  for (int j = 0; j < v[i].size(); j++)
  {
   std::cout << v[i][j];
  }
  std::cout << '\n';
 }*/
 int s = 3;
 int n = 67890;
 display(s, n);
 return 0;
}

void set_screen(int s, std::vector<std::vector<char>> &screen, int len)
{

 for (int i = 0; i < 2 * s + 3; i++)
 {
  std::vector<char> tmp;
  screen.push_back(tmp);
  for (int j = 0; j < (s + 2 + 1) * len; j++)
  {
   screen[i].push_back(' ');
  }
 }
}

void set_number(int n, std::string &numbers)
{

 // n = 1234 --> s[0] = '1',s[1] = '2' ... s[3] = '4'

 while (n >= 10)
 {
  char num = (n % 10) + '0';
  numbers.push_back(num);
  n /= 10;
 }
 numbers.push_back(n + '0');
 reverse(numbers.begin(), numbers.end());
}

void draw_in_y(int strt, int end, int y, std::vector<std::vector<char>> &screen)
{
 for (int i = strt; i <= end; i++)
 {
  screen[i].at(y) = '|';
 }
}

void draw_in_x(int strt, int end, int x, std::vector<std::vector<char>> &screen)
{
 for (int i = strt; i <= end; i++)
 {
  screen[x].at(i) = '-';
 }
}

void draw_1(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int y = strt + s + 1;
 draw_in_y(1, s, y, screen);
 draw_in_y(s + 2, 2 * s + 1, y, screen);
}

void draw_0(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int y = strt;
 draw_in_y(1, s, y, screen);
 draw_in_y(s + 2, 2 * s + 1, y, screen);
 draw_1(strt, s, screen);
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, screen.size() - 1, screen);
}

void draw_2(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);

 draw_in_y(1, s, strt + s + 1, screen);
 draw_in_y(s + 2, 2 * s + 1, strt, screen);
}

void draw_3(int strt, int s, std::vector<std::vector<char>> &screen)
{
 draw_1(strt, s, screen);
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);
}

void draw_4(int strt, int s, std::vector<std::vector<char>> &screen)
{
 draw_1(strt, s, screen);
 draw_in_y(1, s, strt, screen);
 draw_in_x(strt + 1, strt + s, screen.size() / 2, screen);
}

void draw_5(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);
 draw_in_y(1, s, strt, screen);
 draw_in_y(s + 2, 2 * s + 1, strt + s + 1, screen);
}

void draw_6(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);
 draw_in_y(1, s, strt, screen);
 draw_in_y(s + 2, 2 * s + 1, strt + s + 1, screen);
 draw_in_y(s + 2, 2 * s + 1, strt, screen);
}

void draw_7(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_1(strt, s, screen);
}

void draw_8(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int y = strt;
 draw_in_y(1, s, y, screen);
 draw_in_y(s + 2, 2 * s + 1, y, screen);
 draw_1(strt, s, screen);
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);
}

void draw_9(int strt, int s, std::vector<std::vector<char>> &screen)
{
 int y = strt;
 draw_in_y(1, s, y, screen);
 draw_1(strt, s, screen);
 int n = screen.size();
 draw_in_x(strt + 1, strt + s, 0, screen);
 draw_in_x(strt + 1, strt + s, n / 2, screen);
 draw_in_x(strt + 1, strt + s, n - 1, screen);
}

void display(int s, int n)
{
 std::vector<std::vector<char>> screen;
 std::string numbers;
 set_number(n, numbers);
 // std::cout << numbers << '\n';
 set_screen(s, screen, numbers.length());

 int j = 0;
 for (int i = 0; i < screen[0].size() && j < numbers.length(); i += s + 2 + 1)
 {
  int num = numbers[j] - '0';
  // std::cout << num << '\n';
  if (num == 0)
  {
   draw_0(i, s, screen);
  }
  if (num == 1)
  {
   draw_1(i, s, screen);
  }
  if (num == 2)
  {
   draw_2(i, s, screen);
  }
  if (num == 3)
  {
   draw_3(i, s, screen);
  }
  if (num == 4)
  {
   draw_4(i, s, screen);
  }
  if (num == 5)
  {
   draw_5(i, s, screen);
  }
  if (num == 6)
  {
   draw_6(i, s, screen);
  }
  if (num == 7)
  {
   draw_7(i, s, screen);
  }
  if (num == 8)
  {
   draw_8(i, s, screen);
  }
  if (num == 9)
  {
   draw_9(i, s, screen);
  }
  j++;
 }

 for (int i = 0; i < screen.size(); i++)
 {
  for (int j = 0; j < screen[0].size(); j++)
  {
   std::cout << screen[i][j];
  }
  std::cout << '\n';
 }
}
