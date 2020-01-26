#include <libc.h>
void test(void)
{
    char *tmp  = malloc(4);
  //  tmp[0] = 'a';
    tmp[1] = 'b';
    tmp[2] = 'c';
    tmp[3] = 0;
   write(1, tmp, 3);
   fflush(stdout);
   // exit(0);
}
int main()
{
    test();
    return (0);
}
__attribute__((destructor)) void end(void)
{
    write(1, "Bye !\n", 6);
    while (1);
}
