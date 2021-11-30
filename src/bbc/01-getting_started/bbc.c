#include <stdio.h>

typedef unsigned long long U64;
typedef U64                Bitboard;

// board squares
enum
{
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1,
};

// Bit Manipulation Macros
#define full_bitboard                        (0xFFFFFFFFFFFFFFFFULL)                                                   /* 64 bits set to 1 */
#define empty_bitboard                       (0x0000000000000000ULL)                                                   /* 64 bits set to 0 */
#define set_bit(bitboard, square)            (bitboard |= (1ULL << square))
#define rem_bit(bitboard, square)            (bitboard &= (1ULL << square) ^ full_bitboard)
#define is_square_occupied(bitboard, square) (bitboard &  (1ULL << square))
#define pop_bit(bitboard, square)            (is_square_occupied(bitboard, square) ? bitboard ^= (1ULL << square) : 0)

void
print_bitboard(U64 bitboard)
{
  printf("Bitboard: %016llx\n\n", bitboard);

  for   (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (!file) printf("  %d ", 8 - rank);
      printf(" %c", is_square_occupied(bitboard, square) ? 'X' : '_');
    }
    putchar('\n');
  }
  printf("\n     a b c d e f g h\n\n");
}

int
main()
{
  Bitboard bitboard = empty_bitboard;
  printf("Size of U64/Bitboard: %zd\n\n", sizeof bitboard);
  print_bitboard(bitboard);
  set_bit(bitboard, e4); set_bit(bitboard, c3); set_bit(bitboard, f2);   print_bitboard(bitboard);
  rem_bit(bitboard, f2);                                                 print_bitboard(bitboard);
  pop_bit(bitboard, e4);                                                 print_bitboard(bitboard);
  pop_bit(bitboard, f4);                                                 print_bitboard(bitboard);
}
