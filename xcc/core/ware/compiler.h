#ifndef XCC___H___WARE_COMPILER
#define XCC___H___WARE_COMPILER


/* -------------------------------------------------------------------------- */
/*                                    Libs                                    */
/* -------------------------------------------------------------------------- */
#include "init.h"


/* -------------------------------------------------------------------------- */
/*                                   Macros                                   */
/* -------------------------------------------------------------------------- */
//: NVIDIA CUDA C++
#if defined __CUDACC__
    #define XCC_COMP_CUDA
    #define XCC_COMP            "NVIDIA CUDA C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__CUDACC_VER_MAJOR__)
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__CUDACC_VER_MINOR__)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(__CUDACC_VER_BUILD__)

//: GCC XML
#elif defined(__GCCXML__)
    #define XCC_COMP_GCC_XML
    #define XCC_COMP            "GCC XML"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__GCCXML_GNUC__           )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__GCCXML_GNUC_MINOR__     )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(__GCCXML_GNUC_PATCHLEVEL__)

//: Cray C
#elif defined(_CRAYC)
    #define XCC_COMP_CRAY
    #define XCC_COMP            "Cray C"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>( _RELEASE_MINOR / 1000     )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((_RELEASE_MINOR / 100) % 10)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( _RELEASE_MINOR % 1000     )

//: Comeau C++
#elif defined (__COMO__)
    #define XCC_COMP_COMO
    #define XCC_COMP            "Comeau C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__COMO_VERSION__ / 100)
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__COMO_VERSION__ % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(0                     )

//: PathScale EKOPath
#elif defined(__PATHCC__)
    #define XCC_COMP_PATHCC
    #define XCC_COMP            "PathScale EKOPath"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__PATHCC__           )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__PATHCC_MINOR__     )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(__PATHCC_PATCHLEVEL__)

//: Intel ICX
#elif defined(__INTEL_LLVM_COMPILER)
    #define XCC_COMP_ICX
    #define XCC_COMP            "Intel ICX"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__INTEL_LLVM_COMPILER / 10000)    )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__INTEL_LLVM_COMPILER / 100) % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __INTEL_LLVM_COMPILER % 100       )

//: Intel ICC
#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
    #define XCC_COMP_ICC
    #define XCC_COMP            "Intel ICC"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__INTEL_COMPILER_BUILD_DATE / 10000)    )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__INTEL_COMPILER_BUILD_DATE / 100) % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __INTEL_COMPILER_BUILD_DATE % 100       )

//: Clang
#elif defined(__clang__)
    #define XCC_COMP_CLANG      
    #define XCC_COMP            "Clang"
    #define XCC_COMP_VER_MAJ    static_cast<std::uint64_t>(__clang_major__     )
    #define XCC_COMP_VER_MIN    static_cast<std::uint64_t>(__clang_minor__     )
    #define XCC_COMP_VER_PAT    static_cast<std::uint64_t>(__clang_patchlevel__)

//: Digital Mars
#elif defined (__DMC__)
    #define XCC_COMP_DMC
    #define XCC_COMP            "Digital Mars"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__DMC__ >> 8) & 0xF)
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__DMC__ >> 4) & 0xF)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __DMC__       & 0xF)

//: Diab C/C++
#elif defined (__DCC__)
    #define XCC_COMP_DCC
    #define XCC_COMP            "Diab C/C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__VERSION_NUMBER__ / 1000)    )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__VERSION_NUMBER__ / 100) % 10)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __VERSION_NUMBER__ % 100      )

//: Portland Group C/C++
#elif defined(__PGI)
    #define XCC_COMP_PGI
    #define XCC_COMP            "Portland Group C/C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__PGIC__           )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__PGIC_MINOR__     )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(__PGIC_PATCHLEVEL__)

