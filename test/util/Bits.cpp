#include <gtest/gtest.h>

#include "util/Bits.h"
using util::pop_count;
using util::snoob;

TEST(BitsPopCount, Basics) {
  EXPECT_EQ(1u, pop_count(1u));
  EXPECT_EQ(1u, pop_count(2u));
  EXPECT_EQ(3u, pop_count(7u));

  // 32 bits
  EXPECT_EQ(1u, pop_count(0x80000000u));
  EXPECT_EQ(32u, pop_count(0xffffffffu));

  // 64 bits
  EXPECT_EQ(1ull, pop_count(0x8000000000000000ull));
  EXPECT_EQ(64ull, pop_count(0xffffffffffffffffull));
}

TEST(BitsSnoob, Basics) {
  EXPECT_EQ(2, snoob(1u, 10u));
  EXPECT_EQ(2, snoob(1u, 30u));
  EXPECT_EQ(0xau, snoob(0x9u, 10u));

  // TODO: Test 1 argument snoob
}

TEST(BitsSnoob, IncreaseBits32) {
  EXPECT_EQ(3, snoob(0x00000002u, 2u));
  EXPECT_EQ(3, snoob(0x00000004u, 3u));
  EXPECT_EQ(3, snoob(0x00000008u, 4u));
  EXPECT_EQ(3, snoob(0x00000010u, 5u));
  EXPECT_EQ(3, snoob(0x00000020u, 6u));
  EXPECT_EQ(3, snoob(0x00000040u, 7u));
  EXPECT_EQ(3, snoob(0x00000080u, 8u));
  EXPECT_EQ(3, snoob(0x00000100u, 9u));
  EXPECT_EQ(3, snoob(0x00000200u, 10u));
  EXPECT_EQ(3, snoob(0x00000400u, 11u));
  EXPECT_EQ(3, snoob(0x00000800u, 12u));
  EXPECT_EQ(3, snoob(0x00001000u, 13u));
  EXPECT_EQ(3, snoob(0x00002000u, 14u));
  EXPECT_EQ(3, snoob(0x00004000u, 15u));
  EXPECT_EQ(3, snoob(0x00008000u, 16u));
  EXPECT_EQ(3, snoob(0x00010000u, 17u));
  EXPECT_EQ(3, snoob(0x00020000u, 18u));
  EXPECT_EQ(3, snoob(0x00040000u, 19u));
  EXPECT_EQ(3, snoob(0x00080000u, 20u));
  EXPECT_EQ(3, snoob(0x00100000u, 21u));
  EXPECT_EQ(3, snoob(0x00200000u, 22u));
  EXPECT_EQ(3, snoob(0x00400000u, 23u));
  EXPECT_EQ(3, snoob(0x00800000u, 24u));
  EXPECT_EQ(3, snoob(0x01000000u, 25u));
  EXPECT_EQ(3, snoob(0x02000000u, 26u));
  EXPECT_EQ(3, snoob(0x04000000u, 27u));
  EXPECT_EQ(3, snoob(0x08000000u, 28u));
  EXPECT_EQ(3, snoob(0x10000000u, 29u));
  EXPECT_EQ(3, snoob(0x20000000u, 30u));
  EXPECT_EQ(3, snoob(0x40000000u, 31u));
  // Skip 32 since you bit shift out of MSB which is undefined
  // EXPECT_EQ(3, snoob(0x80000000u, 32u));
}

