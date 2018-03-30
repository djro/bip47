#ifndef BIP47_PUSH_DATA_HPP
#define BIP47_PUSH_DATA_HPP

#include <bitcoin/bitcoin/machine/program.hpp>

using namespace libbitcoin;

// I could not find an easy way to just make a push_data operation on the
// stack machine so I had to build one... that seems weird. 
class push_data : public machine::operation {
protected:
    push_data(machine::opcode code, data_chunk data) : operation(code, data, true) {}
public:
    push_data() : operation(){}
    static push_data factory(data_chunk data) {
        int size = data.size();
        if (size > 75) {
            return push_data();
        }
        return push_data(static_cast<machine::opcode>(size), data);
    }
};

#endif
