/** @file
 *****************************************************************************

 Declaration of exceptions and constants for Zerocash.

 *****************************************************************************
 * @author     This file is part of libzerocash, developed by the Zerocash
 *             project and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#ifndef ZEROCASH_H_
#define ZEROCASH_H_

#include <stdexcept>
#include <vector>

/* The version of this library. */
#define ZEROCASH_VERSION_STRING             "0.1"
#define ZEROCASH_VERSION_INT				1
#define ZEROCASH_PROTOCOL_VERSION           "1"
#define ZEROCASH_DEFAULT_TREE_SIZE          64

#define ZEROCASH_A_PK_SIZE       32
#define ZEROCASH_PK_ENC_SIZE     311
#define ZEROCASH_SIG_PK_SIZE		32
#define ZEROCASH_ADDR_PK_SIZE    (ZEROCASH_A_PK_SIZE+ZEROCASH_PK_ENC_SIZE)

#define ZEROCASH_A_SK_SIZE       32
#define ZEROCASH_SK_ENC_SIZE     287
#define ZEROCASH_ADDR_SK_SIZE    (ZEROCASH_A_SK_SIZE+ZEROCASH_SK_ENC_SIZE)

#define ZEROCASH_V_SIZE          8
#define ZEROCASH_RHO_SIZE        32
#define ZEROCASH_R_SIZE          48
#define ZEROCASH_S_SIZE          0
#define ZEROCASH_K_SIZE          32
#define ZEROCASH_CM_SIZE         32
#define ZEROCASH_COIN_SIZE       (ZEROCASH_ADDR_PK_SIZE+ZEROCASH_V_SIZE+ZEROCASH_RHO_SIZE+ZEROCASH_R_SIZE+ZEROCASH_S_SIZE+ZEROCASH_CM_SIZE)
#define ZEROCASH_TX_MINT_SIZE    (ZEROCASH_CM_SIZE+ZEROCASH_V_SIZE+ZEROCASH_K_SIZE+ZEROCASH_S_SIZE)

#define ZEROCASH_ROOT_SIZE       32
#define ZEROCASH_SN_SIZE         32
#define ZEROCASH_PK_SIG_SIZE     66
#define ZEROCASH_H_SIZE          32
#define ZEROCASH_POUR_PROOF_SIZE 288
#define ZEROCASH_C_SIZE          173
#define ZEROCASH_SIGMA_SIZE      72
#define ZEROCASH_TX_POUR_SIZE    (ZEROCASH_ROOT_SIZE+(2*ZEROCASH_SN_SIZE)+(2*ZEROCASH_CM_SIZE)+ZEROCASH_V_SIZE+ZEROCASH_PK_SIG_SIZE+(2*ZEROCASH_H_SIZE)+ZEROCASH_POUR_PROOF_SIZE+(2*ZEROCASH_C_SIZE)+ZEROCASH_SIGMA_SIZE)

#define SNARK

typedef std::vector<unsigned char> MerkleRootType;

namespace libsnark {
};

namespace libzerocash {
    using namespace libsnark;
};

#include "libzerocash/utils/util.h"
#include "streams.h"

#endif /* ZEROCASH_H_ */
