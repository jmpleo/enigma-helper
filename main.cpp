#include "perm.h"
#include "factory.h"

#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    std::string info =
        "enigma {ALPHABET} {DISK} {REFLECTOR}\n"// {S0} {S1}\n"
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

    Perm E  = factory(),
         T  = E >> 1,
         D  = factory(DISK),
         R  = factory(REFLECTOR)
         //S0 = g(argv[2]),
         //S1 = g(argv[3]),
         ;

    /*
    if (!((S0 ^ 2) == E && (S1 ^ 2) == E)) {
        std::cout << "S0 ^ 2 or S1 ^ 2 not equal E\n";
        return 0;
    }
    */

    for (std::size_t rotCorner = 0; rotCorner < ALPHABET.size(); ++rotCorner) {
        auto X = (E << rotCorner) * D * (E >> rotCorner);
        std::cout << factory.toString(X * R * ~X) << "\n";

        /*
        if ((~D0 * S0 * D0) == (~D1 * S1 * D1)) {
            std::cout << "D rotate on " << k << " = " << g.ToStr(D0) << '\n';
            return 0;
        }
        */
    }
}

