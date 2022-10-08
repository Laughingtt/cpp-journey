import unittest
import ecdh_lib


class OtTest(unittest.TestCase):
    def setUp(self):
        "Hook method for setting up the test fixture before exercising it."
        self.ecdh_sender = ecdh_lib.EccObliviousTransfer()
        self.ecdh_receiver = ecdh_lib.EccObliviousTransfer()

    def tearDown(self):
        "Hook method for deconstructing the test fixture after testing it."
        del self.ecdh_sender
        del self.ecdh_receiver

    def test_ot(self):
        msgs = [1, 2, 3, 4, 5, 6]
        choice = 3

        # p1 生成公钥
        sender_public = self.ecdh_sender.get_public_key()

        # p2 接受p1 公钥并计算random k = B + i * A
        B_random_k = self.ecdh_receiver.receiver_compute_k(sender_public, choice)

        # p1 接受random k 分别计算 k_i = a*k - i*a *A
        secret_key_list = self.ecdh_sender.sender_compute_secret_list(B_random_k, len(msgs))

        # p2 sk = b*A = a*b*G
        secret_key = self.ecdh_receiver.receiver_compute_secret_key(sender_public)

        print("secret_key  ", secret_key)
        print("secret_key_list  ", secret_key_list)

        self.assertEqual(secret_key, secret_key_list[choice])


if __name__ == '__main__':
    unittest.main()