//: GNU C++
#elif defined(__GNUC__)
    #define XCC_COMP_GCC        
    #define XCC_COMP            "GNU C++"
    #define XCC_COMP_VER_MAJ    static_cast<std::uint64_t>(__GNUC__           ) 
    #define XCC_COMP_VER_MIN    static_cast<std::uint64_t>(__GNUC_MINOR__     )
    #define XCC_COMP_VER_PAT    static_cast<std::uint64_t>(__GNUC_PATCHLEVEL__)

//: Kai C++
#elif defined (__KCC)
    #define XCC_COMP_KCC
    #define XCC_COMP            "Kai C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(  (__KCC_VERSION >> 12) & 0xF                                )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(  (__KCC_VERSION >> 8)  & 0xF                                )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>((((__KCC_VERSION >> 4)  & 0xF) * 10) + (__KCC_VERSION & 0xF) )

//: SGI MIPSpro C++
#elif defined (__sgi)
#define XCC_COMP_SGI
    #define XCC_COMP            "SGI MIPSpro C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((_COMPILER_VERSION / 100)      )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((_COMPILER_VERSION / 10) % 10  )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( _COMPILER_VERSION % 10        )


//: Compaq C/C++
#elif defined (__DECCXX)
    #define XCC_COMP_COMPAQ
    #define XCC_COMP            "Compaq C/C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>( __DECC_VER / 10000000     )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__DECC_VER / 100000) % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __DECC_VER % 10000        )

//: Green Hill C/C++
#elif defined (__ghs)
    #define XCC_COMP_GHS
    #define XCC_COMP            "Green Hill C/C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>( __GHS_VERSION_NUMBER__ / 100     )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__GHS_VERSION_NUMBER__ / 10) % 10)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __GHS_VERSION_NUMBER__ % 10      )

//: CodeGear
#elif defined (__CODEGEARC__)
    #define XCC_COMP_CODEGEARC
    #define XCC_COMP            "CodeGear"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>( (__CODEGEARC_VERSION__ >> 24) & 0xF                                               )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(((__CODEGEARC_VERSION__ >> 20) & 0xF * 10) +  ((__CODEGEARC_VERSION__ >> 16) & 0xF)) 
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( (__CODEGEARC_VERSION__ >> 12) & 0xF                                               )

//: Borland C++
#elif defined (__BORLANDC__)
    #define XCC_COMP_BORLANDC
    #define XCC_COMP            "Borland C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__BORLANDC__ >> 8) & 0xF)
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__BORLANDC__ >> 4) & 0xF)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __BORLANDC__       & 0xF)

//: Metrowerks CodeWarrior
#elif defined (__MWERKS__)
    #define XCC_COMP_MWERKS
    #define XCC_COMP            "Metrowerks CodeWarrior"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(  (__MWERKS__ >> 12) & 0xF                             )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(  (__MWERKS__ >> 8)  & 0xF                             )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>((((__MWERKS__ >> 4)  & 0xF) * 10) + (__MWERKS__ & 0xF) )

//: Oracle Solaris Studio
#elif defined (__SUNPRO_CC)
    #define XCC_COMP_SUNPRO
    #define XCC_COMP            "Oracle Solaris Studio"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(  (__SUNPRO_CC >> 12) & 0xF                                    )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((((__SUNPRO_CC >> 8)  & 0xF) * 10) + ((__SUNPRO_CC >> 4) & 0xF))
    #define XCC_COMP_PAT        static_cast<std::uint64_t>((  __SUNPRO_CC        & 0xF)                                   )

//: HP aC++
#elif defined (__HP_aCC) 
    #define XCC_COMP_HPACC
    #define XCC_COMP            "HP aC++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>( __HP_aCC / 10000     )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__HP_aCC / 100) % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __HP_aCC % 100       )

//: MPW C++
#elif defined(__MRC__) || defined(__SC__)
    #define XCC_COMP_MRC
    #define XCC_COMP            "MPW C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((((__MRC__ >> 12) & 0xF) * 10) + ((__MRC__ >> 8) & 0xF))
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((((__MRC__ >> 4)  & 0xF) * 10) + ( __MRC__       & 0xF))
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(0)

