//
// Created by tian on 2022/12/23.
//

#ifndef CPP_BASICUSAGE_MPCCOMMON_H
#define CPP_BASICUSAGE_MPCCOMMON_H

const static int FLOAT_PRECISION_DEFAULT = 16;

typedef unsigned __int128 uint128_t;
typedef __int128 int128_t;
typedef uint128_t mpc_t;
typedef int128_t signed_mpc_t;


template<typename T>
mpc_t FloatToMpcType(T a, int precision) {
    return ((mpc_t) (
            (((signed_mpc_t) (a)) << precision) +
            (signed_mpc_t) (((a) - (signed_mpc_t) (a)) * (1L << precision))));
}

template<typename T>
double MpcTypeToFloat(T a, int precision) {
    return ((double((signed_mpc_t) (a))) / (1L << precision));
}

class MpcCommon {


};


#endif //CPP_BASICUSAGE_MPCCOMMON_H
