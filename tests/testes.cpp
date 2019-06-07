#include "doctest.h"

#include "user.h"
#include "administrator.h"
#include "cart.h"
#include "client.h"
#include "clothes.h"
#include "menu.h"
#include "product.h"
#include "shoes.h"
#include "sunglasses.h"
#include "user.h"


TEST_CASE("Test Admin Creation") {
    CHECK_NOTHROW(User("John Snow", "jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@  jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow__", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow123", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test User Creation") {
    CHECK_NOTHROW(User("John Snow", "jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@  jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow__", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow123", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(User("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test User Creation") {
    CHECK_NOTHROW(Client("John Snow", "jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@  jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow__", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow123", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@asdasjsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@jsn", "8888!!!@@##$%*"));
    CHECK_NOTHROW(Client("John Snow", "@jsn", "8888!!!@@##$%*"));
}

TEST_CASE("Test User Creation") {
    CHECK_NOTHROW(Clothes("tipo", "marca", "cor", "tamanho", 2.0, 1));

}
