#Program chatting dengan enkripsi menggunakan private dan public key algoritma RSA
#Client

import socket
import random
import pickle

BUFFSIZE = 1024

def multiplicative_inverse(e, m):
    d = x1 = 0
    x2 = y1 = 1
    temp_m = m

    while e > 0:
        temp1 = temp_m/e
        temp2 = temp_m - temp1 * e
        temp_m = e
        e = temp2

        x = x2 - temp1 * x1
        y = d - temp1 * y1

        x2 = x1
        x1 = x
        d = y1
        y1 = y

    if temp_m == 1:
        return d + m

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def is_prime(num):
    if num == 2:
        return True
    if num < 2 or num % 2 == 0:
        return False
    for n in xrange(3, int(num**0.5)+2, 2):
        if num % n == 0:
            return False
    return True

def buat_key(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Kedua angka harus prima')
    elif p == q:
        raise ValueError('p dan q tidak boleh sama')
    n = p * q
    m = (p-1) * (q-1)
    e = random.randrange(1, m)
    g = gcd(e, m)
    while g != 1:
        e = random.randrange(1, m)
        g = gcd(e, m)
    d = multiplicative_inverse(e, m)
    return ((e, n), (d, n))

def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext]
    return cipher

def decrypt(pk, chipertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in chipertext]
    return ''.join(plain)

if __name__ == '__main__':
    s = socket.socket()
    host = 'localhost'
    port = 12221

    s.connect((host, port))
    print 'Connected to', host

    p = int(raw_input("Masukkan angka prima pertama: "))
    q = int(raw_input("Masukkan angka prima kedua: "))
    print "Membuat public key dan private key..."
    public, private = buat_key(p, q)
    print "Public key anda adalah ", public, " dan private key anda adalah ", private
    flag = False
    while True:
        if flag is False:
            print "Mengirim public key client ke server"
            s.send(pickle.dumps(public))
            print "[Menunggu public key balasan dari server...]"
            public2 = pickle.loads(s.recv(BUFFSIZE))
            print "Public key dari server adalah: "
            print public2
            flag = True
        else:
            z = raw_input("Kirim pesan ke server: ")
            z_enkrip = encrypt(private, z)
            s.send(pickle.dumps(z_enkrip))
            # Halts
            print '[Waiting for response...]'
            data = pickle.loads(s.recv(BUFFSIZE))
            print ''.join(map(lambda x: str(x), data))
            print '[Mendekripsi...]'
            print decrypt(public2, data)
