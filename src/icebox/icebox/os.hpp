#pragma once

#include "enums.hpp"
#include "types.hpp"

namespace core { struct Core; }

namespace os
{
    using bpid_t = uint64_t;

    bool    is_kernel_address   (core::Core&, uint64_t ptr);
    bool    can_inject_fault    (core::Core&, uint64_t ptr);
    size_t  unlisten            (core::Core&, bpid_t bpid);
    void    debug_print         (core::Core&);
    bool    check_flags         (flags_t got, flags_t want);
} // namespace os
