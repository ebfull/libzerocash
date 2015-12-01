/** @file
 *****************************************************************************

 Test for Merkle tree.

 *****************************************************************************
 * @author     This file is part of libzerocash, developed by the Zerocash
 *             project and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#include "libzerocash/IncrementalMerkleTree.h"
#include "libzerocash/MerkleTree.h"

#include <iostream>
#include <vector>

#define BOOST_TEST_MODULE merkleTest
#include <boost/test/included/unit_test.hpp>

using namespace libzerocash;
using namespace std;

void constructNonzeroTestVector(std::vector< std::vector<bool> > &values, uint32_t size)
{
    values.resize(0);
    std::vector<bool> dummy;
    dummy.resize(256);
    dummy[0] = true;

    for (uint32_t i = 0; i < size; i++)
    {
        values.push_back(dummy);
    }
}

void constructZeroTestVector(std::vector< std::vector<bool> > &values, uint32_t size)
{
    values.resize(0);
    std::vector<bool> dummy;
    dummy.resize(256);

    for (uint32_t i = 0; i < size; i++)
    {
        values.push_back(dummy);
    }
}

BOOST_AUTO_TEST_CASE( testRootConsistencyZeroValues ) {
    IncrementalMerkleTree incTree;
    std::vector< std::vector<bool> > values;
    std::vector<bool> root1;
    std::vector<bool> root2;

    constructZeroTestVector(values, 2);

    // Create an IncrementalMerkleTree over the values.
    if (incTree.insertVector(values) == false) {
        BOOST_ERROR("Could not insert into the tree.");
    }
    incTree.prune();

    // Create a MerkleTree over the values.
    MerkleTree oldTree(values);

    incTree.getRootValue(root1);
    oldTree.getRootValue(root2);

    BOOST_CHECK( root1 == root2 );
}

BOOST_AUTO_TEST_CASE( testRootConsistencyNonzeroValues ) {
    IncrementalMerkleTree incTree;
    std::vector< std::vector<bool> > values;
    std::vector<bool> root1;
    std::vector<bool> root2;

    constructNonzeroTestVector(values, 2);

    // Create an IncrementalMerkleTree over the values.
    if (incTree.insertVector(values) == false) {
        BOOST_ERROR("Could not insert into the tree.");
    }
    incTree.prune();

    // Create a MerkleTree over the values.
    MerkleTree oldTree(values);

    incTree.getRootValue(root1);
    oldTree.getRootValue(root2);

    BOOST_CHECK( root1 == root2 );
}

BOOST_AUTO_TEST_CASE( testCompactRepresentation ) {
    for (uint32_t num_entries = 0; num_entries < 100; num_entries++) {
        std::vector< std::vector<bool> > values;
        std::vector<bool> root1, root2;
        IncrementalMerkleTree incTree;

        constructNonzeroTestVector(values, num_entries);

        BOOST_REQUIRE( incTree.insertVector(values) );
        BOOST_REQUIRE( incTree.prune() );

        IncrementalMerkleTreeCompact compact;
        BOOST_REQUIRE( incTree.getCompactRepresentation(compact) );

        IncrementalMerkleTree newTree(compact);

        incTree.getRootValue(root1);
        incTree.getRootValue(root2);

        BOOST_REQUIRE( root1 == root2 );
    }
}
