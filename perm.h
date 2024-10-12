#ifndef PERM_H
#define PERM_H

#include <vector>

struct Perm
{
    Perm(std::vector<int>);
    Perm(Perm const &);
    Perm(Perm&& other);
    Perm(std::size_t size);

    std::size_t size() const;
    std::size_t size();

    const int& operator () (std::size_t i) const;
          int& operator () (std::size_t i);

    Perm& operator = (Perm const & other);
    Perm& operator = (Perm && other);
    Perm  operator * (Perm const & other);
    Perm  operator ~ ();
    Perm  operator ^ (int n);
    bool  operator == (Perm const & other);

private:
    std::vector<int> perm_;
};
#endif
