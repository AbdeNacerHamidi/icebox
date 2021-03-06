#pragma once

#include "interfaces/if_symbols.hpp"

#include <string_view>

namespace symbols
{
    struct Struc;

    struct Indexer
        : public symbols::Module
    {
        virtual ~Indexer() = default;

        // indexing methods
        virtual void    add_symbol  (std::string_view name, size_t offset) = 0;
        virtual Struc&  add_struc   (std::string_view name, size_t size) = 0;
        virtual void    add_member  (Struc& struc, std::string_view name, size_t offset) = 0;
        virtual void    finalize    () = 0;
    };

    std::shared_ptr<Indexer> make_indexer(std::string_view id);
} // namespace symbols
