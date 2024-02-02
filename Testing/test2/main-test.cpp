#include <iostream>
#include "test1.cpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("PushBack") {
    List a;
    a.PushBack(1);
    CHECK(a.PopBack() == 1);
}

TEST_CASE("PushFront") {
    List a;
    a.PushFront(3);
    CHECK(a.PopFront() == 3);
}

TEST_CASE("PopBack") {
    List a;
    REQUIRE_THROWS(a.PopBack());
}

TEST_CASE("PopFront") {
    List a;
    REQUIRE_THROWS(a.PopFront());
}

TEST_CASE("SomeMethods") {
    List a;
    a.PushBack(12);
    CHECK(a.PopBack() == 12);
    a.PushBack(3);
    CHECK(a.PopBack() == 3);
    a.PushFront(4);
    CHECK(a.PopFront() == 4);
    a.PushFront(0);
    CHECK(a.PopFront() == 0);
}
int main()
{
    return Catch::Session().run();
}