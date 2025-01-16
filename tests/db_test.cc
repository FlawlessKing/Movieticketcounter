#include <gtest/gtest.h>
#include "../src/db.h"

class DBTest : public ::testing::Test {
protected:
    void SetUp() override {
        db.setDbName("kiosk_test");
        db.setHost("localhost");
        db.setPort("5432");
        db.setUsername("postgres");
        db.setPassword("postgres");
    }

    DB db;
};

TEST_F(DBTest, ConnectionTest) {
    EXPECT_NO_THROW(db.connect());
    EXPECT_TRUE(db.isConnected());
    db.disconnect();
    EXPECT_FALSE(db.isConnected());
}

TEST_F(DBTest, QueryTest) {
    db.connect();
    EXPECT_NO_THROW(db.query("SELECT 1"));
    db.disconnect();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 