#pragma once
#include "xrCore/xrCore.h"
#include <cryptopp/sha.h>

#include <optional>
#include <array>

namespace crypto
{

using yielder_t = fastdelegate::FastDelegate1<long>;

class XRCORE_API xr_sha1
{
public:
    static const size_t DIGEST_SIZE = CryptoPP::SHA1::DIGESTSIZE;
    static const size_t BLOCK_SIZE = CryptoPP::SHA1::BLOCKSIZE;
    using hash_t = std::array<u8, DIGEST_SIZE>;

    void calculate(hash_t& result, const u8* data, u32 data_size, std::optional<yielder_t> yielder);
    void calculate(hash_t& result, const u8* data, u32 data_size);
};

}

