//
// Copyright (c) 2023 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/tcl/async.hpp>
#include <boost/tcl/eval.hpp>

#include "doctest.h"

extern Tcl_Interp *interp;

struct test_async : boost::tcl::async
{
  bool called = false;
  int invoke(Tcl_Interp * interp, int code) override
  {
    called = true;
    return TCL_OK;
  }
};


TEST_CASE("async")
{
  test_async ta;
  CHECK(!ta.called);
  CHECK_NOTHROW(boost::tcl::eval(interp, "puts nothing"));
  CHECK(!ta.called);
  ta.mark();
  CHECK(!ta.called);
  CHECK_NOTHROW(boost::tcl::eval(interp, "puts someting"));
  CHECK(ta.called);
}
