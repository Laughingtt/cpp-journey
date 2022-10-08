

# 生成proto c++ 代码

protoc -I=/Users/tian/Projects/CPP-BasicUsage/projects/ecdh/proto /Users/tian/Projects/CPP-BasicUsage/projects/ecdh/proto/curve_point.proto --cpp_out=.

# 编译
g++ test.cpp curve_point.pb.cc -o main_test -lprotobuf
