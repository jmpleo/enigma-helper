#pragma once

#include "perm.h"

#include <string>

struct PermFactory
{
    PermFactory(std::string);
    Perm operator () ();
    Perm operator () (std::string const &);
    std::string toString(const Perm &p);

private:
    std::string alphabet_;
};
