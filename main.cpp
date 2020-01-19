#include "demukron.h"
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iterator>

#define BOOST_TEST_MODULE test_main

#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_SUITE(test_suite_main)

/*graph for test purposes was taken from lecture*/

BOOST_AUTO_TEST_CASE(Demukron_sort_and_Tarian_sort_test)
{
    std::vector<std::vector<int>> testGraph(14);
    testGraph[0].push_back(2);
    testGraph[0].push_back(12);
    testGraph[1].push_back(12);
    testGraph[3].push_back(2);
    testGraph[4].push_back(8);
    testGraph[4].push_back(2);
    testGraph[4].push_back(9);
    testGraph[5].push_back(3);
    testGraph[5].push_back(12);
    testGraph[5].push_back(11);
    testGraph[5].push_back(10);
    testGraph[6].push_back(5);
    testGraph[7].push_back(3);
    testGraph[7].push_back(5);
    testGraph[7].push_back(13);
    testGraph[7].push_back(1);
    testGraph[8].push_back(0);
    testGraph[8].push_back(6);
    testGraph[9].push_back(11);
    testGraph[9].push_back(13);
    testGraph[9].push_back(0);
    testGraph[10].push_back(2);
    testGraph[12].push_back(2);
    testGraph[13].push_back(10);

    auto result = graphs::demukronSort(testGraph);

    BOOST_CHECK_MESSAGE(result.size() == 6, "wrong result size");
    BOOST_CHECK_MESSAGE(result[0].size() == 2, "vertices were not included in the level 0");
    BOOST_CHECK_MESSAGE(result[1].size() == 3, "vertices were not included in the level 1");
    BOOST_CHECK_MESSAGE(result[2].size() == 3, "vertices were not included in the level 2");
    BOOST_CHECK_MESSAGE(result[3].size() == 1, "vertices were not included in the level 3");
    BOOST_CHECK_MESSAGE(result[4].size() == 4, "vertices were not included in the level 4");
    BOOST_CHECK_MESSAGE(result[5].size() == 1, "vertices were not included in the level 5");

    auto result2 = graphs::tarianSort(testGraph);
    BOOST_CHECK_MESSAGE(result.size() == testGraph.size(), "wrong result size");
}
BOOST_AUTO_TEST_SUITE_END()
