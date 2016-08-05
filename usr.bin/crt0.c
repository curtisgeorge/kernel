extern void _exit(int);
extern int main();

void _start() {
  _exit(main());
}
