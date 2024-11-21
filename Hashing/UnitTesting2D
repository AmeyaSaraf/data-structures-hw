include "pch.h"
#include "../HW3Data/HashTable2D.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTable2DUnitTest
{
    TEST_CLASS(HashTable2DUnitTest)
    {
    public:

        // Test insertion into the hash table
        TEST_METHOD(TestInsertSuccess)
        {
            HashTable2D table;

            // Insert values and validate slots checked
            Assert::AreEqual(1, table.insert(5));   // Should insert into the first slot
            Assert::AreEqual(1, table.insert(105)); // Should insert into the second slot in the same row
            Assert::AreEqual(1, table.insert(205)); // Should insert into the third slot
            Assert::AreEqual(1, table.insert(305)); // Should insert into the fourth slot
            Assert::AreEqual(1, table.insert(405)); // Should insert into the last slot in the row

            // Attempt to insert into a full row
            Assert::AreEqual(0, table.insert(505)); // Should fail as the row is full
        }

        // Test searching for values in the hash table
        TEST_METHOD(TestSearchSuccess)
        {
            HashTable2D table;

            // Insert values to search
            table.insert(15);
            table.insert(115);
            table.insert(215);

            // Search for existing values
            Assert::AreEqual(1, table.search(15));   // Found in the first slot
            Assert::AreEqual(2, table.search(115));  // Found in the second slot
            Assert::AreEqual(3, table.search(215));  // Found in the third slot

            // Search for a non-existing value
            Assert::AreEqual(0, table.search(315));  // Not found
        }

        // Test removing values from the hash table
        TEST_METHOD(TestRemoveSuccess)
        {
            HashTable2D table;

            // Insert values to remove
            table.insert(20);
            table.insert(120);
            table.insert(220);

            // Remove existing values
            Assert::AreEqual(1, table.remove(20));  // Should successfully remove the first value
            Assert::AreEqual(1, table.remove(120)); // Should successfully remove the second value
            Assert::AreEqual(1, table.remove(220)); // Should successfully remove the third value

            // Attempt to remove a value that does not exist
            Assert::AreEqual(0, table.remove(320)); // Not found
        }

        // Test handling a full row
        TEST_METHOD(TestRowFullCondition)
        {
            HashTable2D table;

            // Fill a single row
            for (int i = 0; i < 5; ++i) {
                Assert::AreEqual(1, table.insert(i * 100)); // Insert into the same row
            }

            // Attempt to insert when the row is full
            Assert::AreEqual(0, table.insert(500)); // Row should be full, insertion should fail
        }

        // Test print functionality
        TEST_METHOD(TestPrintFunctionality)
        {
            HashTable2D table;

            // Insert values and validate output
            table.insert(7);
            table.insert(107);

            // Print should output valid slots, but here we just ensure no crash occurs
            table.print(); // Manually inspect the output in the console
        }
    };
}
