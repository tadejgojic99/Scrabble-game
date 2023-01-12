#define CATCH_CONFIG_MAIN
# include "catch.hpp"
# include "constants.h"

//TESTOVI ZA KLASU CONSTANTS

TEST_CASE("Constants", "[class]") {

    SECTION("Constructor of Player successfully constructs a Player") {
        REQUIRE_NOTHROW(Constants());

    }
}

//TESTOVI ZA KLASU PREFIXTREE

#define CATCH_CONFIG_MAIN
# include "catch.hpp"
# include "prefixtree.h"

TEST_CASE("PrefixTree", "[class]") {

    SECTION("Constructor PrefixTree successfully construct a random objects") {

        // Act + Assert
        REQUIRE_NOTHROW(PrefixTree());

    }
}

TEST_CASE("noSuccessor", "[function]") {
    SECTION("When word is empty, return false") {
        //Arange
        bool expectedReturnValue = false;
        PrefixTree* pt = new PrefixTree();
        // Act
        bool output = pt->noSuccessor(" ");
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
    SECTION("When word isn't empty, return true") {
        //Arange
        bool expectedReturnValue = true;
        PrefixTree* pt = new PrefixTree();
        // Act
        bool output = pt->noSuccessor("hello");
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
}
TEST_CASE("find", "[function]") {
    SECTION("When word is empty, return false") {
        //Arange
        auto expectedReturnValue = 1;
        PrefixTree* pt = new PrefixTree();
        // Act
        auto output = pt->find("all");
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);

    }
 }

 //TESTOVI ZA KLASU BOARD
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "board.h"

TEST_CASE("isNear", "[function]") {
    SECTION("When first argument of function is 0, return false") {
        // Arange
        bool expectedReturnValue = false;
        // Act
        Board* board = new Board();
        bool output = board->isNear(0, 3);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);
    }
    SECTION("When second argument of function is 0, return false") {
        // Arange
        bool expectedReturnValue = false;
        // Act
        Board* board = new Board();
        bool output = board->isNear(2, 0);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);
    }
}
TEST_CASE("firstLeft", "[function]") {
    SECTION("When arguments are in good range, returns the distance to the first free box to the left of the x_y box") {
        //Arange
        auto expectedReturnValue = 0;
        // Act
        Board* board = new Board();
        auto output = board->firstLeft(1,1);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);

    }
}
TEST_CASE("firstUp", "[function]") {
    SECTION("When arguments are in good range, returns the distance to the first free box to the up of the x_y box") {
        //Arange
        auto expectedReturnValue = 0;
        // Act
        Board* board = new Board();
        auto output = board->firstLeft(1,1);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);

    }
}
TEST_CASE("firstRight", "[function]") {
    SECTION("When arguments are in good range, returns the distance to the first free box to the right of the x_y box") {
        //Arange
        auto expectedReturnValue = 1;
        // Act
        Board* board = new Board();
        auto output = board->firstRight(14,14);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);

    }
}
TEST_CASE("firstDown", "[function]") {
    SECTION("When arguments are in good range, returns the distance to the first free box to the down of the x_y box") {
        //Arange
        auto expectedReturnValue = 1;
        // Act
        Board* board = new Board();
        auto output = board->firstDown(14,14);
        // Assert
        REQUIRE_FALSE(output == expectedReturnValue);

    }
}
TEST_CASE("calculateScore", "[function]") {
    SECTION("When board is created, we calculate the result based on the letters from the previous round") {
        //Arange
        auto expectedReturnValue = 0;
        // Act
        Board* board = new Board();
        auto output = board->calculateScore();
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
}

TEST_CASE("Board", "[class]") {

    SECTION("Constructor Board successfully construct a random objects") {

        // Act + Assert
        REQUIRE_NOTHROW(Board());

    }
}


#define CATCH_CONFIG_MAIN
# include "catch.hpp"
# include "player.h"

//TEST ZA KLASU PLAYER
TEST_CASE("Player", "[class]") {

    SECTION("Constructor of Player successfully constructs a Player") {
        REQUIRE_NOTHROW(Player());

    }
}

//TESTOVI ZA KLASU DECK

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "deck.h"

TEST_CASE("getTopCard()","[function]"){
    SECTION("Function returns a top card"){
        // Arrange
        Deck* deck = new Deck();
        std::string s = "ABCDEF";
        deck->setDeck(s);
        std::string e = "A";
        const char expected = e[0];
        // Act
        const char aqured = deck->getTopCard(); // if strings are equal X should return 0
        // Assert
        REQUIRE ( expected == aqured );
    }
    SECTION("Function returns the only card in 1 card deck"){
            Deck* deck = new Deck();
            std::string s = "A";
            deck->setDeck(s);
            std::string e = "A";
            const char expected = e[0];
            const char aqured = deck->getTopCard();
            REQUIRE ( expected == aqured );
    }
    SECTION("Function returns 2 cards from 2 element deck"){
        // Arrange
        Deck* deck = new Deck();
        std::string s = "AB";
        deck->setDeck(s);
        std::string e1 = "A";
        const char expected1 = e1[0];
        std::string e2 = "B";
        const char expected2 = e2[0];
        // Act
        const char aqured1 = deck->getTopCard(); //A
        const char aqured2 = deck->getTopCard(); //B
        int X;
        int Y;
        if(expected1 == aqured1){
            X=0;
        }
        if(expected2 == aqured2){
            Y=0;
        }
        // Assert
        REQUIRE ( X+Y == 0 );
    }
    SECTION("Function returns 3 cards from 5 element deck"){
        // Arrange
        Deck* deck = new Deck();
        std::string s = "ABCDE";
        deck->setDeck(s);
        std::string e1 = "A";
        const char expected1 = e1[0];
        std::string e2 = "B";
        const char expected2 = e2[0];
        std::string e3 = "C";
        const char expected3 = e3[0];
        // Act
        const char aqured1 = deck->getTopCard(); //A
        const char aqured2 = deck->getTopCard(); //B
        const char aqured3 = deck->getTopCard(); //C
        int X,Y,Z;
        if(expected1 == aqured1){
            X=0;
        }
        if(expected2 == aqured2){
            Y=0;
        }
        if(expected3 == aqured3){
            Z=0;
        }
        // Assert
        REQUIRE ( X+Y+Z == 0 );
    }
}

TEST_CASE("isEmpty", "[function]") {
    SECTION("When deck isn't empty return false") {
        //Arange
        bool expectedReturnValue = false;
        // Act
        Deck* deck = new Deck();
        bool output = deck->isEmpty();
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
    SECTION("When deck is empty return true") {
        //Arange
        bool expectedReturnValue = true;
        // Act
        Deck* deck = new Deck();
        deck->setEmpty(true);
        bool output = deck->isEmpty();
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
}

TEST_CASE("Deck", "[class]")
{
    SECTION("Constructor Deck successfully constructs a deck of letters") {

            // Act + Assert
            REQUIRE_NOTHROW(Deck());
    }
}
TEST_CASE("shuffleDeck()","[function]"){
    SECTION("Function shuffles the deck"){
        Deck* deck = new Deck();
        std::string expected = "ABCDEFG";
        std::string s = "ABCDEFG";
        deck->setDeck(s);
        deck->shuffleDeck();
        std::string S = deck->getDeck();
        int x = expected.compare(S);
        REQUIRE_FALSE ( x == 0 );
    }
    SECTION("Unchanged deck after shuffle if it contains same letters"){
        Deck* deck = new Deck();
        std::string expected = "AAAAA";
        std::string s = "AAAAA";
        deck->setDeck(s);
        deck->shuffleDeck();
        std::string S = deck->getDeck();
        int x = expected.compare(S);
        REQUIRE ( x == 0 );
    }
    SECTION("One element deck unchanged after shuffle"){
        // Arrange
        Deck* deck = new Deck();
        std::string s = "A";
        deck->setDeck(s);
        //std::string expected = "A";
        char expected = 'A';
        // Act
        deck->shuffleDeck();
        std::string S = deck->getDeck();
        char S1 = S[0];
        // Assert
        REQUIRE ( expected == S1 );
    }
    SECTION("Different top letter after shuffle"){
        Deck* deck = new Deck();
        //std::string expected = "A";
        char expected = 'A';
        std::string s = "ABCDEFG";
        deck->setDeck(s);
        deck->shuffleDeck();
        std::string S = deck->getDeck();
        const char S1 = S[0];

        REQUIRE_FALSE ( expected == S1 );
    }
    SECTION("Same top letter after shuffle in deck containing the same letter"){
        Deck* deck = new Deck();
        //std::string expected = "A";
        char expected = 'A';
        std::string s = "AAAAA";
        deck->setDeck(s);
        deck->shuffleDeck();
        std::string S = deck->getDeck();
        const char S1 = S[0];

        REQUIRE ( expected == S1 );
    }
}


//TESTOVI ZA KLASU DICTIONARY
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dictionary.h"
#include "prefixtree.h"


TEST_CASE("Dictionary", "[class]") {

    SECTION("Constructor PrefixTree successfully construct a random objects") {

        // Act + Assert
        REQUIRE_NOTHROW(Dictionary("../../resources/dictionary/dictionary.txt"));

    }
}

TEST_CASE("containsWord", "[function]") {
    SECTION("When dictionary contains word, return true") {
        //Arange
        bool expectedReturnValue = true;
        // Act
        Dictionary dict = Dictionary("../../resources/dictionary/dictionary.txt");
        bool output = dict.containsWord("hello");
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
     SECTION("When dictionary doesn't contain word, return false") {
        //Arange
        bool expectedReturnValue = false;
        // Act
        Dictionary dict = Dictionary("../../resources/dictionary/dictionary.txt");
        bool output = dict.containsWord("hwk");
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
    SECTION("When we have empty string, return false") {
        //Arange
        bool expectedReturnValue = true;
        // Act
        Dictionary dict = Dictionary("../../resources/dictionary/dictionary.txt");
        bool output = dict.containsWord(" ");
        // Assert
        REQUIRE(output == expectedReturnValue);

    }
}
