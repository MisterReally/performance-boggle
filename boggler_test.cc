#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#include "trie.h"
#include "boggler.h"

void CheckInt(int expected, int actual) {
  if (expected == actual) return;
  fprintf(stderr, "Expected %d, got %d\n", expected, actual);
  assert(false);
}

int main(int argc, char** argv) {
  Trie t;
  t.AddWord("tea");
  t.AddWord("eta");
  t.AddWord("ate");
  t.AddWord("eat");
  t.AddWord("teak");
  t.AddWord("fiver");
  t.AddWord("sixers");

  assert(7 == t.Size());

  // try out the various interfaces
  Boggler b(&t);
  CheckInt(0, b.NumBoards());
  CheckInt(4, b.Score("texxaxxxyyyyzzzz"));
  CheckInt(5, b.Score("texxakxxyyyyzzzz"));
  CheckInt(2, b.NumBoards());

  b.SetCell(0, 0, 'f' - 'a');
  b.SetCell(1, 0, 'i' - 'a');
  b.SetCell(2, 0, 'v' - 'a');
  b.SetCell(3, 0, 'e' - 'a');
  b.SetCell(3, 1, 'r' - 'a');
  CheckInt(2, b.Score());
  CheckInt(3, b.Score("sxxxixxxexxxrsxx"));
  CheckInt(4, b.NumBoards());

  printf("%s: All tests passed!\n", argv[0]);
}