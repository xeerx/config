#ifndef XCC___H___WARE_INIT
#define XCC___H___WARE_INIT

/* -------------------------------------------------------------------------- */
/*                                    Libs                                    */
/* -------------------------------------------------------------------------- */
#include <cstdint>          //: std::uint64_t
#include <string>           //: std::string


/* -------------------------------------------------------------------------- */
/*                                   Macros                                   */
/* -------------------------------------------------------------------------- */
//: normalizing the value of version (major, minor, patch) to a single value
#define XCC_MAKE_VER_FORM(major,minor,patch) \
static_cast<std::uint64_t>(((major) << 24) + ((minor) << 16) + (patch))


/* -------------------------------------------------------------------------- */
/*                                   Details                                  */
/* -------------------------------------------------------------------------- */
namespace xrx::detail
{
    //: Base of xrx::ware structures
    struct wareBase {};
}


#endif