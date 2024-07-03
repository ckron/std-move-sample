#include <stdio.h>
#include <memory>
#include <string>

int main(int argc, char* argv[])
{
  std::unique_ptr<int> ten(new int(10));
  printf(" ten: %d, address: %p\n", *ten, &ten);
  std::unique_ptr<int> another_ten(std::move(ten));
  // *ten = 100; // segmentation fault
  // printf(" ten: %d, address: %p\n", *ten, &ten); // segmentation fault
  printf("aten: %d, address: %p\n", *another_ten, &another_ten);

  std::shared_ptr<std::string> hoge(new std::string("hoge"));
  printf("hoge: %s, address: %p\n", hoge->c_str(), &hoge);
  std::shared_ptr<std::string> fuga(std::move(hoge));
  // std::unique_ptr<std::string> fuga(std::move(hoge)); // compile error
  // printf("hoge: %s, address: %p\n", hoge->c_str(), &hoge); // segmentation fault
  printf("fuga: %s, address: %p\n", fuga->c_str(), &fuga);

  char a = 'a';
  printf("a: %c, address: %p\n", a, &a);
  char b(std::move(a));
  a = 'b';
  printf("a: %c, address: %p\n", a, &a); // alive a
  printf("b: %c, address: %p\n", b, &b);

  bool* t = new bool(true);
  printf("t: %s, address: %p\n", (*t ? "true" : "false"), t);
  bool* f(std::move(t));
  *t = false;
  printf("t: %s, address: %p\n", (*t ? "true" : "false"), t);
  printf("f: %s, address: %p\n", (*f ? "true" : "false"), f);
  
  printf("hello move world!!\n");
  return 0;
}
