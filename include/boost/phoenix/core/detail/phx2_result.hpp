/*=============================================================================
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_DETAIL_PHX2_RESULT_HPP
#define BOOST_PHOENIX_CORE_DETAIL_PHX2_RESULT_HPP
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/mpl/has_xxx.hpp>

namespace boost { namespace phoenix {
    namespace detail
    {
        BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

        template <typename Result>
        struct has_phx2_result_impl
        {
            typedef char yes;
            typedef char (&no)[2];

            template <typename A>
            static yes check_(typename A::type *);
            
            
            template <typename A>
            static no check_(...);

            static bool const value = (sizeof(yes) == sizeof(check_<Result>(0)));
            typedef boost::mpl::bool_<value> type;
        };

        #include <boost/phoenix/core/detail/cpp03/phx2_result.hpp>
    }
}}

#endif

