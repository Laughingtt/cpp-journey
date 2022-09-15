import algo_lib as example
import time

def t_add():
    a = [i for i in range(10000)]
    b = [i for i in range(10000)]
    c = []

    t0 = time.time()
    for x, y in zip(a, b):
        c.append(x + y)

    print(c[:3])
    print("print for time is :{}".format(time.time() - t0))


    t0 = time.time()
    c = example.add_vector(a, b)
    print(c[:3])
    print("c++ for time is :{}".format(time.time() - t0))


def t_bit_to_int():
    s = ""
    bit_string = "00011111110011111111100011100000110111000011110011110011001000000111110100"
    for i in range(100):
        s += bit_string
    t0 = time.time()
    for i in range(10000):
        lis = example.bit_to_int(s, 10)
    print("print bit_to_int time is :{}".format(time.time() - t0))
    print(lis[:3])


def t_find_position():
    bit_string = "00011111110011111111100011100000110111000011110011110011001000000111110100"
    matrix = [bit_string for i in range(5)]
    v_list = [[3,4,1,5,6],[11,22,3,1,5],[27,19,9,7,5]]
    position_l = example.find_position(v_list,matrix)
    print(position_l)


if __name__ == '__main__':
    t_find_position()