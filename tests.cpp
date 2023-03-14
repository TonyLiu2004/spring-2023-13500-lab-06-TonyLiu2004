#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Caesar Cipher Encrypt"){
    CHECK(encryptCaesar("Way to Go!",5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("HELLO WORLD!",9) == "QNUUX FXAUM!" );
    CHECK(encryptCaesar("",10) == "" );
}

TEST_CASE("Vigenere Cipher Encrypt"){
    CHECK(encryptVigenere("Hello, World!","CaKe") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("I like cookies!","cookie") == "K zwum gqcysmw!");
    CHECK(encryptVigenere("","") == "");
}

TEST_CASE("Decrypt Caesar test"){
    CHECK(decryptCaesar("Bfd yt Lt!",5) == "Way to Go!");
    CHECK(decryptCaesar("QNUUX FXAUM!",9) == "HELLO WORLD!");
    CHECK(decryptCaesar("QNUUX FXAUM!",0) == "QNUUX FXAUM!");
    CHECK(decryptCaesar("",10) == "");
}

TEST_CASE("Decrypt Vigenere test"){
    CHECK(decryptVigenere("Jevpq, Wyvnd!","CaKe") == "Hello, World!");
    CHECK(decryptVigenere("K zwum gqcysmw!","cookie") == "I like cookies!");
    CHECK(decryptVigenere("","banana") == "");
    CHECK(decryptVigenere("nothing there","") == "nothing there");
}

TEST_CASE("Decrypt using automatic Caesar Cipher"){
    CHECK(solve("There are two cakes!") == "There is a cake!");
    CHECK(solve("Way to go!") == "Way to go!");
    CHECK(solve("I love cookies!" == "I love cookies!"));
}