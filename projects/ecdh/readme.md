# 椭圆曲线

首先，椭圆曲线是什么，一个简单的定义是，是由y 2 = x 3 + a x + b , ( 4 a 3 + 27 b 2 ≠ 0 ) y^2 = x^3+ax+b,
(4a^3+27b^2\ne 0)y 2 =x 3 +ax+b,(4a 3 +27b^2  !=0)上面的所有点构成的一个集合，这种方程形式被叫做维尔斯特拉斯标准形式（Weierstrass normal form）

Elliptic curves are not ellipses. An ellipse is a closed curve. A circle is a special case of an ellipse. Ellipses are
pretty simple.

An elliptic curve, on the other hand, is a more complex smoothly curving shape. Potentially much more complex.

You can do operations of addition, negation, and multiplication on points on an elliptic curve. Those operations have
exactly the same properties as they do with integers. But they work very differently.

Calculating powers, or chained multiplications, is easy and fast. But reversing that, calculating a discrete logarithm,
is impractically difficult. There's your trapdoor.

The big two things to see here are the graphical illustration of addition on an elliptic curve, and how to calculate a
set of points on a curve.

[ELliptic Curve Cryptography](https://cromwell-intl.com/cybersecurity/elliptic-curve-cryptography/)

[What Are Elliptic Curves](https://cromwell-intl.com/cybersecurity/elliptic-curve-cryptography/elliptic-curves.html)

[Points On An Elliptic Curve](https://cromwell-intl.com/cybersecurity/elliptic-curve-cryptography/points-on-a-curve.html)


---

# 编译

1. python 编译为wheel 包

```shell
python setup.py bdist_wheel
```

2. cmake 编译测试

```shell
mkdir build && cd build && cmake .. && make -j 6
```

---

# 测试

```shell
python  test/ot.py
python test/psi.py
```