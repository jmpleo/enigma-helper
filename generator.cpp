#include "generator.h"

#include <string>

PermGenerator::PermGenerator(std::string alphabet) : alphabet_(alphabet) {}
Perm PermGenerator::operator () () { return Perm(alphabet_.size()); }
Perm PermGenerator::operator () (std::vector<int> perm)
{
    if (perm.size() != alphabet_.size()) {
        std::__throw_bad_exception();
    }
    return Perm(perm);
}

Perm PermGenerator::operator () (std::string perm)
{
    if (perm.size() != alphabet_.size()) {
        std::__throw_bad_exception();
    }
    Perm p(perm.size());
    for (int i = 0, size = static_cast<int>(perm.size()); i < size; ++i) {
        p(i) = alphabet_.find(perm[i]);
    }
    return p;
}

std::string PermGenerator::ToStr(const Perm &p)
{
    std::string result = "";
    for (int i = 0, size = static_cast<int>(p.size()); i < size; ++i) {
        result += alphabet_[p(i)];
    }
    return result;
}

