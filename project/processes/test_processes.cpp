#include <cstring>

#include "gtest/gtest.h"

extern "C" {
    #include "DynArray.h"
    #include "processes.h"
}

TEST(processes_small, find_indices) {

    char filename[MAX_CHARS] = "../test_files/small.txt";
    size_t seqs_amount = 2;
    char **sequences = (char **)calloc(seqs_amount, sizeof(char*));
    for ( size_t iii = 0; iii < seqs_amount; iii++ ) {
        sequences[iii] = (char *) calloc(MAX_CHARS, sizeof(char));
    }
    strncpy(sequences[0], "wi", MAX_CHARS);
    strncpy(sequences[1], "o", MAX_CHARS);

    int answer = find_indices(filename, seqs_amount, sequences);

    EXPECT_EQ(answer, 4) << " Wrong answer";
}

/*
TEST(processes_medium, find_indices) {

    char filename[MAX_CHARS] = "../test_files/medium.txt";
    size_t seqs_amount = 2;
    char **sequences = (char **)calloc(seqs_amount, sizeof(char*));
    for ( size_t iii = 0; iii < seqs_amount; iii++ ) {
        sequences[iii] = (char *) calloc(MAX_CHARS, sizeof(char));
    }
    strncpy(sequences[0], "wi", MAX_CHARS);
    strncpy(sequences[1], "o", MAX_CHARS);

    int answer = find_indices(filename, seqs_amount, sequences);

    EXPECT_EQ(answer, 41633) << " Wrong answer";
}
*/

/// Had to comment out due to GitHub restrictions
//TEST(processes_big, find_indices) {
//
//    char filename[MAX_CHARS] = "../test_files/big.txt";
//    size_t seqs_amount = 2;
//    char **sequences = (char **)calloc(seqs_amount, sizeof(char*));
//    for ( size_t iii = 0; iii < seqs_amount; iii++ ) {
//        sequences[iii] = (char *) calloc(MAX_CHARS, sizeof(char));
//    }
//    strncpy(sequences[0], "wi", MAX_CHARS);
//    strncpy(sequences[1], "o", MAX_CHARS);
//
//    int answer = find_indices(filename, seqs_amount, sequences);
//
//    EXPECT_EQ(answer, 4191001) << " Wrong answer";
//}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
