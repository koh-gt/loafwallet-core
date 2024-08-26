//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "node1.ferritecoin.org", "node2.ferritecoin.org", "node3.ferritecoin.org",
    "node4.ferritecoin.org", NULL};

static const char *BRTestNetDNSSeeds[] = {
    "test1.ferritecoin.org", "test2.ferritecoin.org", "test3.ferritecoin.org", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {       0, uint256("46ca17415c18e43f5292034ebf9bbd10de80a61fc6dc17180e6609f33d3b48f3"), 1669136135, 0x1e0ffff0 },
    {   10000, uint256("f5da0fabe25733a186805366c0fdede73e2454e782083676e7627b8ec991ef9b"), 1670003010, 0x1c1d9a6b },
    {   20000, uint256("adb0e7df07ef771d90ee7599c76ad68364fe3f8c66f247262eccb3e32285abec"), 1670673637, 0x1c2f6d13 },
    {   30000, uint256("64ddec3dde1a4fd6c41d06aacfc27694cfc9c3094574ae83fe51ef4740956a95"), 1672234642, 0x1c0856d1 },
    {   40000, uint256("0c88d74c24fa521dfde56a8e5f24fe187036cc33e4ae884c6b9d450b6a8bf7a5"), 1672926025, 0x1c0a4c83 },
    {   50000, uint256("d5bdd4df59d03efbb166ae2ffd0a126ef9af61c902a4217a49ee7343f2ca932e"), 1673604916, 0x1c01cc54 },
    {   60000, uint256("f38b639a8db731e7dac96eaae8f9ab443eaf85039433197345a72e1961d7f286"), 1674415778, 0x1c03aecf },
    {   70000, uint256("19cbb1633c02299734af25453876dab95fb6a18417dd82c83911a84f2c1f3884"), 1675179245, 0x1c0335a3 },
    {   80000, uint256("fab6720dadc4297e2a7691aa182e18456e311e03f16169ce86048fb02d186de5"), 1675993322, 0x1c016469 },
    {   90000, uint256("4c58e81efa48d7f5ac159125f974834ed88b46fa5329b5d938e8218c9fdb36e2"), 1676831700, 0x1c011332 },
    {  100000, uint256("022dc4410add84d46359013d45df952493c53343304296a9066fc3df03dc8297"), 1677717184, 0x1c029a55 },
    {  110000, uint256("75bfb038140028c03c401e44840b56938cab0cdcdaa5b97275e0dda9c6513cfc"), 1678399306, 0x1c00d677 },
    {  120000, uint256("388b0d78c68997febce580f37ad84e20e49f483a9867752bc54be2fe12bb57ab"), 1679300010, 0x1c035718 },
    {  130000, uint256("085b4346a7f095161d3aa016c4444dc18bb86d4d5ef225a69bc743684027f819"), 1681605860, 0x1b0d8648 },
    {  140000, uint256("9e1d4516af9f99927412c6b82db107180defda5ebe52801bbf05ae0b2215c378"), 1683646904, 0x1b0fd4a9 },
    {  150000, uint256("9caba4d7f981802b7d9961050bc247c5f7c3c3dbb4fcda9e0fe73dfb569b60a5"), 1688410728, 0x1b1d49e0 },
    {  160000, uint256("1812c51a21e5726013092d4d002fc2399c7542de4a7d28f8b4a24b1bed776cf4"), 1713218734, 0x1b01c8c3 },
    {  170000, uint256("6d64964900a434577e8bab60af321934bbdf2dddf5ae7384552d5031d05400d6"), 1723526129, 0x1c1f4fa0 },
    {  180000, uint256("698e097f7bd8c903a17550a75af97b25b82cc3a7c4a1c55105a4e0adac41fe0f"), 1724165360, 0x1c101fa0 }
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("7a9f43d6e86eefa66e2b79918b2235c9362106f3d9f11f37f7a33450ceae73c1"), 1669136958, 0x1e0ffff0 },
    {    6300, uint256("7c42884a7e701cedadf87b656e6bb13f5cf84b83976dd82d0d2331695040fcd0"), 1691708725, 0x1f0fffff },
    {    6320, uint256("7c42884a7e701cedadf87b656e6bb13f5cf84b83976dd82d0d2331695040fcd0"), 1724711208, 0x1f0fffff }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    // const BRMerkleBlock *previous, *b = NULL;
    // uint32_t i;

    // assert(block != NULL);
    // assert(blockSet != NULL);

    // // check if we hit a difficulty transition, and find previous transition block
    // if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //     for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //         b = BRSetGet(blockSet, &b->prevBlock);
    //     }
    // }

    // previous = BRSetGet(blockSet, &block->prevBlock);
    // return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);
    return 1;
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    9574,       // standardPort
    0xd910824a, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints) / sizeof(*BRMainNetCheckpoints)};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    19574,      // standardPort
    0x8aab76ba, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints) / sizeof(*BRTestNetCheckpoints)};

#endif // BRChainParams_h
