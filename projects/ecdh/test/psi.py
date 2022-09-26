import unittest
import ecdh_lib
import pickle

hello_res = ['112711660439710606056748659173929673102114977341539408544630613555209775888121',
             '25583027980570883691656905877401976406448868254816295069919888960541586679410',
             '20329878786436204988385760252021328656300425018755239228739303522659023427621',
             '35028142331614638340248087792986616819121701108340890405919251062981357323303']


class PsiTest(unittest.TestCase):
    def setUp(self):
        "Hook method for setting up the test fixture before exercising it."
        self.ecdh_encrypt = ecdh_lib.EccEncrypt()

    def tearDown(self):
        "Hook method for deconstructing the test fixture after testing it."
        del self.ecdh_encrypt

    def test_encrypt(self):
        enc_1 = self.ecdh_encrypt.encrypt("hello")
        self.assertEqual(hello_res, enc_1)

    def test_decrypt(self):
        dec_1 = self.ecdh_encrypt.decrypt(hello_res)
        self.assertEqual("f912bfcdd60c851087082139cbb1a9ecb934d47f22d21eafad02cd768ae09886", dec_1)

    def test_psi(self):
        a = [str(i) for i in range(20)]
        b = [str(i) for i in range(5, 15)]
        a_enc = [pickle.dumps(self.ecdh_encrypt.encrypt(i)) for i in a]
        b_enc = [pickle.dumps(self.ecdh_encrypt.encrypt(i)) for i in b]

        psi_lis = []
        for i, d in enumerate(a_enc):
            if d in b_enc:
                psi_lis.append(a[i])

        print("psi_lis len ", len(psi_lis), " psi_lis ", psi_lis)
        self.assertEqual(psi_lis, b)

    def test_encrypt_speed(self):
        import time
        t0 = time.time()
        for i in range(10000):
            self.ecdh_encrypt.encrypt(str(i))
        print("encrypt time is ", time.time() - t0)


if __name__ == '__main__':
    unittest.main()
