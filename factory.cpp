#include "factory.h"

#include <cstddef>
#include <string>

PermFactory::PermFactory(std::string alphabet)
    : alphabet_(alphabet)
{
}

Perm PermFactory::operator () ()
{
    return Perm(alphabet_.size());
}

Perm PermFactory::operator () (std::string const & perm)
{
    if (perm.size() != alphabet_.size()) {
        std::__throw_bad_exception();
    }

    Perm p(perm.size());

    for (std::size_t i = 0; i < perm.size(); ++i) {

        auto pos = alphabet_.find(perm[i]);

        if (pos == std::string::npos) {
            std::__throw_bad_exception();
        }

        p(i) = pos;
    }
    return p;
}

std::string PermFactory::toString(const Perm &p)
{
    std::string s = "";
    if (p.size() != alphabet_.size()) {
        std::__throw_bad_exception();
    }
    for (std::size_t i = 0; i < p.size(); ++i) {
        s += alphabet_[p(i)];
    }
    return s;
}