TEST(BitsSnoob, IncreaseBits64) {
  EXPECT_EQ(3, snoob(0x0000000000000001ull, 1ull));
  EXPECT_EQ(3, snoob(0x0000000000000002ull, 2ull));
  EXPECT_EQ(3, snoob(0x0000000000000004ull, 3ull));
  EXPECT_EQ(3, snoob(0x0000000000000008ull, 4ull));
  EXPECT_EQ(3, snoob(0x0000000000000010ull, 5ull));
  EXPECT_EQ(3, snoob(0x0000000000000020ull, 6ull));
  EXPECT_EQ(3, snoob(0x0000000000000040ull, 7ull));
  EXPECT_EQ(3, snoob(0x0000000000000080ull, 8ull));
  EXPECT_EQ(3, snoob(0x0000000000000100ull, 9ull));
  EXPECT_EQ(3, snoob(0x0000000000000200ull, 10ull));
  EXPECT_EQ(3, snoob(0x0000000000000400ull, 11ull));
  EXPECT_EQ(3, snoob(0x0000000000000800ull, 12ull));
  EXPECT_EQ(3, snoob(0x0000000000001000ull, 13ull));
  EXPECT_EQ(3, snoob(0x0000000000002000ull, 14ull));
  EXPECT_EQ(3, snoob(0x0000000000004000ull, 15ull));
  EXPECT_EQ(3, snoob(0x0000000000008000ull, 16ull));
  EXPECT_EQ(3, snoob(0x0000000000010000ull, 17ull));
  EXPECT_EQ(3, snoob(0x0000000000020000ull, 18ull));
  EXPECT_EQ(3, snoob(0x0000000000040000ull, 19ull));
  EXPECT_EQ(3, snoob(0x0000000000080000ull, 20ull));
  EXPECT_EQ(3, snoob(0x0000000000100000ull, 21ull));
  EXPECT_EQ(3, snoob(0x0000000000200000ull, 22ull));
  EXPECT_EQ(3, snoob(0x0000000000400000ull, 23ull));
  EXPECT_EQ(3, snoob(0x0000000000800000ull, 24ull));
  EXPECT_EQ(3, snoob(0x0000000001000000ull, 25ull));
  EXPECT_EQ(3, snoob(0x0000000002000000ull, 26ull));
  EXPECT_EQ(3, snoob(0x0000000004000000ull, 27ull));
  EXPECT_EQ(3, snoob(0x0000000008000000ull, 28ull));
  EXPECT_EQ(3, snoob(0x0000000010000000ull, 29ull));
  EXPECT_EQ(3, snoob(0x0000000020000000ull, 30ull));
  EXPECT_EQ(3, snoob(0x0000000040000000ull, 31ull));
  EXPECT_EQ(3, snoob(0x0000000080000000ull, 32ull));
  EXPECT_EQ(3, snoob(0x0000000100000000ull, 33ull));
  EXPECT_EQ(3, snoob(0x0000000200000000ull, 34ull));
  EXPECT_EQ(3, snoob(0x0000000400000000ull, 35ull));
  EXPECT_EQ(3, snoob(0x0000000800000000ull, 36ull));
  EXPECT_EQ(3, snoob(0x0000001000000000ull, 37ull));
  EXPECT_EQ(3, snoob(0x0000002000000000ull, 38ull));
  EXPECT_EQ(3, snoob(0x0000004000000000ull, 39ull));
  EXPECT_EQ(3, snoob(0x0000008000000000ull, 40ull));
  EXPECT_EQ(3, snoob(0x0000010000000000ull, 41ull));
  EXPECT_EQ(3, snoob(0x0000020000000000ull, 42ull));
  EXPECT_EQ(3, snoob(0x0000040000000000ull, 43ull));
  EXPECT_EQ(3, snoob(0x0000080000000000ull, 44ull));
  EXPECT_EQ(3, snoob(0x0000100000000000ull, 45ull));
  EXPECT_EQ(3, snoob(0x0000200000000000ull, 46ull));
  EXPECT_EQ(3, snoob(0x0000400000000000ull, 47ull));
  EXPECT_EQ(3, snoob(0x0000800000000000ull, 48ull));
  EXPECT_EQ(3, snoob(0x0001000000000000ull, 49ull));
  EXPECT_EQ(3, snoob(0x0002000000000000ull, 50ull));
  EXPECT_EQ(3, snoob(0x0004000000000000ull, 51ull));
  EXPECT_EQ(3, snoob(0x0008000000000000ull, 52ull));
  EXPECT_EQ(3, snoob(0x0010000000000000ull, 53ull));
  EXPECT_EQ(3, snoob(0x0020000000000000ull, 54ull));
  EXPECT_EQ(3, snoob(0x0040000000000000ull, 55ull));
  EXPECT_EQ(3, snoob(0x0080000000000000ull, 56ull));
  EXPECT_EQ(3, snoob(0x0100000000000000ull, 57ull));
  EXPECT_EQ(3, snoob(0x0200000000000000ull, 58ull));
  EXPECT_EQ(3, snoob(0x0400000000000000ull, 59ull));
  EXPECT_EQ(3, snoob(0x0800000000000000ull, 60ull));
  EXPECT_EQ(3, snoob(0x1000000000000000ull, 61ull));
  EXPECT_EQ(3, snoob(0x2000000000000000ull, 62ull));
  EXPECT_EQ(3, snoob(0x4000000000000000ull, 63ull));
  // Skip 64 since you bit shift out of MSB which is undefined
  // EXPECT_EQ(3, snoob(0x8000000000000000ull, 64ull));
}
