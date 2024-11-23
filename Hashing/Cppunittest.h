#ifndef CPP_UNIT_TEST_H
#define CPP_UNIT_TEST_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <functional>

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {

// Assertion class for test validation
class Assert {
public:
    static void AreEqual(int expected, int actual, const std::string& message = "") {
        if (expected != actual) {
            std::cerr << "AreEqual failed: Expected " << expected << ", Actual " << actual << ". " << message << std::endl;
            throw std::runtime_error("Assertion failed");
        }
    }

    static void IsTrue(bool condition, const std::string& message = "") {
        if (!condition) {
            std::cerr << "IsTrue failed. " << message << std::endl;
            throw std::runtime_error("Assertion failed");
        }
    }

    static void Fail(const std::string& message = "") {
        std::cerr << "Test failed. " << message << std::endl;
        throw std::runtime_error("Test failed");
    }
};

#define TEST_CLASS(className) class className


#define TEST_METHOD(methodName) void methodName()

} // namespace CppUnitTestFramework
} // namespace VisualStudio
} // namespace Microsoft

#endif // CPP_UNIT_TEST_H
