#include "perm.h"
#include "factory.h"

#include <iostream>
#include <iterator>
#include <string>

int main(int argc, char ** argv)
{
    std::string info =
        "enigma {ALPHABET} {DISK} {REFLECTOR}\n"// {S0} {S1}\n"
        //"example:\n"
        //"enigma FDKILEAHGBJC GKFLHCAEJIBD FEKLBAJIHGCD\n";
    ;
    if (argc != 4) {
        std::cout << info;
        return 1;
    }

    std::string const ALPHABET = argv[1];
    std::string const DISK = argv[2];
    std::string const REFLECTOR = argv[3];

    if (DISK.size() != ALPHABET.size() or REFLECTOR.size() != ALPHABET.size()) {
        std::cout << "must be len(DISK) = len(REFLECTOR) = len(ALPHABET)" << std::endl;
        return 1;
    }

    PermFactory factory(ALPHABET);

    Perm E  = factory()
        , T  = E >> 1
        , D  = factory(DISK)
        , R  = factory(REFLECTOR)
         //S0 = g(argv[2]),
         //S1 = g(argv[3]),
        ;
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

    if (!((S0 ^ 2) == E && (S1 ^ 2) == E)) {
        std::cout << "S0 ^ 2 or S1 ^ 2 not equal E\n";
        return 0;
    }
    */
    for (std::size_t rotationCorner = 0; rotationCorner < ALPHABET.size(); ++rotationCorner) {
        auto X = (T^(-rotationCorner)) * D * (T^rotationCorner);
        std::cout << factory.toString(X * R * (~X)) << "\n";
        //if ((~D0 * S0 * D0) == (~D1 * S1 * D1)) {
            //std::cout << "D rotate on " << k << " = " << g.ToStr(D0) << '\n';
            //return 0;
        //}
    }
}