//: IBM z/OS XL C/C++
#elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)
    #define XCC_COMP_IBMXL_ZOS
    #define XCC_COMP            "IBM z/OS XL C/C++"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((__IBMCPP__ / 1000) %  10)
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((__IBMCPP__ / 10)   % 100)
    #define XCC_COMP_PAT        static_cast<std::uint64_t>( __IBMCPP__ % 10         )

//: IBM XL C/C++ (Clang-based versions)
#elif defined(__ibmxl__)
    #define XCC_COMP_IBMXL_CLANG
    #define XCC_COMP            "IBM XL C/C++ (Clang-based versions)"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>(__ibmxl_version__     )
    #define XCC_COMP_MIN        static_cast<std::uint64_t>(__ibmxl_release__     )
    #define XCC_COMP_PAT        static_cast<std::uint64_t>(__ibmxl_modification__)

//: IBM XL C/C++ (legacy versions)
#elif defined(__IBMCPP__)
    #define XCC_COMP_IBMXL_LEGACY
    #define XCC_COMP            "IBM XL C/C++ (legacy versions)"
    #define XCC_COMP_MAJ        static_cast<std::uint64_t>((((__IBMCPP__ >> 20) & 0xF) * 10) + ((__IBMCPP__ >> 16) & 0xF))
    #define XCC_COMP_MIN        static_cast<std::uint64_t>((((__IBMCPP__ >> 12) & 0xF) * 10) + ((__IBMCPP__ >>  8) & 0xF))
    #define XCC_COMP_PAT        static_cast<std::uint64_t>((((__IBMCPP__ >>  4) & 0xF) * 10) + ( __IBMCPP__        & 0xF))

//: Microsoft Visual C++
#elif defined(_MSC_VER)
    #define XCC_COMP_MSVC       
    #define XCC_COMP            "Microsoft Visual C++"
    #define XCC_COMP_VER_MAJ    static_cast<std::uint64_t>(_MSC_VER       /    100)
    #define XCC_COMP_VER_MIN    static_cast<std::uint64_t>(_MSC_VER       %    100)
    #define XCC_COMP_VER_PAT    static_cast<std::uint64_t>(_MSC_FULL_VER  % 100000)

//: Unknown
#else
    #define XCC_COMP_NONE
    #define XCC_COMP            "Unknown"
    #define XCC_COMP_VER_MAJ    static_cast<std::uint64_t>(0)
    #define XCC_COMP_VER_MIN    static_cast<std::uint64_t>(0)
    #define XCC_COMP_VER_PAT    static_cast<std::uint64_t>(0)
#endif

//: Warning
#if defined(XCC_COMP_NONE) && (defined(XCC_OPT_FORCED_WARNINGS) && XCC_OPT_FORCED_WARNINGS == 1)
    #warning "[XCC] Unkown compiler"
#endif

//: Normalized version
#define XCC_COMP_VER_NRM XCC_MAKE_VER_FORM(XCC_COMP_VER_MAJ, XCC_COMP_VER_MIN, XCC_COMP_VER_PAT)


/* -------------------------------------------------------------------------- */
/*                                 Structures                                 */
/* -------------------------------------------------------------------------- */
namespace xrx::ware
{
    //: Compiler Info
    struct compiler : public detail::wareBase
    {
        //: name
        static constexpr auto name      { XCC_COMP        };

        //: major
        static constexpr auto major     { XCC_COMP_VER_MAJ };

        //: major
        static constexpr auto minor     { XCC_COMP_VER_MIN };
        
        //: major
        static constexpr auto patch     { XCC_COMP_VER_PAT };

        //: normalized version
        static constexpr auto nversion  { XCC_COMP_VER_NRM };

        //: version (string form of "major.minor.patch")
        static const std::string version()  noexcept
        {
            return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
        }
    };
}


#endif