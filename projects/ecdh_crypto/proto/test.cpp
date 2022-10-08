//
// Created by tian on 2022/9/26.
//

#include <iostream>
#include <fstream>
#include <string>
#include "include/curve_point.pb.h"

using namespace std;


void ecc_serialize_test() {
    tutorial::CurvePoint curve_point;
    vector<string> point = {"1", "2", "3"};
    curve_point.mutable_point_list()->CopyFrom({point.begin(), point.end()});
    string s;
    curve_point.SerializeToString(&s);
    cout << "curve_point.ByteSizeLong() : " << curve_point.ByteSizeLong() << " " << s.c_str() << endl;

    tutorial::CurvePoint rs_curve_point;
    rs_curve_point.ParseFromString(s);
    cout << "rs_curve_point [0] " << rs_curve_point.point_list()[0] << endl;
    cout << "rs_curve_point [1] " << rs_curve_point.point_list()[1] << endl;
    cout << "rs_curve_point [2] " << rs_curve_point.point_list()[2] << endl;
}

int main(int argc, char *argv[]) {
//    serialize_process();
//    parse_process();

    ecc_serialize_test();


    google::protobuf::ShutdownProtobufLibrary();    //删除所有已分配的内存（Protobuf使用的堆内存）
    return 0;
}
