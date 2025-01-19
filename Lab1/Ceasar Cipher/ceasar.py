def caesar_cipher(text, key):
    encrypted_text = ""
    for char in text:
        if char.isupper():  # encrypt uppercase letters
            encrypted_text += chr((ord(char) - ord('A') + key) % 26 + ord('A'))
        elif char.islower():  # encrypt lowercase letters
            encrypted_text += chr((ord(char) - ord('a') + key) % 26 + ord('a'))
        else:
            encrypted_text += char  #non-alphabetic characters unchanged
    return encrypted_text


text = input("Enter a string to encrypt: ")
key = int(input("Enter the key: "))

result = caesar_cipher(text, key)
print(f"Encrypted text: {result}")
