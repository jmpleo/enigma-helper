#include "perm.h"
#include "generator.h"

#include <iostream>
#include <string>
#include <string.h>

int main(int argc, char ** argv)
{
    std::string info =
        "enigma {D} {S0} {S1}\n"
        "example:\n"
        "enigma FDKILEAHGBJC GKFLHCAEJIBD FEKLBAJIHGCD\n";
    if (              argc != 4
        || strlen(argv[1]) != 12
        || strlen(argv[2]) != 12
        || strlen(argv[3]) != 12
    ) {
        std::cout << info;
        return 0;
    }
    PermGenerator g("ABCDEFGHIJKL");
    Perm D  = g(argv[1]),
         T  = g("BCDEFGHIJKLA"),
         S0 = g(argv[2]),
         S1 = g(argv[3]),
         E  = g();
/*
    Generator g("ABCDEFGHIJKL");
    Perm R1 = g("FDKILEAHGBJC"),
         R2 = g("EJLGBHKIDAFC"),
         T  = g("BCDEFGHIJKLA"),
         S0 = //g("EGILAHBFCKJD"), // 1
              //g("IFGLJBCKAEHD"), // 2
                g("GKFLHCAEJIBD"), // 3
              //g("FEKLBAJIHGCD"), // 4
              //g("KIELCJHGBFAD"), // 5
         S1 = //g("IFGLJBCKAEHD"), // 1
              //g("GKFLHCAEJIBD"), // 2
                g("FEKLBAJIHGCD"), // 3
              //g("KIELCJHGBFAD"), // 4
              //g("EGILAHBFCKJD"), // 5
         E = g();
*/
    if (!((S0 ^ 2) == E && (S1 ^ 2) == E)) {
        std::cout << "S0 ^ 2 or S1 ^ 2 not equal E\n";
        return 0;
    }
    for (int k = 0; k < 12; ++k) {
        Perm D0 = (T^(-(k+0))) * D * (T^(k+0)),
             D1 = (T^(-(k+1))) * D * (T^(k+1));
        if ((~D0 * S0 * D0) == (~D1 * S1 * D1)) {
            std::cout << "D rotate on " << k << " = " << g.ToStr(D0) << '\n';
            return 0;
        }
    }
}

