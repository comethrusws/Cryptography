def skibidi(plaintext, keyword):
    secret_text_hehe = ""
    keyword_index = 0
    keyword_length = len(keyword)

    for character in plaintext:
        if character.isalpha():  # only process alphabetic characters
            allthewayup = character.isupper()  # check if it's uppercase
            offset = ord('A') if allthewayup else ord('a')
            key_shift = ord(keyword[keyword_index % keyword_length].lower()) - ord('a')  # calculate shift
            secret_text_hehe += chr((ord(character) - offset + key_shift) % 26 + offset)
            keyword_index += 1
        else:
            # just append non-alphabetic characters
            secret_text_hehe += character

    return secret_text_hehe


# get inputs from user
plaintext = input("enter plaintext: ")
keyword = input("enter key: ")

# encrypt and print the result
result = skibidi(plaintext, keyword)
print(f"encrypted text: {result}")
