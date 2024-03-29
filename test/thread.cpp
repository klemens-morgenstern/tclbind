//
// Copyright (c) 2022 Klemens Morgenstern (klemens.morgenstern@gmx.net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <tclbind/thread.hpp>
#include <iostream>

#include "doctest.h"

struct channel
{};


TEST_CASE("thread")
{
  tclbind::thread thr{
    []
    {
      std::cout << "hello world" << std::endl;
    }
  };

  thr.join();
}