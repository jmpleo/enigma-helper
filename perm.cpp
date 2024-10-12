#include "perm.h"

#include <numeric>

Perm::Perm(std::vector<int> perm) : perm_(perm) {}
Perm::Perm(Perm const & other)    : perm_(other.perm_) {}
Perm::Perm(Perm&& other)          : perm_(std::move(other.perm_)) {}
Perm::Perm(std::size_t size)      : perm_(size) { std::iota(perm_.begin(), perm_.end(), 0); }

std::size_t Perm::size() const { return perm_.size(); }
std::size_t Perm::size()       { return perm_.size(); }

const int& Perm::operator () (std::size_t i) const { return perm_.at(i); }
      int& Perm::operator () (std::size_t i)       { return perm_.at(i); }

Perm Perm::operator * (Perm const & other)
{
    Perm p(other.perm_.size());
    for (std::size_t i = 0; i < perm_.size(); ++i) {
        p(i) = other.perm_[perm_[i]];
    }
    return p;
}
Perm& Perm::operator = (Perm const & other) {
    perm_ = other.perm_;
    return *this;
}
Perm& Perm::operator = (Perm && other) {
    perm_ = std::move(other.perm_);
    return *this;
}
Perm Perm::operator ^ (int n) {
    Perm p(size());
    if (n > 0) {
        p = (*this);
        while ((--n) > 0) {
            p = p * (*this);
        }
    }
    else if (n < 0) {
        p = ~(*this);
        while ((++n) < 0) {
            p = p * ~(*this);
        }
    }
    return p;
}
bool Perm::operator == (Perm const & other) {
    return std::equal(perm_.begin(), perm_.end(), other.perm_.begin());
}
Perm Perm::operator ~ () {
    Perm p(perm_.size());
    for (std::size_t i = 0; i < perm_.size(); ++i) {
        p(perm_[i]) = i;
    }
    return p;
}
