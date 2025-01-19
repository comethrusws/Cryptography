def make_big_boy(text):
    # plain old uppies for hte lowercase
    return ''.join(char.upper() for char in text if char.isalpha())


def hill_cipher_encrypt(plaintext, key_matrix):
    # if odd length, slap on an X
    if len(plaintext) % 2 != 0:
        plaintext += 'X'

    encrypted_text = ""
    for i in range(0, len(plaintext), 2):
        # get the letter values (A=0, B=1, ...)
        ch1 = ord(plaintext[i]) - ord('A')
        ch2 = ord(plaintext[i + 1]) - ord('A')

        # hill cipher math magic
        new_ch1 = (key_matrix[0][0] * ch1 + key_matrix[0][1] * ch2) % 26
        new_ch2 = (key_matrix[1][0] * ch1 + key_matrix[1][1] * ch2) % 26

        # convert back to letters and append to encrypted_text
        encrypted_text += chr(new_ch1 + ord('A'))
        encrypted_text += chr(new_ch2 + ord('A'))

    return encrypted_text


# input plaintext and key matrix
plaintext = input("enter plaintext: ")
key_matrix = []
print("enter 2x2 key matrix (space-separated):")
for _ in range(2):
    key_matrix.append(list(map(int, input().split())))

plaintext = make_big_boy(plaintext)

result = hill_cipher_encrypt(plaintext, key_matrix)
print(f"encrypted text: {result}")
