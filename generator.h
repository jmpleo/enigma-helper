#ifndef GENERATOR_H
#define GENERATOR_H

#include "perm.h"

#include <string>
#include <vector>

struct PermGenerator
{
    PermGenerator(std::string);
    Perm operator () ();
    Perm operator () (std::vector<int>);
    Perm operator () (std::string);
    std::string ToStr(const Perm &p);

private:
    std::string alphabet_;
};
#endif
